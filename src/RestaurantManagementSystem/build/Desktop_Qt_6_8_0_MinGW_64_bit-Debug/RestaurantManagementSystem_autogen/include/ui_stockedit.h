/********************************************************************************
** Form generated from reading UI file 'stockedit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKEDIT_H
#define UI_STOCKEDIT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_stockedit
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *nameTextbox;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *priceBox;
    QLabel *label_3;
    QListWidget *listWidget;
    QLabel *label_4;
    QTextEdit *othertipsTextBox;
    QLabel *label_5;
    QDoubleSpinBox *stockBox;
    QPlainTextEdit *stockunitTextBox;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_7;

    void setupUi(QDialog *stockedit)
    {
        if (stockedit->objectName().isEmpty())
            stockedit->setObjectName("stockedit");
        stockedit->resize(600, 700);
        stockedit->setMinimumSize(QSize(600, 700));
        stockedit->setMaximumSize(QSize(600, 700));
        stockedit->setWindowTitle(QString::fromUtf8("\347\274\226\350\276\221\350\217\234\345\223\201"));
        buttonBox = new QDialogButtonBox(stockedit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 640, 511, 41));
        buttonBox->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        nameTextbox = new QPlainTextEdit(stockedit);
        nameTextbox->setObjectName("nameTextbox");
        nameTextbox->setGeometry(QRect(100, 40, 411, 21));
        label = new QLabel(stockedit);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 40, 12));
        label_2 = new QLabel(stockedit);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 80, 61, 16));
        priceBox = new QDoubleSpinBox(stockedit);
        priceBox->setObjectName("priceBox");
        priceBox->setGeometry(QRect(120, 70, 62, 22));
        priceBox->setMaximum(9999.989999999999782);
        label_3 = new QLabel(stockedit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 110, 40, 12));
        listWidget = new QListWidget(stockedit);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(100, 110, 421, 211));
        label_4 = new QLabel(stockedit);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 430, 40, 12));
        othertipsTextBox = new QTextEdit(stockedit);
        othertipsTextBox->setObjectName("othertipsTextBox");
        othertipsTextBox->setGeometry(QRect(100, 430, 421, 201));
        label_5 = new QLabel(stockedit);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 390, 40, 12));
        stockBox = new QDoubleSpinBox(stockedit);
        stockBox->setObjectName("stockBox");
        stockBox->setGeometry(QRect(100, 380, 62, 22));
        stockBox->setMaximum(99999.990000000005239);
        stockunitTextBox = new QPlainTextEdit(stockedit);
        stockunitTextBox->setObjectName("stockunitTextBox");
        stockunitTextBox->setGeometry(QRect(370, 380, 161, 21));
        label_6 = new QLabel(stockedit);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 370, 81, 41));
        pushButton = new QPushButton(stockedit);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 340, 31, 18));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(stockedit);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 340, 31, 18));
        pushButton_2->setFont(font);
        label_7 = new QLabel(stockedit);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(180, 340, 371, 20));

        retranslateUi(stockedit);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, stockedit, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, stockedit, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(stockedit);
    } // setupUi

    void retranslateUi(QDialog *stockedit)
    {
        label->setText(QCoreApplication::translate("stockedit", "\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("stockedit", "\345\215\225\344\273\267(\345\205\203)", nullptr));
        label_3->setText(QCoreApplication::translate("stockedit", "\345\217\243\345\221\263", nullptr));
        label_4->setText(QCoreApplication::translate("stockedit", "\345\244\207\346\263\250", nullptr));
        label_5->setText(QCoreApplication::translate("stockedit", "\345\272\223\345\255\230", nullptr));
        label_6->setText(QCoreApplication::translate("stockedit", "\345\272\223\345\255\230\350\256\241\351\207\217\345\215\225\344\275\215", nullptr));
        pushButton->setText(QCoreApplication::translate("stockedit", "+", nullptr));
        pushButton_2->setText(QCoreApplication::translate("stockedit", "\357\274\215", nullptr));
        label_7->setText(QCoreApplication::translate("stockedit", "\347\202\271\345\207\273\345\212\240\345\217\267\346\210\226\345\207\217\345\217\267\345\242\236\345\207\217\345\217\243\345\221\263\347\247\215\347\261\273\357\274\214\346\210\226\345\217\214\345\207\273\345\217\243\345\221\263\345\210\227\350\241\250\344\270\255\347\232\204\351\241\271\346\235\245\347\274\226\350\276\221\345\256\203\344\273\254", nullptr));
        (void)stockedit;
    } // retranslateUi

};

namespace Ui {
    class stockedit: public Ui_stockedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKEDIT_H
