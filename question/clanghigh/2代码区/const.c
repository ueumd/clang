#include<stdio.h>
#include<stdlib.h>

#define N 10   //CPU产生，10 . 1010 不能取地址的
//const是伪常量，限定编译器尽量不直接修改
int main() {
	const int num = 100;
	const int *pnum = &num;//创建指针指向const int 
	int *pnum2 = (int *)pnum;

	*pnum2 = 200;

	printf("%d", num); // 200
	system("pause");
	return 0;
}