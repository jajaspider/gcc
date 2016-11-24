#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_start_clicked()
{
    //YYYYMMDD
    QDate *date = new QDate();
    QDate startDate = date->currentDate();
    date_string_start = startDate.toString("yyyyMMdd");
    //HHmmss
    QDateTime *datetime = new QDateTime();
    QDateTime startTime = datetime->currentDateTime();
    data_string_start_time = startTime.toString("HHmmss");

    ui->start_time->setText(date_string_start+data_string_start_time);
}

void MainWindow::on_end_clicked()
{
    //YYYYMMDD
    QDate *date = new QDate();
    QDate endDate = date->currentDate();
    QString date_string_end = endDate.toString("yyyyMMdd");
    //HHmmss
    QDateTime *datetime = new QDateTime();
    QDateTime endTime = datetime->currentDateTime();
    QString data_string_end_time = endTime.toString("HHmmss");

    ui->end_time->setText(date_string_end+data_string_end_time);


    int temp = (data_string_end_time).toInt();
    int temp2 = (data_string_start_time).toInt();
    int result = temp-temp2;
    QString qtempstr = QString::number(result);

    ui->used_time->setText(qtempstr);
}
