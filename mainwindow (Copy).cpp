#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStorageInfo>
#include <QMessageBox>
#include <QDir>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    process = new QProcess(this);

    // Connect DD output to log
    connect(process, &QProcess::readyReadStandardOutput,
            this, &MainWindow::processOutput);
    connect(process, &QProcess::readyReadStandardError,
            this, &MainWindow::processOutput);

    // Disable target + SMB fields by default
    ui->targetDriveCombo->setEnabled(false);
    ui->smbEdit->setEnabled(false);
    ui->smbUserEdit->setEnabled(false);
    ui->smbPassEdit->setEnabled(false);
    ui->lineWORKGROUP->setEnabled(false);

    // Enable/disable based on checkboxes
    connect(ui->enableTargetCheck, &QCheckBox::toggled,
            ui->targetDriveCombo, &QWidget::setEnabled);

    connect(ui->enableSmbCheck, &QCheckBox::toggled, [=](bool checked){
        ui->smbEdit->setEnabled(checked);
        ui->smbUserEdit->setEnabled(checked);
        ui->smbPassEdit->setEnabled(checked);
        ui->lineWORKGROUP->setEnabled(checked);
    });

    // File selection buttons
    connect(ui->backupLocationButton, &QPushButton::clicked,
            this, &MainWindow::chooseBackupLocation);
    connect(ui->restoreImageButton, &QPushButton::clicked,
            this, &MainWindow::chooseRestoreImage);

    // Action buttons
    connect(ui->backupButton, &QPushButton::clicked,
            this, &MainWindow::backupDrive);
    connect(ui->restoreButton, &QPushButton::clicked,
            this, &MainWindow::restoreImage);
    connect(ui->cloneButton, &QPushButton::clicked,
            this, &MainWindow::cloneDrive);

    refreshDrives();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshDrives()
{
    ui->sourceDriveCombo->clear();
    ui->targetDriveCombo->clear();

    QDir devDir("/dev");
    QStringList filters;
    filters << "sd*" << "nvme*";

    QStringList devices = devDir.entryList(filters, QDir::System);

    for(const QString &dev : devices)
    {
        QString fullPath = "/dev/" + dev;
        ui->sourceDriveCombo->addItem(fullPath);
        ui->targetDriveCombo->addItem(fullPath);
    }
}

void MainWindow::chooseBackupLocation()
{
    QString file = QFileDialog::getSaveFileName(
        this,
        "Select Backup Image File",
        "",
        "Image Files (*.img)");

    if(!file.isEmpty())
        backupFilePath = file;
}

void MainWindow::chooseRestoreImage()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        "Select Image File",
        "",
        "Image Files (*.img)");

    if(!file.isEmpty())
        restoreImagePath = file;
}

void MainWindow::backupDrive()
{
    QString source = ui->sourceDriveCombo->currentText();

    if(source.isEmpty() || backupFilePath.isEmpty())
    {
        QMessageBox::warning(this, "Error",
                             "Select a source drive and backup file.");
        return;
    }

    QStringList args;
    args << "if=" + source
         << "of=" + backupFilePath
         << "bs=64K"
         << "status=progress";

    process->start("dd", args);

    // Optional SMB copy
    if(ui->enableSmbCheck->isChecked())
    {
        QString smbUrl = ui->smbEdit->text();
        QString smbUser = ui->smbUserEdit->text();
        QString smbPass = ui->smbPassEdit->text();
        QString smbWorkgroup = ui->lineWORKGROUP->text();

        if(!smbUrl.isEmpty() && !smbUser.isEmpty())
        {
            QString mountPoint = "/mnt/backup_dd";
            QDir().mkpath(mountPoint);

            QStringList mountArgs;
            mountArgs << "-t" << "cifs"
                      << smbUrl
                      << mountPoint
                      << "-o"
                      << QString("username=%1,password=%2,workgroup=%3")
                             .arg(smbUser)
                             .arg(smbPass)
                             .arg(smbWorkgroup);

            QProcess mountProcess;
            mountProcess.start("mount", mountArgs);
            mountProcess.waitForFinished();

            // Copy backup
            QProcess::execute("cp", QStringList() << backupFilePath << mountPoint);

            // Optionally unmount
            QProcess::execute("umount", QStringList() << mountPoint);
        }
    }
}

void MainWindow::restoreImage()
{
    if (restoreImagePath.isEmpty())
    {
        QMessageBox::warning(this, "Error",
                             "Select a restore image file.");
        return;
    }

    if (!ui->enableTargetCheck->isChecked())
    {
        QMessageBox::warning(this, "Error",
                             "Enable and select a target drive.");
        return;
    }

    QString target = ui->targetDriveCombo->currentText();

    if (target.isEmpty())
    {
        QMessageBox::warning(this, "Error",
                             "Select a target drive.");
        return;
    }

    QStringList args;
    args << "if=" + restoreImagePath
         << "of=" + target
         << "bs=64K"
         << "status=progress";

    process->start("dd", args);
}

void MainWindow::cloneDrive()
{
    QString source = ui->sourceDriveCombo->currentText();
    QString target = ui->targetDriveCombo->currentText();

    if(source.isEmpty() || target.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Select source and target drives.");
        return;
    }

    if(source == target)
    {
        QMessageBox::warning(this, "Error", "Source and target cannot match.");
        return;
    }

    QStringList args;
    args << "if=" + source
         << "of=" + target
         << "bs=64K"
         << "status=progress";

    process->start("dd", args);
}

void MainWindow::processOutput()
{
    ui->logTextEdit->append(process->readAllStandardOutput());
    ui->logTextEdit->append(process->readAllStandardError());
}
