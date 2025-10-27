#include<iostream>
using namespace std;



//LeetCode2.1;

//typedef struct LNode {
//	int data;
//	struct LNode* next;
//}LNode,*LinkList;
//
//int InitList(LinkList& L) {
//	L = new LNode;
//	L->next = NULL;
//	return 1;
//}
//
//void CreateList(LinkList& L, int n) {
//	LinkList p;
//	p = L->next;
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		cin >> p->data;
//		p = p->next;
//	}
//}
//
//void MergeList(LinkList& LA, LinkList& LB, LinkList& LC) {
//	LinkList pa = LA->next;
//	LinkList pb = LB->next;
//	LinkList pc;
//	LC = LA;
//	LinkList pc = LC;
//	while (pa && pb) {
//		if (pa < pb) {
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//
//		}
//		else {
//			pc->next = pb;
//			pc = pb;
//			pb = pb->next;
//		}
//	}
//	pc->next =pa ? pa : pb;
//	delete LB;
//
//}
//
//void Display(LinkList& L, int n) {
//	LinkList p = L -> next;
//	while (p != nullptr) {
//		for (int i = 0; i < n; i++) {
//			cout << p->data << " ";
//			p = p->next;
//		}
//	}
//}
//LinkList RemoveDuplicates(LinkList& L,int n) {
//	LinkList fast=L->next;
//	LinkList slow=L;
//
//	LinkList p = L->next;
//	/*int j = 0;
//	while (p != nullptr) {
//		for (int i = 0; i < n; i++) {
//			p = p->next;
//			++j;
//		}
//	}*/
//	while (n == 0) {
//		return 0;
//	}
//	while (fast !=nullptr) {
//		if ((fast->data) != (fast->next->data)) {
//			slow->next = fast;
//			slow = slow->next;
//		}
//		
//		fast = fast->next;
//	}
//
//	return slow;
//
//}
//int main() {
//		LinkList L;
//		CreateList(L, 5);
//		LinkList slow;
//		Display(slow);



//LeedCode2.2;



typedef struct LNode {
	int data;
	struct LNode*next;

}LNode,*LinkList;

int IntiList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return 0;
}

void CreateList(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = L;

	for (int i = 0; i < n; i++) {
		LinkList p=new LNode;
		cin >> p -> data;

		p->next = NULL;
		r->next = p;
		r = p;
	}
}
LinkList Ratote(LinkList& L, int k, int n) {
	int i = 0;
	LinkList p = L->next;
	if ((k == 0) &&(L=NULL )) {
		return L;
	}
	int sum = 0;
	sum = k % n;
	if (k % n == 0) {
		return L;
	}
	while (i < n - 1) {
		p = p->next;
		++i;
	}
	p->next = L->next;
	int out = n - k;
	while (out--) {
		p = p->next;
	}
	LinkList newL = new LNode;
	newL->next= p->next;
	p->next = NULL;
	return newL;
}


void Display(LinkList& L) {
	LNode* p = L->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
		
	}
}

int main() {
	LinkList L;
	CreateList(L, 5);
	LinkList newL = Ratote(L, 2, 5);
	Display(newL);
}


