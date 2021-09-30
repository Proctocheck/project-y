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
    void launch();
    LaunchWindow(QWidget *parent = nullptr);
    ~LaunchWindow();
    QTimer* t;
    int c;
private:
    Ui::LaunchWindow *ui;
private slots:
    void aboba();
};

#endif // LAUNCHWINDOW_H
