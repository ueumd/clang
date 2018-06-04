#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void maind361()
{
	char myBuf[30];
	char myArray[10][30] = { "aaaa", "cccc", "bbbb", "1111111111" };

	char tmpBuf[30];

	int i = 0, j = 0;
	int num = 4;

	//printf
	for (i = 0;i < num;i++)
	{
		printf("%s\n", myArray[i]);
	}

	//sort
	for (i = 0;i < num;i++)
	{
		for (j = i + 1;j < num;j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				strcpy(tmpBuf, myArray[i]);//交换的是内存块
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}

	//sort
	for (i = 0;i < num;i++)
	{
		printf("%s\n", myArray[i]);
	}

	system("pause");
	return 0;
}

/*
问题的本质是:myArray+1 和第一种的myArray+1 内存模型不一样
也就是指针的步长不一样 指针所指向的内存空间的数据不一样
printfMyArrayd36()行不通
*/

void printfMyArrayd360(char **myArray, int num)
{
	int i = 0;
	for (i = 0;i < num;i++)
	{
		printf("%s \n", *(myArray + i));
	}
}

void sortMyArrayd360(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp = NULL;

	//排序
	for (i = 0;i < num;i++)
	{
		for (j = i;j < num;j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				tmp = myArray[i];//交换的是数组元素 交换的是指针的值 既改变指针指向 详见图 
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}


}

//笨方法
void printfMyArrayd36(char myArray[10][30], int num)
{
	int i = 0;
	for (i = 0;i < num;i++)
	{
		printf("%s \n", *(myArray + i));
	}
}
void sortMyArrayd36(char myArray[10][30], int num)
{
	int i = 0, j = 0;
	char tmpBuf[30];

	//排序
	for (i = 0;i < num;i++)
	{
		for (j = i + 1;j < num;j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				strcpy(tmpBuf, myArray[i]);//交换的是内存块
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}


}

void maind36()
{
	char myBuf[30];
	char myArray[10][30]= { "aaaa", "cccc", "bbbb", "1111111111" };

	char tmpBuf[30];

	int i = 0, j = 0;
	int num = 4;
	/*
		编译器只会关心有10行 每行30列
	*/
	{
		int len1 = sizeof(myArray);//300
		int len2 = sizeof(myArray[0]);//30
		int size = len1 / len2;
		printf("len1:%d, len2:%d, size:%d \n", len1, len2, size);
	}
	printfMyArrayd36(myArray, num);
	sortMyArrayd36(myArray, num);

	//sort
	for (i = 0;i < num;i++)
	{
		printf("%s\n", myArray[i]);
	}
	system("pause");
	return 0;
}