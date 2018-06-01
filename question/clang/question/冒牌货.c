#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void constint()
{
	const int a = 10;
	//a = 11; error
	{
		int *p = &a;
		*p = 100;
		printf("a:%d\n", a);//a:100
												//结论C语言中的const修饰的变量 是假的 C语言中的const 是一个冒牌货
	}
}


void main()
{
	system("pause");
	return;
}