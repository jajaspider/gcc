#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QMainWindow>
#include <QFile>
#include <QDate>

class MyServer;


class MyThread : public QThread
{
    Q_OBJECT
public:
    //서버의 객체
    MyServer *server;

    explicit MyThread(int ID ,QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

private slots:
    void readyRead();
    // 연결  종료시
    void disconnect();

public :
    // 서버의 객체를 참조할수있게 연결하는 함수
    void knowServer(MyServer *serv);
    QFile *file;
    QStringList temp1;
    QString filename;

private:
    QTcpSocket *socket;
    int socketDescriptor;
    quint16 nextBlockSize;

};

#endif // MYTHREAD_H
