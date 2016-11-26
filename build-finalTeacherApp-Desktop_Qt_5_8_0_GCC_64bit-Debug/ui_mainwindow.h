/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QSpinBox *spinBox;
    QPushButton *sendButton1;
    QSpinBox *spinBox_2;
    QTextEdit *textEdit_2;
    QPushButton *sendButton2;
    QSpinBox *spinBox_3;
    QTextEdit *textEdit_3;
    QPushButton *sendButton3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *reflash;
    QTextEdit *textEdit_4;
    QLineEdit *lineEdit;
    QPushButton *notifyButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(818, 613);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 247, 151, 151));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(50, 400, 48, 27));
        sendButton1 = new QPushButton(centralWidget);
        sendButton1->setObjectName(QStringLiteral("sendButton1"));
        sendButton1->setGeometry(QRect(100, 400, 99, 27));
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(220, 400, 48, 27));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(220, 247, 151, 151));
        sendButton2 = new QPushButton(centralWidget);
        sendButton2->setObjectName(QStringLiteral("sendButton2"));
        sendButton2->setGeometry(QRect(270, 400, 99, 27));
        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(390, 400, 48, 27));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(390, 247, 151, 151));
        sendButton3 = new QPushButton(centralWidget);
        sendButton3->setObjectName(QStringLiteral("sendButton3"));
        sendButton3->setGeometry(QRect(440, 400, 99, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 151, 201));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 30, 151, 201));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(390, 30, 151, 201));
        reflash = new QPushButton(centralWidget);
        reflash->setObjectName(QStringLiteral("reflash"));
        reflash->setGeometry(QRect(650, 520, 99, 27));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(570, 210, 211, 191));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(570, 400, 113, 27));
        notifyButton = new QPushButton(centralWidget);
        notifyButton->setObjectName(QStringLiteral("notifyButton"));
        notifyButton->setGeometry(QRect(680, 400, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 818, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        sendButton1->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        sendButton2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        sendButton3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        reflash->setText(QApplication::translate("MainWindow", "\354\203\210\353\241\234\352\263\240\354\271\250", Q_NULLPTR));
        notifyButton->setText(QApplication::translate("MainWindow", "\352\263\265\354\247\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
