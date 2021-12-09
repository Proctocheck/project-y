#include "launchwindow.h"
#include "ui_launchwindow.h"

LaunchWindow::LaunchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LaunchWindow)
{
    ui->setupUi(this);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    c = 0;
    t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(aboba()));
    t->start(15);
}

LaunchWindow::~LaunchWindow()
{
    delete ui;
}

void LaunchWindow::aboba()
{

    ui->progressBar->setValue(c);

    if (c > 100) {

        t->stop();
        MainWindow* window = new MainWindow();
        window->show();
        this->close();
    }
    c++;
}


