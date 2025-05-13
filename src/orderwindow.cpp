#include "orderwindow.h"
#include "mainwindow.h"
#include "orderadd.h"
#include "orderstatusedit.h"
#include "stockdata.h"
#include "orderdata.h"
#include "stockwindow.h"
#include "ui_orderwindow.h"
#include <qdatetime.h>
#include <qmessagebox.h>
#include <qstandarditemmodel.h>
#include "vipdata.h"
#include <QDate>
#include <qstatusbar.h>

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
int alldeskcount;

//将哈希数组中各链表节点录入列表中显示
void orderwindow::freshlist()
{
    int occupiedseat=0,eatingcount=0,eatingrate;
    if(ordermodellist!=NULL)free(ordermodellist);
    orderlistmodellen=0;
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    QStringList headers;
    headers << "订单号" << "创建时间" << "人数" << "位置" << "状态";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(2, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(3, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(3, ui->tableWidget->width()*4/21);
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
            QList<QTableWidgetItem *>* item=new QList<QTableWidgetItem *>();
            item->append(new QTableWidgetItem(QString("%1").arg(p->val.orderid)));
            item->append(new QTableWidgetItem(QString("%1").arg(dateTimeToCharArray(p->val.createtime))));
            item->append(new QTableWidgetItem(QString("%1").arg(p->val.countpeople)));
            item->append(new QTableWidgetItem(QString("%1 楼 %2 区 %3 桌").arg(p->val.desksite[0]).arg(p->val.desksite[1]).arg(p->val.desksite[2])));
            switch(p->val.orderstatus)
            {
            case WAITING:item->append(new QTableWidgetItem(QString(getTextFromOrderStatus(WAITING))));break;
            case EATING:item->append(new QTableWidgetItem(QString(getTextFromOrderStatus(EATING))));break;
            }
            for(int j=0;j<5;j++)
            {
                QTableWidgetItem *tableItem = item->at(j);
                ui->tableWidget->setRowCount(orderlistmodellen+1);
                ui->tableWidget->setItem(orderlistmodellen, j, tableItem);
                tableItem->setFlags(tableItem->flags() & ~Qt::ItemIsEditable);
            }
            orderlistmodellen++;
            if(orderlistmodellen!=1)ordermodellist=(orderlistmodel*)realloc(ordermodellist,sizeof(orderlistmodel)*orderlistmodellen);
            else ordermodellist=(orderlistmodel*)malloc(sizeof(orderlistmodel)*orderlistmodellen);
            orderlistmodel newmodel;
            newmodel.currentnode=p;
            newmodel.row=item;
            ordermodellist[orderlistmodellen-1]=newmodel;
            //更新界面右侧当前状态
            if(p->val.orderstatus==EATING)eatingcount++;
            occupiedseat+=p->val.countpeople;
            p=p->next;
        }
        if(p->val.isnull)continue;
        //遍历到每个有效的链表节点时显示在列表中
        QList<QTableWidgetItem *>* item=new QList<QTableWidgetItem *>();
        item->append(new QTableWidgetItem(QString("%1").arg(p->val.orderid)));
        item->append(new QTableWidgetItem(QString("%1").arg(dateTimeToCharArray(p->val.createtime))));
        item->append(new QTableWidgetItem(QString("%1").arg(p->val.countpeople)));
        item->append(new QTableWidgetItem(QString("%1 楼 %2 区 %3 桌").arg(p->val.desksite[0]).arg(p->val.desksite[1]).arg(p->val.desksite[2])));
        switch(p->val.orderstatus)
        {
        case WAITING:item->append(new QTableWidgetItem(QString(getTextFromOrderStatus(WAITING))));break;
        case EATING:item->append(new QTableWidgetItem(QString(getTextFromOrderStatus(EATING))));break;
        }
        for(int j=0;j<5;j++)
        {
            QTableWidgetItem *tableItem = item->at(j);
            ui->tableWidget->setRowCount(orderlistmodellen+1);
            ui->tableWidget->setItem(orderlistmodellen, j, tableItem);
            tableItem->setFlags(tableItem->flags() & ~Qt::ItemIsEditable);
        }
        orderlistmodellen++;
        if(orderlistmodellen!=1)ordermodellist=(orderlistmodel*)realloc(ordermodellist,sizeof(orderlistmodel)*orderlistmodellen);
        else ordermodellist=(orderlistmodel*)malloc(sizeof(orderlistmodel)*orderlistmodellen);
        orderlistmodel newmodel;
        newmodel.currentnode=p;
        newmodel.row=item;
        ordermodellist[orderlistmodellen-1]=newmodel;
        //更新界面右侧当前状态
        if(p->val.orderstatus==EATING)eatingcount++;
        occupiedseat+=p->val.countpeople;
        p=p->next;
    }
    if(orderlistmodellen!=0)eatingrate=((double)eatingcount)/((double)orderlistmodellen)*100;
    else eatingrate=0;
    ui->occupiedSeatStatus->display(occupiedseat);
    ui->orderCountStatus->display(orderlistmodellen);
    ui->eatingOrderCountStatus->display(eatingcount);
    ui->eatingOrderRateStatus->display(eatingrate);
    ui->seatLeftStatus->display(alldeskcount-occupiedseat);
    if(alldeskcount!=0)ui->occupiedSeatRateStatus->display((double)occupiedseat/(double)alldeskcount*100);
    else ui->occupiedSeatRateStatus->display(0);
}

