#ifndef CALENDAR_H
#define CALENDAR_H

//#include "headers.h"
#include "notewindow.h"

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar() override;

    //void setDataBase(DataBase db);

private slots:
    void on_prew_clicked();
    void on_next_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void removeNote();
    void changeNote();

    void updateNote();
    void closeNote();

private:
    void setTheme(QString theme);

    void setDate(QDate);
    void setMarks();

    void checkDay(QDate date);
    void checkNotes(QDate date);

    void showNotes(int n, QString buttonText, QString labeltext, QString type);

    //DataBase* db = new DataBase();
private:
    Ui::Calendar *ui;

    QHash<QPushButton*,QHBoxLayout*> HashNoteCrossLayout;
    QHash<QPushButton*,QHBoxLayout*> HashNoteChangeLayout;
    QPushButton* _butt;
    QHBoxLayout* _layout;
    NoteWindow* _note;
///days button
//private:
    //void on_Click_Button();
    //void create_grid(int col, int row);

};

#endif // CALENDAR_H
