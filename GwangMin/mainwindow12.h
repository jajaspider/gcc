#ifndef MAINWINDOW12_H
#define MAINWINDOW12_H

#include <QMainWindow>
#include <dataclass.h>
#include <QCloseEvent>
#include <QKeyEvent>

class dataclass;

namespace Ui {
class MainWindow12;
}

class MainWindow12 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow12(QWidget *parent = 0);
    ~MainWindow12();
    QString getNumber();
    dataclass *dc;
    int iscloseable;
    void closeEvent(QCloseEvent *Event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow12 *ui;
};

#endif // MAINWINDOW12_H
