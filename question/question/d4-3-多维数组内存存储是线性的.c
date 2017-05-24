#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 等价关系

 数组参数                        等效的指针参数

 一维数组 char a[30]             指针 char*
 指针数组 char *a[30]			指针的指针 char **a
 二组数组 char a[10][30]			数组的指针 char(*a)[30]
 
 ***/
void printfArrayd43(int *array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ",array[i]);
	}
	return;
}

void maind43()
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
	
	//把二维数组 当成 1维数组 来打印 证明线性存储
	printfArrayd43((int *)a, 15);
	system("pause");
	return;
}