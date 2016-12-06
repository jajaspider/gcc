#include "ui_mainwindow12.h"
#include <mainwindow12.h>

MainWindow12::MainWindow12(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow12)
{
    ui->setupUi(this);
}

MainWindow12::~MainWindow12()
{
    delete ui;
}


QString MainWindow12::getNumber(){
    QString temp = ui->lineEdit->text();
    return temp;
}

void MainWindow12::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != NULL){
        this->close();
        //dataclass.flag=1;
    }
}
