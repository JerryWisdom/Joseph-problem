#include <iostream>
#include "cycleLinkList.h"
using namespace std;

bool Equal(ElemType &a,ElemType &b)
{
	if(a.location==b.location && a.password==b.password)
		return true;
	else
		return false;
}

void print(ElemType &e)
{
	cout<<"位置："<<e.location<<" 密码："<<e.password<<endl;
}

void ysfring(cycleLinkList &L,int n, int m)
{
	struct LNode *current = L.tail, *s;
	ElemType e;
	int k = n;
	while(n>0)
	{
		m = m % n;
		if(m == 0)  //当m整除n
            m = n;
		for(int j=1;j<m;j++)
			current = current->next;
		s = current->next;
		current->next = s->next;     //删除报到m的人
		cout<<endl<<"第"<<k-n+1<<"个出列的位置是"<<s->data.location;
		m = s->data.password;      //使新的m等于被删除结点的密码
		delete s;
		n--;        //循环链表中的总人数减1
	}
	L.head = L.tail = NULL;
}

int main(int argc, char const *argv[])
{
	cycleLinkList L;
	InitList(L);
	int m,n;
	ElemType e;
	cout<<"请输入人数：";
	cin>>n;
	cout<<endl<<"请输入第1个人的密码：";
	cin>>e.password;
	e.location = 1;
	ListInsert(L,1,e);
	for(int i=2;i<=n;i++)
	{
		cout<<"请输入第"<<i<<"个人的密码：";
		cin>>e.password;
		e.location = i;
		ListAppend(L,e);
	}
    cout<<endl<<"当前循环单链表中的元素依次为："<<endl;
	ListTraverse(L,print);

	cout<<endl<<"请输入初始密码：";
	cin>>m;
	ysfring(L,n,m);
	cout<<endl<<endl;
	return 0;
}



