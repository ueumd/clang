#include "iostream"

using namespace std;

int d17getAA1()
{
	int a;
	a = 10;
	return a;
}

//返回的是栈变量 不能成功其他引用的初始值
int& d17getAA2()
{
	int a; //如果返回栈上的引用 有可能会有问题 
	a = 100;
	return a;
}

//变量是static 或者是全局变量 是可以成为其他引用的初始值
int& d17getAA2Static()
{
	static int a; // 
	a = 100;
	return a;
}

int* d17getAA3()
{
	int a;
	a = 1001;
	return &a;
}

//函数当左值 c++中很重要的概念

//返回变量的值
int d17g1()
{
	static int x = 999;
	x++;
	return x;

}

//返回变量本身 
int& d17g2()
{
	static int x = 999;
	x++;
	printf("x:%d\n", x);
	return x;

}

void maind17()
{
	int a1 = 0;
	int a2 = 0;

	a1 = d17getAA1();
	a2 = d17getAA2();

	int &a3 = d17getAA2();//在x86  Debug 会存在潜在bug 乱码

	int &a4 = d17getAA2Static();

	printf("a1:%d, a2:%d, a3:%d,a4:%d\n", a1, a2, a3,a4);

	//d17g1() = 100; //报错
	d17g2() = 200; //相当于 a = 200;
	d17g2(); //201

	cout << "hello..." << endl;

	system("pause");
	return;
}