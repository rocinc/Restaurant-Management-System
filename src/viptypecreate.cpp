#include "viptypecreate.h"
#include "ui_viptypecreate.h"
#include <qpushbutton.h>
#include <qstatusbar.h>
#include <qtimer.h>
#include "stockdata.h"
#include "vipdata.h"
#include "vipwindow.h"

viptypecreate::viptypecreate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viptypecreate)
    ,timer(new QTimer(this))
{
    ui->setupUi(this);
    //状态栏显示提示
    QStatusBar *statusBar = new QStatusBar(this);
    QLabel *statusLabel = new QLabel("      菜品的折后价是原价×（1-折扣）。                        ", this);
    statusBar->addWidget(statusLabel);

    ui->discountBox->setSingleStep(0.1);
    connect(timer, &QTimer::timeout, this, &viptypecreate::updateTimer);
    ui->nameTooLong->hide();
}

viptypecreate::~viptypecreate()
{
    delete ui;
}

void viptypecreate::startTimer(int interval)
{
    timer->start(interval);
}

void viptypecreate::updateTimer(){
    char *name=QStringToCharArray(ui->nameBox->text());
    if(ui->nameBox->text().isEmpty())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        ui->nameTooLong->hide();
    }
    else if(isOutOfTextLimit(name,MAX_VIPTYPE_NAME_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        ui->nameTooLong->show();
    }else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
        ui->nameTooLong->hide();
    }
}

void viptypecreate::handleCloseWindow()
{
    this->close();
}

void viptypecreate::closeEvent(QCloseEvent *event)
{
    timer->stop();
    QDialog::closeEvent(event);
}

void viptypecreate::on_buttonBox_accepted()
{
    viptype newtype;
    newtype.discount=ui->discountBox->value();
    strcpy(newtype.name,QStringToCharArray(ui->nameBox->text()));

    createNewVipType(newtype);

    timer->stop();
    emit windowClosed();
}

