#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "headers.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTimer t;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

///buttons tracking
private slots:
    void on_exit_clicked();

    void removeWidget();

    void on_home_clicked();

    void on_calendar_clicked();

    void on_planner_clicked();

    void on_settings_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_close_clicked();

    void on_hide_clicked();

    void on_fullscreen_clicked();

private:
    Ui::MainWindow *ui;

///mouse tracking in titleBar area
protected:
    QPoint oldPos;
    QPoint currentPos;
    QObject *check_obj;

    bool eventFilter(QObject *, QEvent *event) override;//, QMouseEvent* m_event);

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
