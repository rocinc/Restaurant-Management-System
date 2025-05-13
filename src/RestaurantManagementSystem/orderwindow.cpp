#include "orderwindow.h"
#include "mainwindow.h"
#include "orderadd.h"
#include "stockdata.h"
#include "orderdata.h"
#include "stockwindow.h"
#include "ui_orderwindow.h"
#include <qmessagebox.h>
#include <qstandarditemmodel.h>

/**参考
typedef struct datetime
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}datetime;

typedef struct desk
{
    int site[3];
    int currentpeople;//当前人数（0就是空闲）
    int orderid;
    int size;//固定的人数型号
}desk;

//每个菜品与其口味、状态之间一一对应
typedef struct pair
{
    T dish;
    int tasteindex;//订单对应口味在dish.tastes数组中的索引
    int dishstatus;//是菜品状态不是订单状态
}pair;

typedef struct order
{
    int isnull;
    long int orderid;
    datetime createtime;
    datetime endtime;//仅FINISHED状态下有效
    int orderstatus;//是订单状态不是菜品状态
    int desksite[3];
    int dishescount;
    pair dishes[MAX_DISHES_COUNT];
    int sumprice;//仅FINISHED状态下有效
}order;

typedef struct orderNode
{
    order val;
    struct orderNode *next;
}orderNode;
**/

#define HASH_LEN 1000

orderNode* orderlist;

int orderlistmodellen;
orderlistmodel* ordermodellist;

//将哈希数组中各链表节点录入列表中显示
void orderwindow::freshlist()
{
    if(ordermodellist!=NULL)free(ordermodellist);
    QTableView *tableView = ui->tableView;
    tableView->close();
    orderlistmodellen=0;
    model->clear();
    model = new QStandardItemModel(0,4);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("订单号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("创建时间"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("位置"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("状态"));
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
            //遍历到每个有效的链表节点时显示在列表中
            QList<QStandardItem *>* item=new QList<QStandardItem *>();
            item->append(new QStandardItem(QString("%1").arg(p->val.orderid)));
            item->append(new QStandardItem(QString("%1").arg(dateTimeToCharArray(p->val.createtime))));
            item->append(new QStandardItem(QString("%1 楼 %2 区 %3 桌").arg(p->val.desksite[0]).arg(p->val.desksite[1]).arg(p->val.desksite[2])));
            switch(p->val.orderstatus)
            {
            case WAITING:item->append(new QStandardItem(QString("正在备餐")));break;
            case EATING:item->append(new QStandardItem(QString("备餐完毕")));break;
            //case FINISHED:item->append(new QStandardItem(QString("")));break;
            }
            for(int i=0;i<4;i++)item->at(i)->setFlags(item->at(i)->flags() & ~Qt::ItemIsEditable);
            model->appendRow(*item);
            orderlistmodellen++;
            if(orderlistmodellen!=1)ordermodellist=(orderlistmodel*)realloc(ordermodellist,sizeof(orderlistmodel)*orderlistmodellen);
            else ordermodellist=(orderlistmodel*)malloc(sizeof(listmodel)*orderlistmodellen);
            orderlistmodel newmodel;
            newmodel.currentnode=p;
            newmodel.row=item;
            ordermodellist[orderlistmodellen-1]=newmodel;
            p=p->next;
        }
        if(p->val.isnull)continue;
        //遍历到每个有效的链表节点时显示在列表中
        QList<QStandardItem *>* item=new QList<QStandardItem *>();
        item->append(new QStandardItem(QString("%1").arg(p->val.orderid)));
        item->append(new QStandardItem(QString("%1").arg(dateTimeToCharArray(p->val.createtime))));
        item->append(new QStandardItem(QString("%1 楼 %2 区 %3 桌").arg(p->val.desksite[0]).arg(p->val.desksite[1]).arg(p->val.desksite[2])));
        switch(p->val.orderstatus)
        {
        case WAITING:item->append(new QStandardItem(QString("正在备餐")));break;
        case EATING:item->append(new QStandardItem(QString("备餐完毕")));break;
            //case FINISHED:item->append(new QStandardItem(QString("")));break;
        }
        for(int i=0;i<4;i++)item->at(i)->setFlags(item->at(i)->flags() & ~Qt::ItemIsEditable);
        model->appendRow(*item);
        orderlistmodellen++;
        if(orderlistmodellen!=1)ordermodellist=(orderlistmodel*)realloc(ordermodellist,sizeof(orderlistmodel)*orderlistmodellen);
        else ordermodellist=(orderlistmodel*)malloc(sizeof(listmodel)*orderlistmodellen);
        orderlistmodel newmodel;
        newmodel.currentnode=p;
        newmodel.row=item;
        ordermodellist[orderlistmodellen-1]=newmodel;
    }
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setModel(model);
    tableView->show();
}

orderwindow::orderwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::orderwindow)
{
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    //打开窗口时将本地文件存储的数据录入哈希数组
    orderlist=readAllOrder(HASH_LEN,ORDER_FILE_NAME);
    model = new QStandardItemModel(0,4);

    freshlist();

    connect(ui->addButton, &QPushButton::clicked, this, &orderwindow::openOrderCreateWindow);
}

void orderwindow::openOrderCreateWindow()
{
    orderadd *orderAdd = new orderadd(this);
    connect(orderAdd, &::orderadd::windowClosed, this, &orderwindow::fresh);
    orderAdd->show();
    orderAdd->startTimer();
}

void orderwindow::fresh()
{
    freshlist();
    //如果将来有排序调整，改这里之后的部分
}

orderwindow::~orderwindow()
{
    delete ui;
}

orderNode* getOrderList(int *hashlen)
{
    *hashlen=HASH_LEN;
    return orderlist;
}

void orderwindow::on_saveAndClose_clicked()
{
    int res=saveall(orderlist,HASH_LEN,ORDER_FILE_NAME);//当保存出现错误时，res的值是0，否则为1
    if(res)
    {
        dispose(orderlist,HASH_LEN);//存储出现错误时不释放哈希数组所占内存，否则释放

        free(ordermodellist);

        MainWindow *w=new MainWindow();
        w->show();
        this->close();
    }
}

