/********************************************************************************
** Form generated from reading UI file 'orderaddtaste.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERADDTASTE_H
#define UI_ORDERADDTASTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_orderaddtaste
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *foodSearch;
    QComboBox *tastesCombobox;
    QSpinBox *countSpinBox;
    QLabel *stockWeightTip;

    void setupUi(QDialog *orderaddtaste)
    {
        if (orderaddtaste->objectName().isEmpty())
            orderaddtaste->setObjectName("orderaddtaste");
        orderaddtaste->resize(400, 233);
        orderaddtaste->setMinimumSize(QSize(400, 233));
        orderaddtaste->setMaximumSize(QSize(400, 233));
        buttonBox = new QDialogButtonBox(orderaddtaste);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 180, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(orderaddtaste);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 40, 12));
        label_2 = new QLabel(orderaddtaste);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 40, 12));
        label_3 = new QLabel(orderaddtaste);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 40, 12));
        foodSearch = new QLineEdit(orderaddtaste);
        foodSearch->setObjectName("foodSearch");
        foodSearch->setGeometry(QRect(60, 50, 311, 31));
        tastesCombobox = new QComboBox(orderaddtaste);
        tastesCombobox->setObjectName("tastesCombobox");
        tastesCombobox->setGeometry(QRect(60, 100, 311, 22));
        countSpinBox = new QSpinBox(orderaddtaste);
        countSpinBox->setObjectName("countSpinBox");
        countSpinBox->setGeometry(QRect(60, 140, 61, 22));
        countSpinBox->setMinimum(1);
        stockWeightTip = new QLabel(orderaddtaste);
        stockWeightTip->setObjectName("stockWeightTip");
        stockWeightTip->setGeometry(QRect(160, 140, 241, 16));

        retranslateUi(orderaddtaste);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, orderaddtaste, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, orderaddtaste, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(orderaddtaste);
    } // setupUi

    void retranslateUi(QDialog *orderaddtaste)
    {
        orderaddtaste->setWindowTitle(QCoreApplication::translate("orderaddtaste", "\350\217\234\345\223\201\350\256\242\350\264\255", nullptr));
        label->setText(QCoreApplication::translate("orderaddtaste", "\350\217\234\345\223\201", nullptr));
        label_2->setText(QCoreApplication::translate("orderaddtaste", "\345\217\243\345\221\263", nullptr));
        label_3->setText(QCoreApplication::translate("orderaddtaste", "\344\273\275\346\225\260", nullptr));
        stockWeightTip->setText(QCoreApplication::translate("orderaddtaste", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderaddtaste: public Ui_orderaddtaste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERADDTASTE_H
