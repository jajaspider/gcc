#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    client_num = 0;
}

void MyServer::StartServer()
{
    if(!this->listen(QHostAddress::Any,9989))
    {
        qDebug() <<"could not start server";
    }
    else
    {
        qDebug() <<"Listening..";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    //qDebug()<<socketDescriptor<<" Connecting...";
    MyThread *thread = new MyThread(socketDescriptor,this);
    thread->knowServer(this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}
