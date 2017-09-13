QT       += core  gui  xml
#-------------------------------------------------
#
# Project created by QtCreator 2017-09-04T16:36:12
#
#-------------------------------------------------

QT       += core gui
QT      +=   uitools
QT     +=    sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myWindows
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    mywidget.cpp \
    counter.cpp \
    readxml.cpp \
    testuiloader.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    mywidget.h \
    counter.h \
    readxml.h \
    testuiloader.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    mywidget.ui \
    counter.ui \
    readxml.ui \
    testuiloader.ui

RESOURCES += \
    myicon.qrc
