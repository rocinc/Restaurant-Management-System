#include <QDialog>
#include "stockcreate.h"
#include "stockdata.h"
#include "stockwindow.h"
#include "ui_stockcreate.h"
#include <qtimer.h>
#include <QCloseEvent>
#include <QShortcut>

T newT;

stockcreate::stockcreate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stockcreate),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &stockcreate::updateTimer);
    newT.isnull=0;
    newT.tastescount=0;
    //创建一个新的默认口味，放入列表
    QListWidgetItem *item = new QListWidgetItem("默认口味");
    item->setFlags(item->flags() | Qt::ItemIsEditable);//允许新项可被自由编辑
    ui->listWidget->addItem(item);
    newT.tastescount++;
    //Enter快捷键
    QShortcut *shortcut = new QShortcut(QKeySequence("Enter"), this);
    connect(shortcut, &QShortcut::activated, this, &stockcreate::on_buttonBox_accepted);
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

stockcreate::~stockcreate()
{
    delete ui;
}

void stockcreate::startTimer(int interval)
{
    timer->start(interval);
}

void stockcreate::updateTimer(){
    char *name=QStringToCharArray(ui->nameTextbox->toPlainText());
    if(strlen(name)==0)
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
    if(isOutOfTextLimit(name,MAX_NAME_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }
    else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
    char *stockunit=QStringToCharArray(ui->stockunitTextBox->toPlainText());
    if(isOutOfTextLimit(stockunit,MAX_STOCK_MEASURE_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }
    else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
    char *othertip=QStringToCharArray(ui->othertipsTextBox->toPlainText());
    if(isOutOfTextLimit(othertip,MAX_OTHER_TIP_LEN))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
        return;
    }
    else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
}

void stockcreate::handleCloseWindow()
{
    this->close();
}

void stockcreate::on_buttonBox_accepted()
{
    char *name=QStringToCharArray(ui->nameTextbox->toPlainText());
    strcpy(newT.name,name);

    int p=0;
    for(int i=0;i<newT.tastescount;i++)
    {
        char *itemcontent = QStringToCharArray(ui->listWidget->item(i)->text());
        if(isOutOfTextLimit(itemcontent,MAX_TASTE_LEN))
        {
            QMessageBox::information(this,"提示",QString("第 %1 个口味的名称过长。").arg(i+1));
            return;
        }
        strcpy(newT.tastes[p],itemcontent);
        p++;
    }

    char *stockunit=QStringToCharArray(ui->stockunitTextBox->toPlainText());
    strcpy(newT.stockmeasureunit,stockunit);

    char *othertip=QStringToCharArray(ui->othertipsTextBox->toPlainText());
    strcpy(newT.othertip,othertip);
    newT.price=ui->priceBox->value();
    newT.stock=ui->stockBox->value();

    //加入链表并关闭窗口，停止计时以刷新父窗口列表
    int hashlen;
    Node** list=getStockList(&hashlen);
    createnew(*list,newT,random(randommaxrange,1),hashlen);
    timer->stop();
    emit windowClosed();
}


void stockcreate::on_stockcreate_destroyed()
{

}


void stockcreate::on_pushButton_clicked()
{
    if(newT.tastescount>MAX_TASTES_COUNT)
    {
        QMessageBox::information(this,"提示",QString("最多只能包含 %1 种口味。").arg(MAX_TASTES_COUNT));
        return;
    }
    QListWidgetItem *item = new QListWidgetItem("新的口味");
    item->setFlags(item->flags() | Qt::ItemIsEditable);//允许新项可被自由编辑
    ui->listWidget->addItem(item);
    newT.tastescount++;
}


void stockcreate::on_pushButton_2_clicked()
{
    if(newT.tastescount==1)
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
    newT.tastescount--;
}


void stockcreate::on_buttonBox_rejected()
{
    timer->stop();
    reject();
}

void stockcreate::closeEvent(QCloseEvent *event)
{
        timer->stop();
        QDialog::closeEvent(event);
}

void stockcreate::on_pushButton_3_clicked()
{
    close();
}

