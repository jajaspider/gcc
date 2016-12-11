#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new MyServer(this);
    server->StartServer();
    spinboxnum1 = 0;
    spinboxnum2 = 0;
    spinboxnum3 = 0;
    connect(ui->sendButton1, SIGNAL(clicked()), this, SLOT(sendButton1()));
    connect(ui->sendButton2, SIGNAL(clicked()), this, SLOT(sendButton2()));
    connect(ui->sendButton3, SIGNAL(clicked()), this, SLOT(sendButton3()));
    connect(ui->notifyButton, SIGNAL(clicked()), this, SLOT(notify()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pushButton3()));

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(reflash()));
    m_pTimer->start(1000);


}

MainWindow::~MainWindow()
{
    if (m_pTimer->isActive())
        m_pTimer->stop();
    delete ui;
}
void MainWindow::notify()
{
    QString notifyStr = ui->lineEdit->text();
    qDebug()<<notifyStr;
    QByteArray qstr = notifyStr.toUtf8() ;
    qDebug()<<qstr;
    ui->textEdit_4->append(notifyStr);
    server->notifyDataList.append(qstr);
    qDebug()<<server->notifyDataList;
}
void MainWindow::reflash()
{

    int size = server->clientToServerDataList.size() -1;
    qDebug() <<size;
    if(size ==2){
        ui->textEdit->setText(server->clientToServerDataList.at(0));
        ui->textEdit_2->setText(server->clientToServerDataList.at(1));
        ui->textEdit_3->setText(server->clientToServerDataList.at(2));
    }
    else if(size ==1){
        ui->textEdit->setText(server->clientToServerDataList.at(0));
        ui->textEdit_2->setText(server->clientToServerDataList.at(1));
        ui->textEdit_3->setText("disconnect");
    }
    else if(size ==0){
        ui->textEdit->setText(server->clientToServerDataList.at(0));
        ui->textEdit_2->setText("disconnect");
        ui->textEdit_3->setText("disconnect");
    }
    else{
        ui->textEdit->setText("disconnect");
        ui->textEdit_2->setText("disconnect");
        ui->textEdit_3->setText("disconnect");
    }
    qDebug()<<server->serverToClientDataList;
}

void MainWindow::sendButton1()
{
    if(server->client_num >=1){
        spinboxnum1 = ui->spinBox->value();
        ui->spinBox->setValue(0);
        QByteArray num1;
        num1.setNum(spinboxnum1);
        server->serverToClientDataList.replace(0,num1);
    }
}
void MainWindow::sendButton2()
{
    if(server->client_num >=2){
        spinboxnum2 =ui->spinBox_2->value();
        ui->spinBox_2->setValue(0);
        QByteArray num2;
        num2.setNum(spinboxnum2);
        server->serverToClientDataList.replace(1,num2);
    }
}
void MainWindow::sendButton3()
{
    if(server->client_num >=3){
        spinboxnum3 = ui->spinBox_3->value();
        ui->spinBox_3->setValue(0);
        QByteArray num3;
        num3.setNum(spinboxnum3);
        server->serverToClientDataList.replace(2,num3);
    }

}

void MainWindow::pushButton1()
{
    if(server->client_num >=1){
        QByteArray num1 = "1";
        server->exitDescriptList.replace(0,num1);

    }
}

void MainWindow::pushButton2()
{
    if(server->client_num >=2){
        QByteArray num1 = "1";
        server->exitDescriptList.replace(1,num1);
    }
}

void MainWindow::pushButton3()
{
    if(server->client_num >=3){
        QByteArray num1 = "1";
        server->exitDescriptList.replace(2,num1);
    }
}
