#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QRegularExpression>
#include <QTextCursor>
#include <QStandardPaths>
#include <QDir>
#include <QTimer>

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSmbCredentials();
    process = new QProcess(this);
    process->setProcessChannelMode(QProcess::MergedChannels);

    connect(process, &QProcess::readyRead, this, &MainWindow::processOutput);

    // Buttons
    connect(ui->backupButton, &QPushButton::clicked, this, &MainWindow::backupDrive);
    connect(ui->restoreButton, &QPushButton::clicked, this, &MainWindow::restoreImage);
    connect(ui->cloneButton, &QPushButton::clicked, this, &MainWindow::cloneDrive);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::stopProcess);
    connect(ui->backupLocationButton, &QPushButton::clicked, this, &MainWindow::chooseBackupLocation);
    connect(ui->restoreImageButton, &QPushButton::clicked, this, &MainWindow::chooseRestoreImage);
    connect(ui->ddzerowipe, &QPushButton::clicked, this, &MainWindow::zeroWipeDrive);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::testSmbConnection);
    connect(ui->checkBox_3, &QCheckBox::toggled, this, &MainWindow::saveSmbCredentials);
    // Enable/Disable target
    ui->targetDriveCombo->setEnabled(false);
    connect(ui->enableTargetCheck, &QCheckBox::toggled,
            ui->targetDriveCombo, &QWidget::setEnabled);

    // SMB fields toggle
    connect(ui->enableSmbCheck, &QCheckBox::toggled, this, [=](bool checked){
        ui->smbEdit->setEnabled(checked);
        ui->smbUserEdit->setEnabled(checked);
        ui->smbPassEdit->setEnabled(checked);
        ui->lineWORKGROUP->setEnabled(checked);
    });

    // Block size dial
    ui->BSdial->setMinimum(1);
    ui->BSdial->setMaximum(1024);
    ui->BSdial->setValue(4);
    ui->BSlcdNumber->display(4);

    connect(ui->BSdial, &QDial::valueChanged, this, [=](int value){
        ui->BSlcdNumber->display(value);
    });

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
    for (const QString &dev : devices) {
        QString full = "/dev/" + dev;
        ui->sourceDriveCombo->addItem(full);
        ui->targetDriveCombo->addItem(full);
    }
}

QString MainWindow::blockSizeString()
{
    int bs = ui->BSdial->value();
    return QString("bs=%1M").arg(bs);
}

void MainWindow::backupDrive()
{
    QString source = ui->sourceDriveCombo->currentText();
    if (source.isEmpty() || backupFilePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select source drive and save location.");
        return;
    }

    totalSize = getDriveSize(source);
    ui->DDprogressBar->setValue(0);

    // dd arguments
    QStringList args;
    args << "if=" + source
         << "of=" + backupFilePath
         << blockSizeString()
         << "status=progress";

    process->start("dd", args);

    // After dd finishes, automatically push via SMB if enabled
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [=](int, QProcess::ExitStatus){
                ui->logTextEdit->append("Backup finished.");

                // Call SMB auto copy only if enabled
                if (ui->enableSmbCheck->isChecked()) {
                    smbAutoCopy(backupFilePath);
                }
            });
}

void MainWindow::restoreImage()
{
    if (!ui->enableTargetCheck->isChecked()) {
        QMessageBox::warning(this, "Error", "Enable target drive.");
        return;
    }

    QString target = ui->targetDriveCombo->currentText();
    if (target.isEmpty() || restoreImagePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select target and image file.");
        return;
    }

    totalSize = getDriveSize(target);
    ui->DDprogressBar->setValue(0);

    QStringList args;
    args << "if=" + restoreImagePath
         << "of=" + target
         << blockSizeString()
         << "status=progress";

    process->start("dd", args);
}

void MainWindow::cloneDrive()
{
    QString source = ui->sourceDriveCombo->currentText();
    QString target = ui->targetDriveCombo->currentText();

    if (source.isEmpty() || target.isEmpty() || source == target) {
        QMessageBox::warning(this, "Error", "Invalid source/target.");
        return;
    }

    totalSize = getDriveSize(source);
    ui->DDprogressBar->setValue(0);

    QStringList args;
    args << "if=" + source
         << "of=" + target
         << blockSizeString()
         << "status=progress";

    process->start("dd", args);
}

