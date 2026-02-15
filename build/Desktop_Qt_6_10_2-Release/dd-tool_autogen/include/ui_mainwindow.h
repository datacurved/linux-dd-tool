/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QGroupBox *backupGroup;
    QVBoxLayout *verticalLayout_1;
    QGroupBox *sourceGroup;
    QHBoxLayout *horizontalLayout_1;
    QLabel *labelSource;
    QComboBox *sourceDriveCombo;
    QPushButton *backupLocationButton;
    QPushButton *backupButton;
    QPushButton *pushButton;
    QGroupBox *targetGroup;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *enableTargetCheck;
    QComboBox *targetDriveCombo;
    QPushButton *cloneButton;
    QPushButton *restoreImageButton;
    QPushButton *restoreButton;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QDial *BSdial;
    QLabel *label;
    QLCDNumber *BSlcdNumber;
    QLabel *label_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QTimeEdit *timeEdit;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QComboBox *comboBox;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_2;
    QPushButton *ddzerowipe;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *enableSmbCheck;
    QLineEdit *smbEdit;
    QFormLayout *formLayout;
    QLabel *smbUserLabel;
    QLineEdit *smbUserEdit;
    QLabel *labelWORKGROUP;
    QLineEdit *lineWORKGROUP;
    QLabel *smbPassLabel;
    QLineEdit *smbPassEdit;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_2;
    QProgressBar *DDprogressBar;
    QCheckBox *Verboselogs;
    QGroupBox *logGroup;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *logTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(733, 706);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        backupGroup = new QGroupBox(centralwidget);
        backupGroup->setObjectName("backupGroup");
        verticalLayout_1 = new QVBoxLayout(backupGroup);
        verticalLayout_1->setObjectName("verticalLayout_1");
        sourceGroup = new QGroupBox(backupGroup);
        sourceGroup->setObjectName("sourceGroup");
        horizontalLayout_1 = new QHBoxLayout(sourceGroup);
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        labelSource = new QLabel(sourceGroup);
        labelSource->setObjectName("labelSource");

        horizontalLayout_1->addWidget(labelSource);

        sourceDriveCombo = new QComboBox(sourceGroup);
        sourceDriveCombo->setObjectName("sourceDriveCombo");

        horizontalLayout_1->addWidget(sourceDriveCombo);

        backupLocationButton = new QPushButton(sourceGroup);
        backupLocationButton->setObjectName("backupLocationButton");

        horizontalLayout_1->addWidget(backupLocationButton);

        backupButton = new QPushButton(sourceGroup);
        backupButton->setObjectName("backupButton");

        horizontalLayout_1->addWidget(backupButton);

        pushButton = new QPushButton(sourceGroup);
        pushButton->setObjectName("pushButton");

        horizontalLayout_1->addWidget(pushButton);


        verticalLayout_1->addWidget(sourceGroup);

        targetGroup = new QGroupBox(backupGroup);
        targetGroup->setObjectName("targetGroup");
        horizontalLayout_2 = new QHBoxLayout(targetGroup);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        enableTargetCheck = new QCheckBox(targetGroup);
        enableTargetCheck->setObjectName("enableTargetCheck");

        horizontalLayout_2->addWidget(enableTargetCheck);

        targetDriveCombo = new QComboBox(targetGroup);
        targetDriveCombo->setObjectName("targetDriveCombo");

        horizontalLayout_2->addWidget(targetDriveCombo);

        cloneButton = new QPushButton(targetGroup);
        cloneButton->setObjectName("cloneButton");

        horizontalLayout_2->addWidget(cloneButton);

        restoreImageButton = new QPushButton(targetGroup);
        restoreImageButton->setObjectName("restoreImageButton");

        horizontalLayout_2->addWidget(restoreImageButton);

        restoreButton = new QPushButton(targetGroup);
        restoreButton->setObjectName("restoreButton");

        horizontalLayout_2->addWidget(restoreButton);


        verticalLayout_1->addWidget(targetGroup);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        verticalLayout_1->addLayout(horizontalLayout_4);


        mainLayout->addWidget(backupGroup);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 110));
        BSdial = new QDial(groupBox);
        BSdial->setObjectName("BSdial");
        BSdial->setGeometry(QRect(-30, 30, 131, 71));
        BSdial->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 201, 18));
        BSlcdNumber = new QLCDNumber(groupBox);
        BSlcdNumber->setObjectName("BSlcdNumber");
        BSlcdNumber->setGeometry(QRect(80, 60, 131, 41));
        BSlcdNumber->setStyleSheet(QString::fromUtf8("ui->BSlcdNumber->setSegmentStyle(QLCDNumber::Flat);\n"
"ui->BSlcdNumber->setAutoFillBackground(true);\n"
"\n"
"QPalette pal = ui->BSlcdNumber->palette();\n"
"pal.setColor(QPalette::Window, Qt::black);\n"
"pal.setColor(QPalette::Active,   QPalette::Light, QColor(0,174,239));\n"
"pal.setColor(QPalette::Inactive, QPalette::Light, QColor(0,174,239));\n"
"pal.setColor(QPalette::Disabled, QPalette::Light, QColor(0,174,239));\n"
"pal.setColor(QPalette::Dark, Qt::black);\n"
"\n"
"ui->BSlcdNumber->setPalette(pal);\n"
""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(65, 40, 161, 20));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(220, 30, 111, 23));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(220, 50, 151, 23));
        timeEdit = new QTimeEdit(groupBox);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(380, 80, 118, 27));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(230, 70, 71, 23));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(310, 70, 110, 23));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(230, 90, 81, 23));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(380, 40, 93, 26));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(310, 90, 111, 23));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(500, 29, 201, 71));
        ddzerowipe = new QPushButton(groupBox_2);
        ddzerowipe->setObjectName("ddzerowipe");
        ddzerowipe->setGeometry(QRect(50, 30, 94, 26));

        mainLayout->addWidget(groupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        enableSmbCheck = new QCheckBox(centralwidget);
        enableSmbCheck->setObjectName("enableSmbCheck");

        horizontalLayout_3->addWidget(enableSmbCheck);

        smbEdit = new QLineEdit(centralwidget);
        smbEdit->setObjectName("smbEdit");

        horizontalLayout_3->addWidget(smbEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
        smbUserLabel = new QLabel(centralwidget);
        smbUserLabel->setObjectName("smbUserLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, smbUserLabel);

        smbUserEdit = new QLineEdit(centralwidget);
        smbUserEdit->setObjectName("smbUserEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, smbUserEdit);

        labelWORKGROUP = new QLabel(centralwidget);
        labelWORKGROUP->setObjectName("labelWORKGROUP");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelWORKGROUP);

        lineWORKGROUP = new QLineEdit(centralwidget);
        lineWORKGROUP->setObjectName("lineWORKGROUP");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineWORKGROUP);

        smbPassLabel = new QLabel(centralwidget);
        smbPassLabel->setObjectName("smbPassLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, smbPassLabel);

        smbPassEdit = new QLineEdit(centralwidget);
        smbPassEdit->setObjectName("smbPassEdit");
        smbPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, smbPassEdit);

        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName("checkBox_3");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, checkBox_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, pushButton_2);


        verticalLayout_2->addLayout(formLayout);


        mainLayout->addLayout(verticalLayout_2);

        DDprogressBar = new QProgressBar(centralwidget);
        DDprogressBar->setObjectName("DDprogressBar");
        DDprogressBar->setValue(0);

        mainLayout->addWidget(DDprogressBar);

        Verboselogs = new QCheckBox(centralwidget);
        Verboselogs->setObjectName("Verboselogs");

        mainLayout->addWidget(Verboselogs);

        logGroup = new QGroupBox(centralwidget);
        logGroup->setObjectName("logGroup");
        verticalLayout_3 = new QVBoxLayout(logGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        logTextEdit = new QTextEdit(logGroup);
        logTextEdit->setObjectName("logTextEdit");
        logTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(logTextEdit);


        mainLayout->addWidget(logGroup);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt DD Backup & Clone Tool", nullptr));
        backupGroup->setTitle(QCoreApplication::translate("MainWindow", "Backup / Restore", nullptr));
        sourceGroup->setTitle(QCoreApplication::translate("MainWindow", "Source Drive", nullptr));
        labelSource->setText(QCoreApplication::translate("MainWindow", "Drive:", nullptr));
        backupLocationButton->setText(QCoreApplication::translate("MainWindow", "Save Location", nullptr));
        backupButton->setText(QCoreApplication::translate("MainWindow", "Backup Drive", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        targetGroup->setTitle(QCoreApplication::translate("MainWindow", "Target Drive", nullptr));
        enableTargetCheck->setText(QCoreApplication::translate("MainWindow", "Enable Target", nullptr));
        cloneButton->setText(QCoreApplication::translate("MainWindow", "Clone Drive", nullptr));
        restoreImageButton->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        restoreButton->setText(QCoreApplication::translate("MainWindow", "Restore Drive", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Options:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Block Size: Default is 4", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "UP/Down controls dial", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Start on Boot", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Schedule a backup", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Daily", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Weekly", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Monthly", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Mondays", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Tuesdays", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Wednesdays", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Thursdays", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Fridays", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Saturdays", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Sundays", nullptr));

        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Yearly", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", " wipes target drive with zeros ", nullptr));
        ddzerowipe->setText(QCoreApplication::translate("MainWindow", "ZeroWipe", nullptr));
        enableSmbCheck->setText(QCoreApplication::translate("MainWindow", "Enable SMB Copy", nullptr));
        smbEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "smb://server/share", nullptr));
        smbUserLabel->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        smbUserEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        labelWORKGROUP->setText(QCoreApplication::translate("MainWindow", "Workgroup:", nullptr));
        lineWORKGROUP->setPlaceholderText(QCoreApplication::translate("MainWindow", "enter windows workgroup name", nullptr));
        smbPassLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        smbPassEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Remember me", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "TestConnection", nullptr));
        Verboselogs->setText(QCoreApplication::translate("MainWindow", "Verbose Output", nullptr));
        logGroup->setTitle(QCoreApplication::translate("MainWindow", "Log Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
