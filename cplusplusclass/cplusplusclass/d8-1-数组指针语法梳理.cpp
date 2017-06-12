#include "iostream"

using namespace std;
/*
定义一个数组类型
int a[10]

定义一个指针数组类型

定义一个指向 数组类型的指针 数组类的指针
*/

void maind812()
{

	/*
	a代表的是数组首元素地址 
	&a代表整个数组地址
	a+1 步长是 4； &a+1 步长是：40
	*/
	int a[10];

	{
		//定义一个数组类型 
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n", myArray[0]);
	}
	{
		//定义一个指针数组类型(麻烦)
		typedef int (*PTypeArray)[10]; //int *p=NULL
		PTypeArray myPArray;//sizeof(int)*10
		myPArray = &a;
		(*myPArray)[0] = 400;
		printf("a[0]:%d\n", a[0]);

		//操作类似于

		int b = 10;
		int *p = NULL;
		p = &b;
		*p = 200;
		printf("b:%d\n", b);
	}

	{
		//定义一个指向 数组类型的指针 数组类的指针

		int(*MyPointer)[10];// 变量 告诉C编译器 给我分配内存 等于 	typedef int (*PTypeArray)[10];PTypeArray myPArray; 

		MyPointer = &a;
		(*MyPointer)[0] = 1000;
		printf("a[0]:%d\n", a[0]);

	}

	cout << "hello..." << endl;

	system("pause");
	return;
}

/*
函数指针基本语法知点梳理
1 如何定义一个 函数类型
2 如何定义一个 函数指针类型
3 如何定义一个 函数指针 （指向一个函数入口地址）
*/

int add(int a, int b)
{
	printf("func add...\n");
	return a + b;
}
void main()
{

	add(1, 2);//直接调用 函数名就是函数的入口

	//如何定义一个 函数类型
	{
		typedef int (MyFuncType)(int a, int b); //定义一个类型

		MyFuncType *myPointerFunc = NULL;//定义了一个指针，指向某一种类的函数

		myPointerFunc = &add;
		myPointerFunc(3, 4); //间接调用

		myPointerFunc = add; //不取地址 兼容历史版本
		myPointerFunc(3, 4); //间接调用
	}

	//如何定义一个 函数指针类型
	{
		typedef int(*MyPointerFuncType)(int a, int b); // int *a=NULL;
		MyPointerFuncType myPointerFunc; //定义一个指针
		myPointerFunc = add;
		myPointerFunc(5, 6);
	}

	//如何定义一个 函数指针
	{
		int(*MyPointerFunc)(int a, int b);//定义了一个变量
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}

	cout << "hello..." << endl;

	system("pause");
	return;
}