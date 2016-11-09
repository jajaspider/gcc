#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setId(const QString &stu_id);
     QString stu_id() const;

private slots:
     void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
//    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
