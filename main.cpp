#include <QApplication>
#include <QMessageBox>
#include <QSplashScreen>
#include <QTimer>
#include <unistd.h> // geteuid()
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Ensure the program runs as root
    if (geteuid() != 0)
    {
        QMessageBox::critical(nullptr,
                              "Root Required",
                              "This application must be run as root.\n\n"
                              "Please restart using:\n"
                              "sudo ./dd-tool");
        return 1;
    }

    // Splash screen
    QPixmap splashPixmap("/home/labone/dd-tool/dd-tool.png");
    QSplashScreen splash(splashPixmap);
    splash.show();
    app.processEvents(); // force it to render immediately

    // Delay showing main window by 3 seconds
    MainWindow window;
    window.setWindowTitle("Qt DD Backup & Clone Tool");
    window.resize(800, 600);

    QTimer::singleShot(3000, &splash, [&splash, &window]() {
        splash.close();
        window.show();
    });

    return app.exec();
}
