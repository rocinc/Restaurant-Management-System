#include "orderstatusedit.h"
#include "ui_orderstatusedit.h"
#include <qcombobox.h>
#include <qtimer.h>

orderNode* ordernodeToEdit;

orderstatusedit::orderstatusedit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::orderstatusedit)
    ,timer(new QTimer(this))
{
    ui->setupUi(this);
    //设置列表样式
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

orderstatusedit::~orderstatusedit()
{
    delete ui;
}

//父窗口orderwindow向子窗口orderstatusedit传递订单节点信息，兼具在列表中显示
void orderstatusedit::sendOrderNode(orderNode* n)
{
    ordernodeToEdit=n;

    QStringList headers;headers<<"菜品"<<"状态";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(ordernodeToEdit->val.dishescount);
    ui->tableWidget->setColumnCount(2);
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        QTableWidgetItem *textItem = new QTableWidgetItem(ordernodeToEdit->val.dishes[row].dish.name);
        textItem->setFlags(textItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->setItem(row, 0, textItem);
        QComboBox *comboBox = new QComboBox();
        comboBox->addItem(getTextFromDishStatus(NOT_START_PREPARE));
        comboBox->addItem(getTextFromDishStatus(PREPARING));
        comboBox->addItem(getTextFromDishStatus(PREPARED_TO_DELIVER));
        comboBox->addItem(getTextFromDishStatus(DELIVERED));
        comboBox->setCurrentIndex(ordernodeToEdit->val.dishes[row].dishstatus);//状态数字可以直接当做qCombobox的选择序号，这是因为宏定义菜品状态时的数字是从0依次往后排的
        ui->tableWidget->setCellWidget(row, 1, comboBox);
        ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()*7/10);
        ui->tableWidget->setColumnWidth(1, ui->tableWidget->width()*2/10);
    }
}

void orderstatusedit::on_buttonBox_accepted()
{
    int isTheWholeOrderPrepared=1;
    for(int i=0;i<ordernodeToEdit->val.dishescount;i++)//重新录入该订单的菜品状态
    {
        int newstatus=static_cast<QComboBox*>(ui->tableWidget->cellWidget(i, 1))->currentIndex();
        ordernodeToEdit->val.dishes[i].dishstatus=static_cast<QComboBox*>(ui->tableWidget->cellWidget(i, 1))->currentIndex();
        if(newstatus!=DELIVERED)isTheWholeOrderPrepared=0;
    }
        int hashlen;
        orderNode* orders = getOrderList(&hashlen);
        for(int i=0;i<HASH_LEN;i++)
        {
            orderNode *p=&orders[i];
            if(p->val.isnull){continue;}
            while(p->next!=NULL)
            {
                if(p->val.isnull)
                {
                    p=p->next;
                    continue;
                }
                if(p->val.orderid == ordernodeToEdit->val.orderid)
                {
                    if(isTheWholeOrderPrepared)
                    {
                        p->val.orderstatus=EATING;
                    }else
                    {
                        p->val.orderstatus=WAITING;
                    }
                    timer->stop();
                    emit windowClosed();
                    accept();
                }
                p=p->next;
            }
            if(p->val.isnull)continue;
            if(p->val.orderid == ordernodeToEdit->val.orderid)
            {
                if(isTheWholeOrderPrepared)
                {
                    p->val.orderstatus=EATING;
                }else
                {
                    p->val.orderstatus=WAITING;
                }
                timer->stop();
                emit windowClosed();
                accept();
            }
        }
}

void orderstatusedit::updateTimer(){

}

void orderstatusedit::handleCloseWindow()
{
    this->close();
}

void orderstatusedit::closeEvent(QCloseEvent *event)
{
    timer->stop();
    QDialog::closeEvent(event);
}

void orderstatusedit::startTimer(int interval)
{
    timer->start(interval);
}
