#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);

    //сюда нужно подавать кол-во дней текущего месяца и его название
    //create_month(30, "сентябрь");


}

Calendar::~Calendar()
{
    delete ui;
}

QWidget Calendar::create_grid() {


}

//QPushButton Calendar::create_button() {

//    QPushButton* button = new QPushButton();
//}

QWidget Calendar::create_month(int idx, QString name) {


}
