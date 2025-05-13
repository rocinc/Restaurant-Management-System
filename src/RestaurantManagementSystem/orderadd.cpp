#include "orderadd.h"
#include "orderaddtaste.h"
#include "orderdata.h"
#include "stockdata.h"
#include "ui_orderadd.h"
#include <qtimer.h>
#include <time.h>

int site[3];
pair pairs[MAX_DISHES_COUNT];
int paircount;

// 读取桌子文件并返回存在区域并且区域中包含桌子的楼层数组
int* readFloorsWithDesks(const char* fileName, int* outCount) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        *outCount = 0;
        return NULL;
    }
    // 确定文件中的desk结构体数量
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    int deskCount = fileSize / sizeof(desk);

    // 读取所有desk信息
    desk* desks = (desk*)malloc(deskCount * sizeof(desk));
    fread(desks, sizeof(desk), deskCount, file);
    fclose(file);

    // 找出所有不同的楼层
    int* floors = (int*)malloc(deskCount * sizeof(int));
    int floorCount = 0;
    for (int i = 0; i < deskCount; ++i) {
        bool found = false;
        for (int j = 0; j < floorCount; ++j) {
            if (floors[j] == desks[i].site[0]) {
                found = true;
                break;
            }
        }
        if (!found) {
            floors[floorCount++] = desks[i].site[0];
        }
    }
    // 释放desks内存
    free(desks);

    *outCount = floorCount;
    return floors;
}

// 读取桌子文件并返回存在桌子的区域数组
int* orderadd::readAreasWithDesks(const char* fileName, int floor, int* outCount)
{
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        *outCount = 0;
        return NULL;
    }

    // 读取所有desk信息
    desk deskInfo;
    int areaCount = 0;
    int *areas = NULL;
    while (fread(&deskInfo, sizeof(desk), 1, file) == 1) {
        if (deskInfo.site[0] == floor && deskInfo.site[1] != 0) {
            int found = 0;
            for (int i = 0; i < areaCount; ++i) {
                if (areas[i] == deskInfo.site[1]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                int *temp = (int *)realloc(areas, (areaCount + 1) * sizeof(int));
                if (!temp) {
                    free(areas);
                    fclose(file);
                    *outCount = 0;
                    return NULL;
                }
                areas = temp;
                areas[areaCount++] = deskInfo.site[1];
            }
        }
    }
    fclose(file);

    *outCount = areaCount;
    return areas;
}

// 读取桌子文件并返回特定区域的桌子数据
int* orderadd::readDesksWithArea(const char* fileName, int floor, int area, int* outCount)
{
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        *outCount = 0;
        return NULL;
    }

    desk deskInfo;
    int deskCount = 0;
    int *desks = NULL;
    while (fread(&deskInfo, sizeof(desk), 1, file) == 1) {
        if (deskInfo.site[0] == floor && deskInfo.site[1] == area) {
            int found = 0;
            for (int i = 0; i < deskCount; ++i) {
                if (desks[i] == deskInfo.site[2]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                int *temp = (int *)realloc(desks, (deskCount + 1) * sizeof(int));
                if (!temp) {
                    free(desks);
                    fclose(file);
                    *outCount = 0;
                    return NULL;
                }
                desks = temp;
                desks[deskCount++] = deskInfo.site[2];
            }
        }
    }
    fclose(file);

    *outCount = deskCount;
    return desks;
}

