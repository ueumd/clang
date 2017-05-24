#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**

定义一个结构体类型

定义了一个数据类型。固定大小内存块的别名 还没有分配内存

类型的重定义
**/
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

void main()
{
	
	//struct Teacher t1;//告诉C编译器给我配分内存
	
	Teacher t1;//告诉C编译器给我配分内存
	system("pause");
	return;
}