#pragma warning (disable :4996)
#include <stdio.h>

/*2020�� 12�� 31���� ������̴�. 
2021���� �Ϸ縦 ���� ���� ��Ÿ���� �ΰ��� ������ �Է¹��� ��, 
�ش����� ���� �������� ����Ͻÿ�. */

int main() {
	int mon, day;
	int total = 0;
	int res;
	printf("2021���� ���� ���� �Է��ϼ���: ");
	scanf("%d %d", &mon, &day);

	//1,3,5,7,8,10,12 ->31
	//2 ->28
	//4,6,9,11 ->30
	//�� ������ ��� ���ؼ� 7�� ������ ��

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

	//�ش�������� totalday�� ���ϰ� 7�� ����� ��������� ���
	res = total % 7;
	
	if(res == 0)
		printf("%d�� %d���� ������̴�.\n", mon, day);
	else {
		if(res ==1)
			printf("%d�� %d���� �ݿ����̴�.\n", mon, day);
		else {
			if(res ==2)
				printf("%d�� %d���� ������̴�.\n", mon, day);
			else {
				if(res ==3)
					printf("%d�� %d���� �Ͽ����̴�.\n", mon, day);
				else {
					if(res ==4)
						printf("%d�� %d���� �������̴�.\n", mon, day);
					else {
						if(res ==5)
							printf("%d�� %d���� ȭ�����̴�.\n", mon, day);
						else printf("%d�� %d���� �������̴�.\n", mon, day);
					}
				}
			}
		}
	}
		




	/*switch (res) {
	case 1:
		printf("%d�� %d���� �ݿ����̴�.\n",mon,day);
		break;
	case 2:
		printf("%d�� %d���� ������̴�.\n", mon, day);
		break;
	case 3:
		printf("%d�� %d���� �Ͽ����̴�.\n", mon, day);
		break;
	case 4:
		printf("%d�� %d���� �������̴�.\n", mon, day);
		break;
	case 5:
		printf("%d�� %d���� ȭ�����̴�.\n", mon, day);
		break;
	case 6:
		printf("%d�� %d���� �������̴�.\n", mon, day);
		break;
	case 0:
		printf("%d�� %d���� ������̴�.\n", mon, day);
		break;
	}*/

	return 0;
}

