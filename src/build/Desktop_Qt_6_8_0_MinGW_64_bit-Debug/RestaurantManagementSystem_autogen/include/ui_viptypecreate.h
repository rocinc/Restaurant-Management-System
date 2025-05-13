/********************************************************************************
** Form generated from reading UI file 'viptypecreate.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIPTYPECREATE_H
#define UI_VIPTYPECREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_viptypecreate
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *nameBox;
    QLabel *label_3;
    QLabel *label;
    QDoubleSpinBox *discountBox;
    QLabel *nameTooLong;

    void setupUi(QDialog *viptypecreate)
    {
        if (viptypecreate->objectName().isEmpty())
            viptypecreate->setObjectName("viptypecreate");
        viptypecreate->resize(400, 233);
        viptypecreate->setMinimumSize(QSize(400, 233));
        viptypecreate->setMaximumSize(QSize(400, 233));
        buttonBox = new QDialogButtonBox(viptypecreate);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 180, 351, 61));
        buttonBox->setMinimumSize(QSize(0, 0));
        buttonBox->setMaximumSize(QSize(400, 233));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        nameBox = new QLineEdit(viptypecreate);
        nameBox->setObjectName("nameBox");
        nameBox->setGeometry(QRect(110, 40, 241, 31));
        label_3 = new QLabel(viptypecreate);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 130, 61, 20));
        label = new QLabel(viptypecreate);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 61, 16));
        discountBox = new QDoubleSpinBox(viptypecreate);
        discountBox->setObjectName("discountBox");
        discountBox->setGeometry(QRect(110, 130, 62, 22));
        discountBox->setMaximum(0.990000000000000);
        nameTooLong = new QLabel(viptypecreate);
        nameTooLong->setObjectName("nameTooLong");
        nameTooLong->setGeometry(QRect(110, 90, 261, 16));

        retranslateUi(viptypecreate);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, viptypecreate, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, viptypecreate, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(viptypecreate);
    } // setupUi

    void retranslateUi(QDialog *viptypecreate)
    {
        viptypecreate->setWindowTitle(QCoreApplication::translate("viptypecreate", "\346\267\273\345\212\240\344\274\232\345\221\230\347\261\273\345\236\213", nullptr));
        label_3->setText(QCoreApplication::translate("viptypecreate", "\346\212\230\346\211\243\346\257\224\344\276\213", nullptr));
        label->setText(QCoreApplication::translate("viptypecreate", "\347\261\273\345\236\213\345\220\215\347\247\260", nullptr));
        nameTooLong->setText(QCoreApplication::translate("viptypecreate", "<html><head/><body><p><span style=\" font-weight:700; color:#ff5500;\">\344\274\232\345\221\230\347\261\273\345\236\213\345\220\215\347\247\260\350\277\207\351\225\277</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viptypecreate: public Ui_viptypecreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIPTYPECREATE_H
