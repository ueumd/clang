#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfMyArray()
{

	//数组 数组中的每一元素是指针 指针数组
	char *myArray[] = { "aaaa","cccc","bbbb","1111111111" };
	char *tmp = NULL;
	int i = 0, j = 0;
	int num = 0;

	num = sizeof(myArray) / sizeof(myArray[0]);

	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				tmp = myArray[i];//交换的是数组元素 指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	printf("排序后：\n");
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

}

void printfMyArray1(char **myArray, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s \n", *(myArray + i));
	}
}

void sortMyArray1(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp = NULL;

	//排序
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				tmp = myArray[i];  //交换的是数组元素 交换的是指针的值 既改变指针指向 详见图 
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void main111()
{
	//printfMyArray();

	//数组 数组中的每一元素是指针 指针数组
	char *myArray[] = { "aaaa","cccc","bbbb","1111111111" };
	char *tmp = NULL;
	int i = 0, j = 0;
	int num = 0;

	num = sizeof(myArray) / sizeof(myArray[0]);

	printfMyArray1(myArray, num);

	sortMyArray1(myArray, num);

	printf("排序后：\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", *(myArray + i));
	}

	system("pause");
	return 0;
}