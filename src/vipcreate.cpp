#include "vipcreate.h"
#include "stockdata.h"
#include "ui_vipcreate.h"
#include "vipdata.h"
#include <qpushbutton.h>
#include <qtimer.h>
#include "vipwindow.h"

vip newvip;
viptype* typelist;

vipcreate::vipcreate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vipcreate)
    ,timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &vipcreate::updateTimer);
    ui->nameTooLong->hide();
    ui->phoneWrongLabel->hide();
    ui->preferTooLong->hide();

    //显示会员类别
    int typelistlen;
    typelist = *getVipTypeList(&typelistlen);
    for(int i=0;i<typelistlen;i++)
    {
        ui->typeBox->addItem(QString("%1  折扣 %2").arg(typelist[i].name).arg(typelist[i].discount));
    }
    ui->typeBox->setCurrentIndex(0);

    //由当前日期得到随机生成的卡号
    //生成的原理结合了时间戳和随机数
    //为了保证生成结果在int范围内，需要把生成结果字符串转换为long long后对INT_MAX取余，再转换为字符串后才能显示在文本框中
    time_t now = time(nullptr);
    char timestamp[15];
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", std::localtime(&now));
    int randomNum = random(MAX_RANDOM_VIP_ID, 0);
    char orderNumberStr[20];
    sprintf(orderNumberStr, "%s%04d", timestamp, randomNum);
    long long orderNumber = atoll(orderNumberStr);
    if (orderNumber > INT_MAX) {
        orderNumber = orderNumber % INT_MAX;
    }
    char resid[20];
    itoa(static_cast<int>(orderNumber),resid,10);
    ui->idLabel->setText(resid);

    //显示和记录会员创建日期
    struct tm *local_time = localtime(&now);
    date currentdate = {local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday};
    ui->createTimeLabel->setText(dateToCharArray(currentdate));
    newvip.create=currentdate;

    //会员过期时间应至少在创建时间的后一天
    QDate currentQdate={currentdate.year,currentdate.month,currentdate.day};
    ui->calenderWidget->setMinimumDate(currentQdate.addDays(1));


}

vipcreate::~vipcreate()
{
    delete ui;
}

void vipcreate::startTimer(int interval)
{
    timer->start(interval);
}

void vipcreate::updateTimer(){
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
    strcpy(newvip.name,name);

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
    newvip.phonenumber=atoi(phone);

    char *prefer= QStringToCharArray(ui->preferenceBox->toPlainText());
    if(isOutOfTextLimit(name,MAX_PREFER_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        ui->preferTooLong->show();
    }else
    {
        ui->preferTooLong->hide();
    }
    strcpy(newvip.preference,prefer);

    if(ui->nameBox->text().isEmpty() || ui->phoneNumber->text().isEmpty())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
    }
}

void vipcreate::handleCloseWindow()
{
    this->close();
}

void vipcreate::closeEvent(QCloseEvent *event)
{
    timer->stop();
    QDialog::closeEvent(event);
}

void vipcreate::on_buttonBox_accepted()
{
    newvip.id=atoi(QStringToCharArray(ui->idLabel->text()));
    QDate outdate=ui->calenderWidget->selectedDate();
    newvip.outdated={outdate.year(),outdate.month(),outdate.day()};
    newvip.type=typelist[ui->typeBox->currentIndex()];
    newvip.paidcount=0;
    newvip.paidsum=0;

    int len;
    vipNode* list = getVipList(&len);

    createnew(list,newvip,newvip.id,len);

    timer->stop();
    emit windowClosed();
}