orderwindow::orderwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::orderwindow)
{
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //状态栏显示提示
    QStatusBar *statusBar = new QStatusBar(this);
    QLabel *statusLabel = new QLabel("      新增客户订单，或选择一项订单后，为其结账或编辑其各菜品的上菜状态。多个订单的拼桌是被允许的。已结账的订单不会在列表中显示。可以按菜品上齐状态和桌位双重筛选。                        ", this);
    statusBar->addWidget(statusLabel);
    //记录总座位数以显示在界面右侧
    alldeskcount=0;
    FILE *readdesk=fopen(DESK_FILE_NAME,"rb");
    if(readdesk==NULL)QMessageBox::information(this,"提示","桌位相关文件打开失败，界面右侧将不会显示座位信息。");
    else
    {
        while(!feof(readdesk))
        {
            desk currentdesk;
            fread(&currentdesk,sizeof(desk),1,readdesk);
            alldeskcount+=currentdesk.size;
        }
        fclose(readdesk);
    }
    //打开窗口时将本地文件存储的数据录入哈希数组
    orderlist=readAllOrder(HASH_LEN,ORDER_FILE_NAME);
    freshlist();

    connect(ui->addButton, &QPushButton::clicked, this, &orderwindow::openOrderCreateWindow);
    //读取界面右侧的桌位筛选
    ui->floorBox->addItem("显示所有",-1);
    int floorCount = 0;
    orderadd oa;
    int *floors= oa.readFloorsWithDesks(DESK_FILE_NAME,&floorCount);
    if (floors == NULL)
    {
        QMessageBox::information(this, "提示", "读取楼层信息时失败。");
        goto END;
    }
    for (int i = 0; i < floorCount; ++i) {
        ui->floorBox->addItem(QString::number(floors[i]), floors[i]);
    }
    free(floors);
    connect(ui->floorBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_floorBox_currentIndexChanged(int)));
    connect(ui->areaBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_areaBox_currentIndexChanged(int)));
    connect(ui->deskBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_deskBox_currentIndexChanged(int)));
END:;
}

