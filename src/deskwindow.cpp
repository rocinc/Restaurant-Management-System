#include "deskwindow.h"
#include "mainwindow.h"
#include "ui_deskwindow.h"
#include "orderdata.h"
#include <qlabel.h>
#include <qspinbox.h>
#include <qstatusbar.h>

/**
typedef struct desk
{
    int site[3];
    int currentpeople;
    int orderid;
    int size;
}desk;
 **/

deskwindow::deskwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deskwindow)
{
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    //状态栏显示提示
    QStatusBar *statusBar = new QStatusBar(this);
    QLabel *statusLabel = new QLabel("      餐厅按“楼层-区域-餐桌”的布局呈现在树状图中。选择其中一项并点击底部的按钮来进行相应操作，或直接在表中调整餐桌桌型。                      ", this);
    statusBar->addWidget(statusLabel);
    //设置浅色系，否则展开按钮看不清
    setStyleSheet("QWidget {"
                  "background-color: #F0F0F0; /* 浅灰色背景 */"
                  "color: #333; /* 深灰色字体 */"
                  "}"
                  "QTreeWidget {"
                  "background-color: #FFFFFF; /* 树形控件背景白色 */"
                  "alternate-background-color: #F8F8F8; /* 树形控件交替行背景色 */"
                  "color: #333; /* 树形控件字体颜色 */"
                  "selection-background-color: #D0D0D0; /* 选中行背景色 */"
                  "gridline-color: #A0A0A0; /* 列分隔线颜色 */"
                  "}"
                  "QPushButton {"
                  "background-color: #E0E0E0; /* 按钮背景更浅的灰色 */"
                  "color: #333; /* 按钮字体颜色 */"
                  "}");

    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList()<<"序号"<<"类型"<<"桌型（人数）"<<"该桌当前人数");
    freshlist();
    expandAllItems(ui->treeWidget);//全部展开而不折叠
}

// 展开所有项
void deskwindow::expandAllItems(QTreeWidget *treeWidget)
{
    // 展开所有楼层项
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i)
    {
        treeWidget->topLevelItem(i)->setExpanded(true);
        // 递归展开子项
        expandAllChildItems(treeWidget->topLevelItem(i));
    }
}

// 递归展开子项
void deskwindow::expandAllChildItems(QTreeWidgetItem *item)
{
    item->setExpanded(true);
    for (int i = 0; i < item->childCount(); ++i)
    {
        expandAllChildItems(item->child(i));
    }
}

void deskwindow::freshlist()
{
    FILE *f1 = fopen(DESK_FILE_NAME, "rb");
    if (f1 == NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        this->close();
        return;
    }
    desk d;
    // 用于存储楼层和区域节点的列表
    QList<QTreeWidgetItem*> floorItems;
    QList<QTreeWidgetItem*> areaItems;

    while (1)
    {
        if (fread(&d, sizeof(desk), 1, f1) != 1)
        {
            if (feof(f1))
                break;
            errorcatch(FILE_READ_ERROR);
            this->close();
            fclose(f1);
            return;
        }

        // 创建楼层节点
        QTreeWidgetItem *floorItem = nullptr;
        bool floorFound = false;
        for (int i = 0; i < floorItems.size(); ++i)
        {
            if (floorItems[i]->text(0).toInt() == d.site[0])
            {
                floorItem = floorItems[i];
                floorFound = true;
                break;
            }
        }
        if (!floorFound) // 如果楼层节点不存在，则创建
        {
            floorItem = new QTreeWidgetItem();
            floorItem->setText(0, QString::number(d.site[0]));
            floorItem->setText(1, "楼层");
            ui->treeWidget->addTopLevelItem(floorItem);
            floorItems.append(floorItem);
        }

        // 创建区域节点
        QTreeWidgetItem *areaItem = nullptr;
        bool areaFound = false;
        for (int i = 0; i < floorItem->childCount(); ++i)
        {
            if (floorItem->child(i)->text(0).toInt() == d.site[1])
            {
                areaItem = floorItem->child(i);
                areaFound = true;
                break;
            }
        }
        if (!areaFound) // 如果区域节点不存在，则创建
        {
            areaItem = new QTreeWidgetItem();
            areaItem->setText(0, QString::number(d.site[1]));
            areaItem->setText(1, "区域");
            floorItem->addChild(areaItem);
        }

        // 创建桌位节点
        QTreeWidgetItem *deskItem = new QTreeWidgetItem();
        deskItem->setText(0, QString::number(d.site[2]));
        deskItem->setText(1, "桌位");
        deskItem->setText(2, QString::number(d.site[2])); // 桌型（人数）
        deskItem->setText(3, QString::number(d.currentpeople)); // 该桌当前人数
        areaItem->addChild(deskItem);

        // 设置桌位人数输入框
        QSpinBox *box = new QSpinBox();
        box->setMinimum(d.currentpeople);
        box->setValue(d.size);
        ui->treeWidget->setItemWidget(deskItem, 2, box);
    }

    fclose(f1);

    updateItemNumbers(NULL); // 更新序号


}

deskwindow::~deskwindow()
{
    delete ui;
}

void deskwindow::on_pushButton_clicked()
{
}

//获取item是第几级（从0开始）
int deskwindow::getItemLevel(QTreeWidgetItem* item)
{
    int res=0;
    if(item==NULL)return res;
    while (item->parent() != NULL)
    {
        item = item->parent();
        res++;
    }
    return res;
}

