#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printfArr1(int a[3][5])
{
	int i, j, tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	return;
}

void printfArr2(int a[][5])
{
	int i, j, tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	return;
}

//多维数组做函数参数的推演
void printfArr3(int(*b)[5])
{
	int i, j, tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", b[i][j]);
		}
	}

	return;
}

void main多数数组的本质()
{
	int a[3][5];
	int i = 0, j = 0, tmp = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}
	printf("\n-------------------\n");
	printfArr3(a);
	printf("\n-------------------\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ,", a[i][j]);
		}
	}

	printf("\na:%d , a+1:%d\n ", a, a + 1);//a+1的步长是20个字节 5*4
	printf("&a:%d , &a+1:%d\n ", &a, &a + 1);

	{
		//定义一个指向数组的指针变量
		int(*pArray)[5];//告诉编译器 分配4个字的内存 32bit平台下
		pArray = a;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				printf("%d,", pArray[i][j]);
			}
		}
	}
	/*
	多维数组的本质 数组指针 ，步长 一维的长度

	 (a)    代表是第0行的整个地址 （第一行的地址 和 第一行首元素的地址是重叠的。。。）
	 (a+i)  代表是第i行的首地址 2级指针
	*(a+i)  代表 1级指针 第i行的首元素的地址
	*/

	/*
	转化推演：

	*( *(a+i) + j) ===>a[i][j]     元素的值
	a[i][j] <===> *(*(a+i)+j)
	a[i] ===> a[0+i] ===>*(a+i)    0是占位符
	a[i][j]===a[0+i][j] ==> *(a+i)[j] ===>*(a+i)[0+j] ===>* ( *(a+i) + j)

	**/

	system("pause");
	return;
}