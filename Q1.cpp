#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int a, b;
	int num = 0;
	int sum = 0;
	printf("a와 b를 입력하시오: ");
	scanf("%d %d", &a, &b);
	//printf("a와 b사이 소수들: \n");

	//2,3,5,7,11
	for (int i = a; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)num++;
		}
		if (num == 2)sum += i;
		num = 0;
	}
	
	
	
	/*for (int i = a; i <= b; i++) {
		for (int j = 2; j <= i ; j++) {
			if (i % j == 0)num++;
		}
		if (num < 3)sum += i;
		num = 0;
	}*/

	printf("\na와 b사이 소수들의 합: %d\n", sum);

	return 0;
}