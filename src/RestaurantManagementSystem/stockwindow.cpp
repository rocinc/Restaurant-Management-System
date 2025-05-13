#include "stockwindow.h"
#include "stockcreate.h"
#include "stockedit.h"
#include "ui_stockwindow.h"
#include "stockdata.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QAbstractTableModel>
#include <QList>
#include "mainwindow.h"
#include "QTimer"
#include <QCompleter>
#include <QStringListModel>
//#include <qstatusbar.h>
#include <QStatusBar>
#include <qboxlayout.h>
#include <qlabel.h>

/**
typedef struct T
{
    int isnull;
    char name[MAX_NAME_LEN];
    double price;
    int tastescount;
    char tastes[MAX_TASTES_COUNT][MAX_TASTE_LEN];
    char othertip[MAX_OTHER_TIP_LEN];
    double stock;
    char stockmeasureunit[8];
}T;
**/

#define FILE_NAME "stockdata.bat"

Node* list;

int listmodellen;
listmodel* modellist;

//点击搜索文本框中的建议项
void stockwindow::clicking(const QString &text)
{
    for(int i=0;i<listmodellen;i++)
    {
        if(modellist[i].currentnode->val.isnull==0 && strcmp(modellist[i].currentnode->val.name,QStringToCharArray(text))==0)
        {
            QMessageBox box;
            box.setWindowTitle(QString("%1 的菜品信息").arg(modellist[i].currentnode->val.name));
            QString content=QString("名称：%1\n单价：%2 元\n库存：%3 %4\n口味：\n").arg(modellist[i].currentnode->val.name).arg(modellist[i].currentnode->val.price).arg(modellist[i].currentnode->val.stock).arg(modellist[i].currentnode->val.stockmeasureunit);
            for(int j=0;j<modellist[i].currentnode->val.tastescount;j++)
            {
                content.append(QString("%1\n").arg(modellist[i].currentnode->val.tastes[j]));
            }
            content.append(QString("备注：").arg(modellist->currentnode->val.othertip));
            box.setText(content);
            QPushButton *b1=box.addButton("编辑",QMessageBox::ActionRole);
            QPushButton *b2=box.addButton("关闭",QMessageBox::ActionRole);
            QPushButton *b3=box.addButton("删除",QMessageBox::ActionRole);
            box.exec();
            if(box.clickedButton() == b1)//打开编辑窗口
            {
                stockedit *stockEdit = new stockedit(this);
                stockEdit->sendNode(modellist[i].currentnode);
                connect(stockEdit, &::stockedit::windowClosed, this, &stockwindow::testf);
                stockEdit->show();
                stockEdit->startTimer();
            }
            else if(box.clickedButton()==b3)//删除
            {
                QMessageBox issure;
                issure.setInformativeText(QString("是否确认删除 %1 ？").arg(modellist[i].currentnode->val.name));
                issure.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                issure.setDefaultButton(QMessageBox::Yes);
                if(issure.exec()==QMessageBox::Yes)
                {
                    modellist[i].currentnode->val.isnull=1;
                    testf();
                }
            }
            break;
        }
    }
}

