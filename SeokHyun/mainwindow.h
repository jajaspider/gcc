#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <dirent.h>
#include <string>
#include <QList>
#include <QString>
#include <QByteArray>
#include <QMainWindow>
#include <QTcpSocket>
#include <QtCore>
#include <dataclass.h>
#include <QApplication>
#include <QPixmap>
#include <QDesktopWidget>
#include <QImageWriter>
#include <QScreen>

using namespace std;

typedef struct process_info
{
    char username[32];
    vector<QString> process;
} p_info;

typedef QList<p_info> plist;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

    QTcpSocket tcpSocket;   //socket
    quint16 nextBlockSize;
    QTimer *m_pTimer;

    plist m_plist;

private slots:
    void connectToServer();
    void onConnectServer();
    void sendRequest();
    void readMessage();
    void connectionClosedByServer();
    void error();

    void shutdown(); //시스템 종료시키는 함수
    void processKill(int number); //지정된 위치의 프로세스를 kill하는 함수
    void pListSet(); //프로세스 리스트를 갱신하는 함수

    vector<QString> processParse(char *pfile); //stat파일을 공백문자 단위로 잘라 vector에 저장하는 함수
    int dirIsDigit(char *); //디렉터리가 숫자인지 아닌지를 구분하는 함수
    QByteArray processData(); //데이터를 전송하기 위해 QByteArray로 만들어주는 함수
    QString processPid(int number); //프로세스 kill을 위해서 프로세스 리스트에서 Pid를 가져오는 함수
    void on_screen_clicked();
};

#endif // MAINWINDOW_H
