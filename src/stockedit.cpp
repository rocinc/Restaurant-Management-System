#include <QDialog>
#include "stockedit.h"
#include "orderwindow.h"
#include "stockdata.h"
#include "stockwindow.h"
#include "ui_stockedit.h"
#include <qshortcut.h>
#include <qtimer.h>
#include <QCloseEvent>

Node* node=(Node*)malloc(sizeof(Node));
int beginning;

void stockedit::sendNode(Node* n)
{
    node=n;
}

stockedit::stockedit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stockedit),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &stockedit::updateTimer);
    ui->nameTooLong->hide();
    ui->unitTooLong->hide();
    ui->otherTipTooLong->hide();
    ui->nameTwo->hide();
    beginning=1;

    //Enter快捷键
    QShortcut *shortcut = new QShortcut(QKeySequence("Enter"), this);
    connect(shortcut, &QShortcut::activated, this, &stockedit::on_buttonBox_accepted);
    //禁用菜品名、库存计量单位两个QPlainTextEdit中的Enter键
    CustomPlainTextEdit *customEditor1 = new CustomPlainTextEdit(this);
    customEditor1->setGeometry(ui->nameTextbox->geometry());
    customEditor1->setPlainText(ui->nameTextbox->toPlainText());
    delete ui->nameTextbox;
    ui->nameTextbox = customEditor1;
    CustomPlainTextEdit *customEditor2 = new CustomPlainTextEdit(this);
    customEditor2->setGeometry(ui->stockunitTextBox->geometry());
    customEditor2->setPlainText(ui->stockunitTextBox->toPlainText());
    delete ui->stockunitTextBox;
    ui->stockunitTextBox = customEditor2;
}

stockedit::~stockedit()
{
    delete ui;
}

void stockedit::startTimer(int interval)
{
    timer->start(interval);
}

int isUsing;

