#ifndef DATATEMPLATE_H
#define DATATEMPLATE_H
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QMessageBox>

/**
11.29周五 张永鹏
该文档起到模板的作用
由于每个大模块对应数据的类型及其属性不一致（例如菜品、餐桌、订单），所以用类型T代表，应用到大模块中时，直接更改T类型即可
打开每个大模块时将本地文件装载进一个哈希数组，关闭大模块时将哈希数组存入本地文件
用户在每个大模块的界面中操作时，只对哈希数组中的数据进行处理
哈希数组的每个元素是各链表的头结点。采用链地址法处理哈希冲突
链表的节点由next指针和T类型的数据字段val组成，T类型的各属性由每个大模块（菜品、餐桌……）各自在现实中的特性决定，该文档用int类型val代替
**/

#define MEMORY_ERROR 0
#define FILE_OPEN_ERROR 1
#define FILE_READ_ERROR 2
#define FILE_WRITE_ERROR 3
const int randommaxrange=10000;

void errorcatch(int i)
{
    switch(i)
    {
        case MEMORY_ERROR:
            QMessageBox::critical(nullptr, "错误", "内存分配出现错误。");
            break;
        case FILE_OPEN_ERROR:
            QMessageBox::critical(nullptr, "错误", "打开文件时出现错误。");
            break;
        case FILE_READ_ERROR:
            QMessageBox::critical(nullptr, "错误", "读取文件内容时出现错误。");
            break;
        case FILE_WRITE_ERROR:
            QMessageBox::critical(nullptr, "错误", "存储到文件内容中时出现错误。");
            break;
    }
}

typedef struct T
{
    int isnull;//必备，用来判断哈希数组某位置是否为空
    int val;//可依每个大模块的不同特性分别修改，这里用一个整型变量代替
}T;

typedef struct Node
{
    T val;
    struct Node *next;
}Node;

//初始化哈希数组
Node* initialize(const int len)
{
    Node* newnodelist=(Node*)malloc(sizeof(Node)*len);
    if(newnodelist==NULL && len!=0)
    {
        errorcatch(MEMORY_ERROR);
        return NULL;//失败时返回NULL
    }
    for(int i=0;i<len;i++)
    {
        newnodelist[i].next=NULL;
        newnodelist[i].val.isnull=1;//用来判断哈希数组某位置是否为空
    }
    return newnodelist;
}

int hash(int id,const int len)
{
    return id%len;
}

//向哈希数组添加新元素
int createnew(Node* list,T newitem,int id,const int len)
{
    //QMessageBox::information(nullptr,"hey!","hey");
    int index=hash(id,len);
    if(list[index].val.isnull)//不存在哈希冲突时直接将数据放入对应的位置
    {
        list[index].val=newitem;
    }else//存在哈希冲突时使用链地址法
    {
        Node* p=&list[index];
        while(p->next!=NULL)p=p->next;
        Node* newnode=(Node*)malloc(sizeof(Node));
        if(newnode==NULL)
        {
            errorcatch(MEMORY_ERROR);
            return 0;//失败时返回0
        }
        newnode->next=NULL;
        newnode->val=newitem;
        p->next=newnode;
    }
    return 1;
}

//释放哈希数组中每个链表节点所占内存
void dispose(Node *list,int len)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].val.isnull==0 && list[i].next!=NULL)//释放不是链表头的节点
        {
            Node *p1=&list[i];
            Node *p2=list[i].next;
            while(1)
            {
                if(p2->next==NULL)
                {
                    if(p1!=&list[i])
                    {
                        free(p1);
                    }
                    free(p2);
                    break;
                }
                Node *tmp=p1;
                p1=p1->next;
                if(tmp!=&list[i])free(tmp);
                p2=p2->next;
            }
        }
    }
    free(list);//释放存有链表头节点的哈希数组
}

//将存有各链表头结点的哈希数组遍历，把数据存入本地二进制文件
int saveall(Node* list,int len,char *filename)
{
    FILE *f0=fopen(filename,"w");fclose(f0);//先清空本地文件
    if(f0==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    for(int i=0;i<len;i++)
    {
        Node *p=&list[i];
        if(p->val.isnull==1){continue;}
        while(p->next!=NULL)
        {
            FILE *f1=fopen(filename,"ab");
            if(f1==NULL)
            {
                errorcatch(FILE_OPEN_ERROR);
                return 0;//失败时返回0
            }
            fwrite(&p->val,sizeof(T),1,f1);
            if(ferror(f1))
            {
                errorcatch(FILE_WRITE_ERROR);
                return 0;//失败时返回0
            }
            fclose(f1);
            p=p->next;
        }
        FILE *f2=fopen(filename,"ab");
        fwrite(&p->val,sizeof(T),1,f2);
        if(ferror(f2))
        {
            errorcatch(FILE_WRITE_ERROR);
            return 0;//失败时返回0
        }
        fclose(f2);
    }
    return 1;
}

int random(int max,int min)//取得到min，不能取得到max
{
    srand((unsigned)time(NULL));
    return rand()%max+min;
}

//将本地二进制文件读取到新生成的哈希数组中，返回这个数组（相当于数组第一个元素的地址）
Node* readall(int len,char *filename)
{
    Node *newlist=initialize(len);
    FILE *read=fopen(filename,"rb");
    if(read==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    while(1)
    {
        T newdata;
        fread(&newdata,sizeof(T),1,read);
        if(ferror(read))
        {
            errorcatch(FILE_READ_ERROR);
            return 0;//失败时返回0
        }
        if(feof(read))break;
        createnew(newlist,newdata,random(randommaxrange,0),len);
    }
    fclose(read);
    return newlist;
}


#endif // DATATEMPLATE_H
