#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main() {

	time_t ts;											//����ʱ�����
	srand((unsigned int)time(&ts)); //����ʱ���������

	for (int i = 0; i < 10; i++) {
		printf("%d\n", rand() % 100);
	}

	system("pause");
	return 0;
}