//判断传入的订单节点是否满足界面右侧的筛选条件
bool orderwindow::isCorrectWithDeskCombobox(orderNode *node)
{
    int x=ui->floorBox->itemData(ui->floorBox->currentIndex()).toInt(),
        y=ui->areaBox->itemData(ui->areaBox->currentIndex()).toInt(),
        z=ui->deskBox->itemData(ui->deskBox->currentIndex()).toInt();
    if(x==-1)return true;
    else
    {
        if(node->val.desksite[0]!=x)return false;
        else
        {
            if(y==-1)return true;
            else
            {
                if(node->val.desksite[1]!=y)return false;
                else
                {
                    if(z==-1)return true;
                    else
                    {
                        if(node->val.desksite[2]!=z)return false;
                        else return true;
                    }
                }
            }
        }
    }
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

    //条件筛选
    //先筛是否已上齐菜
    if(ui->displayAll->isChecked())
    {
        for(int i=0;i<orderlistmodellen;i++)
        {
            ui->tableWidget->setRowHidden(i,0);
        }
    }else if(ui->displayEating->isChecked())
    {
        for(int i=0;i<orderlistmodellen;i++)
        {
            if(ordermodellist[i].currentnode->val.orderstatus!=EATING)
            {
                ui->tableWidget->setRowHidden(i,1);
            }
            else
            {
                ui->tableWidget->setRowHidden(i,0);
            }
        }
    }else if(ui->displayWaiting->isChecked())
    {
        for(int i=0;i<orderlistmodellen;i++)
        {
            if(ordermodellist[i].currentnode->val.orderstatus!=WAITING)
            {
                ui->tableWidget->setRowHidden(i,1);
            }
            else
            {
                ui->tableWidget->setRowHidden(i,0);
            }
        }
    }

    //再筛桌位
    for(int i=0;i<orderlistmodellen;i++)
    {
        if(!ui->tableWidget->isRowHidden(i))
        {
            if(isCorrectWithDeskCombobox(ordermodellist[i].currentnode))ui->tableWidget->setRowHidden(i,0);
            else ui->tableWidget->setRowHidden(i,1);
        }
    }
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

//所选订单的菜品状态按钮
void orderwindow::on_statusButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::information(this,"提示","没有选中任何项。");
        return;
    }

    orderNode* node = seek(orderlist,atoi(QStringToCharArray(selectedItems.first()->text())));//哈希查找
    if(node==NULL)
    {
        QMessageBox::information(this,"提示","没有找到这个订单。发生了错误。");
        return;
    }
    orderstatusedit *w=new orderstatusedit();
    connect(w, &::orderstatusedit::windowClosed, this, &orderwindow::fresh);
    w->sendOrderNode(node);
    w->show();
    w->startTimer();
}

//非会员结账
void orderwindow::on_payButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::information(this,"提示","没有选中任何订单。");
        return;
    }

    orderNode* node = seek(orderlist,atoi(QStringToCharArray(selectedItems.first()->text())));//哈希查找
    if(node==NULL)
    {
        QMessageBox::information(this,"提示","没有找到这个订单。发生了错误。");
        return;
    }
    double sumprice=0;
    QMessageBox issure;
    issure.setWindowTitle("结账确认");
    QString content;
    content.append(QString("编号为 %1 的订单：\n").arg(node->val.orderid));
    content.append(QString("订单创建时间：%1\n").arg(dateTimeToCharArray(node->val.createtime)));
    content.append(QString("位置：%1 楼 %2 区 %3 桌\n").arg(node->val.desksite[0]).arg(node->val.desksite[1]).arg(node->val.desksite[2]));
    content.append(QString("人数：%1\n\n").arg(node->val.countpeople));
    int someDishHasNotPrepared=0;
    for(int j=0;j<node->val.dishescount;j++)
    {
        int price=(node->val.dishes[j].dish.price)*(node->val.dishes[j].count);
        sumprice+=price;
        content.append(QString("%1 × %2份    共 %3 元\n").arg(node->val.dishes[j].dish.name).arg(node->val.dishes[j].count).arg(price));
        if((!someDishHasNotPrepared) && node->val.dishes[j].dishstatus!=DELIVERED)someDishHasNotPrepared=1;
    }
    if(someDishHasNotPrepared)
    {
        QMessageBox q;
        q.setWindowTitle("确认");
        q.setText("该订单当前还未上齐菜，是否确认结账？");
        q.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        q.setDefaultButton(QMessageBox::Yes);
        q.show();
        if(q.exec() == QMessageBox::No)return;
    }
    content.append(QString("\n总计 %1 元，顾客是否已确认结账？").arg(sumprice));
    issure.setText(content);
    issure.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    issure.setDefaultButton(QMessageBox::Yes);
    issure.show();
    if(issure.exec()==QMessageBox::Yes)
    {
        deletenode(orderlist,node,HASH_LEN);//在哈希数组中删除这个节点
        setDeskCurrentPeople(node->val.desksite[0],node->val.desksite[1],node->val.desksite[2],-node->val.countpeople);//同步更新桌子currentpeople
        fresh();
    }
}


