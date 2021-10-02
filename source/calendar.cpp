#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);

    QObject::connect(ui->calendarWidget, SIGNAL(clicked(QDate)),
                     this, SLOT(check_day()));

    set_date(ui->calendarWidget->selectedDate());

    QTextCharFormat format;
    QBrush brush;
    QImage image;
    image.load("qrc:/icons/ui_icons/standart/eventindicator.png");
    brush.setTextureImage(image);
    format.setBackground(brush);
    ui->calendarWidget->setDateTextFormat(QDate(2021,10,2), format);

    //paintCell(new QPainter(),rect(),ui->calendarWidget->selectedDate());
    //set_icons();

    //сюда нужно подавать кол-во дней текущего месяца и его название
    //create_month(30, "сентябрь");

    //this->setMinimumHeight(618);
    //this->setMinimumWidth(940);
    //delete ui->none;
    butt = nullptr;
}

void Calendar::check_day()
{
    QCalendarWidget* cal =qobject_cast<QCalendarWidget*>(sender());
    QDate date = cal->selectedDate();
    set_date(date);
}

void Calendar::set_date(QDate time)
{
    ui->Date->setText(time.toString("MMMM yyyy"));
    ui->Date->setStyleSheet("QTextEdit { font-size: 14px; text-align: left; }");

    ui->day->setText(time.toString("d"));
    ui->dayName->setText(QDate::longDayName(time.dayOfWeek()));
    ui->MonthYear->setText(time.toString("MMMM yyyy"));
    //ui->
}

void Calendar::show_notes(QDate date)
{

}

Calendar::~Calendar()
{
    delete ui;
}


/*
void Calendar::create_month(int idx, QString name)
{

    for(int i=0;i<6;i++)
        for(int j=0;j<7;j++)
            create_grid(i,j);
}


 * /void Calendar::create_grid(int col, int row) {

//    QGridLayout* layout = ui->DayListGrid;
//    QString buttonText = QString::number(col*7+row+1);
//    QPushButton* button = new QPushButton(buttonText,this);
//    button->setMinimumHeight(80);
//    button->setMinimumWidth(80);
//    button->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
//    button->setText(buttonText);
//    button->setStyleSheet("border: none;");
//    layout->addWidget(button,col,row);

//    QObject::connect(button, &QPushButton::clicked, this, &Calendar::onClickButton);
//}

//void Calendar::onClickButton() {

//    QPushButton* button =qobject_cast<QPushButton*>(sender());
////    delete button;
//    if (butt == nullptr) {

//        button->setStyleSheet("background-color: rgb(0, 255, 0);");
//        butt = button;
//    }
//    else {

//        butt->setStyleSheet("background-color: rgb(255, 255, 255); border: none;");
//        button->setStyleSheet("background-color: rgb(0, 255, 0);");
//        butt = button;
//    }
//}*/

void Calendar::on_prew_clicked()
{
    QDate time =  ui->calendarWidget->selectedDate();
    (time.month() - 1<1) ? time.setDate(time.year()-1,12,time.day()) : time.setDate(time.year(),time.month()-1,time.day());
    ui->calendarWidget->setSelectedDate(time);
    set_date(time);
}

void Calendar::on_next_clicked()
{
    QDate time =  ui->calendarWidget->selectedDate();
    (time.month() + 1>12) ? time.setDate(time.year()+1,1,time.day()) : time.setDate(time.year(),time.month()+1,time.day());
    ui->calendarWidget->setSelectedDate(time);
    set_date(time);
}
