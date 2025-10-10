#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define MAXSIZE 100




typedef struct
{
	ElemType* elem;
	int length;
}SqList;

Status InitList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}

Status GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
int LocateELem(SqList L, ElemType e)
{
	int i = 0;
	for (i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
}

Status ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) return ERROR;
	if (L.length = MAXSIZE) return ERROR;
	for (int j = L.length; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
Status ListDelete(SqList& L, int i)
{
	if (i<1 || i>L.length) return ERROR;
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}

int main() {
	SqList L;
	if (InitList(L))
		cout << "顺序表成功建立\n";
	else
		cout << "顺序表建立失败\n";
	int arr[] = { 0,1,2,3,4,5 };
	for (int i = 0; i < 6; i++) {
		L.elem[i] = arr[i];
		L.length++;
	}
	ListDelete(L, 4);
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i] << "";
	}
	return 0;
}
