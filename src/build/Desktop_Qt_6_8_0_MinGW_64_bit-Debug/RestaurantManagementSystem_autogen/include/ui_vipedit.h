/********************************************************************************
** Form generated from reading UI file 'vipedit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIPEDIT_H
#define UI_VIPEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_vipedit
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *preferenceBox;
    QLabel *label_6;
    QLineEdit *phoneNumber;
    QCalendarWidget *calenderWidget;
    QLabel *idLabel;
    QLabel *preferTooLong;
    QLabel *label_2;
    QLabel *phoneWrongLabel;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_5;
    QComboBox *typeBox;
    QLabel *label_14;
    QLabel *label;
    QLabel *createTimeLabel;
    QLabel *nameTooLong;
    QLineEdit *nameBox;
    QLabel *label_7;
    QLabel *label_4;

    void setupUi(QDialog *vipedit)
    {
        if (vipedit->objectName().isEmpty())
            vipedit->setObjectName("vipedit");
        vipedit->resize(600, 700);
        vipedit->setMinimumSize(QSize(600, 700));
        vipedit->setMaximumSize(QSize(600, 700));
        buttonBox = new QDialogButtonBox(vipedit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 630, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        preferenceBox = new QPlainTextEdit(vipedit);
        preferenceBox->setObjectName("preferenceBox");
        preferenceBox->setGeometry(QRect(130, 440, 361, 141));
        label_6 = new QLabel(vipedit);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 390, 71, 16));
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        phoneNumber = new QLineEdit(vipedit);
        phoneNumber->setObjectName("phoneNumber");
        phoneNumber->setGeometry(QRect(130, 340, 361, 20));
        calenderWidget = new QCalendarWidget(vipedit);
        calenderWidget->setObjectName("calenderWidget");
        calenderWidget->setGeometry(QRect(130, 150, 361, 171));
        idLabel = new QLabel(vipedit);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(130, 10, 361, 16));
        preferTooLong = new QLabel(vipedit);
        preferTooLong->setObjectName("preferTooLong");
        preferTooLong->setGeometry(QRect(10, 470, 111, 20));
        QFont font;
        font.setBold(true);
        preferTooLong->setFont(font);
        preferTooLong->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(vipedit);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 10, 71, 16));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        phoneWrongLabel = new QLabel(vipedit);
        phoneWrongLabel->setObjectName("phoneWrongLabel");
        phoneWrongLabel->setGeometry(QRect(130, 370, 191, 16));
        phoneWrongLabel->setFont(font);
        label_3 = new QLabel(vipedit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 100, 71, 16));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_12 = new QLabel(vipedit);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(500, 50, 51, 20));
        label_12->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_13 = new QLabel(vipedit);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(500, 340, 51, 20));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_5 = new QLabel(vipedit);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 340, 71, 16));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        typeBox = new QComboBox(vipedit);
        typeBox->setObjectName("typeBox");
        typeBox->setGeometry(QRect(130, 390, 171, 22));
        label_14 = new QLabel(vipedit);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(310, 390, 51, 20));
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label = new QLabel(vipedit);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 71, 16));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        createTimeLabel = new QLabel(vipedit);
        createTimeLabel->setObjectName("createTimeLabel");
        createTimeLabel->setGeometry(QRect(130, 100, 361, 16));
        nameTooLong = new QLabel(vipedit);
        nameTooLong->setObjectName("nameTooLong");
        nameTooLong->setGeometry(QRect(130, 80, 121, 16));
        nameTooLong->setFont(font);
        nameBox = new QLineEdit(vipedit);
        nameBox->setObjectName("nameBox");
        nameBox->setGeometry(QRect(130, 50, 361, 20));
        label_7 = new QLabel(vipedit);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 440, 71, 16));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(vipedit);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 150, 71, 16));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        retranslateUi(vipedit);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, vipedit, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, vipedit, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(vipedit);
    } // setupUi

    void retranslateUi(QDialog *vipedit)
    {
        vipedit->setWindowTitle(QCoreApplication::translate("vipedit", "\346\233\264\346\226\260\344\274\232\345\221\230\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("vipedit", "\344\274\232\345\221\230\347\261\273\345\236\213", nullptr));
        idLabel->setText(QCoreApplication::translate("vipedit", "TextLabel", nullptr));
        preferTooLong->setText(QCoreApplication::translate("vipedit", "<html><head/><body><p><span style=\" color:#ff5500;\">\345\256\242\346\210\267\345\201\217\345\245\275\350\277\207\351\225\277</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("vipedit", "\344\274\232\345\221\230\345\215\241\345\217\267", nullptr));
        phoneWrongLabel->setText(QCoreApplication::translate("vipedit", "<html><head/><body><p><span style=\" color:#ff5500;\">\346\211\213\346\234\272\345\217\267\344\270\215\347\254\246\345\220\210\346\240\274\345\274\217</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("vipedit", "\345\274\200\345\215\241\346\227\266\351\227\264", nullptr));
        label_12->setText(QCoreApplication::translate("vipedit", "\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_13->setText(QCoreApplication::translate("vipedit", "\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("vipedit", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        label_14->setText(QCoreApplication::translate("vipedit", "\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label->setText(QCoreApplication::translate("vipedit", "\345\247\223\345\220\215", nullptr));
        createTimeLabel->setText(QCoreApplication::translate("vipedit", "TextLabel", nullptr));
        nameTooLong->setText(QCoreApplication::translate("vipedit", "<html><head/><body><p><span style=\" color:#ff5500;\">\345\247\223\345\220\215\350\277\207\351\225\277</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("vipedit", "\345\256\242\346\210\267\345\201\217\345\245\275", nullptr));
        label_4->setText(QCoreApplication::translate("vipedit", "\350\277\207\346\234\237\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vipedit: public Ui_vipedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIPEDIT_H
