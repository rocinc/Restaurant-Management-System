/********************************************************************************
** Form generated from reading UI file 'vipcreate.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIPCREATE_H
#define UI_VIPCREATE_H

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

class Ui_vipcreate
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QCalendarWidget *calenderWidget;
    QLineEdit *phoneNumber;
    QComboBox *typeBox;
    QPlainTextEdit *preferenceBox;
    QLabel *idLabel;
    QLineEdit *nameBox;
    QLabel *createTimeLabel;
    QLabel *nameTooLong;
    QLabel *phoneWrongLabel;
    QLabel *preferTooLong;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;

    void setupUi(QDialog *vipcreate)
    {
        if (vipcreate->objectName().isEmpty())
            vipcreate->setObjectName("vipcreate");
        vipcreate->resize(600, 700);
        vipcreate->setMinimumSize(QSize(600, 700));
        vipcreate->setMaximumSize(QSize(600, 700));
        buttonBox = new QDialogButtonBox(vipcreate);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(140, 610, 401, 71));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(vipcreate);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 71, 16));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(vipcreate);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 40, 71, 16));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_3 = new QLabel(vipcreate);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 71, 16));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(vipcreate);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 180, 71, 16));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_5 = new QLabel(vipcreate);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 370, 71, 16));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_6 = new QLabel(vipcreate);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 420, 71, 16));
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_7 = new QLabel(vipcreate);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 470, 71, 16));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        calenderWidget = new QCalendarWidget(vipcreate);
        calenderWidget->setObjectName("calenderWidget");
        calenderWidget->setGeometry(QRect(150, 180, 361, 171));
        phoneNumber = new QLineEdit(vipcreate);
        phoneNumber->setObjectName("phoneNumber");
        phoneNumber->setGeometry(QRect(150, 370, 361, 20));
        typeBox = new QComboBox(vipcreate);
        typeBox->setObjectName("typeBox");
        typeBox->setGeometry(QRect(150, 420, 171, 22));
        preferenceBox = new QPlainTextEdit(vipcreate);
        preferenceBox->setObjectName("preferenceBox");
        preferenceBox->setGeometry(QRect(150, 470, 361, 141));
        idLabel = new QLabel(vipcreate);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(150, 40, 361, 16));
        nameBox = new QLineEdit(vipcreate);
        nameBox->setObjectName("nameBox");
        nameBox->setGeometry(QRect(150, 80, 361, 20));
        createTimeLabel = new QLabel(vipcreate);
        createTimeLabel->setObjectName("createTimeLabel");
        createTimeLabel->setGeometry(QRect(150, 130, 361, 16));
        nameTooLong = new QLabel(vipcreate);
        nameTooLong->setObjectName("nameTooLong");
        nameTooLong->setGeometry(QRect(150, 110, 121, 16));
        QFont font;
        font.setBold(true);
        nameTooLong->setFont(font);
        phoneWrongLabel = new QLabel(vipcreate);
        phoneWrongLabel->setObjectName("phoneWrongLabel");
        phoneWrongLabel->setGeometry(QRect(150, 400, 191, 16));
        phoneWrongLabel->setFont(font);
        preferTooLong = new QLabel(vipcreate);
        preferTooLong->setObjectName("preferTooLong");
        preferTooLong->setGeometry(QRect(30, 500, 111, 20));
        preferTooLong->setFont(font);
        preferTooLong->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_12 = new QLabel(vipcreate);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(520, 80, 51, 20));
        label_12->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_13 = new QLabel(vipcreate);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(520, 370, 51, 20));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_14 = new QLabel(vipcreate);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(330, 420, 51, 20));
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        retranslateUi(vipcreate);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, vipcreate, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, vipcreate, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(vipcreate);
    } // setupUi

    void retranslateUi(QDialog *vipcreate)
    {
        vipcreate->setWindowTitle(QCoreApplication::translate("vipcreate", "\346\226\260\344\274\232\345\221\230", nullptr));
        label->setText(QCoreApplication::translate("vipcreate", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("vipcreate", "\344\274\232\345\221\230\345\215\241\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("vipcreate", "\345\274\200\345\215\241\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("vipcreate", "\350\277\207\346\234\237\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("vipcreate", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("vipcreate", "\344\274\232\345\221\230\347\261\273\345\236\213", nullptr));
        label_7->setText(QCoreApplication::translate("vipcreate", "\345\256\242\346\210\267\345\201\217\345\245\275", nullptr));
        idLabel->setText(QCoreApplication::translate("vipcreate", "TextLabel", nullptr));
        createTimeLabel->setText(QCoreApplication::translate("vipcreate", "TextLabel", nullptr));
        nameTooLong->setText(QCoreApplication::translate("vipcreate", "<html><head/><body><p><span style=\" color:#ff5500;\">\345\247\223\345\220\215\350\277\207\351\225\277</span></p></body></html>", nullptr));
        phoneWrongLabel->setText(QCoreApplication::translate("vipcreate", "<html><head/><body><p><span style=\" color:#ff5500;\">\346\211\213\346\234\272\345\217\267\344\270\215\347\254\246\345\220\210\346\240\274\345\274\217</span></p></body></html>", nullptr));
        preferTooLong->setText(QCoreApplication::translate("vipcreate", "<html><head/><body><p><span style=\" color:#ff5500;\">\345\256\242\346\210\267\345\201\217\345\245\275\350\277\207\351\225\277</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("vipcreate", "\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_13->setText(QCoreApplication::translate("vipcreate", "\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_14->setText(QCoreApplication::translate("vipcreate", "\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vipcreate: public Ui_vipcreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIPCREATE_H
