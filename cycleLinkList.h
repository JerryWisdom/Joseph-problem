#ifndef CYCLELINKLIST_H
#define CYCLELINKLIST_H

struct ElemType     //Ԫ������
{
	int location;
	int password;
};

struct LNode    //���
{
    ElemType data;
    LNode *next;
};

struct cycleLinkList    //ѭ��������
{
    struct LNode *head;
    struct LNode *tail;
};

void InitList(cycleLinkList &L);     //��ʼ������
bool ListEmpty(cycleLinkList &L);    //�ж�Ϊ��
void ClearList(cycleLinkList &L);    //�������
void DestroyList(cycleLinkList &L);   //��������
int ListLength(cycleLinkList L);       //����������
bool GetElem(cycleLinkList L,ElemType &e,int i);
bool ListInsert(cycleLinkList &L,int i,ElemType e);
void ListAppend(cycleLinkList &L,ElemType e);
bool ListDelete(cycleLinkList &L,int i,ElemType e);
int LocateElem(cycleLinkList &L,ElemType &e,bool (*compare)(ElemType &e1,ElemType &e2));
void ListTraverse(cycleLinkList &L,void (*Visit)(ElemType &e));


#endif // CYCLELINKLIST_H
