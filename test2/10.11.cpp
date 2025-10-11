#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define MAXSIZE 100



typedef struct LNode
{
	ElemType data;
	struct LNode* next;

}LNode, * LinkList;
Status InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
Status GetElem(LinkList L, int i, ElemType& e)
{

	int j = 0;
	LinkList p = L->next; j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;

}
LNode* LocateElem(LinkList L, ElemType e)
{


	LinkList p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}
Status ListInsert(LinkList& L, int i, ElemType e)
{
	LinkList p = L; int j = 0;
	while (p && j < i)
		p = p->next; ++j;
	if (!p || j > i - 1) return ERROR;
	LinkList s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;

}
Status ListDelete(LinkList& L, int i)
{
	LinkList p = L; int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next; j++;
	}

	if (!(p->next) || (j > i - 1))return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
void CreateList_L(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; ++i) {
		LinkList p = new LNode;
		cin >> p->data;
		p->next = L->next; L->next = p;
	}


}


int main() {
	LinkList L;
	InitList(L);
	CreateList_L(L, 5);
	ListDelete(L, 3);
	for (LNode* p = L->next; p; p = p->next) {
		cout << p->data << " ";

	}
	return 0;
}
