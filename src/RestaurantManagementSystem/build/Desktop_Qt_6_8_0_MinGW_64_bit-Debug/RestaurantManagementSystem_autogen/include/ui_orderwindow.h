/********************************************************************************
** Form generated from reading UI file 'orderwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERWINDOW_H
#define UI_ORDERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_orderwindow
{
public:
    QPushButton *saveAndClose;
    QPushButton *addButton;
    QPushButton *seeButton;
    QTableView *tableView;
    QPushButton *deleteButton;
    QPushButton *payButton;
    QPushButton *historyButton;

    void setupUi(QDialog *orderwindow)
    {
        if (orderwindow->objectName().isEmpty())
            orderwindow->setObjectName("orderwindow");
        orderwindow->resize(1200, 600);
        orderwindow->setMinimumSize(QSize(1200, 600));
        orderwindow->setMaximumSize(QSize(1200, 600));
        saveAndClose = new QPushButton(orderwindow);
        saveAndClose->setObjectName("saveAndClose");
        saveAndClose->setGeometry(QRect(1080, 20, 91, 31));
        addButton = new QPushButton(orderwindow);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 20, 101, 31));
        seeButton = new QPushButton(orderwindow);
        seeButton->setObjectName("seeButton");
        seeButton->setGeometry(QRect(140, 20, 111, 31));
        tableView = new QTableView(orderwindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 60, 1181, 511));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(14);
        tableView->setFont(font);
        tableView->horizontalHeader()->setDefaultSectionSize(300);
        deleteButton = new QPushButton(orderwindow);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(390, 20, 91, 31));
        payButton = new QPushButton(orderwindow);
        payButton->setObjectName("payButton");
        payButton->setGeometry(QRect(270, 20, 101, 31));
        historyButton = new QPushButton(orderwindow);
        historyButton->setObjectName("historyButton");
        historyButton->setGeometry(QRect(500, 20, 111, 31));

        retranslateUi(orderwindow);

        QMetaObject::connectSlotsByName(orderwindow);
    } // setupUi

    void retranslateUi(QDialog *orderwindow)
    {
        orderwindow->setWindowTitle(QCoreApplication::translate("orderwindow", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
        saveAndClose->setText(QCoreApplication::translate("orderwindow", "\344\277\235\345\255\230\345\271\266\345\205\263\351\227\255", nullptr));
        addButton->setText(QCoreApplication::translate("orderwindow", "\346\226\260\350\256\242\345\215\225", nullptr));
        seeButton->setText(QCoreApplication::translate("orderwindow", "\346\237\245\347\234\213\346\211\200\351\200\211\350\256\242\345\215\225\347\212\266\346\200\201", nullptr));
        deleteButton->setText(QCoreApplication::translate("orderwindow", "\345\217\226\346\266\210\350\256\242\345\215\225", nullptr));
        payButton->setText(QCoreApplication::translate("orderwindow", "\344\270\272\346\211\200\351\200\211\350\256\242\345\215\225\347\273\223\350\264\246", nullptr));
        historyButton->setText(QCoreApplication::translate("orderwindow", "\345\216\206\345\217\262\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderwindow: public Ui_orderwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERWINDOW_H
