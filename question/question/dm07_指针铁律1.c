#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int a = 10;
	char *p1 = 100;//分配4个字节的内存   （给内存赋值）  

	char ****p2 = 100;

	int *p3 = NULL;

	p3 = &a;

	*p3 = 20;//间接修改a的值

	int c = *p3;//取值

	printf("%d\n", c);

	printf("a:%d,p1:%d,p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));//4 4 4 

	system("pause");
	return;
}