void MainWindow::zeroWipeDrive()
{
    if (!ui->enableTargetCheck->isChecked()) {
        QMessageBox::warning(this, "Error", "Enable target drive.");
        return;
    }

    QString target = ui->targetDriveCombo->currentText();
    if (target.isEmpty()) {
        QMessageBox::warning(this, "Error", "Select target drive.");
        return;
    }

    totalSize = getDriveSize(target);
    ui->DDprogressBar->setValue(0);

    QStringList args;
    args << "if=/dev/zero"
         << "of=" + target
         << blockSizeString()
         << "status=progress";

    process->start("dd", args);
}

void MainWindow::testSmbConnection()
{
    QString smbPath = ui->smbEdit->text().trimmed();
    QString user = ui->smbUserEdit->text().trimmed();
    QString pass = ui->smbPassEdit->text();
    QString workgroup = ui->lineWORKGROUP->text().trimmed();

    if (smbPath.isEmpty()) {
        ui->logTextEdit->append("Error: Enter SMB server/share");
        return;
    }

    // Convert smb://server/share -> //server/share
    if (smbPath.startsWith("smb://"))
        smbPath = "//" + smbPath.mid(6);

    // Create temporary credentials file
    QString credFile = QDir::temp().filePath("smbcred.txt");
    QFile file(credFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->logTextEdit->append("Error: Cannot create temporary credentials file.");
        return;
    }

    QTextStream out(&file);
    if (!user.isEmpty()) out << "username=" << user << "\n";
    if (!pass.isEmpty()) out << "password=" << pass << "\n";
    if (!workgroup.isEmpty()) out << "workgroup=" << workgroup << "\n";
    file.close();

    // Build smbclient arguments
    QStringList args;
    args << "-L" << smbPath << "-A" << credFile << "-m" << "SMB3";

    QProcess *proc = new QProcess(this);
    proc->setProcessChannelMode(QProcess::MergedChannels); // merge stdout + stderr

    connect(proc, &QProcess::readyRead, this, [=]() {
        QString output = proc->readAll();
        ui->logTextEdit->moveCursor(QTextCursor::End);
        ui->logTextEdit->insertPlainText(output);
        ui->logTextEdit->ensureCursorVisible();
    });

    connect(proc, &QProcess::finished, this, [=](int exitCode, QProcess::ExitStatus){
        if (exitCode == 0)
            ui->logTextEdit->append("\nSMB connection successful.");
        else
            ui->logTextEdit->append("\nSMB connection failed with exit code: " + QString::number(exitCode));

        // Delete temporary credentials file
        QFile::remove(credFile);

        proc->deleteLater();
    });

    proc->start("smbclient", args);

    if (!proc->waitForStarted(5000)) {
        ui->logTextEdit->append("Failed to start smbclient process.");
        QFile::remove(credFile);
        proc->deleteLater();
        return;
    }


}

void MainWindow::copyBackupToSmb(const QString &filePath)
{
    if (!ui->enableSmbCheck->isChecked())
        return;

    QString smbPath = ui->smbEdit->text().trimmed();
    QString user = ui->smbUserEdit->text().trimmed();
    QString pass = ui->smbPassEdit->text();
    QString workgroup = ui->lineWORKGROUP->text().trimmed();

    if (smbPath.startsWith("smb://"))
        smbPath = "//" + smbPath.mid(6);

    QString credFile = QDir::temp().filePath("smbcred.txt");
    QFile file(credFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        if (!user.isEmpty()) out << "username=" << user << "\n";
        if (!pass.isEmpty()) out << "password=" << pass << "\n";
        if (!workgroup.isEmpty()) out << "workgroup=" << workgroup << "\n";
        file.close();
    }

    QStringList args;
    args << smbPath << "-A" << credFile << "-m" << "SMB3" << "-c" << QString("put \"%1\"").arg(filePath);

    QProcess *proc = new QProcess(this);
    proc->setProcessChannelMode(QProcess::MergedChannels);

    connect(proc, &QProcess::readyRead, this, [=]() {
        QString output = proc->readAll();
        ui->logTextEdit->moveCursor(QTextCursor::End);
        ui->logTextEdit->insertPlainText(output);
        ui->logTextEdit->ensureCursorVisible();
    });

    connect(proc, &QProcess::finished, this, [=](int exitCode, QProcess::ExitStatus){
        if (exitCode == 0)
            ui->logTextEdit->append("\nBackup copied to SMB share successfully.");
        else
            ui->logTextEdit->append("\nFailed to copy backup to SMB share.");
        QFile::remove(credFile);
        proc->deleteLater();
    });

    proc->start("smbclient", args);
}

