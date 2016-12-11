#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T00:45:26
#
#-------------------------------------------------

QT       += core gui network webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finalTeacherApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    myserver.h \
    mythread.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    finalTeacherApp.pro.user
