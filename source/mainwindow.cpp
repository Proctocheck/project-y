#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    ui->titleBar->installEventFilter(this);
}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::on_exit_clicked() {

    this->close();
}

void MainWindow::removeWidget() {

    QPushButton* b = qobject_cast<QPushButton*>(sender());
    delete b;
}

///side frame
void MainWindow::on_home_clicked() {

    Home* home = new Home();
    ui->tabWidget->addTab(home,"Home");
}

void MainWindow::on_calendar_clicked() {

    Calendar* cal = new Calendar();
    ui->tabWidget->addTab(cal, "Calendar");
}

void MainWindow::on_planner_clicked() {

    Planner* plan = new Planner();
    ui->tabWidget->addTab(new Planner(),"Planner");
}

void MainWindow::on_settings_clicked() {

    //тут будет вызов нового окна, в которое по ссылке мы будем передавать главное окно
}



///tabwidget
void MainWindow::on_tabWidget_tabCloseRequested(int index) {

    ui->tabWidget->removeTab(index);
}



///titleBar
void MainWindow::on_close_clicked() {

    this->close();
}

void MainWindow::on_hide_clicked() {

    this->showMinimized();
}

void MainWindow::on_fullscreen_clicked() {

    std::cout << this->isMaximized();
    if (this->isMaximized() == 0)
        this->showMaximized();
    else {
        this->showNormal();
    }

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {

    if (obj == ui->titleBar) {

        QEvent::Type type = event->type();
        if  (type == QEvent::Leave)
            check_obj = nullptr;
        else if (type == QEvent::Enter)
            check_obj = obj;
    }

    return QWidget::eventFilter(obj, event);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton && check_obj == ui->titleBar && !this->isMaximized())
        oldPos = event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {

    if (check_obj == ui->titleBar && !this->isMaximized()) {
        currentPos = event->pos() - oldPos;
        this->move(pos() + currentPos);
    }
}

