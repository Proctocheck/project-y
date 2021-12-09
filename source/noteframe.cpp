#include "noteframe.h"
#include "ui_noteframe.h"

NoteFrame::NoteFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteFrame)
{
    ui->setupUi(this);
}

NoteFrame::~NoteFrame()
{
    delete ui;
}

void NoteFrame::on_delete_note_clicked()
{
    delete this;
}

void NoteFrame::on_open_note_clicked()
{
    NoteWindow* note = new NoteWindow();
    //QObject::connect(note, destroyed(), this, destroy_note());
    note->show();
    this->setEnabled(false);
    QObject::connect(note, SIGNAL(note_delete()), this, SLOT(detele_n()));
    QObject::connect(note, SIGNAL(save_note()), this, SLOT(update_note()));
    QObject::connect(note, SIGNAL(close_note()), this, SLOT(close_note()));
}

void NoteFrame::detele_n()
{
    //из базы данных ничего не надо удалять, это всё произойдёт в открытом виджете

    //передмал, тут будем стирать заметку из бд
    QWidget* widget = qobject_cast<QWidget*>(sender());
    delete widget;
    delete this;
}

void NoteFrame::update_note()
{

}

void NoteFrame::close_note()
{
    this->setEnabled(true);
}