void deskwindow::updateItemNumbers(QTreeWidgetItem *parent)
{
    int count = (parent ? parent->childCount() : ui->treeWidget->topLevelItemCount());
    for (int i = 0; i < count; i++)
    {
        QTreeWidgetItem *item = (parent ? parent->child(i) : ui->treeWidget->topLevelItem(i));
        item->setText(0, QString::number(i + 1));
    }
}

//添加子项
void deskwindow::on_addbutton_clicked()
{
    QTreeWidgetItem *selectedItem = ui->treeWidget->currentItem();
    QTreeWidgetItem *newItem = new QTreeWidgetItem();
    if (selectedItem)
    {
        switch(getItemLevel(selectedItem))
        {
            case 0:newItem->setText(1,"区域");selectedItem->addChild(newItem);break;
            case 2:QMessageBox::information(this,"提示","只能添加到三级（楼层、区域和桌号）。");return;
            case 1:newItem->setText(1,"桌位");newItem->setText(3, "0");selectedItem->addChild(newItem);QSpinBox *box=new QSpinBox();box->setMinimum(1);ui->treeWidget->setItemWidget(newItem,2,box);break;
        }
        ui->treeWidget->expandItem(selectedItem); //自动展开父节点
        updateItemNumbers(selectedItem);
    } else {
        newItem->setText(1,"楼层");
        ui->treeWidget->addTopLevelItem(newItem);
        updateItemNumbers(NULL);
    }
}


void deskwindow::on_addParallelbutton_clicked()
{
    QTreeWidgetItem *selectedItem = ui->treeWidget->currentItem();
    QTreeWidgetItem *newItem = new QTreeWidgetItem();
    if (selectedItem) {
        QTreeWidgetItem *parentItem = selectedItem->parent();
        if (parentItem)
        {
            int level = getItemLevel(selectedItem);
            switch (level) {
            case 1: newItem->setText(1, "区域");parentItem->addChild(newItem); break;
            case 2: newItem->setText(1, "桌位");newItem->setText(3, "0");parentItem->addChild(newItem);QSpinBox *box=new QSpinBox();box->setMinimum(1);ui->treeWidget->setItemWidget(newItem,2,box); break;
            }
            ui->treeWidget->expandItem(parentItem); // 自动展开父节点
            updateItemNumbers(parentItem);
        } else {
            newItem->setText(1, "楼层");ui->treeWidget->addTopLevelItem(newItem);
            updateItemNumbers(nullptr);
        }
    }
    else
    {
        newItem->setText(1, "楼层");
        ui->treeWidget->addTopLevelItem(newItem);
        updateItemNumbers(nullptr);
    }
}


void deskwindow::on_deletebutton_clicked()
{
    QTreeWidgetItem *selectedItem = ui->treeWidget->currentItem();
    if(selectedItem)
    {
        QTreeWidgetItem *parentItem = selectedItem->parent();
        if(parentItem)
        {
            if(getItemLevel(selectedItem)==2 && selectedItem->text(3).toInt()!=0)
            {
                QMessageBox::information(this,"提示","该桌位有人，不能删除。");
                return;
            }
            parentItem->removeChild(selectedItem);
        }
        else
        {
            int index = ui->treeWidget->indexOfTopLevelItem(selectedItem);
            if (index != -1) {
                ui->treeWidget->takeTopLevelItem(index);
            }
        }
        delete selectedItem;
    }
}

//保存并退出
void deskwindow::on_saveButton_clicked()
{
    //遍历树状图，将所有桌位信息存入desks数组中
    int alldeskscount=0;
    desk *desks=(desk*)malloc(sizeof(desk)*1);
    if(desks==NULL)
    {
        errorcatch(MEMORY_ERROR);
        return;
    }
    QTreeWidgetItemIterator iterator(ui->treeWidget);
    while(*iterator)
    {
        QTreeWidgetItem *item = *iterator;
        if(getItemLevel(item)==2 && item->parent()!=NULL && item->parent()->parent()!=NULL)
        {
            alldeskscount++;
            desks=(desk*)realloc(desks,sizeof(desk)*alldeskscount);
            desks[alldeskscount-1].site[0]=atoi(QStringToCharArray(item->parent()->parent()->text(0)));
            desks[alldeskscount-1].site[1]=atoi(QStringToCharArray(item->parent()->text(0)));
            desks[alldeskscount-1].site[2]=atoi(QStringToCharArray(item->text(0)));
            desks[alldeskscount-1].currentpeople=atoi(QStringToCharArray(item->text(3)));
            if(ui->treeWidget->itemWidget(item, 2)!=NULL)
            {
                desks[alldeskscount-1].size=qobject_cast<QSpinBox*>(ui->treeWidget->itemWidget(item, 2))->value();
            }
        }
        iterator++;
    }

    //存入本地文件
    FILE *f0=fopen(DESK_FILE_NAME,"w");fclose(f0);//先清空本地文件
    FILE *f1=fopen(DESK_FILE_NAME,"ab");
    for(int i=0;i<alldeskscount;i++)
    {
        fwrite(&desks[i],sizeof(desk),1,f1);
    }
    fclose(f1);

    free(desks);
    MainWindow *w=new MainWindow();
    w->show();
    this->close();
}


void deskwindow::on_seeDetailsButton_clicked()
{
}

