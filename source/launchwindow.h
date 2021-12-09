#ifndef LAUNCHWINDOW_H
#define LAUNCHWINDOW_H

#include "mainwindow.h"

namespace Ui {
class LaunchWindow;
}

class LaunchWindow : public QMainWindow
{
    Q_OBJECT

public:
    LaunchWindow(QWidget *parent = nullptr);
    ~LaunchWindow();
private:
    Ui::LaunchWindow *ui;

    QTimer* t;
    int c;
    void launch();
private slots:
    void aboba();
};

#endif // LAUNCHWINDOW_H
