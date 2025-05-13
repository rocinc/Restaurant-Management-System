#include "vipdata.h"
#include "stockdata.h"

//初始化哈希数组
vipNode* vipListInitialize(const int len)
{
    vipNode* newnodelist=(vipNode*)malloc(sizeof(vipNode)*len);
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

//向哈希数组添加新节点
int createnew(vipNode* list,vip newitem,int id,const int len)
{
    int index=hash(id,len);
    if(list[index].val.isnull)//不存在哈希冲突时直接将数据放入对应的位置
    {
        list[index].val=newitem;
    }else//存在哈希冲突时使用链地址法
    {
        vipNode* p=&list[index];
        while(p->next!=NULL)p=p->next;
        vipNode* newnode=(vipNode*)malloc(sizeof(vipNode));
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

//删除哈希数组中的节点
void deletenode(vipNode *list, vipNode* node, const int hashSize)
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
            vipNode *p1=&list[i];
            vipNode *p2=list[i].next;
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
                    vipNode *tmp=p2;
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
void dispose(vipNode *list,int len)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].val.isnull==0 && list[i].next!=NULL)//释放不是链表头的节点
        {
            vipNode *p1=&list[i];
            vipNode *p2=list[i].next;
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
                vipNode *tmp=p1;
                p1=p1->next;
                if(tmp!=&list[i])free(tmp);
                p2=p2->next;
            }
        }
    }
    free(list);//释放存有链表头节点的哈希数组
}

//将存有各链表头结点的哈希数组遍历，把数据存入本地二进制文件
int saveall(vipNode* list,int len,char *filename)
{
    FILE *f0=fopen(filename,"w");fclose(f0);//先清空本地文件
    if(f0==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    for(int i=0;i<len;i++)
    {
        vipNode *p=&list[i];
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
            fwrite(&p->val,sizeof(vip),1,f1);
            if(ferror(f1))
            {
                errorcatch(FILE_WRITE_ERROR);
                return 0;//失败时返回0
            }
            fclose(f1);
            p=p->next;
        }
        if(p->val.isnull){continue;}
        FILE *f2=fopen(filename,"ab");
        fwrite(&p->val,sizeof(vip),1,f2);
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
vipNode* readAllVip(int len,char *filename)
{
    vipNode *newlist=vipListInitialize(len);
    FILE *read=fopen(filename,"rb");
    if(read==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    while(1)
    {
        vip newdata;
        fread(&newdata,sizeof(vip),1,read);
        if(ferror(read))
        {
            errorcatch(FILE_READ_ERROR);
            return 0;//失败时返回0
        }
        if(feof(read))break;
        createnew(newlist,newdata,newdata.id,len);
    }
    fclose(read);
    return newlist;
}

//哈希查找
vipNode* seek(vipNode* list,int vipid)
{
    int index=hash(vipid,HASH_LEN);
    vipNode *p=&list[index];
    if(p->val.isnull){return NULL;}
    while(p->next!=NULL)
    {
        if(p->val.isnull)
        {
            p=p->next;
            continue;
        }
        if(p->val.id==vipid)return p;
        p=p->next;
    }
    //遍历act
    if(p->val.id==vipid)return p;
    return NULL;
}

char *dateToCharArray(date d)
{
    return QStringToCharArray(QString("%1 年 %2 月 %3 日").arg(d.year).arg(d.month).arg(d.day));
}

//从本地文件读取会员类型到一个动态数组
viptype* readAllVipType(char *filename,int *len)
{
    FILE *read=fopen(filename,"rb");
    int length=0;
    viptype *list;
    if(read==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    while(1)
    {
        viptype type;
        fread(&type,sizeof(viptype),1,read);
        if(feof(read))break;
        if(ferror(read))
        {
            errorcatch(FILE_READ_ERROR);
            return 0;//失败时返回0
        }
        if(length==0)
        {
            list=(viptype*)malloc(sizeof(viptype));
        }
        else
        {
            list=(viptype*)realloc(list,sizeof(viptype)*(length+1));
        }
        list[length]=type;
        length++;
    }
    fclose(read);
    *len=length;
    return list;
}

//将存储会员类型信息的动态数组存入本地文件
int saveAllVipType(int len,viptype* typelist,char *filename)
{
    FILE *write=fopen(filename,"wb");
    if(write==NULL)
    {
        errorcatch(FILE_OPEN_ERROR);
        return 0;//失败时返回0
    }
    for(int i=0;i<len;i++)
    {
        fwrite(&typelist[i],sizeof(viptype),1,write);
        if(ferror(write))
        {
            errorcatch(FILE_WRITE_ERROR);
            return 0;//失败时返回0
        }
    }
    fclose(write);
    return 1;
}
