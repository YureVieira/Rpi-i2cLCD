#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T11:27:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_LCD_Writer
TEMPLATE = app


SOURCES += main.cpp\
        form.cpp \
    lcd_i2c.cpp

HEADERS  += form.h \
    lcd_i2c.h

FORMS    += form.ui

INCLUDEPATH += -I/usr/local/include

LIBS += -L/usr/local/lib\
-lwiringPi
