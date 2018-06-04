#include "iostream"

using namespace std;
/*
基类静态成员被所有派生类共享
根据静态成员的访问特性和派生类的继承方式，在类层次中具有不同的访问性质（遵守派生类的访问控制）
派生类访问静态成员：
类名：：成员
*/
class A68
{
	/*A68() //如果不写public 是有问题的，可以在单例模示中情况使用私有的
	{

	}*/
public:
	int a;
	int b;
	static int c;
public://下面的方法如果不写修饰 默认是私有的 重要
	virtual void get()
	{
		cout <<"A68:"<< b << endl;
	}
	void getC()
	{
		cout << "A68:" << c << endl;
	}
};

int A68::c = 100;//不是简单的赋值，重要的是告诉c++编译器要分配内存，我再继承中用到了c，不然会报错

class B68 : public A68
{
public:
	int a;
	int b;
public:
	virtual	void get()
	{
		cout << "B68:" << b << endl;
	}

};

void rund68()
{
	A68 a1;

	B68 b1;
	b1.b = 100;
	/*
	父类和子类成员变量和成员函数同名时的调用方法:

	B.A::a=100;

	*/

	b1.A68::b = 300;

	b1.get();
	b1.A68::get();
}

void rund68static()
{
	
	B68 b1;
	b1.c = 200; //如果是私有继承是不能访问 c
	b1.A68::getC(); //20

	A68 *a2 = NULL;
	A68 a3;
	a3.b = 1000;
	a2 = &a3;

	a2->get(); // 父类的

	B68 b2;
	b2.b = 2000;

	a2 = &b2;

	/*
	如果父类不加 virtaul  a2.get() 调用时有是问题的

	加vitraul正常 多态的来源virtual
	*/
	a2->get();//？执行谁的 

	

}

void maind68()
{
	
	//rund68();
	rund68static();

	cout << "hello..." << endl;

	system("pause");
	return;
}