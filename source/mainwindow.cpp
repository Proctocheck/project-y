#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);


    ui->titleBar->installEventFilter(this);
    ui->moveFrame->installEventFilter(this);

    QSizeGrip* sg = new QSizeGrip(ui->moveFrame);
    sg->setStyleSheet("border-radius: 10px;");
    ui->moveFrameLayout->addWidget(sg);

    home = new Home();
    replaceWidget(home);
    ui->NotesWidget_->addWidget(home);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::changeTheme(QString theme)
{
    if (theme == "dark"){
        ui->sideFrame->setStyleSheet("background-color: rgb(29, 54, 62);");
        ui->titleBar->setStyleSheet("background-color: rgb(29, 54, 62);");
        ui->widgetFrame->setStyleSheet(dark_bg);
        ui->frame->setStyleSheet("background-color: rgb(29, 54, 62);");
        ui->centralwidget->setStyleSheet(dark_text);
    }
    if (theme == "light"){
        ui->sideFrame->setStyleSheet("background-color: rgb(0, 132, 140);");
        ui->titleBar->setStyleSheet("background-color: rgb(0, 132, 140);");
        ui->widgetFrame->setStyleSheet(light_bg);
        ui->frame->setStyleSheet("background-color: rgb(0, 132, 140);");
        ui->centralwidget->setStyleSheet(light_text);
    }
    //    ui->create->setFixedSize(60,60);
    //    ui->create->setIcon(QPixmap(":/icons/ui_icons/"+theme+"/home.png"));
    //    ui->create->setIconSize(QSize(55,55));
}

void MainWindow::on_exit_clicked()
{

    this->close();
}

void MainWindow::replaceWidget(QWidget* w)
{
    if (currWidg != nullptr)
        delete currWidg;
    currWidg = w;
}

///side frame
void MainWindow::on_home_clicked()
{
    //    replaceWidget(home);
    //    home->show();
    Home* home = new Home();
    replaceWidget(home);
    ui->NotesWidget_->addWidget(home);
}

void MainWindow::on_calendar_clicked()
{
    //    replaceWidget(calendar);
    //    calendar->show();
    Calendar* cal = new Calendar();
    replaceWidget(cal);
    ui->NotesWidget_->addWidget(cal);
}

void MainWindow::on_planner_clicked()
{
    //    replaceWidget(planner);
    //  planner->show();
    Planner* plan = new Planner();
    replaceWidget(plan);
    ui->NotesWidget_->addWidget(plan);
}

void MainWindow::on_settings_clicked()
{
    Settings* set = new Settings();
    QObject::connect(set, &Settings::changeTheme,
                     this, &MainWindow::changeTheme);
    replaceWidget(set);
    ui->NotesWidget_->addWidget(set);
}

///titleBar
void MainWindow::on_close_clicked()
{

    this->close();
}

void MainWindow::on_hide_clicked()
{

    this->showMinimized();
}

void MainWindow::on_fullscreen_clicked()
{

    std::cout << this->isMaximized();
    if (this->isMaximized() == 0)
        this->showMaximized();
    else {
        this->showNormal();
    }

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    if (obj == ui->titleBar) {
        QEvent::Type type = event->type();
        if  (type == QEvent::Leave)
            check_obj = nullptr;
        else if (type == QEvent::Enter)
            check_obj = obj;
    }

    if (obj == ui->moveFrame) {
        QEvent::Type type = event->type();
        if  (type == QEvent::Leave)
            check_obj = nullptr;
        else if (type == QEvent::Enter)
            check_obj = obj;
    }

    return QWidget::eventFilter(obj, event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton && check_obj == ui->titleBar && !this->isMaximized())
        oldPos = event->pos();
    if (event->button() == Qt::LeftButton && check_obj == ui->moveFrame && !this->isMaximized()) {

    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    if (check_obj == ui->titleBar && !this->isMaximized()) {
        currentPos = event->pos() - oldPos;
        this->move(pos() + currentPos);
    }
}


void MainWindow::on_create_clicked()
{
    NoteWindow* note = new NoteWindow();
    //QObject::connect(note, destroyed(), this, destroy_note());
    note->lockMode();
    note->show();
    QObject::connect(note, SIGNAL(save_note()), this, SLOT(createNote()));
    QObject::connect(note, SIGNAL(close_note()), this, SLOT(closeNote()));
    ui->centralwidget->setEnabled(false);
}

void MainWindow::createNote()
{

}

void MainWindow::closeNote()
{
    ui->centralwidget->setEnabled(true);
}
