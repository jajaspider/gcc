#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    m_pBackgroundImg = new QImage(":/backImg");
    QPixmap pix("/home/matt/Desktop/backImg.png");
    ui->label_bkImg->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setId(const QString &stu_id)
{
    ui->lineEdit_usernum->setText(stu_id);
}

QString MainWindow::stu_id() const
{
    return ui->lineEdit_usernum->text();
}

/*void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
//    painter.drawImage(0,0, *m_pBackgroundImg);
//    painter.drawRect(0,0,64,64);
    painter.end();
}*/

void MainWindow::on_pushButton_clicked()
{
    QString usernumber = ui->lineEdit_usernum->text();
    QString password = ui->lineEdit_password->text();

    if(usernumber == "test" && password == "test")
    {
        QMessageBox::information(this, "Login", "Username and Password is Correct"); //메시지박스는 팝업창을 띄움.
    }
    else
    {
        QMessageBox::warning(this,"Login", "Username and Password is not Correct");
    }
}
