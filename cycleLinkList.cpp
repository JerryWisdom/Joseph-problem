#include "cycleLinkList.h"
#include <cstdio>
void InitList(cycleLinkList &L)
{
    L.head = L.tail = NULL;
}

bool ListEmpty(cycleLinkList &L)
{
    return !L.head;
}

void ClearList(cycleLinkList &L)
{
    if(!L.head)
    {
        LNode *p =L.head,*q;
        while(p != L.tail)
        {
            q = p->next;
            delete p;
            p =q;
        }
        delete L.tail;
        L.tail = L.head = NULL;
    }
}

void DestroyList(cycleLinkList &L)
{
    ClearList(L);
}

int ListLength(cycleLinkList L)
{
    if(!L.head) return 0;
    int k = 1;
    LNode *p = L.head;
    while(p != L.tail)
    {
        p = p->next;
        k++;
    }
    return k;
}

bool GetElem(cycleLinkList L,ElemType &e,int i)
{
    if(i<1||!L.head)
        return false;
    LNode *p = L.head;
    if(i == 1)
        e = p->data;
    else
    {
        p = p->next;
        int k = 2;
        while(p != L.head || k<i)
        {
            p = p->next;
            k++;
        }
        if(p == L.head)
            return false;
        e = p->data;
    }
}

bool ListInsert(cycleLinkList &L,int i,ElemType e)
{
    LNode *p,*s;
    if(i < 1)
        return false;
    if(i == 1)
    {
        s = new LNode;
        s->data = e;
        if(!L.head)
            L.head = L.tail = s;
        else
        {
            s->next = L.head;
            L.head = s;
        }
        L.tail->next = L.head;
    }
    else
    {
        p = L.head;
        int j = 1;
        while(p != L.head && j<i-1)
        {
            p = p->next;
            j++;
        }
        if(p = L.head)
            return false;
        else
        {
            s = new LNode;
            s->data = e;
            s->next = p->next;
            p->next = s;
        }
    }
    return true;
}

void ListAppend(cycleLinkList &L,ElemType e)
{
    struct LNode* s;
    s = new LNode;
    s->data = e;
    s->next = L.tail->next;
    L.tail->next = s;
    L.tail = s;
}

bool ListDelete(cycleLinkList &L,int i,ElemType e)
{
    LNode *p,*s;
    if(i<1 || !L.head)
        return false;
    if(i == 1)
    {
        s = L.head;
        e = s->data;
        if(L.head == L.tail)
            L.head = L.tail = NULL;
        else
            L.head = L.tail->next = L.head->next;
            delete s;
    }
    else
    {
        p = L.head;
        int j = 1;
        while(p!=L.tail && j<i-1)
        {
            p = p->next;
            j++;
        }
        if(p == L.tail)
            return false;
        else
        {
            s = p->next;
            p->next = s->next;
            e = s->data;
            if(L.tail == s)
                L.tail = p;
            delete s;
        }
    }
    return true;
}

int LocateElem(cycleLinkList &L,ElemType &e,bool (*compare)(ElemType &e1,ElemType &e2))
{
    if(!L.head)
        return 0;
    int k = 1;
    LNode *p = L.head;
    while(p!=L.tail && compare(p->data,e))
    {
        k++;
        p = p->next;
    }
    if(p != L.tail)
        return k;
    else if(compare(p->data,e))
        return k+1;
    else
        return 0;
}

void ListTraverse(cycleLinkList &L,void (*Visit)(ElemType &e))
{
    LNode *p = L.head;
    if(p)
    {
        while(p!=L.tail)
        {
            Visit(p->data);
            p = p->next;
        }
        Visit(p->data);
    }
}