void stockedit::updateTimer(){

    if(beginning)//将选定的菜品的各种信息展示在各自对应的文本框、列表中
    {
        beginning=0;
        ui->nameTextbox->setPlainText(node->val.name);
        ui->priceBox->setValue(node->val.price);
        ui->stockBox->setValue(node->val.stock);
        ui->stockunitTextBox->setPlainText(node->val.stockmeasureunit);
        ui->othertipsTextBox->setPlainText(node->val.othertip);
        for(int i=0;i<node->val.tastescount;i++)
        {
            QListWidgetItem *item = new QListWidgetItem(node->val.tastes[i]);
            item->setFlags(item->flags() | Qt::ItemIsEditable);//允许新项可被自由编辑
            ui->listWidget->addItem(item);
        }


        //判断该菜品是否正被某个订单所订，如果是则不准编辑菜品名称、价格和口味，只能编辑备注和库存
        orderNode* orderlist = readAllOrder(HASH_LEN,ORDER_FILE_NAME);
        for(int i=0;i<HASH_LEN;i++)
        {
            orderNode *p=&orderlist[i];
            if(p->val.isnull){continue;}
            while(p->next!=NULL)
            {
                if(p->val.isnull)
                {
                    p=p->next;
                    continue;
                }
                //遍历p对应订单的菜品，做出判断
                for(int j=0;j<p->val.dishescount;j++)
                {
                    if(strcmp(p->val.dishes[j].dish.name,node->val.name)==0)
                    {
                        QMessageBox::information(this,"提示",QString("编号为 %1 的订单正在使用该菜品，因此不能更改菜品的名称、价格和口味，但可以更改库存、库存计量单位和备注。").arg(p->val.orderid));
                        ui->nameTextbox->setEnabled(0);
                        ui->priceBox->setEnabled(0);
                        ui->listWidget->setEnabled(0);
                        ui->pushButton->setEnabled(0);
                        ui->pushButton_2->setEnabled(0);
                        isUsing=1;
                        free(orderlist);
                        return;
                    }
                }
                p=p->next;
            }
            if(p->val.isnull)continue;
            //遍历p对应订单的菜品，做出判断
            for(int j=0;j<p->val.dishescount;j++)
            {
                if(strcmp(p->val.dishes[j].dish.name,node->val.name)==0)
                {
                    QMessageBox::information(this,"提示",QString("编号为 %1 的订单正在使用该菜品，因此不能更改菜品的名称、价格和口味，但可以更改库存、库存计量单位和备注。").arg(p->val.orderid));
                    ui->nameTextbox->setEnabled(0);
                    ui->priceBox->setEnabled(0);
                    ui->listWidget->setEnabled(0);
                    ui->pushButton->setEnabled(0);
                    ui->pushButton_2->setEnabled(0);
                    isUsing=1;
                    free(orderlist);
                    return;
                }
            }
        }
        free(orderlist);
    }

    char *name=QStringToCharArray(ui->nameTextbox->toPlainText());
    int nameTwo=0;

    Node* list=readall(HASH_LEN,STOCK_FILE_NAME);
    for(int i=0;i<HASH_LEN;i++)
    {
        if(isUsing)break;
        Node *p=&list[i];
        if(p->val.isnull){continue;}
        while(p->next!=NULL)
        {
            if(p->val.isnull)
            {
                p=p->next;
                continue;
            }
            //遍历到重名菜名时跳出遍历并给予提示
            if(strcmp(p->val.name,name)==0 && strcmp(p->val.name,node->val.name)!=0)
            {
                nameTwo=1;
                goto NEXT;
            }
            p=p->next;
        }
        if(p->val.isnull)continue;
        //遍历到重名菜名时跳出遍历并给予提示
        if(strcmp(p->val.name,name)==0 && strcmp(p->val.name,node->val.name)!=0)
        {
            nameTwo=1;
            goto NEXT;
        }
    }
NEXT:
    free(list);
    if(strlen(name)==0)
    {
        ui->nameTooLong->hide();
        ui->nameTwo->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }else if(nameTwo)
    {
        ui->nameTooLong->hide();
        ui->nameTwo->show();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }
    else
    {
        ui->nameTwo->hide();
        ui->nameTooLong->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
    if(isOutOfTextLimit(name,MAX_NAME_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        ui->nameTooLong->show();
        return;
    }
    else
    {
        ui->nameTooLong->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
    char *stockunit=QStringToCharArray(ui->stockunitTextBox->toPlainText());
    if(isOutOfTextLimit(stockunit,MAX_STOCK_MEASURE_LEN))
    {
        ui->unitTooLong->show();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }
    else
    {
        ui->unitTooLong->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
    char *othertip=QStringToCharArray(ui->othertipsTextBox->toPlainText());
    if(isOutOfTextLimit(othertip,MAX_OTHER_TIP_LEN))
    {
        ui->otherTipTooLong->show();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }
    else
    {
        ui->otherTipTooLong->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
}

void stockedit::handleCloseWindow()
{
    this->close();
}

void stockedit::on_buttonBox_accepted()
{
    node->val.tastescount=ui->listWidget->count();
    for(int i=0;i<ui->listWidget->count();i++)
    {
        char *itemcontent = QStringToCharArray(ui->listWidget->item(i)->text());
        if(isOutOfTextLimit(itemcontent,MAX_TASTE_LEN))
        {
            QMessageBox::information(this,"提示",QString("第 %1 个口味的名称过长。").arg(i+1));
            return;
        }
        strcpy(node->val.tastes[i],itemcontent);
    }

    char *name=QStringToCharArray(ui->nameTextbox->toPlainText());
    strcpy(node->val.name,name);
    char *stockunit=QStringToCharArray(ui->stockunitTextBox->toPlainText());
    strcpy(node->val.stockmeasureunit,stockunit);
    char *othertip=QStringToCharArray(ui->othertipsTextBox->toPlainText());
    strcpy(node->val.othertip,othertip);
    node->val.price=ui->priceBox->value();
    node->val.stock=ui->stockBox->value();
    timer->stop();
    emit windowClosed();
}


void stockedit::on_pushButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem("新的口味");
    item->setFlags(item->flags() | Qt::ItemIsEditable);//允许新项可被自由编辑
    ui->listWidget->addItem(item);
}


void stockedit::on_pushButton_2_clicked()
{
    if(ui->listWidget->count()==1)
    {
        QMessageBox::information(this,"提示","至少要有一种口味。");
        return;
    }
    int CurrentRow = ui->listWidget->currentRow();
    if(CurrentRow!=-1)
    {
        QListWidgetItem *item = ui->listWidget->takeItem(CurrentRow);
        free(item);
    }
    else
    {
        QMessageBox::information(this,"提示","删除口味前没有选中任何口味。");
    }
}


void stockedit::on_buttonBox_rejected()
{
    timer->stop();
    reject();
}

void stockedit::on_stockcreate_destroyed()
{

}

void stockedit::closeEvent(QCloseEvent *event)
{
        timer->stop();
        QDialog::closeEvent(event);
}

void stockedit::on_pushButton_3_clicked()
{
    close();
}

