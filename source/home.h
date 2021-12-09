#ifndef HOME_H
#define HOME_H

//#include "headers.h"
#include "noteframe.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home() override;

private:
    void resizeEvent(QResizeEvent *event) override;

    void sort_notes(int n);

private:
    //DataBase* db = new DataBase();
    int columns;

    std::vector<QLayout> layouts;
    Ui::Home *ui;
};

#endif // HOME_H
