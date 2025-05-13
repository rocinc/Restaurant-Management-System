/********************************************************************************
** Form generated from reading UI file 'vipwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIPWINDOW_H
#define UI_VIPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_vipwindow
{
public:
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QTableWidget *vipTypeTable;
    QPushButton *deleteButton;
    QPushButton *addButton;
    QLabel *label_7;
    QPushButton *saveAndExitButton;
    QPushButton *addVipButton;
    QPushButton *editVipButton;
    QPushButton *deleteVipButton;
    QLineEdit *idSearch;
    QLabel *label_2;

    void setupUi(QDialog *vipwindow)
    {
        if (vipwindow->objectName().isEmpty())
            vipwindow->setObjectName("vipwindow");
        vipwindow->resize(1200, 600);
        vipwindow->setMinimumSize(QSize(1200, 600));
        vipwindow->setMaximumSize(QSize(1200, 600));
        tableWidget = new QTableWidget(vipwindow);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 70, 921, 501));
        groupBox = new QGroupBox(vipwindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(960, 70, 221, 501));
        vipTypeTable = new QTableWidget(groupBox);
        vipTypeTable->setObjectName("vipTypeTable");
        vipTypeTable->setGeometry(QRect(20, 30, 181, 401));
        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(90, 450, 31, 18));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        deleteButton->setFont(font);
        addButton = new QPushButton(groupBox);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 450, 31, 18));
        addButton->setFont(font);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 470, 371, 20));
        saveAndExitButton = new QPushButton(vipwindow);
        saveAndExitButton->setObjectName("saveAndExitButton");
        saveAndExitButton->setGeometry(QRect(1080, 20, 101, 31));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        saveAndExitButton->setIcon(icon);
        addVipButton = new QPushButton(vipwindow);
        addVipButton->setObjectName("addVipButton");
        addVipButton->setGeometry(QRect(20, 20, 81, 31));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addVipButton->setIcon(icon1);
        editVipButton = new QPushButton(vipwindow);
        editVipButton->setObjectName("editVipButton");
        editVipButton->setGeometry(QRect(130, 20, 131, 31));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        editVipButton->setIcon(icon2);
        deleteVipButton = new QPushButton(vipwindow);
        deleteVipButton->setObjectName("deleteVipButton");
        deleteVipButton->setGeometry(QRect(290, 20, 101, 31));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove));
        deleteVipButton->setIcon(icon3);
        idSearch = new QLineEdit(vipwindow);
        idSearch->setObjectName("idSearch");
        idSearch->setGeometry(QRect(540, 30, 161, 20));
        label_2 = new QLabel(vipwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 30, 91, 16));

        retranslateUi(vipwindow);

        QMetaObject::connectSlotsByName(vipwindow);
    } // setupUi

    void retranslateUi(QDialog *vipwindow)
    {
        vipwindow->setWindowTitle(QCoreApplication::translate("vipwindow", "\344\274\232\345\221\230\347\256\241\347\220\206", nullptr));
        groupBox->setTitle(QCoreApplication::translate("vipwindow", "\344\274\232\345\221\230\347\261\273\345\236\213\347\256\241\347\220\206", nullptr));
        deleteButton->setText(QCoreApplication::translate("vipwindow", "\357\274\215", nullptr));
        addButton->setText(QCoreApplication::translate("vipwindow", "+", nullptr));
        label_7->setText(QCoreApplication::translate("vipwindow", "\347\202\271\345\207\273\345\212\240\345\217\267\346\226\260\345\273\272\344\274\232\345\221\230\347\261\273\345\236\213\357\274\214\346\210\226\351\200\211\346\213\251\344\270\200\351\241\271\345\220\216\346\214\211\345\207\217\345\217\267\345\210\240\351\231\244", nullptr));
        saveAndExitButton->setText(QCoreApplication::translate("vipwindow", "\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
        addVipButton->setText(QCoreApplication::translate("vipwindow", "\346\226\260\344\274\232\345\221\230", nullptr));
        editVipButton->setText(QCoreApplication::translate("vipwindow", "\347\274\226\350\276\221\351\200\211\344\270\255\347\232\204\344\274\232\345\221\230\344\277\241\346\201\257", nullptr));
        deleteVipButton->setText(QCoreApplication::translate("vipwindow", "\345\210\240\351\231\244\344\274\232\345\221\230", nullptr));
        label_2->setText(QCoreApplication::translate("vipwindow", "\346\214\211\344\274\232\345\221\230\345\215\241\345\217\267\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vipwindow: public Ui_vipwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIPWINDOW_H