void MainWindow::setupScheduledBackup()
{
    if (!ui->checkBox_2->isChecked()) // "Schedule a backup"
        return;

    QString time = ui->timeEdit->time().toString("HH:mm");
    int hour = ui->timeEdit->time().hour();
    int minute = ui->timeEdit->time().minute();

    QString frequency;
    if (ui->radioButton->isChecked()) frequency = "daily";
    else if (ui->radioButton_2->isChecked()) frequency = "weekly";
    else if (ui->radioButton_3->isChecked()) frequency = "monthly";
    else if (ui->radioButton_4->isChecked()) frequency = "yearly";

    QString dayOfWeek = ui->comboBox->currentText();
    QString backupCommand = QString("%1 --backup").arg(QCoreApplication::applicationFilePath());

    QString cronLine;
    if (frequency == "daily") cronLine = QString("%1 %2 * * * %3").arg(minute).arg(hour).arg(backupCommand);
    else if (frequency == "weekly") cronLine = QString("%1 %2 * * %3 %4").arg(minute).arg(hour).arg(dayOfWeekToNumber(dayOfWeek)).arg(backupCommand);
    else if (frequency == "monthly") cronLine = QString("%1 %2 1 * * %3").arg(minute).arg(hour).arg(backupCommand);
    else if (frequency == "yearly") cronLine = QString("%1 %2 1 1 * %3").arg(minute).arg(hour).arg(backupCommand);

    QProcess proc;
    proc.start("bash", QStringList() << "-c" << QString("(crontab -l 2>/dev/null; echo '%1') | crontab -").arg(cronLine));
    proc.waitForFinished();

    ui->logTextEdit->append("Scheduled backup added: " + cronLine);
}

// Helper to convert day string to cron number
int MainWindow::dayOfWeekToNumber(const QString &day)
{
    if (day == "Sundays") return 0;
    if (day == "Mondays") return 1;
    if (day == "Tuesdays") return 2;
    if (day == "Wednesdays") return 3;
    if (day == "Thursdays") return 4;
    if (day == "Fridays") return 5;
    if (day == "Saturdays") return 6;
    return 1; // default Monday
}

void MainWindow::setupAutostart()
{
    if (!ui->checkBox->isChecked()) return;

    QString autostartDir = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/autostart";
    QDir().mkpath(autostartDir);

    QString desktopFile = autostartDir + "/QtDDBackup.desktop";

    QFile file(desktopFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "[Desktop Entry]\n";
        out << "Type=Application\n";
        out << "Exec=" << QCoreApplication::applicationFilePath() << "\n";
        out << "Hidden=false\n";
        out << "NoDisplay=false\n";
        out << "X-GNOME-Autostart-enabled=true\n";
        out << "Name=Qt DD Backup\n";
        out << "Comment=Start Qt DD Backup on login\n";
        file.close();
    }

    ui->logTextEdit->append("Autostart configured.");
}


void MainWindow::chooseBackupLocation()
{
    QString file = QFileDialog::getSaveFileName(this, "Save Backup", "", "*.img");
    if (!file.isEmpty())
        backupFilePath = file;
}

void MainWindow::chooseRestoreImage()
{
    QString file = QFileDialog::getOpenFileName(this, "Select Image", "", "*.img");
    if (!file.isEmpty())
        restoreImagePath = file;
}

