#include<iostream>
using namespace std;
#define OK  1;
#define ERROR 0;
#define OVERFLOW -2;

#define MAXSIZE 100

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


int InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}


//int GetElem(LinkList L, int i, int& e) {
//	LNode* p = L->next;
//	int j = 1;
//	while (p && j < i) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)
//		return ERROR;
//	e = p->data;
//	return OK;
//}

void CreateList(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;

	LinkList r = L;

	for (int i = 0; i < n; i++) {
		LinkList p = new LNode;
		cin >> p->data;

		r->next = p;
		p->next = NULL;
		r = p;
	}


	
}




void Permuta(LinkList& L, int n) {
	int i = 0;
	int j = 0;
	LNode* q = L->next;
	LNode* p = L->next->next;
	for (i = 1; i < n; i++) {
		
		while (p != nullptr) {
			if ((p->data < q->data)) {
				int sum = 0;
				sum = p->data;
				p->data = q->data;
				q->data = sum;
			}
			else if (p->data == q->data) {
				LNode* d = p;
				p = p->next;
				q->next = p;
				delete d;
			}
			p = p->next;
			q = q->next;
		}
			


	}
}




	void MergeList(LinkList & LA, LinkList & LB, LinkList & LC) {
		LinkList pa = LA->next;
		LinkList pb = LB->next;
		LC = LA;
		LinkList pc = LC;
		while (pa && pb) {
			if (pa->data <= pb->data) {
				pc->next = pa;
				pc = pa;
				pa = pa->next;

			}
			else {
				pc->next = pb;
				pc = pb;
				pb = pb->next;
			}
		}
		pc->next = pa ? pa : pb;
		delete LB;


	}



void Display(LinkList& L) {
	LNode* p = L->next;
	while(p!=nullptr){
		cout << p->data <<' ';
		p = p -> next;
	}
}



int main() {
	LNode* La;
	LNode* Lb;
	LNode* Lc;
	cout << "创造一个4个元素的表" << endl;
	CreateList(La, 4);
	cout << "创造一个5个元素的表" << endl;
	CreateList(Lb, 5);
	MergeList(La, Lb,Lc);
	Permuta(Lc, 9);
	cout << "表Lc内容是:" << endl;
	Display(Lc);
	
}

