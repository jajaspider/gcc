#include <QApplication>
#include "mainwindow.h"
#include "mainwindow12.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow12 w12;
w.show();
//    w12.setWindowFlags(Qt::FramelessWindowHint);
       w12.setWindowFlags(Qt::WindowStaysOnTopHint);    //항상 상위에 잡아놓기 때문에 alt+tab키를 입력하여도 다른창이 안보임.
        //MainWindow *w = new MainWindow(0, "Student", Qt::WStyle_Customize | Qt::WStyle_NoBorder );
        //a.setStyle(Qt::WStyle_Customize | Qt::WStyle_NoBorder);
        w12.showFullScreen();


    return a.exec();
}
