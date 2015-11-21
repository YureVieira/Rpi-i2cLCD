#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T07:19:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_i2c_tst
TEMPLATE = app


SOURCES += main.cpp\
        form.cpp

HEADERS  += form.h

FORMS    += form.ui

INCLUDEPATH += -I/usr/local/include

LIBS += -L/usr/local/lib\
-lwiringPi
