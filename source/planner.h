#ifndef PLANNER_H
#define PLANNER_H

#include <QWidget>

namespace Ui {
class Planner;
}

class Planner : public QWidget
{
    Q_OBJECT

public:
    explicit Planner(QWidget *parent = nullptr);
    ~Planner();

private:
    Ui::Planner *ui;
};

#endif // PLANNER_H
