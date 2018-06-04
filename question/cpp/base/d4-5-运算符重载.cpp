#include "iostream"

using namespace std;
class Complex
{
public:
	int a;
	int b;
public:
	Complex(int a = 0, int b = 0)
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
	Complex operator-(Complex &c2)
	{
		Complex tmp(1, 3);
		return tmp;
	}
};

//全局函数
Complex myAdd(Complex &c1, Complex &c2)
{
	//Complex tmp(1, 2);
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

// 全局函数实现实现 c1+c2  运算符  operator关键字 
Complex operator+(Complex &c1, Complex &c2)
{
	//Complex tmp(1, 2);
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

void runComplex()
{
	Complex c1(1, 2), c2(3, 4);
	Complex c3;
	//c3 = c1 + c2; 用户自定义类型 c++编译器不知道是如何进行计算的

	//运算符重载机制


	//Complex c4 = myAdd(c1, c2);
	//c4.printCom();

	//Complex c5 = operator+(c1, c2);
	//c5.printCom();

	Complex c5 = c1 + c2; //自动去找operator+
	c5.printCom();

}

void runComplex2()
{
	Complex c1(1, 2);
	Complex c2(100, 10);
	
	Complex c3 = c1.operator-(c2);

	c3.printCom();
}

void maind45()
{
	//runComplex();
	runComplex2();
	
	/*
		总结：运算符重载的本质 是 函数调用
	*/

	cout << "hello..." << endl;

	system("pause");
	return;
}