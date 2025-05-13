#include "orderdata.h"

//把自定义的日期-时间 格式化输出
char* dateTimeToCharArray(datetime t)
{
    char year[5];
    char month[3];
    char day[3];
    char hour[3]="";
    char minute[3]="";
    char second[3]="";
    itoa(t.year,year,10);
    itoa(t.month,month,10);
    itoa(t.day,day,10);

    if(t.hour<10)strcat(hour,"0");
    char hour2[3];
    itoa(t.hour,hour2,10);
    strcat(hour,hour2);

    if(t.minute<10)strcat(minute,"0");
    char minute2[3];
    itoa(t.minute,minute2,10);
    strcat(minute,minute2);

    if(t.second<10)strcat(second,"0");
    char second2[3];
    itoa(t.second,second2,10);
    strcat(second,second2);

    QString res=QString("%1年%2月%3日 %4:%5:%6").arg(year).arg(month).arg(day).arg(hour).arg(minute).arg(second);
    return QStringToCharArray(res);
}

//下列函数与stockdata.h(stockdata.cpp)中各函数的区别是，下列函数处理订单信息，stockdata.h(stockdata.cpp)中的函数处理菜品信息。两者在数据类型上有区别

//初始化哈希数组
orderNode* orderListInitialize(const int len)
{
    orderNode* newnodelist=(orderNode*)malloc(sizeof(orderNode)*len);
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

//向哈希数组添加新元素
int createnew(orderNode* list, order newitem, int id, const int len)
{
    int index=hash(id,len);
    if(list[index].val.isnull)//不存在哈希冲突时直接将数据放入对应的位置
    {
        list[index].val=newitem;
    }else//存在哈希冲突时使用链地址法
    {
        orderNode* p=&list[index];
        while(p->next!=NULL)p=p->next;
        orderNode* newnode=(orderNode*)malloc(sizeof(orderNode));
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
void dispose(orderNode *list,int len)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].val.isnull==0 && list[i].next!=NULL)//释放不是链表头的节点
        {
            orderNode *p1=&list[i];
            orderNode *p2=list[i].next;
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
                orderNode *tmp=p1;
                p1=p1->next;
                if(tmp!=&list[i])free(tmp);
                p2=p2->next;
            }
        }
    }
    free(list);//释放存有链表头节点的哈希数组
}

//将存有各链表头结点的哈希数组遍历，把数据存入本地二进制文件
int saveall(orderNode* list,int len,char *filename)
{
    FILE *f0=fopen(filename,"w");fclose(f0);//先清空本地文件
    if(f0==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    for(int i=0;i<len;i++)
    {
        orderNode *p=&list[i];
        if(p->val.isnull){continue;}
        while(p->next!=NULL)
        {
            if(p->val.isnull)
            {
                p=p->next;
                continue;
            }
            FILE *f1=fopen(filename,"ab");
            if(f1==NULL)
            {
                errorcatch(FILE_OPEN_ERROR);
                return 0;//失败时返回0
            }
            fwrite(&p->val,sizeof(order),1,f1);
            if(ferror(f1))
            {
                errorcatch(FILE_WRITE_ERROR);
                return 0;//失败时返回0
            }
            fclose(f1);
            p=p->next;
        }
        FILE *f2=fopen(filename,"ab");
        fwrite(&p->val,sizeof(order),1,f2);
        if(ferror(f2))
        {
            errorcatch(FILE_WRITE_ERROR);
            return 0;//失败时返回0
        }
        fclose(f2);
    }
    return 1;
}

//将本地二进制文件读取到新生成的哈希数组中，返回这个数组（相当于数组第一个元素的地址）
orderNode* readAllOrder(int len,char *filename)
{
    orderNode *newlist=orderListInitialize(len);
    FILE *read=fopen(filename,"rb");
    if(read==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    while(1)
    {
        order newdata;
        fread(&newdata,sizeof(order),1,read);
        if(ferror(read))
        {
            errorcatch(FILE_READ_ERROR);
            return 0;//失败时返回0
        }
        if(feof(read))break;
        createnew(newlist,newdata,newdata.orderid,len);
    }
    fclose(read);
    return newlist;
}