void MainWindow::stopProcess()
{
    if (process->state() == QProcess::Running) {
        process->kill();
        ui->logTextEdit->append("Process stopped.");
        ui->DDprogressBar->setValue(0);
    }
}




void MainWindow::saveSmbCredentials()
{
    QSettings settings("DDTool", "BackupApp");

    if (ui->checkBox_3->isChecked()) {
        // Save values if "Remember me" is checked
        settings.setValue("smb/path", ui->smbEdit->text().trimmed());
        settings.setValue("smb/user", ui->smbUserEdit->text().trimmed());
        settings.setValue("smb/pass", ui->smbPassEdit->text());
        settings.setValue("smb/workgroup", ui->lineWORKGROUP->text().trimmed());
    } else {
        // Remove saved credentials if unchecked
        settings.remove("smb/path");
        settings.remove("smb/user");
        settings.remove("smb/pass");
        settings.remove("smb/workgroup");
    }
}

void MainWindow::smbAutoCopy(const QString &localFile)
{
    if (!ui->enableSmbCheck->isChecked() || localFile.isEmpty())
        return;

    // Prepare variables
    smbTotalBytes = QFileInfo(localFile).size();
    smbRemoteFile = QFileInfo(localFile).fileName();
    smbRemotePath = ui->smbEdit->text().trimmed();
    if (smbRemotePath.startsWith("smb://"))
        smbRemotePath = "//" + smbRemotePath.mid(6);

    // Credentials file
    if (ui->checkBox_3->isChecked()) {
        smbCredFile = QDir::homePath() + "/.smbcred.txt";
    } else {
        smbCredFile = QDir::temp().filePath("smbcred.txt");
    }

    // Write credentials to the file
    QFile file(smbCredFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->logTextEdit->append("[SMB] Error: Cannot create credentials file.");
        return;
    }
    QTextStream out(&file);
    QString user = ui->smbUserEdit->text().trimmed();
    QString pass = ui->smbPassEdit->text();
    QString workgroup = ui->lineWORKGROUP->text().trimmed();
    if (!user.isEmpty()) out << "username=" << user << "\n";
    if (!pass.isEmpty()) out << "password=" << pass << "\n";
    if (!workgroup.isEmpty()) out << "workgroup=" << workgroup << "\n";
    file.close();

    // Show the "transferring" message
    ui->logTextEdit->append("[SMB] Now Transferring Backup to the Cloud; Please be patient as this could take some time...");
    ui->logTextEdit->append("[SMB] Uploading file: " + smbRemoteFile);

    // Optionally, set progress bar to 0 if you want it visible
    ui->DDprogressBar->setValue(0);

    // Build smbclient command: use 'put' to upload the file
    QString smbCommand = QString("put \"%1\" \"%2\"").arg(localFile, smbRemoteFile);
    QStringList args;
    args << "-A" << smbCredFile
         << "-m" << "SMB3"
         << smbRemotePath
         << "-c" << smbCommand;

    QProcess *proc = new QProcess(this);
    proc->setProcessChannelMode(QProcess::MergedChannels);

    // Capture both standard output and error output for debugging
    connect(proc, &QProcess::readyReadStandardOutput, this, [this, proc]() {
        QByteArray data = proc->readAllStandardOutput();

        // Here, we'll simply ignore the file transfer stats and instead focus on showing the message
        // We check for a successful transfer in the finished handler, but we can log some info
        // Log the output for debugging if needed (but don't display transfer speeds)
        ui->logTextEdit->moveCursor(QTextCursor::End);
        ui->logTextEdit->insertPlainText(QString::fromUtf8(data));
        ui->logTextEdit->ensureCursorVisible();
    });

    // Capture errors
    connect(proc, &QProcess::readyReadStandardError, this, [this, proc]() {
        QByteArray errorData = proc->readAllStandardError();
        ui->logTextEdit->moveCursor(QTextCursor::End);
        ui->logTextEdit->insertPlainText("[SMB Error] " + QString::fromUtf8(errorData));
        ui->logTextEdit->ensureCursorVisible();
    });

    // Finished handler: this will run when smbclient finishes
    connect(proc, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this, proc](int exitCode, QProcess::ExitStatus) {
                if (exitCode == 0) {
                    ui->logTextEdit->append("[SMB] UPLOAD FINISHED");
                } else {
                    ui->logTextEdit->append("[SMB] Copy failed, exit code: " + QString::number(exitCode));
                }

                if (!ui->checkBox_3->isChecked())
                    QFile::remove(smbCredFile);

                // Set progress bar to 100% once finished
                ui->DDprogressBar->setValue(100);

                proc->deleteLater();
            });

    // Start the smbclient process
    proc->start("smbclient", args);
    if (!proc->waitForStarted(5000)) {
        ui->logTextEdit->append("[SMB] Failed to start smbclient.");
        proc->deleteLater();
    }
}



