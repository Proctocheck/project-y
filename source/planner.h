#ifndef PLANNER_H
#define PLANNER_H

//#include "headers.h"
#include "noteframe.h"

namespace Ui {
class Planner;
}

class Planner : public QWidget
{
    Q_OBJECT

public:
    explicit Planner(QWidget *parent = nullptr);
    ~Planner() override;

private:
    void resizeEvent(QResizeEvent *event) override;

    void sort_notes(int n);

private:
    int columns;
    //DataBase* db = new DataBase();

    Ui::Planner *ui;
};

#endif // PLANNER_H
