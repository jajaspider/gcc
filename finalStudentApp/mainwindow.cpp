#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <QByteArray>
#include <QString>
#include <QHostAddress>
#include "dialog.h"
#include <qdebug.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*Dialog dialog(this);
    dialog.exec();*/
//    qDebug() <<dialog.getNumber();
//    while(true){
//        if(dataclass.flag == 1){
//            connectToServer();
//            break;
//        }
//    }
    this->nextBlockSize = 0;
    this->setWindowTitle("Students");
    pListSet();
    //connect signal and slot
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(onConnectServer()));

    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(&tcpSocket, SIGNAL(disconnected()), this, SLOT(connectionClosedByServer()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(sendRequest()));
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(pListSet()));
    m_pTimer->start(1000);
    pListSet();


}


//slots
void MainWindow::sendRequest(){
    QByteArray block;
    block = processData();
    //qDebug()<<block;
    //프로세스.목록을.보내야한다.
    tcpSocket.write(block);
}

void MainWindow::readMessage(){
    QByteArray Data= tcpSocket.readAll();
    qDebug() <<"recv from server1: "<<Data;
    QList<QByteArray>splitData;
    splitData.append(Data.split('//'));
    qDebug()<<"스플릿."<<splitData;
    QByteArray exitnum = splitData.at(0);
    QByteArray quitnum = splitData.at(2);
    qDebug()<<"스플릿."<<splitData;
    if(quitnum=="1") {
        reboot();
    }
    int num = exitnum.toInt();
    qDebug()<< "종료할프로세스 : " << num;
    //프로세스.제거함수에.num을넘겨종료하는.코드를.넣는다.
    processKill(num);
    ui->textEdit->setText(Data);
}


void MainWindow::connectToServer(){
    //서버 연결 요청
    tcpSocket.connectToHost("113.198.235.233", 9989);
    MainWindow12 mw12;
    QString id = mw12.getNumber();

    //YYYYMMDD
    QDate *date = new QDate();
    QDate startDate = date->currentDate();
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


<<<<<<< HEAD
    QByteArray block;
    block.append("log");
    block.append(","+iptemp);
    block.append(","+id);
    block.append(","+startDate.toString("yyyyMMdd")+startTime.toString("HHmmss"));
=======
        QByteArray block;
            block.append("a");
            block.append(","+iptemp);
            block.append(","+id);
            block.append(","+startDate.toString("yyyyMMdd")+startTime.toString("HHmmss"));
>>>>>>> e85348709a94e9020d088eaffca24779fd9d5adf

    tcpSocket.write(block);
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

void MainWindow::reboot()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execl("/sbin/shutdown", "shutdown", "-r", "now", NULL);
        perror("execl fail");
    }
    else if(pid > 0)
    {
        wait((int*)0);
        qDebug("shutdown complete");
    }
    else
    {
        qDebug("fork failed");
    }
}

void MainWindow::processKill(int number)
{
    //구조체에서 데이터를 가져와서 삭제시도해야함
    if(number != 0) {
        pid_t pid;
        pid = fork();
        int kill_num = m_plist.size()-number;
        QString process = processPid(kill_num);
        const char* p_pid = process.toStdString().c_str();
        qDebug() << "process : " << process;
        qDebug() << "p_pid   : " << p_pid;
        if(pid == 0)
        {
            execl("/bin/kill", "kill", "-15", p_pid, NULL);
            perror("execl fail");
        }
        else if(pid > 0)
        {
            wait((int*)0);
            qDebug("kill complete");
        }
        else
        {
            qDebug("fork failed");
        }
    }
}

QString MainWindow::processPid(int number) {
    return m_plist[number].process[0];
}

void MainWindow::pListSet()
{
    //프로세스 리스트를 입력하는 함수, 현재 사용자가 실행한 프로세스만 저장함
    DIR *dir;
    struct dirent *entry = NULL;
    char pfile[40];
    p_info m_process;
    struct stat m_stat;

    uid_t user_id;
    struct passwd *user_pwd;
    user_id = getuid();
    user_pwd = getpwuid(user_id);
    string user_name = user_pwd->pw_name;

    m_plist.clear();

    if( (dir = opendir("/proc")) == NULL )
    {
        perror("dir open error");
        exit(0);
    }

    while( (entry = readdir(dir)) != NULL )
    {
        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, ".") != 0)
        {
            //파일이 . 또는 ..이 아닐 경우에만 실행함
            sprintf(pfile, "/proc/%s/stat", entry->d_name);
            if(access(pfile, F_OK) != 0)
            {
                //파일이 존재하지 않으면 실행함
                continue;
            }

            if(dirIsDigit(entry->d_name))
            {
                struct passwd *pwd;
                stat(pfile, &m_stat);
                m_process.process = processParse(pfile);

                pwd = getpwuid(m_stat.st_uid);

                if( strcmp(user_name.c_str(), pwd->pw_name) == 0 )
                {
                    //프로세스를 실행한 유저 이름이 현재 사용자의 이름과 같은 경우에 실행
                    strncpy(m_process.username, pwd->pw_name, 32);
                    if( atoi(m_process.process[0].toStdString().c_str()) == atoi(entry->d_name) )
                    {
                        m_plist.append(m_process);
                    }
                }
            }
        }
    }
}

vector<QString> MainWindow::processParse(char *pfile)
{
    FILE *file;
    char buf[512] = {0x00, };
    char field[80];
    int index = 0;
    unsigned int i, j = 0;
    vector<QString> proc;

    file = fopen(pfile, "r"); //읽기 전용으로 파일 오픈
    if(file == NULL)
    {
        perror("fopen error");
        exit(0);
    }

    memset(field, 0x00, 80);
    fgets(buf, 511, file);

    for(i=0;i<strlen(buf);i++)
    {
        if( buf[i] != ' ' && i != (strlen(buf)-1) )
        {
            field[j++] = buf[i];
        }
        else
        {
            if(index == 1)
            {
                field[strlen(field)-1] = 0x00;
                proc.push_back(field+1);
            }
            else
            {
                proc.push_back(field);
            }
            memset(field, 0x00, 80);
            j=0;
            index++;
        }
    }
    fclose(file);
    return proc;
}

int MainWindow::dirIsDigit(char *str)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(isdigit(str[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

QByteArray MainWindow::processData()
{
    //프로세스 리스트를 서버에 전송하기 위해 QByteArray형식으로 만드는 함수
    QByteArray array;
    int remove_index = 1;
    array.append("b");
    for(int i=m_plist.size()-1;i>m_plist.size()-21;i--)
    {
        QString s = m_plist[i].process[1];
        array.append("\n"+s);
    }
    array.remove(remove_index,remove_index+1);
    return array;
}
/**
 * @brief MainWindow::on_pushButton_clicked
 * 로그아웃 버튼을 눌렀을때만 프로그램이 종료하도록.
 */
void MainWindow::on_pushButton_clicked()
{
    iscloseable = 1;
    reboot();
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *Event){
    if(iscloseable == 1){
        Event->accept();
    }
    else
        Event->ignore();
}
