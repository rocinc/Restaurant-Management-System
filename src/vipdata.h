#ifndef VIPDATA_H
#define VIPDATA_H

#define VIP_FILE_NAME "vipdata.bat"
#define VIP_TYPE_FILE_NAME "viptypedata.bat"

#define MAX_VIPTYPE_NAME_LEN 36
#define MAX_VIP_NAME_LEN 30
#define MAX_PREFER_LEN 100

#define HASH_LEN 1000

#define MAX_RANDOM_VIP_ID 10000

typedef struct viptype
{
    char name[MAX_VIPTYPE_NAME_LEN];
    double discount;
}viptype;

typedef struct date
{
    int year;
    int month;
    int day;
}date;

typedef struct vip
{
    int isnull;
    int id;
    date create;
    date outdated;
    char name[MAX_VIP_NAME_LEN];
    int phonenumber;
    double paidsum;
    int paidcount;
    viptype type;
    char preference[MAX_PREFER_LEN];
}vip;

typedef struct vipNode
{
    vip val;
    struct vipNode* next;
}vipNode;

//初始化哈希数组
vipNode* vipListInitialize(const int len);

//向哈希数组添加新节点
int createnew(vipNode* list,vip newitem,int id,const int len);

//删除哈希数组中的节点
void deletenode(vipNode *list, vipNode* node, const int hashSize);

//释放哈希数组中每个链表节点所占内存
void dispose(vipNode *list,int len);

//将存有各链表头结点的哈希数组遍历，把数据存入本地二进制文件
int saveall(vipNode* list,int len,char *filename);

//将本地二进制文件读取到新生成的哈希数组中，返回这个数组（相当于数组第一个元素的地址）
vipNode* readAllVip(int len,char *filename);

vipNode* getVipList(int *hashlen);
viptype** getVipTypeList(int *arraylen);

//哈希查找
vipNode* seek(vipNode* list,int orderid);

char *dateToCharArray(date d);

//从本地文件读取会员类型到一个动态数组
viptype* readAllVipType(char *filename,int *len);

//将存储会员类型信息的动态数组存入本地文件
int saveAllVipType(int len,viptype* typelist,char *filename);

#endif // VIPDATA_H
