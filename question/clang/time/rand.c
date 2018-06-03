#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main() {

	time_t ts;											//设置时间变量
	srand((unsigned int)time(&ts)); //设置时间随机种子

	for (int i = 0; i < 10; i++) {
		printf("%d\n", rand() % 100);
	}

	system("pause");
	return 0;
}
