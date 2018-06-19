#include<string.h>
#include<stdio.h>
/*
数组类型基本语法知识点梳理
1 定义一个数组类型
2 定义一个指针数组类型
3 定义一个指向 数组类型的指针 数组类的指针
*/

void test1() {
	int a[10]; //a 代表数组首元素地址 &a代表整个数组地址

	{
		//定义一个数组类型
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("myArray[0]=%d \n", myArray[0]);
	}

	{
		// 定义一个指针数组类型 相当于二级指针
		typedef int(*PTypeArray)[10]; // int *p
		PTypeArray myPArray; //sizeof(int)*10
		myPArray = &a;

		(*myPArray)[0] = 20;
		printf("a[0]=%d\n", a[0]);

		//类似这样
		int b = 10;
		int *p = NULL;
		p = &b;
	}

	{
		// 定义一个指向 数组类型的指针 数组类的指针
		int(*MyPointer)[10]; //变量 告诉C编译器 给我分配内存
		MyPointer = &a;
		(*MyPointer)[0] = 40;
		printf("a[0]=%d\n", a[0]);
	}
}

/*
函数指针基本语法梳理
1 如何定义一个函数类型
2 如何定义一个函数指针类型
3 如何定义 函数指针（指向一个函数的入口地址）
*/

int add(int a, int b) {
	printf("func add ... \n");
	return a + b;
}


void test2() {
	add(1, 2);

	{
		// 定义一个函数类型
		typedef int (MyFuncType)(int a, int b); //定义一个类型（有两个参数）
		MyFuncType *myPointerFunc = NULL; //定义了一个指针 指向某一种类的函数

		myPointerFunc = &add;
		myPointerFunc(3, 4); //间接调用
	}

	{
		//定义一个函数指针类型
		typedef int(*MyPointerFuncType) (int a, int b);
		MyPointerFuncType myPointer;
		myPointer = add;
		myPointer(5, 6);
	}

	{
		//直接函数指针
		int(*MyPointerFunc)(int a, int b);
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}
	
}

void main1() {
	//test1();
	test2();

	system("pause");
}