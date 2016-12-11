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
    //qDebug() << "starting thread";
    //qDebug() << "접근.descriptor: " << socketDescriptor;
    server->socketDescriptorList.append(socketDescriptor);
    //qDebug() << "server sdl:"<< server->socketDescriptorList;
    server->clientToServerDataList.append("default");
    //qDebug() << "ifno:"<< server->clientToServerDataList;
    server->serverToClientDataList.append("0");
    server->exitDescriptList.append("0");
    //qDebug()<<server->socketDescriptorList<<" 소켓번호.";
    int client_number = server->socketDescriptorList.size();
    server->client_num = client_number;
    //qDebug()<< "client num : "<< server->client_num;
    
    
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnect()));
    //connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendRequest()));


    //qDebug() << socketDescriptor<<"client connected\n";
    exec();
}

void MyThread::readyRead()
{
    //누가보낸.데이터인지.식별한다.
    int index = server->socketDescriptorList.indexOf(socketDescriptor);
    if(index == -1){
        //qDebug()<<"index err: has not socketDescriptor";
    }
    else{

        QByteArray Data= socket->readAll();

        if( Data[0]=='a'){

            //QByteArray Data= socket->readAll();
            QString temp;
            temp = Data;
            temp1 = temp.split(",");
            qDebug() << temp1[0] << temp1[1] <<" log!";

            file = new QFile;
            filename = temp1[2]+".txt";
            file->setFileName(filename);
            file->open(QIODevice::ReadWrite|QIODevice::Append);
            QByteArray logdata;
            logdata.append(temp1[1]);
            logdata.append(","+temp1[2]);
            logdata.append(","+temp1[3]);
            file->write(logdata);
            file->close();
        }
        else if(Data[0] == 'c'){
            server->clientToServerDataList.replace(index, Data);


            QByteArray noti;
            Q_FOREACH (const QByteArray& s, server->notifyDataList) {
                noti +=s+"\n";
            }
            // qDebug()<<noti;
            socket->write(server->serverToClientDataList.at(index)+"//"+server->exitDescriptList.at(index)+"//번 프로세스를 종료하겠습니다.\n"+noti);
            server->serverToClientDataList.replace(index,"0");
        }
    }

}

/*
void MyThread::readyRead()
{
    //누가보낸.데이터인지.식별한다.
    int index = server->socketDescriptorList.indexOf(socketDescriptor);
    if(index == -1){
        //qDebug()<<"index err: has not socketDescriptor";
    }
    else{

        QByteArray Data= socket->readAll();
        QString temp;
        temp = Data;
        temp1 = temp.split(",");
        qDebug() << temp1[0] << temp1[1] <<" log!";

        if(temp1[0]=="log"){
            file = new QFile;
            filename = temp1[2]+".txt";
            file->setFileName(filename);
            file->open(QIODevice::ReadWrite|QIODevice::Append);
            QByteArray logdata;
            logdata.append(temp1[1]);
            logdata.append(","+temp1[2]);
            logdata.append(","+temp1[3]);
            file->write(logdata);
            file->close();
        }
        else{
            server->clientToServerDataList.replace(index, Data);


            QByteArray noti;
            Q_FOREACH (const QByteArray& s, server->notifyDataList) {
                noti +=s+"\n";
            }
            // qDebug()<<noti;
            socket->write(server->serverToClientDataList.at(index)+"//"+server->exitDescriptList.at(index)+"//번 프로세스를 종료하겠습니다.\n"+noti);
            server->serverToClientDataList.replace(index,"0");
        }
    }

}
*/
void MyThread::disconnect()
{
    //sanghwa,kwangmin edit start
    file->open(QIODevice::ReadWrite|QIODevice::Append);
    QByteArray logenddata;
    //YYYYMMDD
    QDate *date = new QDate();
    QDate endDate = date->currentDate();
    //HHmmss
    QDateTime *datetime = new QDateTime();
    QDateTime endTime = datetime->currentDateTime();
    logenddata.append(","+endDate.toString("yyyyMMdd")+endTime.toString("HHmmss")+"\n");

    file->write(logenddata);
    file->close();
    //sanghwa,kwangmin edit end

    //qDebug() <<socketDescriptor<<" Disconnected";
    socket->deleteLater();

    int index = server->socketDescriptorList.indexOf(socketDescriptor);
    server->socketDescriptorList.removeAt(index);
    server->clientToServerDataList.removeAt(index);
    server->serverToClientDataList.removeAt(index);

    server->exitDescriptList.removeAt(index);

    int client_number = server->socketDescriptorList.size();
    server->client_num = client_number;

    //qDebug()<< "client num : "<< server->client_num;
    //qDebug()<<server->socketDescriptorList<<" 소켓번호.";
    //qDebug()<<server->socketDescriptorList<<" ctos";
    //qDebug()<<server->serverToClientDataList<<" stoc";
    //qDebug()<<server->exitDescriptList<<"exitnum";
    exit(0);
}
