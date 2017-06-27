#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**

定义一个结构体类型

定义了一个数据类型。固定大小内存块的别名 还没有分配内存

类型的重定义
**/

//用类型定义变量的方法3种
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;


//2
struct Student
{
	char name[64];
	int age;
}s1, s2; // 定义类型的同时 D

//3
struct
{
	char name[64];
	int age;
	int id;
}s3, s4; // 匿名类型 定义变量

//初始化变量的三种方法 2
struct Student2
{
	char name[64];
	int age;
}s5 = { "aaa",10 };

//初始化变量的三种方法 3
struct
{
	char name[64];
	int age;
}s6 = { "aaa",10 };

void struct1()
{

	//初始化变量的三种方法

	//struct Teacher t1;//告诉C编译器给我配分内存

	Teacher t1;//告诉C编译器给我配分内存  前面已经用typedef重定义了 所以struct可以去掉

	Teacher t2 = { "aaaa", 30, 01 };

	t1.age = 12; // t1. 操作符是干什么 有没有操作内存  -> 是寻址操作 计算 age 相对于 t1大变量的 偏移量 ===》计算 cpu中进行  没有操作操作内存

				 //通过指针操作的方式 操作 内存空间
	{
		Teacher *p = NULL;
		p = &t2;
		printf("p->age:%d\n", p->age); //  是寻址操作 计算 cpu中进行  没有操作操作内存
	}

	strcpy(t1.name, "t1name");

	printf("t1.name:%s \n", t1.name);

	
	return;
}

void copyTeacher(Teacher to, Teacher from)
{
	to = from; //这里不会改变实参
}

void copyTeacher2(Teacher *to, Teacher *from)
{
	*to = *from; 
}

void maind45()
{
	
	struct1();

	Teacher t3 = { "Hello",33,22 };

	Teacher t4;

	Teacher t5;

	t4 = t3;
	printf("t4.name:%s \n", t4.name); // hello

	copyTeacher2(&t5, &t3);
	printf("t5.name:%s \n", t5.name); //hello

	system("pause");
	return;
}