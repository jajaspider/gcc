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
    //클리이언트가 서버에게 보내는 데이터 리스트
    QList<QByteArray> clientToServerDataList;
    // 서버가 클라이언트에게 보내는 데이터 리스트
    QList<QByteArray> serverToClientDataList;
    // 접속중인 클라이언트 고유번호 리스트
    QList<int> socketDescriptorList;
    // 공지 데이터 리스트
    QList<QByteArray> notifyDataList;
   // 종료 메시지 보관 리스트
    QList<QByteArray> exitDescriptList;
    explicit MyServer(QObject *parent = 0);
    void StartServer();
    int client_num;
signals:

public slots:

protected:
    //소켓에 연결을 시도할때 동작됨
    void incomingConnection(qintptr socketDescriptor);


};

#endif // MYSERVER_H
