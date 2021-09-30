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


/*void MainWindow::on_show_side_frame_clicked() {


    QPropertyAnimation* anim = new QPropertyAnimation(ui->side_frame, "geometry");
    //QPropertyAnimation* banim = new QPropertyAnimation(ui->show_side_frame, "geometry");

    QRect begin_f = ui->side_frame->geometry();
    QRect end_f;
    //QRect begin_b = ui->show_side_frame->geometry();
    QRect end_b;

    if (ui->side_frame->geometry() != QRect(0,0,270,621)) {

        end_f = QRect(0,0,270,621);
        end_b = QRect(10,10,60,50);
    }
    else {

        end_f = QRect(-190,0,270,621);
        end_b = QRect(200,10,60,50);
    }

    anim->setDuration(100);
    anim->setStartValue(begin_f);
    anim->setEndValue(end_f);

//    banim->setDuration(100);
//    banim->setStartValue(begin_b);
//    banim->setEndValue(end_b);

    anim->start();
    //banim->start();

}
*/

void MainWindow::on_exit_clicked() {

    this->close();
}

void MainWindow::removeWidget() {

    QPushButton* b = qobject_cast<QPushButton*>(sender());
    delete b;
}



///side frame
void MainWindow::on_home_clicked() {

    ui->tabWidget->addTab(new Home(),"Home");
}

void MainWindow::on_calendar_clicked() {

    Calendar* cal = new Calendar();
    ui->tabWidget->addTab(cal, "Calendar");
}

void MainWindow::on_planner_clicked() {

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
            check_obj = NULL;
        else if (type == QEvent::Enter)
            check_obj = obj;
    }
    /*
 *        //        if (type == QEvent::MouseButtonPress) {

        //            QMouseEvent *m_event;
        //            if (m_event->button() == Qt::LeftButton)
        //                oldPos = m_event->pos();

        //        }
        //        if (type == QEvent::MouseMove) {

        //            QMouseEvent *m_event;
        //            this->move(this->pos() + m_event->globalPos() - oldPos);
        //        }
//        if (type == QEvent::MouseButtonPress)
//            if (m_event->button() == Qt::LeftButton)
//                oldPos = m_event->pos();
//        if (type == QEvent::MouseMove) {

//            QPoint delta = m_event->pos() - oldPos;
//            move(pos() + delta);
//        }*/

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

