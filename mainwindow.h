#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtCore>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

    QTcpSocket tcpSocket;   //socket
    quint16 nextBlockSize;
    QTimer *m_pTimer;

private slots:
    void connectToServer();
    void onConnectServer();
    void sendRequest();
    void readMessage();
    void connectionClosedByServer();
    void error();
};

#endif // MAINWINDOW_H
