/********************************************************************************
** Form generated from reading UI file 'orderwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERWINDOW_H
#define UI_ORDERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_orderwindow
{
public:
    QPushButton *saveAndClose;
    QPushButton *addButton;
    QPushButton *statusButton;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QRadioButton *displayAll;
    QRadioButton *displayWaiting;
    QRadioButton *displayEating;
    QGroupBox *groupBox_2;
    QComboBox *floorBox;
    QComboBox *areaBox;
    QComboBox *deskBox;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_14;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLCDNumber *seatLeftStatus;
    QLCDNumber *occupiedSeatStatus;
    QLCDNumber *occupiedSeatRateStatus;
    QLCDNumber *orderCountStatus;
    QLCDNumber *eatingOrderCountStatus;
    QLCDNumber *eatingOrderRateStatus;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox_4;
    QPushButton *payButton;
    QPushButton *vipPayButton;
    QLabel *label_3;
    QLineEdit *vipIdEdit;
    QFrame *line;

    void setupUi(QDialog *orderwindow)
    {
        if (orderwindow->objectName().isEmpty())
            orderwindow->setObjectName("orderwindow");
        orderwindow->resize(1200, 600);
        orderwindow->setMinimumSize(QSize(1200, 600));
        orderwindow->setMaximumSize(QSize(1200, 600));
        saveAndClose = new QPushButton(orderwindow);
        saveAndClose->setObjectName("saveAndClose");
        saveAndClose->setGeometry(QRect(1080, 30, 91, 31));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        saveAndClose->setIcon(icon);
        addButton = new QPushButton(orderwindow);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(20, 30, 101, 31));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addButton->setIcon(icon1);
        statusButton = new QPushButton(orderwindow);
        statusButton->setObjectName("statusButton");
        statusButton->setGeometry(QRect(140, 30, 181, 31));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        statusButton->setIcon(icon2);
        tableWidget = new QTableWidget(orderwindow);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 70, 951, 521));
        groupBox = new QGroupBox(orderwindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(360, 20, 351, 41));
        displayAll = new QRadioButton(groupBox);
        displayAll->setObjectName("displayAll");
        displayAll->setGeometry(QRect(20, 20, 72, 16));
        displayAll->setChecked(true);
        displayWaiting = new QRadioButton(groupBox);
        displayWaiting->setObjectName("displayWaiting");
        displayWaiting->setGeometry(QRect(110, 20, 111, 16));
        displayEating = new QRadioButton(groupBox);
        displayEating->setObjectName("displayEating");
        displayEating->setGeometry(QRect(230, 20, 101, 16));
        groupBox_2 = new QGroupBox(orderwindow);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(980, 70, 211, 131));
        floorBox = new QComboBox(groupBox_2);
        floorBox->setObjectName("floorBox");
        floorBox->setGeometry(QRect(50, 20, 111, 22));
        areaBox = new QComboBox(groupBox_2);
        areaBox->setObjectName("areaBox");
        areaBox->setGeometry(QRect(50, 60, 111, 22));
        deskBox = new QComboBox(groupBox_2);
        deskBox->setObjectName("deskBox");
        deskBox->setGeometry(QRect(50, 100, 151, 22));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 60, 51, 16));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 20, 51, 16));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 100, 51, 16));
        groupBox_3 = new QGroupBox(orderwindow);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(980, 220, 211, 241));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 51, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 61, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 90, 61, 20));
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 180, 61, 20));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 150, 61, 20));
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 180, 61, 20));
        label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 210, 61, 20));
        label_10->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        seatLeftStatus = new QLCDNumber(groupBox_3);
        seatLeftStatus->setObjectName("seatLeftStatus");
        seatLeftStatus->setGeometry(QRect(90, 30, 64, 23));
        QFont font;
        font.setPointSize(9);
        seatLeftStatus->setFont(font);
        seatLeftStatus->setSmallDecimalPoint(true);
        occupiedSeatStatus = new QLCDNumber(groupBox_3);
        occupiedSeatStatus->setObjectName("occupiedSeatStatus");
        occupiedSeatStatus->setGeometry(QRect(90, 60, 64, 23));
        occupiedSeatStatus->setFont(font);
        occupiedSeatStatus->setSmallDecimalPoint(true);
        occupiedSeatStatus->setProperty("intValue", QVariant(0));
        occupiedSeatRateStatus = new QLCDNumber(groupBox_3);
        occupiedSeatRateStatus->setObjectName("occupiedSeatRateStatus");
        occupiedSeatRateStatus->setGeometry(QRect(90, 90, 64, 23));
        occupiedSeatRateStatus->setFont(font);
        occupiedSeatRateStatus->setSmallDecimalPoint(true);
        orderCountStatus = new QLCDNumber(groupBox_3);
        orderCountStatus->setObjectName("orderCountStatus");
        orderCountStatus->setGeometry(QRect(90, 150, 64, 23));
        orderCountStatus->setFont(font);
        orderCountStatus->setSmallDecimalPoint(true);
        eatingOrderCountStatus = new QLCDNumber(groupBox_3);
        eatingOrderCountStatus->setObjectName("eatingOrderCountStatus");
        eatingOrderCountStatus->setGeometry(QRect(90, 180, 64, 23));
        eatingOrderCountStatus->setFont(font);
        eatingOrderCountStatus->setSmallDecimalPoint(true);
        eatingOrderRateStatus = new QLCDNumber(groupBox_3);
        eatingOrderRateStatus->setObjectName("eatingOrderRateStatus");
        eatingOrderRateStatus->setGeometry(QRect(90, 210, 64, 23));
        eatingOrderRateStatus->setFont(font);
        eatingOrderRateStatus->setSmallDecimalPoint(true);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(170, 90, 40, 21));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(170, 210, 40, 21));
        groupBox_4 = new QGroupBox(orderwindow);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(980, 470, 211, 121));
        payButton = new QPushButton(groupBox_4);
        payButton->setObjectName("payButton");
        payButton->setGeometry(QRect(20, 20, 171, 31));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSend));
        payButton->setIcon(icon3);
        vipPayButton = new QPushButton(groupBox_4);
        vipPayButton->setObjectName("vipPayButton");
        vipPayButton->setGeometry(QRect(140, 80, 71, 31));
        vipPayButton->setIcon(icon3);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 191, 16));
        vipIdEdit = new QLineEdit(groupBox_4);
        vipIdEdit->setObjectName("vipIdEdit");
        vipIdEdit->setGeometry(QRect(10, 90, 121, 20));
        line = new QFrame(groupBox_4);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 55, 211, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        retranslateUi(orderwindow);

        QMetaObject::connectSlotsByName(orderwindow);
    } // setupUi

    void retranslateUi(QDialog *orderwindow)
    {
        orderwindow->setWindowTitle(QCoreApplication::translate("orderwindow", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
        saveAndClose->setText(QCoreApplication::translate("orderwindow", "\344\277\235\345\255\230\345\271\266\345\205\263\351\227\255", nullptr));
        addButton->setText(QCoreApplication::translate("orderwindow", "\346\226\260\350\256\242\345\215\225", nullptr));
        statusButton->setText(QCoreApplication::translate("orderwindow", "\346\211\200\351\200\211\350\256\242\345\215\225\347\232\204\350\217\234\345\223\201\347\212\266\346\200\201", nullptr));
        groupBox->setTitle(QCoreApplication::translate("orderwindow", "\346\214\211\350\256\242\345\215\225\347\212\266\346\200\201\347\255\233\351\200\211", nullptr));
        displayAll->setText(QCoreApplication::translate("orderwindow", "\345\205\250\351\203\250\346\230\276\347\244\272", nullptr));
        displayWaiting->setText(QCoreApplication::translate("orderwindow", "\345\217\252\346\230\276\347\244\272\346\255\243\345\234\250\345\244\207\351\244\220", nullptr));
        displayEating->setText(QCoreApplication::translate("orderwindow", "\345\217\252\346\230\276\347\244\272\345\267\262\344\270\212\351\275\220", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("orderwindow", "\346\214\211\346\241\214\344\275\215\347\255\233\351\200\211", nullptr));
        label_5->setText(QCoreApplication::translate("orderwindow", "\345\214\272\345\237\237", nullptr));
        label_13->setText(QCoreApplication::translate("orderwindow", "\346\245\274\345\261\202", nullptr));
        label_14->setText(QCoreApplication::translate("orderwindow", "\346\241\214\345\217\267", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("orderwindow", "\345\275\223\345\211\215\347\212\266\346\200\201", nullptr));
        label->setText(QCoreApplication::translate("orderwindow", "\345\217\257\344\276\233\345\272\247\344\275\215", nullptr));
        label_2->setText(QCoreApplication::translate("orderwindow", "\345\275\223\345\211\215\345\267\262\345\215\240\345\272\247\344\275\215", nullptr));
        label_6->setText(QCoreApplication::translate("orderwindow", "\344\270\212\345\272\247\347\216\207", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("orderwindow", "\345\275\223\345\211\215\350\256\242\345\215\225\346\225\260", nullptr));
        label_9->setText(QCoreApplication::translate("orderwindow", "\344\270\212\351\275\220\350\256\242\345\215\225\346\225\260", nullptr));
        label_10->setText(QCoreApplication::translate("orderwindow", "\344\270\212\351\275\220\347\216\207", nullptr));
        label_11->setText(QCoreApplication::translate("orderwindow", "%", nullptr));
        label_12->setText(QCoreApplication::translate("orderwindow", "%", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("orderwindow", "\344\270\272\351\200\211\345\256\232\347\232\204\350\256\242\345\215\225\347\273\223\350\264\246", nullptr));
        payButton->setText(QCoreApplication::translate("orderwindow", "\351\235\236\344\274\232\345\221\230\347\233\264\346\216\245\347\273\223\350\264\246", nullptr));
        vipPayButton->setText(QCoreApplication::translate("orderwindow", "\344\274\232\345\221\230\347\273\223\350\264\246", nullptr));
        label_3->setText(QCoreApplication::translate("orderwindow", "\344\274\232\345\221\230\345\207\255\344\274\232\345\221\230\345\215\241\345\217\267\347\273\223\350\264\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderwindow: public Ui_orderwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERWINDOW_H
