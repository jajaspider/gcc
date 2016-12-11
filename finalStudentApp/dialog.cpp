#include "dialog.h"

#include "ui_dialog.h"
#include <QtWidgets>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowState(this->windowState()|Qt::WindowMaximized);
    this->showMaximized();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != NULL)
        this->close();
}

QString Dialog::getNumber(){
    QString temp = ui->lineEdit->text();
    return temp;
}
