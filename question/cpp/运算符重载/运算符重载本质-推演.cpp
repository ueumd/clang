#include <iostream>
using namespace std;

class ComplexA
{
public:
	int a;
	int b;
public:
	ComplexA(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}
public:
	//成员函数实现重载
	ComplexA operator-(ComplexA &c2)
	{
		ComplexA tmp(1, 3);
		return tmp;
	}
};

//全局函数
ComplexA myAdd (ComplexA &c1, ComplexA &c2) {
	ComplexA tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

// 全局函数实现实现 c1+c2  运算符  operator关键字 
ComplexA operator+(ComplexA &c1, ComplexA &c2)
{
	//ComplexA tmp(1, 2);
	ComplexA tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

void testComplexA()
{
	int a, b, c;
	c = a + b; //基本类型CPP编译器知道怎么运算
	
	ComplexA c1(1, 2), c2(3, 4);
	ComplexA c3;
	//c3 = c1 + c2; 用户自定义类型 c++编译器不知道是如何进行计算的

	//运算符重载机制
	//Complex2 c4 = myAdd(c1, c2);
	//c4.printCom();

	//Complex2 c5 = operator+(c1, c2);
	//c5.printCom();

	ComplexA c5 = c1 + c2; //自动去找operator+
	c5.printCom();

}

void testComplexA2()
{
	ComplexA c1(1, 2);
	ComplexA c2(100, 10);

	ComplexA c3 = c1.operator-(c2);

	c3.printCom();
}

void maind45()
{
	/*
		总结：运算符重载的本质 是 函数调用
		函数返回值当左值，需返回引用
		友元函数应用场景：
		友元函数存在真正原因
		链式编程-函数返回值当左值
		友元函数没有this指针
	*/

	//testComplexA();
	testComplexA2();

	cin.get();
}