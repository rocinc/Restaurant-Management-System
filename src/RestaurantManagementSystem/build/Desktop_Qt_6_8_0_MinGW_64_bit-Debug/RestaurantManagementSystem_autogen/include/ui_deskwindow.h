/********************************************************************************
** Form generated from reading UI file 'deskwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKWINDOW_H
#define UI_DESKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_deskwindow
{
public:
    QTreeWidget *treeWidget;
    QPushButton *saveButton;
    QPushButton *deletebutton;
    QPushButton *addbutton;
    QPushButton *addParallelbutton;

    void setupUi(QDialog *deskwindow)
    {
        if (deskwindow->objectName().isEmpty())
            deskwindow->setObjectName("deskwindow");
        deskwindow->resize(800, 600);
        deskwindow->setMinimumSize(QSize(800, 600));
        deskwindow->setMaximumSize(QSize(800, 600));
        treeWidget = new QTreeWidget(deskwindow);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(30, 20, 741, 521));
        saveButton = new QPushButton(deskwindow);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(680, 560, 91, 31));
        QFont font;
        font.setPointSize(11);
        saveButton->setFont(font);
        deletebutton = new QPushButton(deskwindow);
        deletebutton->setObjectName("deletebutton");
        deletebutton->setGeometry(QRect(440, 560, 111, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        deletebutton->setFont(font1);
        addbutton = new QPushButton(deskwindow);
        addbutton->setObjectName("addbutton");
        addbutton->setGeometry(QRect(30, 560, 161, 31));
        addbutton->setFont(font1);
        addParallelbutton = new QPushButton(deskwindow);
        addParallelbutton->setObjectName("addParallelbutton");
        addParallelbutton->setGeometry(QRect(220, 560, 191, 31));
        addParallelbutton->setFont(font1);

        retranslateUi(deskwindow);

        QMetaObject::connectSlotsByName(deskwindow);
    } // setupUi

    void retranslateUi(QDialog *deskwindow)
    {
        deskwindow->setWindowTitle(QCoreApplication::translate("deskwindow", "\346\241\214\344\275\215\347\256\241\347\220\206", nullptr));
        saveButton->setText(QCoreApplication::translate("deskwindow", "\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
        deletebutton->setText(QCoreApplication::translate("deskwindow", "\345\210\240\351\231\244\351\200\211\345\256\232\351\241\271", nullptr));
        addbutton->setText(QCoreApplication::translate("deskwindow", "\346\267\273\345\212\240\351\200\211\345\256\232\351\241\271\347\232\204\345\255\220\351\241\271", nullptr));
        addParallelbutton->setText(QCoreApplication::translate("deskwindow", "\346\267\273\345\212\240\351\200\211\345\256\232\351\241\271\347\232\204\345\271\266\345\210\227\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deskwindow: public Ui_deskwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKWINDOW_H
