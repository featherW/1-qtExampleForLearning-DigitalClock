#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initWindow();
    w.show();
    QObject::connect(&w,SIGNAL(exitsignal()),&a,SLOT(quit()));

    return a.exec();
}
