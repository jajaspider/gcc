#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //this->setWindowFlags(QT::WStyle_NoBorder);
    //this->setWindowFlags(Qt::WStyle_Customize);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signin_clicked()
{
    QString id;
    id=ui->id_Input->text();

    //    QMessageBox msgBox;
    //    msgBox.setText(id);
    //    msgBox.warning(this,id,id);
    tcpSocket.connectToHost(QHostAddress::LocalHost, 9989);
    //YYYYMMDD
    QDate *date = new QDate();
    QDate startDate = date->currentDate();
    startDate.toString("yyyyMMdd");
    //HHmmss
    QDateTime *datetime = new QDateTime();
    QDateTime startTime = datetime->currentDateTime();

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString iptemp;
    for(int nIter=0; nIter<list.count(); nIter++)

    {
        if(!list[nIter].isLoopback())
            if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol )
                iptemp = list[nIter].toString();
    }

    QByteArray block;
    block.append("log");
    block.append(","+iptemp);
    block.append(","+id);
    block.append(","+startDate.toString("yyyyMMdd")+startTime.toString("HHmmss"));

    tcpSocket.write(block);
}

void MainWindow::keyPressEvent(QKeyEvent* evt){
    if((evt->key()==Qt::Key_F4)&&evt->key()==Qt::Key_Alt){
        QMessageBox msgBox;
        msgBox.setText("done");
        msgBox.warning(this,"done","done");
    }
}

void MainWindow::closeEvent(QCloseEvent *Event){
    //Event->ignore();

}
