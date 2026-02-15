#include <QApplication>
#include <QMessageBox>
#include <unistd.h>     // geteuid()
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
                              "sudo ./YourAppName");
        return 1;
    }

    MainWindow window;
    window.setWindowTitle("Qt DD Backup & Clone Tool");
    window.resize(800, 600);
    window.show();

    return app.exec();
}
