QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar.cpp \
    compactor.cpp \
    database.cpp \
    home.cpp \
    launchwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    noteframe.cpp \
    notewindow.cpp \
    planner.cpp \
    settings.cpp \
    shell.c \
    sqlite3.c \
    togglebutton.cpp

HEADERS += \
    calendar.h \
    compactor.h \
    database.h \
    headers.h \
    home.h \
    launchwindow.h \
    mainwindow.h \
    noteframe.h \
    notewindow.h \
    planner.h \
    settings.h \
    sqlite3.h \
    sqlite3ext.h \
    togglebutton.h

FORMS += \
    calendar.ui \
    home.ui \
    launchwindow.ui \
    mainwindow.ui \
    noteframe.ui \
    notewindow.ui \
    planner.ui \
    settings.ui

win32-g++ {
    INCLUDEPATH += C:\boost\include\boost-1_66
    INCLUDEPATH += C:\Users\User\Documents\qt projects\sqlite
} else:win32-msvc* {
    INCLUDEPATH += C:\boost\include\boost-1_66
    INCLUDEPATH += C:\Users\User\Documents\qt projects\sqlite
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    ui_source.qrc
