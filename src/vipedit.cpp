#include "vipedit.h"
#include "stockdata.h"
#include "ui_vipedit.h"
#include "vipdata.h"
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qtimer.h>

viptype* VipTypelist;
date currentdate;
int vipEditBeginning;
vipNode* vipnode;
int typelistlen;

vipedit::vipedit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vipedit)
    ,timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &vipedit::updateTimer);
    ui->nameTooLong->hide();
    ui->phoneWrongLabel->hide();
    ui->preferTooLong->hide();
    vipEditBeginning=1;
    vipnode=new vipNode();

    //显示会员类别
    VipTypelist = *getVipTypeList(&typelistlen);
    if(typelistlen==0)
    {
        QMessageBox::information(this,"提示","需要在会员管理主页添加至少一种会员类型。");
        return;
    }
    for(int i=0;i<typelistlen;i++)
    {
        ui->typeBox->addItem(QString("%1  折扣 %2").arg(VipTypelist[i].name).arg(VipTypelist[i].discount));
    }

    //会员过期时间应至少在创建时间的后一天
    time_t now = time(nullptr);
    struct tm *local_time = localtime(&now);
    QDate currentQdate={local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday};
    ui->calenderWidget->setMinimumDate(currentQdate.addDays(1));
}

vipedit::~vipedit()
{
    delete ui;
}

void vipedit::startTimer(int interval)
{
    timer->start(interval);
}

void vipedit::sendnode(vipNode* node)
{
    vipnode=node;
}

void vipedit::updateTimer(){
    if(vipEditBeginning)
    {
        vipEditBeginning=0;
        ui->idLabel->setText(QString("%1").arg(vipnode->val.id));
        ui->createTimeLabel->setText(QString("%1").arg(dateToCharArray(vipnode->val.create)));
        ui->calenderWidget->setSelectedDate({vipnode->val.outdated.year,vipnode->val.outdated.month,vipnode->val.outdated.day});
        ui->nameBox->setText(vipnode->val.name);
        ui->preferenceBox->setPlainText(vipnode->val.preference);
        ui->phoneNumber->setText(QString("%1").arg(vipnode->val.phonenumber));
        for(int i=0;i<typelistlen;i++)
        {
            if(strcmp(vipnode->val.type.name,VipTypelist[i].name)==0)
            {
                ui->typeBox->setCurrentIndex(i);
                break;
            }
        }
    }

    char *name= QStringToCharArray(ui->nameBox->text());
    if( isOutOfTextLimit(name,MAX_VIP_NAME_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        ui->nameTooLong->show();
    }else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
        ui->nameTooLong->hide();
    }

    char *phone = QStringToCharArray(ui->phoneNumber->text());
    int isPhoneError=0;
    for(int i=0;i<strlen(phone);i++)
    {
        if(strlen(phone)>11 || (phone[i]<'0' || phone[i]>'9'))
        {
            ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
            ui->phoneWrongLabel->show();
            isPhoneError=1;
            break;
        }
    }
    if(!isPhoneError)
    {
        ui->phoneWrongLabel->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }

    char *prefer= QStringToCharArray(ui->preferenceBox->toPlainText());
    if(isOutOfTextLimit(name,MAX_PREFER_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        ui->preferTooLong->show();
    }else
    {
        ui->preferTooLong->hide();
    }

    if(ui->nameBox->text().isEmpty() || ui->phoneNumber->text().isEmpty())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
    }
}

void vipedit::handleCloseWindow()
{
    this->close();
}

void vipedit::closeEvent(QCloseEvent *event)
{
    timer->stop();
    QDialog::closeEvent(event);
}

void vipedit::on_buttonBox_accepted()
{
    vipnode->val.id=ui->idLabel->text().toInt();
    vipnode->val.outdated={ui->calenderWidget->selectedDate().year(),ui->calenderWidget->selectedDate().month(),ui->calenderWidget->selectedDate().day()};
    strcpy(vipnode->val.name,QStringToCharArray(ui->nameBox->text()));
    vipnode->val.phonenumber=ui->phoneNumber->text().toInt();
    vipnode->val.type=VipTypelist[ui->typeBox->currentIndex()];
    strcpy(vipnode->val.preference,QStringToCharArray(ui->preferenceBox->toPlainText()));


    timer->stop();
    emit windowClosed();
}