void orderwindow::on_displayAll_clicked()
{
    fresh();
}


void orderwindow::on_displayWaiting_clicked()
{
    fresh();
}


void orderwindow::on_displayEating_clicked()
{
    fresh();
}


void orderwindow::on_floorBox_currentIndexChanged(int index)
{
    if(ui->floorBox->itemData(index)==-1)
    {
        ui->areaBox->setCurrentIndex(0);
        ui->deskBox->setCurrentIndex(0);
        ui->areaBox->setEnabled(false);
        ui->deskBox->setEnabled(false);
        return;
    }
    else
    {
        ui->areaBox->setEnabled(true);
    }
    ui->areaBox->clear();
    ui->deskBox->clear();
    ui->areaBox->addItem("显示所有",-1);
    ui->deskBox->addItem("显示所有",-1);

    int floor = ui->floorBox->itemData(index).toInt();
    int areaCount = 0;
    orderadd oa;int* areas = oa.readAreasWithDesks(DESK_FILE_NAME, floor, &areaCount);
    if(areas == NULL)
    {
        QMessageBox::information(this, "提示", "读取区域信息时失败。");
        close();
        return;
    }
    for (int i = 0; i < areaCount; ++i) {
        ui->areaBox->addItem(QString::number(areas[i]), areas[i]);
    }
    free(areas);

    if (ui->areaBox->count() > 0) {
        ui->areaBox->setCurrentIndex(0);
    }
}


