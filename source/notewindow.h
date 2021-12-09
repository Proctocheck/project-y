#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include "headers.h"

namespace Ui {
class NoteWindow;
}

class NoteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = nullptr);
    ~NoteWindow() override;

    void lockMode();
private slots:
    void on_close_clicked();

    void on_fullscreen_clicked();

    void on_hide_clicked();

    void on_mode_currentIndexChanged(const QString &arg1);

    void on_delete_2_clicked();

    void on_save_clicked();

    void on_mode_currentTextChanged(const QString &arg1);

signals:
    void note_delete();

    void save_note();

    void close_note();

private:
    Ui::NoteWindow *ui;

    QWidget* currWidg = nullptr;

    QPoint oldPos;
    QPoint currentPos;
    QObject *check_obj;

protected:
    bool eventFilter(QObject *, QEvent *event) override;//, QMouseEvent* m_event);

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // NOTEWINDOW_H
