#include<stdio.h>
int main()
{

	int arr[10];
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &arr[i]);
	}
	for (int j = 0; j < 9; j++) {
		for (int k = 0; k < 9 - j;k++) {
			if (arr[k] > arr[k+1]) {
				int t = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = t;

			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	

		return 0;
}
