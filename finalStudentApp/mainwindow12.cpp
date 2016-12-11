#include "ui_mainwindow12.h"
#include <mainwindow12.h>
#include "mainwindow.h"

MainWindow12::MainWindow12(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow12)
{
    ui->setupUi(this);

    QString img_path = "./deu.jpg";
    QImage img(img_path);
    QPixmap buf = QPixmap::fromImage(img);

    ui->label->setPixmap(buf);
    ui->label->resize(buf.width(), buf.height());
}

MainWindow12::~MainWindow12()
{
    delete ui;
}
void MainWindow12::knowMainwin(MainWindow *mainwindow){

    mw = mainwindow;

}

QString MainWindow12::getNumber(){
    QString temp = ui->lineEdit->text();
    return temp;
}

void MainWindow12::on_pushButton_clicked()
{
    iscloseable = 0;
    if(ui->lineEdit->text() != NULL){
        iscloseable = 1;

        mw->connectToServer();
        this->close();
        //dataclass.flag=1;
    }
}

void MainWindow12::closeEvent(QCloseEvent *Event){
    if(iscloseable==1){
        Event->accept();
    }
    else{
        Event->ignore();
    }
}
