#ifndef MAINWINDOW12_H
#define MAINWINDOW12_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>


class MainWindow;

namespace Ui {
class MainWindow12;
}

class MainWindow12 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow *mw;
    void knowMainwin(MainWindow *mainwindow);
    explicit MainWindow12(QWidget *parent = 0);
    ~MainWindow12();
    QString getNumber();
    int iscloseable;
    void closeEvent(QCloseEvent *Event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow12 *ui;
};

#endif // MAINWINDOW12_H
