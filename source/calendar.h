#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QPainter>
#include <QTextCharFormat>
#include <QCalendarWidget>
#include <database.h>

struct Days {

    QString Sunday = "su";
    QString Monday = "mn";
    QString Tuesday = "tu";
    QString Wensday = "we";
    QString Thursday = "th";
    QString Friday = "fr";
    QString Saturday = "st";
};

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar() override;

    void create_month(int idx, QString name);

private slots:
    void on_prew_clicked();
    void on_next_clicked();

    void check_day();

private:
    void set_date(QDate);
    void set_marks();
    //void set_icons();
    void show_notes(QDate);
    Ui::Calendar *ui;

///days button
private:
    QPushButton* butt;
    void onClickButton();
    void create_grid(int col, int row);

protected:
};

#endif // CALENDAR_H
