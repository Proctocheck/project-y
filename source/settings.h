#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "togglebutton.h"
#include <QDebug>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
signals:
    void changeTheme(QString theme);
private slots:
    void getToggleSignal(bool toggle);
private:
    Ui::Settings *ui;

    QLabel* label;
    toggleButton* tb;
};

#endif // SETTINGS_H
