#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"

class MainWindow;


class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    QList<QByteArray> clientToServerDataList;
    QList<QByteArray> serverToClientDataList;
    QList<int> socketDescriptorList;
    QList<QByteArray> notifyDataList;
    QList<QByteArray> exitDescriptList;
    explicit MyServer(QObject *parent = 0);
    void StartServer();
    int client_num;
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);


};

#endif // MYSERVER_H