void orderwindow::on_areaBox_currentIndexChanged(int index)
{
    if(ui->areaBox->itemData(index)==-1)
    {
        ui->deskBox->setCurrentIndex(0);
        ui->deskBox->setEnabled(false);
    }else
    {
        ui->deskBox->setEnabled(true);
    }

    if(index < 0 || index >= ui->areaBox->count()) {
        return;
    }
    ui->deskBox->clear();

    ui->deskBox->addItem("显示所有",-1);

    int floor = ui->floorBox->currentText().toInt();
    int area = ui->areaBox->itemData(index).toInt();
    int deskCount = 0;
    orderadd oa;int* desks = oa.readDesksWithArea(DESK_FILE_NAME, floor, area, &deskCount);
    if (desks == NULL)
    {
        return;
    }

    // 读取所有桌位信息，包括桌型
    desk* deskInfoArray = (desk*)malloc(deskCount * sizeof(desk));
    if(deskInfoArray==NULL && deskCount!=0)
    {
        errorcatch(MEMORY_ERROR);
        return;
    }
    int readCount = 0;
    FILE* file = fopen(DESK_FILE_NAME, "rb");
    if (!file) {
        free(desks);
        QMessageBox::information(this, "提示", "无法打开桌位文件。");
        close();
        return;
    }
    desk deskInfo;
    while (fread(&deskInfo, sizeof(desk), 1, file) == 1) {
        if (deskInfo.site[0] == floor && deskInfo.site[1] == area) {
            int found = 0;
            for (int i = 0; i < readCount; ++i) {
                if (deskInfo.site[2] == deskInfoArray[i].site[2]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                deskInfoArray[readCount++] = deskInfo;
            }
        }
    }
    fclose(file);
    for (int i = 0; i < readCount; ++i) {
        // 构造显示的字符串，格式为 "桌号(桌型+人)"
        QString deskItemText = QString::number(deskInfoArray[i].site[2]) + "  (总" + QString::number(deskInfoArray[i].size) + "人，空闲"+QString::number(deskInfoArray[i].size-deskInfoArray[i].currentpeople)+"人）";
        ui->deskBox->addItem(deskItemText, deskInfoArray[i].site[2]);
    }
    free(desks);
    free(deskInfoArray);

    // 设置桌位ComboBox的第一个索引为当前索引
    if (ui->deskBox->count() > 0) {
        ui->deskBox->setCurrentIndex(0);
    }
}

void orderwindow::on_deskBox_currentIndexChanged(int index)
{
    fresh();
}

//会员结账
void orderwindow::on_vipPayButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::information(this,"提示","没有选中任何订单。");
        return;
    }

    if(ui->vipIdEdit->text().isEmpty())
    {
        QMessageBox::information(this,"提示","应先输入会员卡号。（实际运营时由客户刷卡得到）");
        return;
    }
    char *idtext = QStringToCharArray(ui->vipIdEdit->text());
    int id=atoi(idtext);
    vipNode* viplist=readAllVip(HASH_LEN,VIP_FILE_NAME);
    vipNode* p=seek(viplist,id);
    if(p==NULL)
    {
        QMessageBox::information(this,"提示","没有找到这个会员。");
        return;
    }

    //判断会员是否过期
    time_t now = time(nullptr);
    struct tm *local_time = localtime(&now);
    QDate currentdate = {local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday};
    QDate vipenddate = {p->val.outdated.year,p->val.outdated.month,p->val.outdated.day};
    if(currentdate >= vipenddate)
    {
        QMessageBox::information(this,"提示",QString("该用户的会员已在 %1 到期。").arg(dateToCharArray(p->val.outdated)));
        return;
    }

    QMessageBox issure;
    issure.setWindowTitle("结账确认");
    QString content;
    content.append(QString("会员相关信息：\n订单号：%1\n").arg(p->val.id));
    content.append(QString("姓名：%1\n").arg(p->val.name));
    content.append(QString("会员开卡日期：%1\n").arg(dateToCharArray(p->val.create)));
    content.append(QString("到期时间：%1\n").arg(dateToCharArray(p->val.outdated)));
    content.append(QString("类型：%1\n").arg(p->val.type.name));
    content.append(QString("折扣：%1\n").arg(p->val.type.discount));
    content.append(QString("偏好：%1\n\n").arg(p->val.preference));
    content.append(QString("累计消费次数：%1\n").arg(p->val.paidcount));
    content.append(QString("累计消费金额：%1\n").arg(p->val.paidsum));
    content.append(QString("距离到期还有：%1 天\n\n当前订单信息：\n").arg(currentdate.daysTo({p->val.outdated.year,p->val.outdated.month,p->val.outdated.day})));
    orderNode* ordernode = seek(orderlist,atoi(QStringToCharArray(selectedItems.first()->text())));//借订单号来哈希查找订单节点及其信息
    double sumprice=0;
    content.append(QString("编号为 %1 的订单：\n").arg(ordernode->val.orderid));
    content.append(QString("订单创建时间：%1\n").arg(dateTimeToCharArray(ordernode->val.createtime)));
    content.append(QString("位置：%1 楼 %2 区 %3 桌\n").arg(ordernode->val.desksite[0]).arg(ordernode->val.desksite[1]).arg(ordernode->val.desksite[2]));
    content.append(QString("人数：%1\n\n").arg(ordernode->val.countpeople));
    int someDishHasNotPrepared=0;
    for(int j=0;j<ordernode->val.dishescount;j++)//计价
    {
        int price=(ordernode->val.dishes[j].dish.price)*(ordernode->val.dishes[j].count);
        sumprice+=price*(1-p->val.type.discount);//这里体现会员折扣
        content.append(QString("%1 × %2份    原共 %3 元\n").arg(ordernode->val.dishes[j].dish.name).arg(ordernode->val.dishes[j].count).arg(price));
        if((!someDishHasNotPrepared) && ordernode->val.dishes[j].dishstatus!=DELIVERED)someDishHasNotPrepared=1;
    }
    if(someDishHasNotPrepared)
    {
        content.append(QString("注意：有菜品还未上齐。\n"));
    }
    content.append(QString("\n打折后 总计 %1 元，顾客是否已确认结账？").arg(sumprice));
    issure.setText(content);
    issure.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    issure.setDefaultButton(QMessageBox::Yes);
    issure.show();
    if(issure.exec()==QMessageBox::Yes)
    {
        deletenode(orderlist,ordernode,HASH_LEN);//在哈希数组中删除这个节点
        setDeskCurrentPeople(ordernode->val.desksite[0],ordernode->val.desksite[1],ordernode->val.desksite[2],-ordernode->val.countpeople);//同步更新桌子currentpeople
        setVipPaid(p->val.id,sumprice);//同步更新会员的累计消费信息
        fresh();
    }
}

