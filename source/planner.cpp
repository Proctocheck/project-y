#include "planner.h"
#include "ui_planner.h"

Planner::Planner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Planner)
{
    ui->setupUi(this);

    columns = this->width() / 300;
    delete ui->label;

    int count = 0;
    int total = 13;
    for(int j=0;j<total/columns+1;j++)
        for(int i=0;i<columns && count < total;i++) {
            NoteFrame* noteframe = new NoteFrame();
            ui->gridLayout->addWidget(noteframe,j,i);
            count++;
        }
}

Planner::~Planner()
{
    delete ui;
}

void Planner::sort_notes(int n)
{
    std::vector<QWidget*> w;
    for(int i = 0;i<ui->gridLayout->count();i++)
        w.push_back(ui->gridLayout->itemAt(i)->widget());

    //создание новой таблицы
    int count = 0;
    int total = 13;
    for(int j=0;j<total/n+1;j++)
        for(int i=0;i<n && count < total;i++) {
            ui->gridLayout->addWidget(w[i+j*n],j,i);
            count++;
        }
}

/*void Planner::sort_notes(int n, QString command)
{
    //удаление из памяти
    while(ui->gridLayout->count() != 0 && command != "start") {
        QLayoutItem* item =  ui->gridLayout->takeAt(0);
        delete item->widget();
        delete item;
    }

    //создание новой таблицы
    int count = 0;
    int total = 13;
    for(int j=0;j<total/n+1;j++)
        for(int i=0;i<n;i++) {
            if (count == total)
                return;
            //            QPushButton* button = new QPushButton();
            //            button->setFixedSize(150,150);
            //            button->setStyleSheet("background-color: rgb(151,241,14);");
            NoteFrame* noteframe = new NoteFrame();
            ui->gridLayout->addWidget(noteframe,j,i);
            count++;
        }
}
*/

void Planner::resizeEvent(QResizeEvent *event)
{
    int n = event->size().width() / 300;
    if (n > columns || n < columns) {
        columns = n;
        sort_notes(n);
    }
}
