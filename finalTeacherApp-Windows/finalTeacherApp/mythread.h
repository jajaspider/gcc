#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QMainWindow>

class MyServer;


class MyThread : public QThread
{
    Q_OBJECT
public:
    MyServer *server;

    explicit MyThread(int ID ,QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

private slots:
    void readyRead();
    void disconnect();

public :
    void knowServer(MyServer *serv);

private:
    QTcpSocket *socket;
    int socketDescriptor;
    quint16 nextBlockSize;

};

#endif // MYTHREAD_H
