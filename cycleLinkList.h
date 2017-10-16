#ifndef CYCLELINKLIST_H
#define CYCLELINKLIST_H

struct ElemType     //元素类型
{
	int location;
	int password;
};

struct LNode    //结点
{
    ElemType data;
    LNode *next;
};

struct cycleLinkList    //循环单链表
{
    struct LNode *head;
    struct LNode *tail;
};

void InitList(cycleLinkList &L);     //初始化链表
bool ListEmpty(cycleLinkList &L);    //判断为空
void ClearList(cycleLinkList &L);    //清空链表
void DestroyList(cycleLinkList &L);   //销毁链表
int ListLength(cycleLinkList L);       //计算链表长度
bool GetElem(cycleLinkList L,ElemType &e,int i);
bool ListInsert(cycleLinkList &L,int i,ElemType e);
void ListAppend(cycleLinkList &L,ElemType e);
bool ListDelete(cycleLinkList &L,int i,ElemType e);
int LocateElem(cycleLinkList &L,ElemType &e,bool (*compare)(ElemType &e1,ElemType &e2));
void ListTraverse(cycleLinkList &L,void (*Visit)(ElemType &e));


#endif // CYCLELINKLIST_H
