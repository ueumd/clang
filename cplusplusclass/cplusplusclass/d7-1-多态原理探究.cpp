/*
实现多态的三个条件：
1.  要有继承
2、 要有虚函数重写
3、 用父类指针（父类引用） 指向子类对象
*/
/*
C++中多态的实现原理
当类中声明虚函数时，编译器会在类中生成一个虚函数表
虚函数表是一个存储类成员函数指针的数据结构
虚函数表是由编译器自动生成与维护的
virtual成员函数会被编译器放入虚函数表中
存在虚函数时，每个对象中都有一个指向虚函数表的指针(vptr指针)
*/

#include "iostream"
using namespace std;

class Parent71
{
public:
	Parent71(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1 动手脚 写virtual关键字 会特殊处理 //虚函数表
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

class Child71 : public Parent71
{
public:
	Child71(int a = 0, int b=0):Parent71(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "我是儿子" << endl;
	}
private:
	int b;
};

class ParentVptr
{
	ParentVptr(int a = 0)
	{
		this->a = a;
	}
	void print()
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

class ParentVptr2
{
	ParentVptr2(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

void HowToPlay(Parent71 *base)
{
	base->print();//有多态发生 //2 动手脚

	/*
		效果：传来的子类对象 执行子类的print函数 传来父类 执行父类的 print函数
		c++编译器根本不需要区分是子类对象 还是父类对象

		父类对象和子类对象分别有步vptr指针 ==>虚函数表 ===> 函数的入口地址 ，这样实现了
		迟邦定（运行的时候，c++编译器才会去判断）
	*/
}

void main()
{
	Parent71 p1; //3 动手脚 用类定义对象的时候 c++编译器会在对象中添加一个vptr指针
	Child71 c1; //子类里面也有一个对vptr指针

	HowToPlay(&p1);
	HowToPlay(&c1);

	//问题 怎么证明vptr指针存在

	printf("ParentVptr:%d ,ParentVptr2:%d\n", sizeof(ParentVptr), sizeof(ParentVptr2));
	// x86 4 8

	cout << "hello..." << endl;

	system("pause");
	return;
}