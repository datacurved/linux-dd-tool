#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void backupDrive();
    void restoreImage();
    void cloneDrive();
    void stopProcess();
    void zeroWipeDrive();
    void testSmbConnection();
    void saveSmbCredentials();
    void loadSmbCredentials();
    void updateSmbProgress();   // ✅ function stays here

    void processOutput();
    void chooseBackupLocation();
    void chooseRestoreImage();

    void copyBackupToSmb(const QString &filePath);
    void setupScheduledBackup();
    void setupAutostart();

private:
    Ui::MainWindow *ui;
    int calculateProgress(const QByteArray &data);
    QProcess *process;
    quint64 totalSize = 0;

    void smbAutoCopy(const QString &localFile);

    QString backupFilePath;
    QString restoreImagePath;

    void refreshDrives();
    quint64 getDriveSize(const QString &drive);
    QString blockSizeString();
    int dayOfWeekToNumber(const QString &day);

    // ✅ SMB tracking variables MUST be here
    QTimer *smbProgressTimer = nullptr;
    qint64 smbTotalBytes = 0;
    QString smbRemoteFile;
    QString smbRemotePath;
    QString smbCredFile;
};

#endif // MAINWINDOW_H
