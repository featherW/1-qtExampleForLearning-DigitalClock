#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/res/default.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    MainWindow w;
    w.initWindow();
    w.show();
    QObject::connect(&w,SIGNAL(exitsignal()),&a,SLOT(quit()));

    return a.exec();
}
