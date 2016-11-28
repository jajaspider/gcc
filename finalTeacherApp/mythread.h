#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QDate>

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
    //sanghwa,kwangmin edit start
    QFile *file;
    QStringList temp1;
    QString filename;
    //sanghwa,kwangmin edit end
};

#endif // MYTHREAD_H
