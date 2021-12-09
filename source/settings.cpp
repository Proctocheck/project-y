#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    toggleButton* tb = new toggleButton();
    tb->setFixedSize(60,20);
    QObject::connect(tb,&toggleButton::switchChanged,
                     this,&Settings::getToggleSignal);
    ui->gridLayout->addWidget(tb,0,0);
    label = new QLabel();
    ui->gridLayout->addWidget(label,0,1);
    label->setText("light");
}

Settings::~Settings()
{
    delete ui;
}

void Settings::getToggleSignal(bool toggle)
{
    if (toggle) {
        label->setText("dark");
        emit changeTheme("dark");
    }
    else {
        label->setText("light");
        emit changeTheme("light");
    }
}
