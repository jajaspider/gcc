#include "myserver.h"
#include "mythread.h"
#include "myserver.h"
#include "ui_mainwindow.h"

MyThread::MyThread(int ID,QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::knowServer(MyServer *serv)
{
    server =serv;

}

void MyThread::run()
{
    socket =new QTcpSocket();
    qDebug() << "starting thread";
    qDebug() << "접근.descriptor: " << socketDescriptor;
    server->socketDescriptorList.append(socketDescriptor);
    qDebug() << "server sdl:"<< server->socketDescriptorList;

    server->clientToServerDataList.append("default");

    qDebug() << "ifno:"<< server->clientToServerDataList;
    server->serverToClientDataList.append("0");

    qDebug()<<server->socketDescriptorList<<" 소켓번호.";
    int client_number = server->socketDescriptorList.size();
    server->client_num = client_number;
    qDebug()<< "client num : "<< server->client_num;
    
    
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnect()));
    //connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendRequest()));


    qDebug() << socketDescriptor<<"client connected\n";
    exec();
}

void MyThread::readyRead()
{
    //누가보낸.데이터인지.식별한다.
    int index = server->socketDescriptorList.indexOf(socketDescriptor);
    if(index == -1){
        qDebug()<<"index err: has not socketDescriptor";
    }
    else{
        QByteArray Data= socket->readAll();
        server->clientToServerDataList.replace(index, Data);

        QByteArray noti;
        Q_FOREACH (const QByteArray& s, server->notifyDataList) {
            noti +=s+"\n";
        }
         qDebug()<<noti;
        socket->write(server->serverToClientDataList.at(index)+"번 프로세스를 종료하겠습니다.\n"+noti);
        server->serverToClientDataList.replace(index,"0");
    }

}
void MyThread::disconnect()
{
    qDebug() <<socketDescriptor<<" Disconnected";
    socket->deleteLater();



    int index = server->socketDescriptorList.indexOf(socketDescriptor);
    server->socketDescriptorList.removeAt(index);
    server->clientToServerDataList.removeAt(index);
    server->serverToClientDataList.removeAt(index);

    int client_number = server->socketDescriptorList.size();
    server->client_num = client_number;
    qDebug()<< "client num : "<< server->client_num;


    qDebug()<<server->socketDescriptorList<<" 소켓번호.";
    qDebug()<<server->socketDescriptorList<<" ctos";
    qDebug()<<server->serverToClientDataList<<" stoc";
    exit(0);
}