orderadd::orderadd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::orderadd),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    paircount=0;
    connect(timer, &QTimer::timeout, this, &orderadd::updateTimer);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //生成订单号并把它显示在文本框中
    //生成的原理结合了时间戳和随机数
    //为了保证生成结果在int范围内，需要把生成结果字符串转换为long long后对INT_MAX取余，再转换为字符串后才能显示在文本框中
    std::time_t now = std::time(nullptr);
    char timestamp[15];
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", std::localtime(&now));
    int randomNum = random(MAX_RANDOM_ORDER_ID, 0);
    char orderNumberStr[20];
    sprintf(orderNumberStr, "%s%04d", timestamp, randomNum);
    long long orderNumber = atoll(orderNumberStr);
    if (orderNumber > INT_MAX) {
        orderNumber = orderNumber % INT_MAX;
    }
    char resid[20];
    itoa(static_cast<int>(orderNumber),resid,10);
    ui->idlabel->setText(resid);

    // 将楼层添加到各QComboBox中
    int floorCount = 0;
    int* floors = readFloorsWithDesks(DESK_FILE_NAME, &floorCount);
    if (floors == NULL)
    {
        QMessageBox::information(this, "提示", "读取楼层信息时失败。");
        return;
    }
    for (int i = 0; i < floorCount; ++i) {
        ui->floorTextBox->addItem(QString::number(floors[i]), floors[i]);
    }
    free(floors);
    connect(ui->floorTextBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_floorTextBox_currentIndexChanged(int)));
    connect(ui->areaTextBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_areaTextBox_currentIndexChanged(int)));
    connect(ui->deskTextBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_deskTextBox_currentIndexChanged(int)));
}

void orderadd::on_floorTextBox_currentIndexChanged(int index){
    ui->areaTextBox->clear();
    ui->deskTextBox->clear();

    int floor = ui->floorTextBox->itemData(index).toInt();
    int areaCount = 0;
    int* areas = readAreasWithDesks(DESK_FILE_NAME, floor, &areaCount);
    if(areas == NULL)
    {
        QMessageBox::information(this, "提示", "读取区域信息时失败。");
        close();
        return;
    }
    for (int i = 0; i < areaCount; ++i) {
        ui->areaTextBox->addItem(QString::number(areas[i]), areas[i]);
    }
    free(areas);

    if (ui->areaTextBox->count() > 0) {
        ui->areaTextBox->setCurrentIndex(0);
    }
}

void orderadd::on_areaTextBox_currentIndexChanged(int index)
{
    if(index < 0 || index >= ui->areaTextBox->count()) {
        return;
    }
    ui->deskTextBox->clear();

    int floor = ui->floorTextBox->currentText().toInt();
    int area = ui->areaTextBox->itemData(index).toInt();
    int deskCount = 0;
    int* desks = readDesksWithArea(DESK_FILE_NAME, floor, area, &deskCount);
    if (desks == NULL)
    {
        return;
    }

    // 读取所有桌位信息，包括桌型
    desk* deskInfoArray = (desk*)malloc(deskCount * sizeof(desk));
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
        ui->deskTextBox->addItem(deskItemText, deskInfoArray[i].site[2]);
    }
    free(desks);
    free(deskInfoArray);

    // 设置桌位ComboBox的第一个索引为当前索引
    if (ui->deskTextBox->count() > 0) {
        ui->deskTextBox->setCurrentIndex(0);
    }
}

//根据桌型设置订餐的人数上限
void orderadd::on_deskTextBox_currentIndexChanged(int index)
{
    int floor = ui->floorTextBox->currentText().toInt();
    int area = ui->areaTextBox->currentText().toInt();
    int deskId = ui->deskTextBox->itemData(index).toInt();
    desk deskInfo;
    FILE* file = fopen(DESK_FILE_NAME, "rb");
    if (!file)
    {
        QMessageBox::information(this, "提示", "无法打开桌位文件。");
        close();
        return;
    }
    while(fread(&deskInfo, sizeof(desk), 1, file) == 1)
    {
        if(deskInfo.site[0] == floor && deskInfo.site[1] == area && deskInfo.site[2] == deskId)
        {
            int size = deskInfo.size-deskInfo.currentpeople;
            fclose(file);
            ui->countpeopleSpinBox->setMaximum(size);
            return;
        }
    }
    fclose(file);
    site[0]=floor;
    site[1]=area;
    site[2]=deskId;
}

orderadd::~orderadd()
{
    delete ui;
}

void orderadd::startTimer(int interval)
{
    timer->start(interval);
}

void orderadd::updateTimer(){
    if(ui->deskTextBox->count()<=0)
    {
        QMessageBox::information(this,"提示","没有空闲桌。");
        close();
    }
    if(paircount==0 || ui->countpeopleSpinBox->value()==0)
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
    }else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
    }
}

