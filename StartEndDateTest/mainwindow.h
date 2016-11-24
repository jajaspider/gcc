#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_start_clicked();

    void on_end_clicked();

private:
    Ui::MainWindow *ui;
    QString date_string_start;
    QString data_string_start_time;
};

#endif // MAINWINDOW_H
