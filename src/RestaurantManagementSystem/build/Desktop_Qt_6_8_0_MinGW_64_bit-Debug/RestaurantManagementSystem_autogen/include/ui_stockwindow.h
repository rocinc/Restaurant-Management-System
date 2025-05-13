/********************************************************************************
** Form generated from reading UI file 'stockwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stockwindow
{
public:
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QLineEdit *searchLineEdit;
    QLineEdit *searchLineEdit_2;

    void setupUi(QWidget *stockwindow)
    {
        if (stockwindow->objectName().isEmpty())
            stockwindow->setObjectName("stockwindow");
        stockwindow->resize(1200, 600);
        stockwindow->setMinimumSize(QSize(1200, 600));
        stockwindow->setMaximumSize(QSize(1200, 600));
        pushButton = new QPushButton(stockwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 101, 31));
        tableView = new QTableView(stockwindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 60, 1181, 511));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(14);
        tableView->setFont(font);
        tableView->horizontalHeader()->setDefaultSectionSize(300);
        pushButton_2 = new QPushButton(stockwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1080, 20, 91, 31));
        pushButton_3 = new QPushButton(stockwindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(150, 20, 91, 31));
        pushButton_4 = new QPushButton(stockwindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(280, 20, 91, 31));
        radioButton = new QRadioButton(stockwindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(610, 30, 91, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(stockwindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(880, 30, 91, 16));
        radioButton_3 = new QRadioButton(stockwindow);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(700, 30, 111, 16));
        radioButton_4 = new QRadioButton(stockwindow);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(790, 30, 101, 16));
        radioButton_5 = new QRadioButton(stockwindow);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(980, 30, 111, 16));
        searchLineEdit = new QLineEdit(stockwindow);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(400, 20, 181, 31));
        searchLineEdit_2 = new QLineEdit(stockwindow);
        searchLineEdit_2->setObjectName("searchLineEdit_2");
        searchLineEdit_2->setGeometry(QRect(620, 550, 181, 31));

        retranslateUi(stockwindow);

        QMetaObject::connectSlotsByName(stockwindow);
    } // setupUi

    void retranslateUi(QWidget *stockwindow)
    {
        stockwindow->setWindowTitle(QCoreApplication::translate("stockwindow", "\350\217\234\345\223\201\344\270\216\345\272\223\345\255\230\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("stockwindow", "\346\267\273\345\212\240\350\217\234\345\223\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("stockwindow", "\344\277\235\345\255\230\345\271\266\345\205\263\351\227\255", nullptr));
        pushButton_3->setText(QCoreApplication::translate("stockwindow", "\345\210\240\351\231\244\350\217\234\345\223\201", nullptr));
        pushButton_4->setText(QCoreApplication::translate("stockwindow", "\347\274\226\350\276\221\350\217\234\345\223\201", nullptr));
        radioButton->setText(QCoreApplication::translate("stockwindow", "\351\273\230\350\256\244\346\216\222\345\272\217", nullptr));
        radioButton_2->setText(QCoreApplication::translate("stockwindow", "\346\214\211\345\272\223\345\255\230\345\215\207\345\272\217", nullptr));
        radioButton_3->setText(QCoreApplication::translate("stockwindow", "\346\214\211\345\215\225\344\273\267\345\215\207\345\272\217", nullptr));
        radioButton_4->setText(QCoreApplication::translate("stockwindow", "\346\214\211\345\215\225\344\273\267\351\231\215\345\272\217", nullptr));
        radioButton_5->setText(QCoreApplication::translate("stockwindow", "\346\214\211\345\272\223\345\255\230\351\231\215\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stockwindow: public Ui_stockwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
