#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "myserver.h"
#include <QtCore>
#include <QWebEngineView>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    MyServer * server;
    Ui::MainWindow *ui;
    QTimer *m_pTimer;
    int spinboxnum1;
    int spinboxnum2;
    int spinboxnum3;

private slots:

    void sendButton1();
    void sendButton2();
    void sendButton3();
    void notify();
    void reflash();
    void pushButton1();
    void pushButton2();
    void pushButton3();
};

#endif // MAINWINDOW_H

