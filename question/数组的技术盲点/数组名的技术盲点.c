#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main数组名的技术盲点()
{
	int a[] = { 1, 2};
	int b[100] = { 1, 3 };

	int c[200] = { 0 };      //编译时 就已经确定 所有的值 为零
	memset(c, 0, sizeof(c)); //显示的 重置内存块
	// 对一维数组C规定：
	// c  是数组首元素的地址 c+1    步长 4个字节
	// &c 是整个数组的地址   &c+1   步长 200*4
	
	system("pause");
	return;
}

void main定义数组()
{
	typedef int(MyArrayType)[5]; // 定义了一个数据类型 数组数据类型
	int i = 0;
	MyArrayType lessons;

	for (i = 0; i < 5; i++) {
		lessons[i] = i + 1;
	}

	printf("lessons:%d lessons+1:%d\n", lessons, lessons + 1);			// lessons  : 4193968   lessons + 1 : 4193972   步长4
	printf("&lessons:%d &lessons+1:%d\n", &lessons, &lessons + 1);  // &lessons : 4193968  &lessons + 1 : 4193988   步长20

	system("pause");
	return;
}

// 定义数组指针变量的方法1 
// 用数组类型 加*
void main定义数组指针变量的方法1()
{
	char *MyArray[] = { "111","2222","3333" }; // 指针 数组

	typedef int(MyArrayType)[5]; // 定义了一个数据类型 数组数据类型
	int i = 0;
	MyArrayType lessons;    // 数据类型 定义变量

	MyArrayType *pLessons; // 数据类型 定义一个指针变量 这个指针变量 指向一个数组
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		int lessons2[5];
		// 可以通过指针变量pLessons来操作lessons2的内存空间
		pLessons = &lessons2; // pLessons = &lessons;
		for (i = 0; i < 5; i++) {
			// lessons2[i] = i + 1;
			(*pLessons)[i] = i + 1;
		}
		for (i = 0; i < 5; i++) {
			printf("%d ", (*pLessons)[i]); // 1 2 3 4 5
		}
	}

	system("pause");
	return;
}

//定义数组指针变量的方法2
void main定义数组指针变量的方法()
{
	
	typedef int (*MyArrayType)[5]; // 定义了一个数组指针类型
	MyArrayType pLessons;          // 告诉编译器 分配一个指针变量
	int c[5];
	int i = 0;

	pLessons = &c;

	for (i = 0; i < 5; i++) {
		(*pLessons)[i] = i + 1;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", (*pLessons)[i]); // 1 2 3 4 5
	}

	system("pause");
	return;
}

//定义数组指针变量的方法3
//前面两种方法 通过类型定义 比较麻烦 
// 直接定义
void main定义数组指针变量的方法3()
{
	int c[5];
	int i = 0;

	int (*pLessons)[5]; // 直接定义了一个指向数组的 指针变量
	pLessons = &c;

	for (i = 0; i < 5; i++) {
		(*pLessons)[i] = i + 1;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", (*pLessons)[i]); // 1 2 3 4 5
	}

	system("pause");
	return;
}