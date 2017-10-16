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
	cout<<"λ�ã�"<<e.location<<" ���룺"<<e.password<<endl;
}

void ysfring(cycleLinkList &L,int n, int m)
{
	struct LNode *current = L.tail, *s;
	ElemType e;
	int k = n;
	while(n>0)
	{
		m = m % n;
		if(m == 0)  //��m����n
            m = n;
		for(int j=1;j<m;j++)
			current = current->next;
		s = current->next;
		current->next = s->next;     //ɾ������m����
		cout<<endl<<"��"<<k-n+1<<"�����е�λ����"<<s->data.location;
		m = s->data.password;      //ʹ�µ�m���ڱ�ɾ����������
		delete s;
		n--;        //ѭ�������е���������1
	}
	L.head = L.tail = NULL;
}

int main(int argc, char const *argv[])
{
	cycleLinkList L;
	InitList(L);
	int m,n;
	ElemType e;
	cout<<"������������";
	cin>>n;
	cout<<endl<<"�������1���˵����룺";
	cin>>e.password;
	e.location = 1;
	ListInsert(L,1,e);
	for(int i=2;i<=n;i++)
	{
		cout<<"�������"<<i<<"���˵����룺";
		cin>>e.password;
		e.location = i;
		ListAppend(L,e);
	}
    cout<<endl<<"��ǰѭ���������е�Ԫ������Ϊ��"<<endl;
	ListTraverse(L,print);

	cout<<endl<<"�������ʼ���룺";
	cin>>m;
	ysfring(L,n,m);
	cout<<endl<<endl;
	return 0;
}



