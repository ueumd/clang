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
//通过数组类型定义数组指针
void arrpointer()
{

	//指针 数组
	char *myArray[] = { "1111","2222","333333333" };

	//数组指针 用一个指针指向数据
	typedef int(MyArrayType)[5]; //定义了一个数据类型 数组的数据类型
	MyArrayType myArray3; //int myArray[5]
	int i = 0;

	MyArrayType *pArray;//定义一个指针变理 这个指针变量 指向一个数组
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		int myArray2[5];

		pArray = &myArray2;//相当于二级指针

		for (i = 0; i < 5; i++)
		{
			//myArray2[i] = i + 1;
			(*pArray)[i] = i + 1;
		}

		for (i = 0; i < 5; i++)
		{
			printf("\n%d", (*pArray)[i]);
		}

		
	}
}

//定义数组指针变量的第二种方法
void arrpointer2()
{
	//定义声明一个数组指针类型
	typedef int(*PArrayType)[5];

	PArrayType pArray; //告诉编译器给我分配一个指针变量

	int c[5];

	int i = 0;

	pArray = &c;

	for (i = 0; i < 5; i++)
	{

		(*pArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d", (*pArray)[i]);
	}

	return;
}

//定义数组指针变量的第三种方法
//前两种方法都是通过类型定义变量 比较麻烦
void arrpointer3()
{
	int(*pMyArray)[5]; //直接定义一个指向数组的 数组指针变量

	int c[5];

	int i = 0;

	pMyArray = &c;

	for (i = 0; i < 5; i++)
	{

		(*pMyArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d", (*pMyArray)[i]);
	}

	return;
}

void maind41()
{
	
	based41();
	//typedefarr();

	//arrpointer();

	//arrpointer2();
	arrpointer3();
	
	system("pause");
	return 0;
}