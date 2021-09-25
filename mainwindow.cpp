#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_show_side_frame_clicked() {


    QPropertyAnimation* anim = new QPropertyAnimation(ui->side_frame, "geometry");
    QPropertyAnimation* banim = new QPropertyAnimation(ui->show_side_frame, "geometry");

    QRect begin_f = ui->side_frame->geometry();
    QRect end_f;
    QRect begin_b = ui->show_side_frame->geometry();
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


void MainWindow::on_exit_clicked()
{
    this->close();
}