//将哈希数组中各链表节点录入列表中显示
void stockwindow::freshlist()
{
    if(modellist!=NULL)free(modellist);
    QTableView *tableView = ui->tableView;
    tableView->close();
    listmodellen=0;
    model->clear();
    model = new QStandardItemModel(0,4);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("菜品名称"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("单价/元"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("库存"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("备注"));
    for(int i=0;i<HASH_LEN;i++)
    {
        Node *p=&list[i];
        if(p->val.isnull){continue;}
        while(p->next!=NULL)
        {
            if(p->val.isnull)
            {
                p=p->next;
                continue;
            }
            //遍历到每个有效的链表节点时显示在列表中
            QList<QStandardItem *>* item=new QList<QStandardItem *>();
            item->append(new QStandardItem(p->val.name));
            item->append(new QStandardItem(QString("%1").arg(p->val.price)));
            item->append(new QStandardItem(QString("%1 %2").arg(p->val.stock).arg(p->val.stockmeasureunit)));
            item->append(new QStandardItem(QString("%1").arg(p->val.othertip)));
            for(int i=0;i<4;i++)item->at(i)->setFlags(item->at(i)->flags() & ~Qt::ItemIsEditable);
            model->appendRow(*item);
            listmodellen++;
            if(listmodellen!=1)modellist=(listmodel*)realloc(modellist,sizeof(listmodel)*listmodellen);
            else modellist=(listmodel*)malloc(sizeof(listmodel)*listmodellen);
            listmodel newmodel;
            newmodel.currentnode=p;
            newmodel.row=item;
            modellist[listmodellen-1]=newmodel;
            p=p->next;
        }
        if(p->val.isnull)continue;
        //遍历到每个有效的链表节点时显示在列表中
        QList<QStandardItem *>* item=new QList<QStandardItem *>();
        item->append(new QStandardItem(p->val.name));
        item->append(new QStandardItem(QString("%1").arg(p->val.price)));
        item->append(new QStandardItem(QString("%1 %2").arg(p->val.stock).arg(p->val.stockmeasureunit)));
        item->append(new QStandardItem(QString("%1").arg(p->val.othertip)));
        for(int i=0;i<4;i++)item->at(i)->setFlags(item->at(i)->flags() & ~Qt::ItemIsEditable);
        model->appendRow(*item);
        listmodellen++;
        if(listmodellen!=1)modellist=(listmodel*)realloc(modellist,sizeof(listmodel)*listmodellen);
        else modellist=(listmodel*)malloc(sizeof(listmodel)*listmodellen);
        listmodel newmodel;
        newmodel.currentnode=p;
        newmodel.row=item;
        modellist[listmodellen-1]=newmodel;
    }
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setModel(model);
    tableView->show();
    //将数据导入搜索文本框Completer用于搜索
    ui->searchLineEdit->clear();
    QStringList wordList;
    for(int i=0;i<listmodellen;i++)
    {
        if(modellist[i].currentnode->val.isnull==0)wordList.append(modellist[i].currentnode->val.name);
    }
    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->searchLineEdit->setPlaceholderText("键入搜索...");
    ui->searchLineEdit->setCompleter(completer);
    connect(completer, QOverload<const QString &>::of(&QCompleter::activated),this, &stockwindow::clicking);//点击搜索框建议项
}

stockwindow::stockwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::stockwindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    //状态栏显示提示
    QStatusBar *statusBar = new QStatusBar(this);
    QLabel *statusLabel = new QLabel("      创建或搜索菜品，或选择一项菜品后编辑或删除。                      ", this);
    statusBar->addWidget(statusLabel);
    //打开窗口时将本地文件存储的数据录入哈希数组
    list=readall(HASH_LEN,FILE_NAME);
    model = new QStandardItemModel(0,4);
    freshlist();

    connect(ui->pushButton, &QPushButton::clicked, this, &stockwindow::openStockCreateWindow);
}

void stockwindow::openStockCreateWindow()
{
    stockcreate *stockCreate = new stockcreate(this);
    connect(stockCreate, &::stockcreate::windowClosed, this, &stockwindow::testf);
    stockCreate->show();
    stockCreate->startTimer();
}

//关闭创建、编辑菜品等子窗口或删除某一菜品后，菜品信息变化，因此需要用freshlist()刷新列表并再做排序，使持有新信息的菜品依据打开窗口前用户选择的排序方式在恰当的位置展示
void stockwindow::testf()
{
    freshlist();
    if(ui->radioButton_2->isChecked())
    {
        sort(modellist,0,ui->tableView->model()->rowCount()-1,UP_SORT,SORT_BY_STOCK);
    }
    else if(ui->radioButton_3->isChecked())
    {
        sort(modellist,0,ui->tableView->model()->rowCount()-1,UP_SORT,SORT_BY_PRICE);
    }else if(ui->radioButton_4->isChecked())
    {
        sort(modellist,0,ui->tableView->model()->rowCount()-1,DOWN_SORT,SORT_BY_PRICE);
    }else if(ui->radioButton_5->isChecked())
    {
        sort(modellist,0,ui->tableView->model()->rowCount()-1,DOWN_SORT,SORT_BY_STOCK);
    }
}


stockwindow::~stockwindow()
{
    delete ui;
}

void stockwindow::on_stockwindow_destroyed(QObject *arg1)
{

}

//关闭窗口时将哈希数组存入本地文件，并将哈希数组占用的内存释放
void stockwindow::on_pushButton_2_clicked()
{
    int res=saveall(list,HASH_LEN,FILE_NAME);//当保存出现错误时，res的值是0，否则为1
    if(res)
    {
        dispose(list,HASH_LEN);//存储出现错误时不释放哈希数组所占内存，否则释放

        free(modellist);

        MainWindow *w=new MainWindow();
        w->show();
        this->close();
    }
}

Node** getStockList(int *hashlen)
{
    *hashlen=HASH_LEN;
    return &list;
}

void stockwindow::on_pushButton_clicked()
{

}

void stockwindow::on_pushButton_3_clicked()
{
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedIndexes();
    if (indexes.isEmpty()) {
        QMessageBox::information(this,"提示","没有选中任何项。");
        return;
    }

    int row=indexes.first().row();
    for (int i = 0; i < listmodellen; ++i)
    {
        if (ui->tableView->model()->index(row, 0) == modellist[i].row->at(0)->index())
        {
            Node* node = modellist[i].currentnode;
            QMessageBox issure;
            issure.setInformativeText(QString("是否确认删除 %1 ？").arg(node->val.name));
            issure.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            issure.setDefaultButton(QMessageBox::Yes);
            if(issure.exec()==QMessageBox::Yes)
            {
                node->val.isnull=1;
                testf();
            }
            break;
        }
    }
}

//打开编辑菜品窗口
void stockwindow::on_pushButton_4_clicked()
{
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedIndexes();
    if (indexes.isEmpty()) {
        QMessageBox::information(this,"提示","没有选中任何项。");
        return;
    }

    int row=indexes.first().row();
    for (int i = 0; i < listmodellen; ++i)
    {
        if (ui->tableView->model()->index(row, 0) == modellist[i].row->at(0)->index())
        {
            Node* node = modellist[i].currentnode;
            stockedit *stockEdit = new stockedit(this);
            stockEdit->sendNode(node);
            connect(stockEdit, &::stockedit::windowClosed, this, &stockwindow::testf);
            stockEdit->show();
            stockEdit->startTimer();
            break;
        }
    }
}

void stockwindow::on_setSequenceCombobox_currentIndexChanged(int index)
{

}

//选默认排序
void stockwindow::on_radioButton_clicked()
{
    freshlist();
}

//交换两行
void SwapRows(QAbstractItemModel *model, int row1, int row2)
{
    for (int i=0;i<model->columnCount();i++)//明面上，数据的交换
    {
        QVariant temp = model->data(model->index(row1, i));
        model->setData(model->index(row1, i), model->data(model->index(row2, i)));
        model->setData(model->index(row2, i), temp);
    }
    //暗面上，modellist中“行与节点对应关系”的交换
    Node* tmp2=modellist[row1].currentnode;
    modellist[row1].currentnode=modellist[row2].currentnode;
    modellist[row2].currentnode=tmp2;
}

//快速排序法按what指代的字段为列表排序
//单次排序函数
int stockwindow::sortonce(listmodel* list,int left,int right,int upordown,int what)
{
    listmodel pivot=list[left];
    if(upordown==UP_SORT)//升序
    {
        while(left<right)
        {
            if(what==SORT_BY_PRICE)//按价格排列
            {
                while(list[right].currentnode->val.price>=pivot.currentnode->val.price && left<right)
                {
                    right--;
                }
                SwapRows(ui->tableView->model(),left,right);
                while(list[left].currentnode->val.price<=pivot.currentnode->val.price && left<right)
                {
                    left++;
                }
                SwapRows(ui->tableView->model(),left,right);
                return left;
            }else//按库存排列
            {
                while(list[right].currentnode->val.stock>=pivot.currentnode->val.stock && left<right)
                {
                    right--;
                }
                SwapRows(ui->tableView->model(),left,right);
                while(list[left].currentnode->val.stock<=pivot.currentnode->val.stock && left<right)
                {
                    left++;
                }
                SwapRows(ui->tableView->model(),left,right);
                return left;
            }
        }
    }else//降序
    {
        while(left<right)
        {
            if(what==SORT_BY_PRICE)//按价格排列
            {
                while(list[right].currentnode->val.price<=pivot.currentnode->val.price && left<right)
                {
                    right--;
                }
                SwapRows(ui->tableView->model(),left,right);
                while(list[left].currentnode->val.price>=pivot.currentnode->val.price && left<right)
                {
                    left++;
                }
                SwapRows(ui->tableView->model(),left,right);
                return left;
            }else//按库存排列
            {
                while(list[right].currentnode->val.stock<=pivot.currentnode->val.stock && left<right)
                {
                    right--;
                }
                SwapRows(ui->tableView->model(),left,right);
                while(list[left].currentnode->val.stock>=pivot.currentnode->val.stock && left<right)
                {
                    left++;
                }
                SwapRows(ui->tableView->model(),left,right);
                return left;
            }
        }
    }
}

//总排序函数
void stockwindow::sort(listmodel* list,int left,int right,int upordown,int what)
{
    if(left<right)
    {
        int mid=sortonce(list,left,right,upordown,what);
        sort(list,left,mid-1,upordown,what);
        sort(list,mid+1,right,upordown,what);
    }
}

//选按单价升序
void stockwindow::on_radioButton_3_clicked()
{
    sort(modellist,0,ui->tableView->model()->rowCount()-1,UP_SORT,SORT_BY_PRICE);
}

void stockwindow::on_radioButton_4_clicked()
{
    sort(modellist,0,ui->tableView->model()->rowCount()-1,DOWN_SORT,SORT_BY_PRICE);
}


void stockwindow::on_radioButton_2_clicked()
{
    sort(modellist,0,ui->tableView->model()->rowCount()-1,UP_SORT,SORT_BY_STOCK);
}


void stockwindow::on_radioButton_5_clicked()
{
    sort(modellist,0,ui->tableView->model()->rowCount()-1,DOWN_SORT,SORT_BY_STOCK);
}


void stockwindow::on_pushButton_5_clicked()
{

}

