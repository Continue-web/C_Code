#include<stdio.h>


//水仙花
// 
// 
// 
// 
//#include<math.h>
//int main() {
//	int uni = 0;
//	int tens = 0;
//	int hdds = 0;
//	int i = 0;
//	for (i = 100; i < 999; i++) {
//		uni = i % 10;
//		tens = i / 10 % 10;
//		hdds = i / 100;
//		/*if (i == uni * uni * uni + tens * tens * tens + hdds * hdds * hdds) {
//			printf("%d\n", i);
//		}*/
//
//		if ((int)(pow(uni, 3) + pow(tens, 3) + pow(hdds, 3)) == i) {
//			
//			
//			printf("%d\n", i);
//		}
//
//
//
//	}
//	return 0;
//}




//不同的三位数

int main() {
	int sum = 0;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			
				for (int k = 1; k < 5; k++) {
					if (i != j && j != k && i != k) {
						printf("%d,%d,%d\n", i, j, k);
						
						sum++;
					}
						
					
						
					
					
				}
			
			
		}
	}
	printf("\n有%d个互不相同且重复的三位数", sum);
	return 0;
}