#include "mainwindow.h"
#include <QApplication>
#include <QWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowFlags(Qt::FramelessWindowHint);
    //MainWindow *w = new MainWindow(0, "Student", Qt::WStyle_Customize | Qt::WStyle_NoBorder );
    //a.setStyle(Qt::WStyle_Customize | Qt::WStyle_NoBorder);
    w.showFullScreen();
    return a.exec();
}

