#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T00:45:26
#
#-------------------------------------------------
TEMPLATE = app
QT       += core gui network webenginewidgets


QT += webenginewidgets

target.path = $$[QT_INSTALL_EXAMPLES]/webenginewidgets/minimal

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finalTeacherApp

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
INSTALLS += target
