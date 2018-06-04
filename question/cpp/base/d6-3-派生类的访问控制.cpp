#include "iostream"

using namespace std;
class A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

class B : public A
{
public:
	void print() //不加public 默认是private
	{
		//cout << "a=" << a << endl;//error
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;
	}
};

class C : protected A
{
public:
	void print()
	{
		//cout << "a=" << a << endl; //error
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;
	}
};

class D : private A //私有继随
{
public:
	void print()
	{
		//cout << "a=" << a << endl; //error
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;
	}
};

void maind63()
{
	A aa;
	B bb;
	C cc;
	D dd;

	aa.c = 100;
	bb.c = 100;
//	cc.c = 100; //C是保护继承 原来公有的会变成保护的 外部不能访问的
//	dd.c = 100;//私有继承 外部不能访问的

	aa.set(1, 2, 3);
	bb.set(10, 20, 30);
	//cc.set(1, 2, 3); //err
	//dd.set(1, 2, 3); //err


	bb.print();
	cc.print();
	dd.print();

	cout << "hello..." << endl;

	system("pause");
	return;
}