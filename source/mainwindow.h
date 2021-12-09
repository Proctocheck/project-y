#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "headers.h"

//Widgets
#include "home.h"
#include "calendar.h"
#include "planner.h"
#include "settings.h"

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

    void on_home_clicked();

    void on_calendar_clicked();

    void on_planner_clicked();

    void on_settings_clicked();

    void on_close_clicked();

    void on_hide_clicked();

    void on_fullscreen_clicked();

    void on_create_clicked();

///widget tracking
private slots:
    void replaceWidget(QWidget* w);

    void createNote();

    void closeNote();

    void changeTheme(QString theme);

///работа с compactor
signals:

private slots:


private:
    //Compactor* c;

    Ui::MainWindow *ui;

    Calendar* calendar;
    Home* home;
    Planner* planner;

    QWidget* currWidg = nullptr;

    QPoint oldPos;
    QPoint currentPos;
    QObject *check_obj;

///theme properties
protected:
    QString theme = "light";

    QString light_bg = "background-color: rgb(255, 255, 255);";
    QString light_text = "color: rgb(0, 0, 0);";

    QString dark_bg = "background-color: rgb(32, 58, 67);";
    QString dark_text = "color: rgb(255, 255, 255);";
///mouse tracking in titleBar area
protected:

    bool eventFilter(QObject *, QEvent *event) override;//, QMouseEvent* m_event);

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
