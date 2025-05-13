/********************************************************************************
** Form generated from reading UI file 'orderadd.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERADD_H
#define UI_ORDERADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_orderadd
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *floorTextBox;
    QComboBox *areaTextBox;
    QComboBox *deskTextBox;
    QLabel *label_6;
    QTableWidget *tableWidget;
    QPushButton *deleteButton;
    QLabel *label_7;
    QPushButton *addButton;
    QLabel *label_8;
    QSpinBox *countpeopleSpinBox;
    QLabel *idlabel;

    void setupUi(QDialog *orderadd)
    {
        if (orderadd->objectName().isEmpty())
            orderadd->setObjectName("orderadd");
        orderadd->resize(600, 700);
        orderadd->setMinimumSize(QSize(600, 700));
        orderadd->setMaximumSize(QSize(600, 700));
        buttonBox = new QDialogButtonBox(orderadd);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 650, 531, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(orderadd);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 121, 16));
        label_2 = new QLabel(orderadd);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 110, 81, 16));
        label_3 = new QLabel(orderadd);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 140, 51, 16));
        label_4 = new QLabel(orderadd);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 190, 51, 16));
        label_5 = new QLabel(orderadd);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(120, 240, 51, 16));
        floorTextBox = new QComboBox(orderadd);
        floorTextBox->setObjectName("floorTextBox");
        floorTextBox->setGeometry(QRect(170, 140, 101, 22));
        areaTextBox = new QComboBox(orderadd);
        areaTextBox->setObjectName("areaTextBox");
        areaTextBox->setGeometry(QRect(170, 190, 101, 22));
        deskTextBox = new QComboBox(orderadd);
        deskTextBox->setObjectName("deskTextBox");
        deskTextBox->setGeometry(QRect(170, 240, 321, 22));
        label_6 = new QLabel(orderadd);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 340, 81, 16));
        tableWidget = new QTableWidget(orderadd);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(80, 340, 401, 251));
        deleteButton = new QPushButton(orderadd);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(120, 610, 31, 18));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        deleteButton->setFont(font);
        label_7 = new QLabel(orderadd);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(180, 610, 371, 20));
        addButton = new QPushButton(orderadd);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(50, 610, 31, 18));
        addButton->setFont(font);
        label_8 = new QLabel(orderadd);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 300, 81, 16));
        countpeopleSpinBox = new QSpinBox(orderadd);
        countpeopleSpinBox->setObjectName("countpeopleSpinBox");
        countpeopleSpinBox->setGeometry(QRect(90, 300, 71, 21));
        countpeopleSpinBox->setMinimum(1);
        idlabel = new QLabel(orderadd);
        idlabel->setObjectName("idlabel");
        idlabel->setGeometry(QRect(170, 50, 381, 16));

        retranslateUi(orderadd);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, orderadd, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, orderadd, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(orderadd);
    } // setupUi

    void retranslateUi(QDialog *orderadd)
    {
        orderadd->setWindowTitle(QCoreApplication::translate("orderadd", "\346\226\260\350\256\242\345\215\225", nullptr));
        label->setText(QCoreApplication::translate("orderadd", "\350\256\242\345\215\225\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("orderadd", "\351\200\211\345\272\247", nullptr));
        label_3->setText(QCoreApplication::translate("orderadd", "\346\245\274\345\261\202", nullptr));
        label_4->setText(QCoreApplication::translate("orderadd", "\345\214\272\345\237\237", nullptr));
        label_5->setText(QCoreApplication::translate("orderadd", "\346\241\214\345\217\267", nullptr));
        label_6->setText(QCoreApplication::translate("orderadd", "\351\200\211\350\217\234", nullptr));
        deleteButton->setText(QCoreApplication::translate("orderadd", "\357\274\215", nullptr));
        label_7->setText(QCoreApplication::translate("orderadd", "\347\202\271\345\207\273\345\212\240\345\217\267\346\210\226\345\207\217\345\217\267\345\242\236\345\207\217\350\217\234\345\223\201\347\247\215\347\261\273", nullptr));
        addButton->setText(QCoreApplication::translate("orderadd", "+", nullptr));
        label_8->setText(QCoreApplication::translate("orderadd", "\344\272\272\346\225\260", nullptr));
        idlabel->setText(QCoreApplication::translate("orderadd", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderadd: public Ui_orderadd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERADD_H
