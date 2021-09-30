#include "planner.h"
#include "ui_planner.h"

Planner::Planner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Planner)
{
    ui->setupUi(this);
}

Planner::~Planner()
{
    delete ui;
}
