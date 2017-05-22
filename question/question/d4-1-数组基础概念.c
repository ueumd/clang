#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*


*/

void based41()
{
	int a[] = { 1,2 };
	int b[100] = { 1,3 };
	int c[200] = { 0 };//编译时 就已经确定所有的值为零

	memset(c, 0, sizeof(c));//显示的 重置内存块
							//对一维数组：
							//c  是数组首元素的地址 c+1 步长 4个字长
							//&c 是整个数组的地址 &c+1 步长 200*4
	return;
}

//怎么样表达int a[10]这种数据类型？ int []
//类型本质：固定大小内存块的别名
void typedefarr() 
{
	typedef int(MyArrayType)[5]; //定义了一个数据类型 数组的数据类型
	MyArrayType myArray; //int myArray[5]
	int i = 0;

	for (i = 0; i < 5; i++)
	{
	
		myArray[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d", myArray[i]);
	}

	printf("\n myArray: %d, myArray+1:%d\n", myArray, myArray + 1);

	return;
}

void arrpointer()
{

	//指针 数组
	char *myArray[] = { "1111","2222","333333333" };

	//数组指针 用一个指针指向数据
	typedef int(MyArrayType)[5]; //定义了一个数据类型 数组的数据类型
	MyArrayType myArray; //int myArray[5]
	int i = 0;

	MyArrayType *pArray;//定义一个指针变理 这个指针变量 指向一个数组
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		int myArray2[5];
		for (i = 0; i < 5;i++)
		pArray = &myArray;
	}
}

void main()
{
	
	based41();
	typedefarr();

	
	system("pause");
	return 0;
}