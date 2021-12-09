#include "notewindow.h"
#include "ui_notewindow.h"

NoteWindow::NoteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    ui->titleBar->installEventFilter(this);

    if (ui->mode->currentText() != "event")
        ui->dateTimeEdit->hide();
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::lockMode()
{
    ui->mode->setEnabled(false);
    ui->dateTimeEdit->setEnabled(false);
    ui->delete_2->setEnabled(false);
}

void NoteWindow::on_close_clicked()
{
    QMessageBox* pmbx =
                        new QMessageBox("Внимание!",
                        "Вы уверены что хотите выйти? Все несохранённые данные будут удалены.",
                        QMessageBox::Information,
                        QMessageBox::Yes,
                        QMessageBox::No,
                        QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::No || n == QMessageBox::Cancel)
    {
        return;
    }

    emit close_note();

    this->close();
}

void NoteWindow::on_fullscreen_clicked()
{
    if (this->isMaximized() == 0)
        this->showMaximized();
    else {
        this->showNormal();
    }
}

void NoteWindow::on_hide_clicked()
{
    this->showMinimized();
}

void NoteWindow::on_mode_currentIndexChanged(const QString &arg1)
{
    if (ui->mode->currentText() == "event")
        ui->dateTimeEdit->show();
    else ui->dateTimeEdit->hide();
}

void NoteWindow::on_delete_2_clicked()
{
    //что-то делаем чтобы удалить заметку

    emit note_delete();
}

void NoteWindow::on_save_clicked()
{
    //что-то делаем чтобы сохранить заметку

    emit save_note();
}

bool NoteWindow::eventFilter(QObject *obj, QEvent *event)
{

    if (obj == ui->titleBar) {
        QEvent::Type type = event->type();
        if  (type == QEvent::Leave)
            check_obj = nullptr;
        else if (type == QEvent::Enter)
            check_obj = obj;
    }

    return QWidget::eventFilter(obj, event);
}

void NoteWindow::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton && check_obj == ui->titleBar && !this->isMaximized())
        oldPos = event->pos();
}

void NoteWindow::mouseMoveEvent(QMouseEvent *event)
{

    if (check_obj == ui->titleBar && !this->isMaximized()) {
        currentPos = event->pos() - oldPos;
        this->move(pos() + currentPos);
    }
}

void NoteWindow::on_mode_currentTextChanged(const QString &arg1)
{

}
