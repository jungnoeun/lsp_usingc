#pragma warning (disable :4996)
#include <stdio.h>

/*2020년 12월 31일은 목요일이다. 
2021년의 하루를 월과 일을 나타내는 두개의 정수로 입력받은 후, 
해당일이 무슨 요일인지 출력하시오. */

int main() {
	int mon, day;
	int total = 0;
	int res;
	printf("2021년의 월과 일을 입력하세요: ");
	scanf("%d %d", &mon, &day);

	//1,3,5,7,8,10,12 ->31
	//2 ->28
	//4,6,9,11 ->30
	//이 날들을 모두 더해서 7로 나눠야 함

	for (int i = 0; i < mon; i++) {
		if (i == 0)
			total += day;
		else {
			if (i == 2)
				total += 28;
			else {
				if (i == 4 || i == 6 || i == 9 || i == 11)
					total += 30;
				else
					total += 31;
			}
		}
			
	}

	//해당월까지의 totalday를 구하고 7로 나누어서 몇요일인지 출력
	res = total % 7;
	
	if(res == 0)
		printf("%d월 %d일은 목요일이다.\n", mon, day);
	else {
		if(res ==1)
			printf("%d월 %d일은 금요일이다.\n", mon, day);
		else {
			if(res ==2)
				printf("%d월 %d일은 토요일이다.\n", mon, day);
			else {
				if(res ==3)
					printf("%d월 %d일은 일요일이다.\n", mon, day);
				else {
					if(res ==4)
						printf("%d월 %d일은 월요일이다.\n", mon, day);
					else {
						if(res ==5)
							printf("%d월 %d일은 화요일이다.\n", mon, day);
						else printf("%d월 %d일은 수요일이다.\n", mon, day);
					}
				}
			}
		}
	}
		




	/*switch (res) {
	case 1:
		printf("%d월 %d일은 금요일이다.\n",mon,day);
		break;
	case 2:
		printf("%d월 %d일은 토요일이다.\n", mon, day);
		break;
	case 3:
		printf("%d월 %d일은 일요일이다.\n", mon, day);
		break;
	case 4:
		printf("%d월 %d일은 월요일이다.\n", mon, day);
		break;
	case 5:
		printf("%d월 %d일은 화요일이다.\n", mon, day);
		break;
	case 6:
		printf("%d월 %d일은 수요일이다.\n", mon, day);
		break;
	case 0:
		printf("%d월 %d일은 목요일이다.\n", mon, day);
		break;
	}*/

	return 0;
}

