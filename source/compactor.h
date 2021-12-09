#ifndef COMPACTOR_H
#define COMPACTOR_H

#include "mainwindow.h"

class Compactor
{
public:
    Compactor();
private:
    MainWindow* m;
signals:
    void send_data();

private slots:
    void get_data(QDate);
};

#endif // COMPACTOR_H
