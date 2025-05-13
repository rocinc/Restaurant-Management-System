#include "vipwindow.h"
#include "mainwindow.h"
#include "ui_vipwindow.h"
#include "vipcreate.h"
#include "vipdata.h"
#include "vipedit.h"
#include "viptypecreate.h"
#include <qcompleter.h>
#include <qmessagebox.h>
#include <qstatusbar.h>

vipNode* viplist;

int viplistmodellen;
viplistmodel* vipmodellist;

int viptypelistmodellen;
viptype* viptypelist;

//将哈希数组中各链表节点录入列表中显示
void vipwindow::freshlist()
{
    if(vipmodellist!=NULL)free(vipmodellist);
    viplistmodellen=0;
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    QStringList headers;
    headers << "卡号" << "姓名" << "类型" << "到期时间" << "偏好";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(2, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(3, ui->tableWidget->width()*4/21);
    ui->tableWidget->setColumnWidth(3, ui->tableWidget->width()*4/21);
    for(int i=0;i<HASH_LEN;i++)
    {
        vipNode *p=&viplist[i];
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
            item->append(new QTableWidgetItem(QString("%1").arg(p->val.id)));
            item->append(new QTableWidgetItem(QString("%1").arg(p->val.name)));
            item->append(new QTableWidgetItem(QString("%1").arg(p->val.type.name)));
            item->append(new QTableWidgetItem(QString("%1").arg(dateToCharArray(p->val.outdated))));
            item->append(new QTableWidgetItem(QString("%1").arg(p->val.preference)));
            qDebug()<<viplistmodellen;
            for(int j=0;j<5;j++)
            {
                QTableWidgetItem *tableItem = item->at(j);
                ui->tableWidget->setRowCount(viplistmodellen+1);
                ui->tableWidget->setItem(viplistmodellen, j, tableItem);
                tableItem->setFlags(tableItem->flags() & ~Qt::ItemIsEditable);
            }
            viplistmodellen++;
            if(viplistmodellen!=1)vipmodellist=(viplistmodel*)realloc(vipmodellist,sizeof(viplistmodel)*viplistmodellen);
            else vipmodellist=(viplistmodel*)malloc(sizeof(viplistmodel)*viplistmodellen);
            viplistmodel newmodel;
            newmodel.currentnode=p;
            newmodel.row=item;
            vipmodellist[viplistmodellen-1]=newmodel;
        }
        if(p->val.isnull)continue;
        //遍历到每个有效的链表节点时显示在列表中
        QList<QTableWidgetItem *>* item=new QList<QTableWidgetItem *>();
        item->append(new QTableWidgetItem(QString("%1").arg(p->val.id)));
        item->append(new QTableWidgetItem(QString("%1").arg(p->val.name)));
        item->append(new QTableWidgetItem(QString("%1").arg(p->val.type.name)));
        item->append(new QTableWidgetItem(QString("%1").arg(dateToCharArray(p->val.outdated))));
        item->append(new QTableWidgetItem(QString("%1").arg(p->val.preference)));
        qDebug()<<viplistmodellen;
        for(int j=0;j<5;j++)
        {
            QTableWidgetItem *tableItem = item->at(j);
            ui->tableWidget->setRowCount(viplistmodellen+1);
            ui->tableWidget->setItem(viplistmodellen, j, tableItem);
            tableItem->setFlags(tableItem->flags() & ~Qt::ItemIsEditable);
        }
        viplistmodellen++;
        if(viplistmodellen!=1)vipmodellist=(viplistmodel*)realloc(vipmodellist,sizeof(viplistmodel)*viplistmodellen);
        else vipmodellist=(viplistmodel*)malloc(sizeof(viplistmodel)*viplistmodellen);
        viplistmodel newmodel;
        newmodel.currentnode=p;
        newmodel.row=item;
        vipmodellist[viplistmodellen-1]=newmodel;
    }
    //将数据导入搜索文本框Completer用于搜索
    ui->idSearch->clear();
    QStringList idList;
    for(int i=0;i<viplistmodellen;i++)
    {
        if(vipmodellist[i].currentnode->val.isnull==0)
        {
            idList.append(QString("%1").arg(vipmodellist[i].currentnode->val.id));
        }
    }
    QCompleter *completer = new QCompleter(idList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->idSearch->setPlaceholderText("键入会员卡号搜索...");
    ui->idSearch->setCompleter(completer);
    connect(completer, QOverload<const QString &>::of(&QCompleter::activated),this, &vipwindow::SearchSuggestionClicking);//点击搜索框建议项
}

//点击搜索文本框中的建议项
void vipwindow::SearchSuggestionClicking(const QString &text)
{
    vipNode* p=seek(viplist,text.toInt());//哈希查找
    QMessageBox box;
    box.setWindowTitle(QString("%1 的会员信息").arg(p->val.name));
    QString content;
    content.append(QString("订单号：%1\n").arg(p->val.id));
    content.append(QString("姓名：%1\n").arg(p->val.name));
    content.append(QString("会员开卡日期：%1\n").arg(dateToCharArray(p->val.create)));
    content.append(QString("到期时间：%1\n").arg(dateToCharArray(p->val.outdated)));
    content.append(QString("类型：%1\n").arg(p->val.type.name));
    content.append(QString("折扣：%1\n").arg(p->val.type.discount));
    content.append(QString("偏好：%1\n\n").arg(p->val.preference));
    content.append(QString("累计消费次数：%1\n").arg(p->val.paidcount));
    content.append(QString("累计消费金额：%1\n").arg(p->val.paidsum));
    box.setText(content);
    QPushButton *b1=box.addButton("编辑",QMessageBox::ActionRole);
    QPushButton *b2=box.addButton("关闭",QMessageBox::ActionRole);
    QPushButton *b3=box.addButton("删除",QMessageBox::ActionRole);
    box.exec();
    if(box.clickedButton() == b1)//打开编辑窗口
    {
        vipedit *w = new vipedit(this);
        connect(w, &::vipedit::windowClosed, this, &vipwindow::fresh);
        w->sendnode(p);
        w->show();
        w->startTimer();
    }
    else if(box.clickedButton()==b3)//删除
    {
        QMessageBox issure;
        vipNode* p=seek(viplist,ui->tableWidget->selectedItems().at(0)->text().toInt());
        issure.setInformativeText(QString("是否确认删除 %1 的会员？").arg(p->val.name));
        issure.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        issure.setDefaultButton(QMessageBox::Yes);
        if(issure.exec() == QMessageBox::Yes)
        {
            deletenode(viplist,p,HASH_LEN);
            fresh();
        }
    }
}

vipwindow::vipwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vipwindow)
{
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->resizeRowsToContents();
    ui->vipTypeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->vipTypeTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //状态栏显示提示
    QStatusBar *statusBar = new QStatusBar(this);
    QLabel *statusLabel = new QLabel("      选择或搜索一个会员后编辑其资料和到期时间，新增会员，或在界面右侧管理会员类型。在餐厅实际运营中会员卡号由前台扫描客户会员卡直接得到。菜品折后价为原价×（1 - 折扣）。                        ", this);
    statusBar->addWidget(statusLabel);
    ui->vipTypeTable->resizeRowsToContents();
    //打开窗口时将本地文件存储的会员数据录入哈希数组
    viplist=readAllVip(HASH_LEN,VIP_FILE_NAME);
    freshlist();
    //打开窗口时将本地的会员类型信息录入界面右侧的会员类型列表
    //卡号、姓名、类型、到期时间、偏好
    viptypelist = readAllVipType(VIP_TYPE_FILE_NAME,&viptypelistmodellen);
    freshTypeListWithArray();

}

