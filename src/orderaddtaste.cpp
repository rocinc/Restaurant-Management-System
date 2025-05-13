#include "orderaddtaste.h"
#include "orderdata.h"
#include "ui_orderaddtaste.h"
#include <qcompleter.h>
#include <qpushbutton.h>
#include <qtimer.h>
#include "stockdata.h"

QStringList wordList;
Node* stocklist;
int stockcount;
int tasteid;
T orderedT;

orderaddtaste::orderaddtaste(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::orderaddtaste)
    ,timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(ui->foodSearch, &QLineEdit::textChanged, this, &orderaddtaste::onFoodSearchTextChanged);
    wordList.clear();
    stocklist=NULL;
    ui->stockWeightTip->clear();
    tasteid=0;
    //将菜品信息导入搜索框
    ui->foodSearch->clear();
    stockcount=getCount();
    stocklist = readall(stockcount,STOCK_FILE_NAME);
    for(int i=0;i<stockcount;i++)
    {
        if(stocklist[i].val.isnull==0)wordList.append(stocklist[i].val.name);
    }
    for(int i=0;i<stockcount;i++)
    {
        if(stocklist[i].val.isnull==0 && stocklist[i].next!=NULL)
        {
            Node *p1=&stocklist[i];
            Node *p2=stocklist[i].next;
            while(1)
            {
                if(p2->next==NULL)
                {
                    if(p1!=&stocklist[i])
                    {
                        if(p1->val.isnull==0)wordList.append(p1->val.name);
                    }
                    if(p2->val.isnull==0)wordList.append(p2->val.name);
                    break;
                }
                Node *tmp=p1;
                p1=p1->next;
                if(tmp!=&stocklist[i])free(tmp);
                p2=p2->next;
            }
        }
    }
    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->foodSearch->setPlaceholderText("键入搜索并点击展开的建议项...");
    ui->foodSearch->setCompleter(completer);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
}

orderaddtaste::~orderaddtaste()
{
    delete ui;
}

void orderaddtaste::onFoodSearchTextChanged()
{
    QString currentText = ui->foodSearch->text();
    int isEnabled = wordList.contains(currentText, Qt::CaseInsensitive);
    if(!isEnabled)
    {
        ui->tastesCombobox->clear();
        ui->tastesCombobox->addItem("先键入搜索菜品名，并点击搜索建议中的菜品");
        ui->stockWeightTip->clear();
    }
    ui->tastesCombobox->setEnabled(isEnabled);
    if(!isEnabled)
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
    }else
    {
        ui->tastesCombobox->clear();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
        //遍历存放菜品的哈希数组，把选择的菜品的全部口味录入tastesCombobox
        for(int i=0;i<HASH_LEN;i++)
        {
            Node *p=&stocklist[i];
            if(p->val.isnull){continue;}
            while(p->next!=NULL)
            {
                if(p->val.isnull)
                {
                    p=p->next;
                    continue;
                }
                if(p->val.isnull==0 && strcmp(p->val.name,QStringToCharArray(currentText))==0)
                {
                    for(int k=0;k<p->val.tastescount;k++)
                    {
                        ui->tastesCombobox->addItem(QString(p->val.tastes[k]));
                        ui->stockWeightTip->setText(QString("提示：该菜品当前库存 %1 %2").arg(p->val.stock).arg(p->val.stockmeasureunit));
                    }
                    orderedT=p->val;
                    goto next;
                }
                p=p->next;
            }
            if(p->val.isnull==0 && strcmp(p->val.name,QStringToCharArray(currentText))==0)
            {
                for(int k=0;k<p->val.tastescount;k++)
                {
                    ui->tastesCombobox->addItem(QString(p->val.tastes[k]));
                    ui->stockWeightTip->setText(QString("提示：该菜品当前库存 %1 %2").arg(p->val.stock).arg(p->val.stockmeasureunit));
                }
                orderedT=p->val;
                goto next;
            }
        }
    next:ui->tastesCombobox->setCurrentIndex(0);
    }
}

void orderaddtaste::startTimer(int interval)
{
    timer->start(interval);
}

void orderaddtaste::updateTimer(){

}

void orderaddtaste::handleCloseWindow()
{
    this->close();
}

void orderaddtaste::on_buttonBox_accepted()
{
    int dishescount;
    pair* dishes = getDishesList(&dishescount);
    pair newpair;
    newpair.dishstatus=NOT_START_PREPARE;
    newpair.count=ui->countSpinBox->value();
    newpair.tasteindex=ui->tastesCombobox->currentIndex();
    newpair.dish=orderedT;
    dishes[dishescount]=newpair;

    timer->stop();
    emit AddWindowClosed();
}

