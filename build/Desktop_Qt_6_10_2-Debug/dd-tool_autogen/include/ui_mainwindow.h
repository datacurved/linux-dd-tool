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
#include <QtWidgets/QCalendarWidget>
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
#include <QtWidgets/QTabWidget>
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
    QProgressBar *DDprogressBar;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab_7;
    QGroupBox *logGroup;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *Verboselogs;
    QTextEdit *logTextEdit;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QPushButton *ddzerowipe;
    QLCDNumber *BSlcdNumber;
    QDial *BSdial;
    QLabel *label;
    QLabel *label_3;
    QCheckBox *checkBox;
    QWidget *tab_6;
    QWidget *widget;
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
    QWidget *tab_4;
    QComboBox *comboBox;
    QTimeEdit *timeEdit;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QCheckBox *checkBox_2;
    QCalendarWidget *calendarWidget;
    QWidget *tab_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(835, 697);
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


        mainLayout->addWidget(backupGroup);

        DDprogressBar = new QProgressBar(centralwidget);
        DDprogressBar->setObjectName("DDprogressBar");
        DDprogressBar->setValue(0);

        mainLayout->addWidget(DDprogressBar);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 110));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 791, 281));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        logGroup = new QGroupBox(tab_7);
        logGroup->setObjectName("logGroup");
        logGroup->setGeometry(QRect(0, 10, 671, 231));
        verticalLayout_3 = new QVBoxLayout(logGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        Verboselogs = new QCheckBox(logGroup);
        Verboselogs->setObjectName("Verboselogs");

        verticalLayout_3->addWidget(Verboselogs);

        logTextEdit = new QTextEdit(logGroup);
        logTextEdit->setObjectName("logTextEdit");
        logTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(logTextEdit);

        tabWidget->addTab(tab_7, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(430, 80, 201, 81));
        ddzerowipe = new QPushButton(groupBox_2);
        ddzerowipe->setObjectName("ddzerowipe");
        ddzerowipe->setGeometry(QRect(50, 30, 110, 40));
        BSlcdNumber = new QLCDNumber(tab_3);
        BSlcdNumber->setObjectName("BSlcdNumber");
        BSlcdNumber->setGeometry(QRect(200, 10, 130, 60));
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
        BSdial = new QDial(tab_3);
        BSdial->setObjectName("BSdial");
        BSdial->setGeometry(QRect(50, 60, 140, 130));
        BSdial->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(tab_3);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 90, 201, 10));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 30, 161, 10));
        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(0, 180, 672, 23));
        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        widget = new QWidget(tab_6);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 641, 201));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        enableSmbCheck = new QCheckBox(widget);
        enableSmbCheck->setObjectName("enableSmbCheck");

        horizontalLayout_3->addWidget(enableSmbCheck);

        smbEdit = new QLineEdit(widget);
        smbEdit->setObjectName("smbEdit");

        horizontalLayout_3->addWidget(smbEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
        smbUserLabel = new QLabel(widget);
        smbUserLabel->setObjectName("smbUserLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, smbUserLabel);

        smbUserEdit = new QLineEdit(widget);
        smbUserEdit->setObjectName("smbUserEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, smbUserEdit);

        labelWORKGROUP = new QLabel(widget);
        labelWORKGROUP->setObjectName("labelWORKGROUP");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelWORKGROUP);

        lineWORKGROUP = new QLineEdit(widget);
        lineWORKGROUP->setObjectName("lineWORKGROUP");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineWORKGROUP);

        smbPassLabel = new QLabel(widget);
        smbPassLabel->setObjectName("smbPassLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, smbPassLabel);

        smbPassEdit = new QLineEdit(widget);
        smbPassEdit->setObjectName("smbPassEdit");
        smbPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, smbPassEdit);

        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName("checkBox_3");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, checkBox_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, pushButton_2);


        verticalLayout_2->addLayout(formLayout);

        tabWidget->addTab(tab_6, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        comboBox = new QComboBox(tab_4);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(380, 10, 90, 26));
        timeEdit = new QTimeEdit(tab_4);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(390, 40, 81, 30));
        radioButton_4 = new QRadioButton(tab_4);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(270, 40, 71, 20));
        radioButton_2 = new QRadioButton(tab_4);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(270, 10, 71, 20));
        radioButton = new QRadioButton(tab_4);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(170, 10, 71, 20));
        radioButton_3 = new QRadioButton(tab_4);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(170, 40, 81, 20));
        checkBox_2 = new QCheckBox(tab_4);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(0, 50, 151, 20));
        calendarWidget = new QCalendarWidget(tab_4);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(130, 70, 261, 151));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());

        mainLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


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
        cloneButton->setText(QCoreApplication::translate("MainWindow", "Clone Source", nullptr));
        restoreImageButton->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        restoreButton->setText(QCoreApplication::translate("MainWindow", "Restore Drive", nullptr));
        groupBox->setTitle(QString());
        logGroup->setTitle(QCoreApplication::translate("MainWindow", "Log Output", nullptr));
        Verboselogs->setText(QCoreApplication::translate("MainWindow", "Verbose Output", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Output", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", " wipes target drive with zeros ", nullptr));
        ddzerowipe->setText(QCoreApplication::translate("MainWindow", "ZeroWipe", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Block Size: Default is 4", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "UP/Down controls dial", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Start on Boot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Options", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Network", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Mondays", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Tuesdays", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Wednesdays", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Thursdays", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Fridays", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Saturdays", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Sundays", nullptr));

        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Yearly", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Weekly", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Daily", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Monthly", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Schedule a backup", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Schedule", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
