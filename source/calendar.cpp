#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);

    //    QObject::connect(ui->calendarWidget, SIGNAL(clicked(QDate)),
    //                     this, SLOT(check_day()));

    setDate(ui->calendarWidget->selectedDate());
    setMarks();
    checkNotes(ui->calendarWidget->selectedDate());

    //setTheme("dark");

    _note = nullptr;
    _butt = nullptr;
    _layout = nullptr;
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::setTheme(QString theme)
{
    if (theme == "dark") {
        ui->calendarWidget->setStyleSheet("alternate-background-color: rgb(29, 54, 62)");
        ui->scrollArea->setStyleSheet("background-color: rgb(29, 54, 62)");
    }
    if (theme == "light") {
        ui->calendarWidget->setStyleSheet("alternate-background-color: rgb(239, 239, 239);");
        ui->scrollArea->setStyleSheet("background-color: rgb(255, 255, 255)");
    }
}

void Calendar::checkDay(QDate date)
{
    setDate(date);
    checkNotes(date);
}

void Calendar::setDate(QDate time)
{
    ui->Date->setText(time.toString("MMMM yyyy"));
    ui->Date->setStyleSheet("QTextEdit { font-size: 14px; text-align: left; }");

    ui->day->setText(time.toString("d"));
    ui->dayName->setText(QDate::longDayName(time.dayOfWeek()));
    ui->MonthYear->setText(time.toString("MMMM yyyy"));
    //ui->
}

void Calendar::checkNotes(QDate date)
{
    QDate d,d1;
    d.setDate(2021,12,3);
    d1.setDate(2021,12,14);
    //QMessageBox::critical(this, "qwd", "qwdqwd");
    while(ui->scroll_layout->count() > 0) {
        QLayout* layout = ui->scroll_layout->takeAt(0)->layout();
        while(layout->count() > 0) {
            QLayoutItem* item =  layout->takeAt(0);
            delete item->widget();
            delete item;
        }

        delete layout;
    }
    if (d == date) {
        showNotes(0,"кнопка","текст для label", "note");
    }
    if (d1 == date) {
        showNotes(1,"кнопка","fgergerg", "note");
    }
}

void Calendar::setMarks()
{
    //работа с database
    int day = 3, month = 12, year = 2021;

    //тут будет цикл где мы будем бегать по массиву и по очереди грузить кнопочки
    int i = 0;
    while (i<1) {
        if (true) {
            QTextCharFormat format;
            format.setBackground(Qt::yellow);
            //ui->calendarWidget->s
            ui->calendarWidget->setDateTextFormat(QDate(year,month,day), format);
            //showNotes(i,"текст для кнопки","текст для label", "note");
        }
        i++;
    }
}

void Calendar::on_prew_clicked()
{
    QDate time =  ui->calendarWidget->selectedDate();
    (time.month() - 1<1) ? time.setDate(time.year()-1,12,time.day()) : time.setDate(time.year(),time.month()-1,time.day());
    ui->calendarWidget->setSelectedDate(time);
    setDate(time);
}

void Calendar::on_next_clicked()
{
    QDate time =  ui->calendarWidget->selectedDate();
    (time.month() + 1>12) ? time.setDate(time.year()+1,1,time.day()) : time.setDate(time.year(),time.month()+1,time.day());
    ui->calendarWidget->setSelectedDate(time);
    setDate(time);
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    checkDay(date);
}

void Calendar::showNotes(int n, QString buttonText, QString labeltext, QString type)//передаём какой-то массив
{
    //также это тоже нужно сделать в цикле, где из базы данных мы будем брать {название, содержимое, тип}
    QPushButton* change = new QPushButton();//buttonText);
    QLabel* l = new QLabel(labeltext);
    QPushButton* cross = new QPushButton();

    change->setFixedSize(60,60);
    //button->setIcon(QPixmap(":/icons/ui_icons/standart/gotonote.png"));
    change->setIcon(QPixmap(":/icons/ui_icons/standart/cross.png"));
    change->setIconSize(QSize(55,55));

    cross->setFixedSize(60,60);
    cross->setIcon(QPixmap(":/icons/ui_icons/standart/cross.png"));
    cross->setIconSize(QSize(50,50));
    cross->setFlat(true);

    l->setFixedSize(190,60);
    //l->setStyleSheet("background-image: url(:/icons/ui_icons/standart/eventindicator.png);");

    QHBoxLayout* layout = new QHBoxLayout();

    //if (type == "note")
    //    l->setStyleSheet("background: red;");

    layout->addWidget(l);
    layout->addWidget(change);
    layout->addWidget(cross);
    layout->setContentsMargins(0,0,0,0);

    ui->scroll_layout->addLayout(layout,n,0);
    HashNoteCrossLayout.insert(cross,layout);
    HashNoteChangeLayout.insert(change,layout);

    QObject::connect(cross, &QAbstractButton::clicked, this, &Calendar::removeNote);
    QObject::connect(change, &QAbstractButton::clicked, this, &Calendar::changeNote);
    //QObject::connect(button, &QAbstractButton::close, this, &Calendar::showWindowNote); на будущее
    //тут мы будем коннектить кнопку с скакому-то действию(желательно, чтобы у нас в tab_widget высветилось новое окно, но это маловероятно(((()
    //QObject::connect(button, &QAbstractButton::clicked, this, &Calendar::checkDay);
}

void Calendar::removeNote()
{
    QMessageBox* pmbx =
            new QMessageBox("Внимание!",
                            "Вы действительно хотите удалить заметку?",
                            QMessageBox::Information,
                            QMessageBox::Yes,
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::No || n == QMessageBox::Cancel)
    {
        return;
    }


    //нужна реализация удаления из памяти. т.к. все заметки выводятся последовательно, то нужно просто удалять самый верхний элемент
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* layout = HashNoteCrossLayout.value(button);
    if (HashNoteCrossLayout.value(button) == nullptr)
        layout = HashNoteChangeLayout.value(_butt);

    while(layout->count() != 0) {
        QLayoutItem* item =  layout->takeAt(0);
        delete item->widget();
        delete item;
    }

    delete layout;

    if (_note != nullptr) {
        _note->close();
        _note = nullptr;
    }
}

void Calendar::changeNote()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    NoteWindow* note = new NoteWindow();
    _note = note;
    note->show();

    _butt = button;

    QHBoxLayout* layout = HashNoteChangeLayout.value(button);
    _layout = layout;
    _layout->setEnabled(false);

    QObject::connect(note, SIGNAL(save_note()), this, SLOT(updateNote()));
    QObject::connect(note, SIGNAL(close_note()), this, SLOT(closeNote()));
    QObject::connect(note, SIGNAL(note_delete()), this, SLOT(removeNote()));
}

void Calendar::updateNote()
{
    //обновляем инфу по заметке
}

void Calendar::closeNote()
{
    _layout->setEnabled(true);
    _layout = nullptr;
    _note = nullptr;
}
