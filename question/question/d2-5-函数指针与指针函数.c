#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

1.指针函数
先看下面的函数声明，注意，此函数有返回值，返回值为int *，即返回值是指针类型的。

2.函数指针
顾名思义，函数指针说的就是一个指针，但这个指针指向的函数，不是普通的基本数据类型或者类对象。

区别:函数指针的函数名是一个指针，即函数名前面有一个指针类型的标志型号“*”。
*/

int *f(int a, int b); // 声明指针函数   也可以写成 

int(*g)(int a, int b); // 声明函数指

/*
* 求最大值
* 返回值是int类型，返回两个整数中较大的一个
*/
int maxmax(int a, int b) {
	return a > b ? a : b;
}

/*
* 求最小值
* 返回值是int类型，返回两个整数中较小的一个
*/
int minmin(int a, int b) {
	return a < b ? a : b;
}

/*
* 指针函数的定义
* 返回值是指针类型int *
*/

int *f(int a, int b) {
	int *p = (int *)malloc(sizeof(int));

	printf("The memeory address of p = 0x%x \n", p);

	memset(p, 0, sizeof(int));

	*p = a + b;

	printf("*p = %d \n", *p);

	return p;
}

void maind25()
{
	printf("-------------指针函数----------------- Start\n");

	int *p1 = NULL;
	printf("The memeory address of p1 = 0x%x \n", p1);

	p1 = f(1, 2);

	printf("The memeory address of p1 = 0x%x \n", p1);
	printf("*p1 = %d \n", *p1);

	printf("------------------------------ End\n");



	printf("---------------函数指针--------------- Start\n");

	g = maxmax; // 函数指针g指向求最大值的函数max  
	int c = (*g)(1, 2);

	printf("The max value is %d \n", c);

	g = minmin; // 函数指针g指向求最小值的函数min  
	c = (*g)(1, 2);

	printf("The min value is %d \n", c);

	printf("------------------------------ End\n");
	
	system("pause");
	return;
}