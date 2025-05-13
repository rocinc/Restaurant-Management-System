/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName("test");
        test->resize(400, 300);
        buttonBox = new QDialogButtonBox(test);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(test);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, test, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, test, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QDialog *test)
    {
        test->setWindowTitle(QCoreApplication::translate("test", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
