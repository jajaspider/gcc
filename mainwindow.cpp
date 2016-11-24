#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->nextBlockSize = 0;
    this->setWindowTitle("Students");
    //connect signal and slot
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(onConnectServer()));

    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(&tcpSocket, SIGNAL(disconnected()), this, SLOT(connectionClosedByServer()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(sendRequest()));
    m_pTimer->start(1000);

}

//slots
void MainWindow::sendRequest(){
    QByteArray block;
    block = "s/kakao";
    //프로세스.목록을.보내야한다.
    tcpSocket.write(block);
}

void MainWindow::readMessage(){
    QByteArray Data= tcpSocket.readAll();
    //qDebug() <<"recv from server1: "<<Data;
    //QList<QByteArray>splitData;
    //splitData.append(Data.split('//'));
    //QByteArray exitnum = splitData.at(1);
    //qDebug()<<"스플릿."<<splitData;

    int num = Data.toInt();
    qDebug()<< num;
    //프로세스.제거함수에.num을넘겨종료하는.코드를.넣는다.
    ui->textEdit->setText(Data);

}


void MainWindow::connectToServer(){
    //서버 연결 요청
    tcpSocket.connectToHost(QHostAddress::LocalHost, 9989);
}

void MainWindow::onConnectServer(){
    ui->textEdit->setText(tr("교사용 컴퓨터와 정상접속 되었습니다."));
}

void MainWindow::connectionClosedByServer(){
    tcpSocket.close();
}

void MainWindow::error(){
    ui->textEdit->setText(tcpSocket.errorString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

