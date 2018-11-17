#-------------------------------------------------
#
# Project created by QtCreator 2018-11-17T10:17:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    singleton.cpp \
    WriteInfoToFile.cpp

HEADERS  += mainwindow.h \
    singleton.h \
    commonMsg.h \
    commonType.h \
    WriteInfoToFile.h

FORMS    += mainwindow.ui