vipwindow::~vipwindow()
{
    delete ui;
}

vipNode* getVipList(int *hashlen)
{
    *hashlen=HASH_LEN;
    return viplist;
}

viptype** getVipTypeList(int *arraylen)
{
    *arraylen=viptypelistmodellen;
    return &viptypelist;
}

void createNewVipType(viptype newtype)
{
    if(viptypelistmodellen!=0)viptypelist=(viptype*)realloc(viptypelist,sizeof(viptype)*(viptypelistmodellen+1));
    else viptypelist=(viptype*)malloc(sizeof(viptype));
    viptypelist[viptypelistmodellen]=newtype;
    viptypelistmodellen++;
}

void vipwindow::freshTypeListWithArray()
{
    ui->vipTypeTable->clear();
    ui->vipTypeTable->setColumnCount(2);
    QStringList headers;
    headers << "类型名称" << "折扣";
    ui->vipTypeTable->setHorizontalHeaderLabels(headers);
    ui->vipTypeTable->setColumnWidth(0, ui->vipTypeTable->width()*6/10);
    ui->vipTypeTable->setColumnWidth(1, ui->vipTypeTable->width()*3/10);
    for(int i=0;i<viptypelistmodellen;i++)
    {
        ui->vipTypeTable->setRowCount(i+1);
        QTableWidgetItem *nameItem = new QTableWidgetItem(viptypelist[i].name);
        ui->vipTypeTable->setItem(i, 0, nameItem);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);

        QTableWidgetItem *discountItem = new QTableWidgetItem(QString("%1").arg(viptypelist[i].discount));
        ui->vipTypeTable->setItem(i, 1, discountItem);
        discountItem->setFlags(discountItem->flags() & ~Qt::ItemIsEditable);
    }
}

