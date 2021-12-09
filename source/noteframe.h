#ifndef NOTEFRAME_H
#define NOTEFRAME_H

#include <QWidget>
#include "notewindow.h"

namespace Ui {
class NoteFrame;
}

class NoteFrame : public QWidget
{
    Q_OBJECT

public:
    explicit NoteFrame(QWidget *parent = nullptr);
    ~NoteFrame() override;

private slots:
    void on_delete_note_clicked();

    void on_open_note_clicked();

private slots:
    void detele_n();

    void update_note();

    void close_note();

private:
    Ui::NoteFrame *ui;
};

#endif // NOTEFRAME_H
