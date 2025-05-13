/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *stockbutton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 500);
        MainWindow->setMinimumSize(QSize(600, 500));
        MainWindow->setMaximumSize(QSize(600, 500));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(228, 245, 154);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(320, 50, 281, 401));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(4);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(10, 0, 10, 0);
        pushButton_3 = new QPushButton(gridLayoutWidget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(25);
        pushButton_3->setFont(font);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"color: black;"));

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(0, 100));
        pushButton_6->setFont(font);
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"color: black;"));

        gridLayout_2->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 100));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"color: black;"));

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 50, 281, 401));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(4);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(10, 0, 10, 0);
        stockbutton = new QPushButton(gridLayoutWidget_3);
        stockbutton->setObjectName("stockbutton");
        stockbutton->setMinimumSize(QSize(0, 100));
        stockbutton->setFont(font);
        stockbutton->setAutoFillBackground(false);
        stockbutton->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"color: black;"));

        gridLayout_3->addWidget(stockbutton, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(0, 100));
        pushButton_7->setFont(font);
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"color: black;"));

        gridLayout_3->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 100));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"color: black;"));

        gridLayout_3->addWidget(pushButton_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\244\220\351\245\256\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\226\207\346\234\254", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\226\207\346\234\254", nullptr));
        stockbutton->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\223\201\344\270\216\345\272\223\345\255\230", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\241\214\344\275\215\347\256\241\347\220\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\226\207\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
