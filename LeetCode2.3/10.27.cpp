#include<iostream>
using namespace std;




//LeetCode2.3


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

int InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return 1;
}

int CreateList(LinkList& L, int n) {
	int i = 0;
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (i = 0; i < n; i++) {
		LinkList p = new LNode;
		p->next = NULL;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	return 1;
}

LinkList separate(LinkList& L, int x, int n) {
	LinkList r = L;
	LinkList pL = L;
	int i = 0;
	LinkList small = new LNode;
	LNode* ps = small;
	LinkList large = new LNode;
	LNode* pl = large;
	int j = 0;
	while (j < n) {
		r = r->next;
		if ((r->data) < x) {
			ps->next = r;
			ps = r;
		}
		else {
			pl->next = r;

			pl = r;

		}
		j++;
	}
	ps->next = large->next;
	pl->next = NULL;
	LinkList newL = small->next;
	return newL;
}void Display(LinkList L) {
	LinkList p = L;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	LinkList L;
	CreateList(L, 6);
	LinkList newL = separate(L, 3, 6);
	Display(newL);
}