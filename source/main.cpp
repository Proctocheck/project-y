#include "mainwindow.h"
#include "launchwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    LaunchWindow l;
//    l.show();
    MainWindow m;
    m.show();
    return a.exec();
}