int MainWindow::calculateProgress(const QByteArray &data)
{
    // Use QRegularExpression instead of QRegExp
    QRegularExpression regex("(\\d+)/(\\d+)");
    QRegularExpressionMatch match = regex.match(data);

    if (match.hasMatch()) {
        int bytesTransferred = match.captured(1).toInt();
        int totalBytes = match.captured(2).toInt();

        // Calculate progress percentage
        if (totalBytes > 0) {
            return (bytesTransferred * 100) / totalBytes;
        }
    }

    return 0;  // Default: 0% if no progress info found
}

void MainWindow::updateSmbProgress()
{
    if (smbTotalBytes == 0 || smbRemoteFile.isEmpty())
        return;

    // Use 'allinfo' to get file size from the remote share (rough estimate)
    QString smbCommand = QString("allinfo \"%1\"").arg(smbRemoteFile);
    QStringList args;
    args << smbRemotePath
         << "-A" << smbCredFile
         << "-m" << "SMB3"
         << "-c" << smbCommand;

    QProcess proc;
    proc.start("smbclient", args);
    proc.waitForFinished();

    QString output = proc.readAllStandardOutput();
    QRegularExpression rx("File Size:\\s+(\\d+)");
    QRegularExpressionMatch match = rx.match(output);

    if (match.hasMatch()) {
        qint64 copied = match.captured(1).toLongLong();
        int percent = (copied * 100) / smbTotalBytes;
        ui->DDprogressBar->setValue(qMin(percent, 100));
    }
}


quint64 MainWindow::getDriveSize(const QString &drive)
{
    QProcess proc;
    proc.start("blockdev", QStringList() << "--getsize64" << drive);

    if (!proc.waitForFinished())
        return 0;

    QByteArray output = proc.readAllStandardOutput().trimmed();

    bool ok = false;
    quint64 size = output.toULongLong(&ok);

    return ok ? size : 0;
}



void MainWindow::loadSmbCredentials()
{
    QSettings settings("DDTool", "BackupApp");

    ui->smbEdit->setText(settings.value("smb/path").toString());
    ui->smbUserEdit->setText(settings.value("smb/user").toString());
    ui->smbPassEdit->setText(settings.value("smb/pass").toString());
    ui->lineWORKGROUP->setText(settings.value("smb/workgroup").toString());

    // Check "Remember me" if a path exists
    ui->checkBox_3->setChecked(!settings.value("smb/path").toString().isEmpty());
}

void MainWindow::processOutput()
{
    QString output = process->readAll();

    if (ui->Verboselogs->isChecked()) {
        ui->logTextEdit->moveCursor(QTextCursor::End);
        ui->logTextEdit->insertPlainText(output);
        ui->logTextEdit->ensureCursorVisible();
    }

    QRegularExpression rx("(\\d+) bytes");
    QRegularExpressionMatch match = rx.match(output);

    if (match.hasMatch() && totalSize > 0) {
        quint64 copied = match.captured(1).toULongLong();
        int percent = (copied * 100) / totalSize;
        ui->DDprogressBar->setValue(qMin(percent, 100));
    }
    // At the very end of processOutput()
    if (process->state() != QProcess::Running) {

        ui->logTextEdit->append("Backup finished.");
        smbAutoCopy(backupFilePath);   // <-- call SMB copy here
    }

}
