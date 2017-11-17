#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int str[] = { 1,2,3,4,5,6,7,8,9,10 };
void fn(int *str) {
	int flag = 1;
	for (int i = 0; i < 9; i++) {
		if (str[i] > str[i + 1]) {
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("递增\n");
	}
	else
	{
		printf("fei递增\n");
	}
}

int digui(int n) {
	if (n==8) {
		return str[n] < str[n + 1];
	}
	else {
		return (str[n] < str[n + 1]) && digui(n + 1);
	}
}

// 递归判断一个数组是否递减

int main() {

	fn(str);

	int a = digui(0);
	printf("a = %d", a);

	system("pause");
	return 0;
}