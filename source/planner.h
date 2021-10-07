#ifndef PLANNER_H
#define PLANNER_H

#include <QWidget>
#include <QPushButton>

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
    Ui::Planner *ui;
};

#endif // PLANNER_H
