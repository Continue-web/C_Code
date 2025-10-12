#include<iostream>
using namespace std;
#define N 10
void sub(int b[]) {
	int i, j, temp, m;
	m = N / 2;
	for (i = 0; i < m; i++) {
		j = N - 1 - i;
		temp = b[i];
		b[i] = b[j];
		b[j] = temp;
		
	}
}
int main() {
	int a[10], i;
	for (i = 0; i < N; i++)
		cin >> a[i];
	sub(a);
	for (i = 0; i < N; i++)
		cout << a[i] <<" ";
	return 0;
}