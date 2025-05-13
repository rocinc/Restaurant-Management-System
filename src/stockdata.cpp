#include "stockdata.h"

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

void deletenode(Node *list, Node* node, const int hashSize)
{
    for(int i=0;i<hashSize;i++)
    {
        if(&list[i]==node)
        {
            if(list[i].next!=NULL)
            {
                list[i]=*list[i].next;
            }else
            {
                list[i].val.isnull=1;
            }
            return;
        }
        if(list[i].val.isnull==0 && list[i].next!=NULL)//释放不是链表头的节点
        {
            Node *p1=&list[i];
            Node *p2=list[i].next;
            while(1)
            {
                if(p2->next==NULL)
                {
                    if(p2==node)
                    {
                        p1->next=NULL;
                        return;
                    }
                    break;
                }
                if(p2==node)
                {
                    p1->next = p2->next;
                    Node *tmp=p2;
                    p2=p2->next;
                    free(tmp);
                    return;
                }else
                {
                    p1=p1->next;
                    p2=p2->next;
                }
            }
        }
    }
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
    //记录总菜品数
    FILE *fcount=fopen(STOCK_COUNT_FILE_NAME,"wb");
    if(fcount==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    fwrite(&len,sizeof(int),1,fcount);
    if(ferror(fcount))
    {
        errorcatch(FILE_WRITE_ERROR);
        return 0;//失败时返回0
    }
    fclose(fcount);

    FILE *f0=fopen(filename,"w");fclose(f0);//先清空本地文件
    if(f0==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    for(int i=0;i<len;i++)
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

//检测用户输入字符串类型的字段时字符串是否超出既定的容量限制
int isOutOfTextLimit(char t[],int maxsize)//需要考虑用户输入中文、英文或数字等单个字符占字节数不同的情况
{
    int size = 0;
    for (int i=0;t[i]!='\0';i++)
    {
        if ((t[i] & 0x80) == 0)
        {
            size+=1;
        }
        else if ((t[i] & 0xE0) == 0xC0)
        {
            size+=2;
            i++;
        }
        else if ((t[i] & 0xF0) == 0xE0)
        {
            size+=3;
            i+=2;
        }
        else if ((t[i] & 0xF8) == 0xF0)
        {
            size+=4;
            i+=3;
        }
    }
    if(size>maxsize)return 1;
    return 0;
}

//将QString类型转换为熟悉的char数组
char* QStringToCharArray(QString s)
{
    QByteArray utf8String = s.toUtf8();
    char* charArray = new char[utf8String.size() + 1];
    memcpy(charArray, utf8String.data(), utf8String.size() + 1);
    return charArray;
}

int getCount()
{
    FILE *fcount=fopen(STOCK_COUNT_FILE_NAME,"rb");
    if(fcount==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return -1;
    }
    int res;
    fread(&res,sizeof(int),1,fcount);
    if(ferror(fcount))
    {
        errorcatch(FILE_WRITE_ERROR);
        fclose(fcount);
        return -1;
    }
    fclose(fcount);
    return res;
}
