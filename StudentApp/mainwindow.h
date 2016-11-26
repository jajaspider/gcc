#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDate>
#include <QMessageBox>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QKeyEvent>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_signin_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket tcpSocket;   //socket
    void keyPressEvent(QKeyEvent* evt);
    void closeEvent(QCloseEvent *Event);
};

#endif // MAINWINDOW_H


