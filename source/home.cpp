#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    columns = this->width() / 300;
    delete ui->label;

    int count = 0;
    int total = 100;
    for(int j=0;j<total/columns+1;j++)
        for(int i=0;i<columns && count < total;i++) {
            NoteFrame* noteframe = new NoteFrame();
            ui->gridLayout->addWidget(noteframe,j,i);
            count++;
        }
}

Home::~Home()
{
    delete ui;
}

void Home::sort_notes(int n)
{
    std::vector<QWidget*> w;
    for(int i = 0;i<ui->gridLayout->count();i++)
        w.push_back(ui->gridLayout->itemAt(i)->widget());

    //создание новой таблицы
    int count = 0;
    int total = 100;
    for(int j=0;j<total/n+1;j++)
        for(int i=0;i<n && count < total;i++) {
            ui->gridLayout->addWidget(w[i+j*n],j,i);
            count++;
        }
}

void Home::resizeEvent(QResizeEvent *event)
{
    int n = event->size().width() / 300;
    if (n > columns || n < columns) {
        columns = n;
        sort_notes(n);
    }
}
