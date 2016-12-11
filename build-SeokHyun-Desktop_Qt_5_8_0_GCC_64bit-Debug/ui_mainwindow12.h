/********************************************************************************
** Form generated from reading UI file 'mainwindow12.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW12_H
#define UI_MAINWINDOW12_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow12
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow12)
    {
        if (MainWindow12->objectName().isEmpty())
            MainWindow12->setObjectName(QStringLiteral("MainWindow12"));
        MainWindow12->resize(800, 600);
        centralwidget = new QWidget(MainWindow12);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(490, 500, 113, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 500, 89, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 190, 67, 17));
        MainWindow12->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow12);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow12->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow12);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow12->setStatusBar(statusbar);

        retranslateUi(MainWindow12);

        QMetaObject::connectSlotsByName(MainWindow12);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow12)
    {
        MainWindow12->setWindowTitle(QApplication::translate("MainWindow12", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow12", "\353\241\234\352\267\270\354\235\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow12", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow12: public Ui_MainWindow12 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW12_H
