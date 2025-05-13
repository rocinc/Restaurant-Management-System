#ifndef STOCKDATA_H
#define STOCKDATA_H
#include <ctime>
#include <qabstractitemmodel.h>
#include <qplaintextedit.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QMessageBox>

/**
处理菜品及库存
打开每个大模块时将本地文件装载进一个哈希数组，关闭大模块时将哈希数组存入本地文件
用户在每个大模块的界面中操作时，只对哈希数组中的数据进行处理
哈希数组的每个元素是各链表的头结点。采用链地址法处理哈希冲突
**/
#define HASH_LEN 1000

#define MEMORY_ERROR 0
#define FILE_OPEN_ERROR 1
#define FILE_READ_ERROR 2
#define FILE_WRITE_ERROR 3

#define MAX_TASTE_LEN 30
#define MAX_NAME_LEN 60
#define MAX_OTHER_TIP_LEN 300
#define MAX_STOCK_MEASURE_LEN 16
#define MAX_TASTES_COUNT 50

#define UP_SORT 0
#define DOWN_SORT 1
#define SORT_BY_PRICE 0
#define SORT_BY_STOCK 1

#define STOCK_FILE_NAME "stockdata.bat"
#define ORDER_FILE_NAME "orderdata.bat"
#define ORFER_HISTORY_FILE_NAMEA "orderhistorydata.bat"
#define DESK_FILE_NAME "deskdata.bat"
#define STOCK_COUNT_FILE_NAME "stockcount.bat"

const int randommaxrange=10000;

void errorcatch(int i);

typedef struct T
{
    int isnull;//必备，用来判断哈希数组某位置是否为空
    char name[MAX_NAME_LEN];
    double price;
    int tastescount;
    char tastes[MAX_TASTES_COUNT][MAX_TASTE_LEN];
    char othertip[MAX_OTHER_TIP_LEN];
    double stock;
    char stockmeasureunit[MAX_STOCK_MEASURE_LEN];
}T;

typedef struct Node
{
    T val;
    struct Node *next;
}Node;

//初始化哈希数组
Node* initialize(const int len);

int hash(int id,const int len);

//向哈希数组添加新元素
int createnew(Node* list,T newitem,int id,const int len);

//释放哈希数组中每个链表节点所占内存
void dispose(Node *list,int len);

//将存有各链表头结点的哈希数组遍历，把数据存入本地二进制文件
int saveall(Node* list,int len,char *filename);

int random(int max,int min);//取得到min，不能取得到max

//将本地二进制文件读取到新生成的哈希数组中，返回这个数组（相当于数组第一个元素的地址）
Node* readall(int len,char *filename);

//检测用户输入字符串类型的字段时字符串是否超出既定的容量限制
int isOutOfTextLimit(char t[],int maxsize);

//将QString类型转换为熟悉的char数组
char* QStringToCharArray(QString s);

//得到总菜品数
int getCount();

Node** getStockList(int *hashlen);

class CustomPlainTextEdit : public QPlainTextEdit {
    Q_OBJECT

public:
    explicit CustomPlainTextEdit(QWidget *parent = nullptr) : QPlainTextEdit(parent) {}

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        {
            return;
        }
        QPlainTextEdit::keyPressEvent(event);
    }
};

#endif // STOCKDATA_H
