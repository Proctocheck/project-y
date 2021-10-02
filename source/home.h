#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPushButton>

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
    Ui::Home *ui;
};

#endif // HOME_H
