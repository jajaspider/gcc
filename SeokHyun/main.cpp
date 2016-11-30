#include <QApplication>
#include "mainwindow.h"
#include "mainwindow12.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow12 w12;
w.show();
    w12.setWindowFlags(Qt::FramelessWindowHint);
        //MainWindow *w = new MainWindow(0, "Student", Qt::WStyle_Customize | Qt::WStyle_NoBorder );
        //a.setStyle(Qt::WStyle_Customize | Qt::WStyle_NoBorder);
        w12.showFullScreen();


    return a.exec();
}