void orderadd::handleCloseWindow()
{
    this->close();
}

void orderadd::closeEvent(QCloseEvent *event)
{
    timer->stop();
    QDialog::closeEvent(event);
}

void orderadd::on_buttonBox_rejected()
{
    timer->stop();
    reject();
}


void orderadd::on_buttonBox_accepted()
{
    FILE *examdesks=fopen(DESK_FILE_NAME,"rb+");
    int x=ui->floorTextBox->itemData(ui->floorTextBox->currentIndex()).toInt(),
        y=ui->areaTextBox->itemData(ui->areaTextBox->currentIndex()).toInt(),
        z=ui->deskTextBox->itemData(ui->deskTextBox->currentIndex()).toInt();
    desk d;
    while(1)
    {
        fread(&d,sizeof(desk),1,examdesks);
        qDebug()<<x<<y<<z;
        if(d.site[0]==x && d.site[1]==y && d.site[2]==z)
        {
            break;
        }
    }
    d.currentpeople+=ui->countpeopleSpinBox->value();
    fseek(examdesks, -sizeof(desk), SEEK_CUR);
    fwrite(&d,sizeof(desk),1,examdesks);
    fclose(examdesks);

    int ordercount;
    orderNode* ordernodes = getOrderList(&ordercount);
    order neworder;
    neworder.isnull=0;
    neworder.orderid=atoi(QStringToCharArray(ui->idlabel->text()));
    neworder.countpeople=ui->countpeopleSpinBox->value();
    neworder.desksite[0]= x;
    neworder.desksite[1]= y;
    neworder.desksite[2]= z;
    neworder.dishescount=ui->tableWidget->rowCount();
    neworder.orderstatus=WAITING;
    for(int i=0;i<paircount;i++)
    {
        neworder.dishes[i]=pairs[i];
    }
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    neworder.createtime.year = local_time->tm_year + 1900;
    neworder.createtime.month = local_time->tm_mon + 1;
    neworder.createtime.day = local_time->tm_mday;
    neworder.createtime.hour = local_time->tm_hour;
    neworder.createtime.minute = local_time->tm_min;
    neworder.createtime.second = local_time->tm_sec;
    createnew(ordernodes,neworder,neworder.orderid,HASH_LEN);
    timer->stop();
    emit windowClosed();
}

void orderadd::addRow(char *name, char *taste, int count)
{
    int rowPosition = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowPosition);
    QTableWidgetItem *dishItem = new QTableWidgetItem(name);
    QTableWidgetItem *tasteItem = new QTableWidgetItem(taste);
    QTableWidgetItem *countItem = new QTableWidgetItem(QString::number(count));
    ui->tableWidget->setItem(rowPosition, 0, dishItem);
    ui->tableWidget->setItem(rowPosition, 1, tasteItem);
    ui->tableWidget->setItem(rowPosition, 2, countItem);
}

void orderadd::freshdishes()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"菜名", "口味", "份数"});
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<paircount;i++)
    {
        addRow(pairs[i].dish.name,pairs[i].dish.tastes[pairs[i].tasteindex],pairs[i].count);
    }
}

void orderadd::newdish()
{
    paircount++;
    freshdishes();
}

void orderadd::on_addButton_clicked()
{
    if(paircount<50)
    {
    orderaddtaste *w=new orderaddtaste();
    connect(w, &::orderaddtaste::AddWindowClosed, this, &orderadd::newdish);
    w->show();
    w->startTimer();
    }else
    {
        QMessageBox::information(this,"提示","最多只能添加到50个菜。");
    }
}

pair* getDishesList(int *arraylen)
{
    *arraylen=paircount;
    return pairs;
}


void orderadd::on_deleteButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow == -1)
    {
        QMessageBox::information(this, "提示", "应选择一行再删除。");
    }
    else
    {
        std::move(pairs + currentRow + 1, pairs + MAX_DISHES_COUNT, pairs + currentRow);
        paircount--;
        freshdishes();
    }
}

