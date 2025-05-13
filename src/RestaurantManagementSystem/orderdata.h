#ifndef ORDERDATA_H
#define ORDERDATA_H

#include "stockdata.h"//一方面由于需要和菜品信息联动，所以这里包含菜品相关数据处理；另一方面，该头文件包QStringToCharArray、isOutOfTextLimit等各模块都常用的自定义函数
#include <qobject.h>
#include <qplaintextedit.h>

//每个菜品的状态
#define NOT_START_PREPARE 0
#define PREPARING 1
#define PREPARED_TO_DELIVER 2
#define DELIVERED 3
#define NONE -1

//订单状态
#define WAITING 0
#define EATING 1
#define FINISHED 2

#define MAX_DISHES_COUNT 50

#define MAX_RANDOM_ORDER_ID 10000//用于控制生成的订单号中随机部分的范围

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
    int size;//固定的人数型号
}desk;

//每个菜品与其口味、状态之间一一对应
typedef struct pair
{
    T dish;
    int tasteindex;//订单对应口味在dish.tastes数组中的索引
    int count;//点几份
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
    int countpeople;
}order;

typedef struct orderNode
{
    order val;
    struct orderNode *next;
}orderNode;

//把自定义的日期-时间 格式化输出
char* dateTimeToCharArray(datetime t);

//下列函数与stockdata.h(stockdata.cpp)中各函数的区别是，下列函数处理订单信息，stockdata.h(stockdata.cpp)中的函数处理菜品信息。两者在数据类型上有区别

//初始化哈希数组
orderNode* orderListInitialize(const int len);

//向哈希数组添加新元素
int createnew(orderNode* list,order newitem,int id,const int len);

//释放哈希数组中每个链表节点所占内存
void dispose(orderNode *list,int len);

//将存有各链表头结点的哈希数组遍历，把数据存入本地二进制文件
int saveall(orderNode* list,int len,char *filename);

//将本地二进制文件读取到新生成的哈希数组中，返回这个数组（相当于数组第一个元素的地址）
orderNode* readAllOrder(int len,char *filename);

orderNode* getOrderList(int *hashlen);

pair *getDishesList(int *arraylen);

#endif // ORDERDATA_H
