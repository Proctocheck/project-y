#ifndef CALENDAR_H
#define CALENDAR_H

#include "headers.h"

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

    QWidget create_month(int idx, QString name);

private:
    Ui::Calendar *ui;

///days button
private:
    QWidget create_grid();
    //QPushButton create_button();
};

#endif // CALENDAR_H
