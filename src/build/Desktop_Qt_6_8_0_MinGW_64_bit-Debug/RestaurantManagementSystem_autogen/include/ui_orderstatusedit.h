/********************************************************************************
** Form generated from reading UI file 'orderstatusedit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSTATUSEDIT_H
#define UI_ORDERSTATUSEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_orderstatusedit
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *orderstatusedit)
    {
        if (orderstatusedit->objectName().isEmpty())
            orderstatusedit->setObjectName("orderstatusedit");
        orderstatusedit->resize(600, 600);
        orderstatusedit->setMinimumSize(QSize(600, 600));
        orderstatusedit->setMaximumSize(QSize(600, 600));
        buttonBox = new QDialogButtonBox(orderstatusedit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 550, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        tableWidget = new QTableWidget(orderstatusedit);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 10, 551, 521));

        retranslateUi(orderstatusedit);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, orderstatusedit, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, orderstatusedit, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(orderstatusedit);
    } // setupUi

    void retranslateUi(QDialog *orderstatusedit)
    {
        orderstatusedit->setWindowTitle(QCoreApplication::translate("orderstatusedit", "\350\217\234\345\223\201\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderstatusedit: public Ui_orderstatusedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSTATUSEDIT_H