void vipwindow::on_addButton_clicked()
{
    viptypecreate *w = new viptypecreate(this);
    connect(w, &::viptypecreate::windowClosed, this, &vipwindow::freshTypeListWithArray);
    w->show();
    w->startTimer();
}


void vipwindow::on_saveAndExitButton_clicked()
{
    //保存会员信息
    int res1=saveall(viplist,HASH_LEN,VIP_FILE_NAME);//当保存出现错误时，res的值是0，否则为1
    if(res1)
    {
        dispose(viplist,HASH_LEN);//存储出现错误时不释放哈希数组所占内存，否则释放
        //保存会员类型
        int res2=saveAllVipType(viptypelistmodellen,viptypelist,VIP_TYPE_FILE_NAME);
        if(res2)
        {
            if(viptypelistmodellen!=0)free(viptypelist);
            MainWindow *w=new MainWindow();
            w->show();
            this->close();
        }
    }
}

void vipwindow::fresh()
{
    freshlist();
}

void vipwindow::on_deleteButton_clicked()
{
    int index=ui->vipTypeTable->currentRow();
    if(index==-1)
    {
        QMessageBox::information(this,"提示","没有选中任何会员类型。");
    }else
    {
        for(int i=0;i<viplistmodellen;i++)
        {
            if(strcmp(vipmodellist[i].currentnode->val.type.name,viptypelist[i].name)==0)
            {
                QMessageBox::information(this,"提示","仍然存在这种类型的会员，因此不能删除它。");
                return;
            }
        }
        memmove(&viptypelist[index], &viptypelist[index + 1], (viptypelistmodellen - index - 1) * sizeof(viptype));
        viptypelist=(viptype*)realloc(viptypelist,sizeof(viptype)*(viptypelistmodellen-1));
        viptypelistmodellen--;
        freshTypeListWithArray();
    }
}


void vipwindow::on_addVipButton_clicked()
{
    if(viptypelistmodellen==0)
    {
        QMessageBox::information(this,"提示","需要在会员管理主页添加至少一种会员类型。");
        return;
    }
    vipcreate *w = new vipcreate(this);
    connect(w, &::vipcreate::windowClosed, this, &vipwindow::fresh);
    w->show();
    w->startTimer();
}


void vipwindow::on_editVipButton_clicked()
{
    int index=ui->tableWidget->currentRow();
    if(index==-1)
    {
        QMessageBox::information(this,"提示","没有选中任何会员类型。");
        return;
    }
    vipedit *w = new vipedit(this);
    connect(w, &::vipedit::windowClosed, this, &vipwindow::fresh);
    w->sendnode(seek(viplist,ui->tableWidget->selectedItems().at(0)->text().toInt()));//哈希查找，由会员卡号快速得到节点
    w->show();
    w->startTimer();
}


void vipwindow::on_deleteVipButton_clicked()
{
    int index=ui->tableWidget->currentRow();
    if(index==-1)
    {
        QMessageBox::information(this,"提示","没有选中任何会员类型。");
        return;
    }

    QMessageBox issure;
    vipNode* p=seek(viplist,ui->tableWidget->selectedItems().at(0)->text().toInt());
    issure.setInformativeText(QString("是否确认删除 %1 的会员？\n\n详细信息：\n电话号码：%2\n累计消费金额：%3元\n累计消费次数：%3").arg(p->val.name).arg(p->val.phonenumber).arg(p->val.paidsum).arg(p->val.paidcount));
    issure.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    issure.setDefaultButton(QMessageBox::Yes);
    if(issure.exec() == QMessageBox::Yes)
    {
        deletenode(viplist,p,HASH_LEN);
        fresh();
    }
}

