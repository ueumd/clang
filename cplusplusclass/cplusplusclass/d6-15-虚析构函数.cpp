#define _CRT_SECURE_NO_WARNINGS

#include "iostream"

using namespace std;

class A615
{
public:
	A615()
	{
		p = new char[20];
		strcpy(p, "ojba");
		printf("A615()\n");
	}
	virtual ~A615()
	{
		delete[] p;
		printf("~A615()\n");
	}

private:
	char *p;
};

class B615 : public A615
{
public:
	B615()
	{
		p = new char[20];
		strcpy(p, "ojbb");
		printf("B615()\n");
	}
	~B615()
	{
		delete[] p;
		printf("~B615()\n");
	}

private:
	char *p;
};


class C615 : public B615
{
public:
	C615()
	{
		p = new char[20];
		strcpy(p, "ojbc");
		printf("C615()\n");
	}
	~C615()
	{
		delete[] p;
		printf("~C615()\n");
	}

private:
	char *p;
};


/*
//基类释放派生类对象 通过

只执行了父类的析构 造成内存泄漏 //delete base; 这句话不会表现多态 这种属性
解决办法：在父类析构函数上加 virtual 这就是虚析构函数的功能

虚析构函数功能：
向通过父类指针 把 所有的子类对象的析构函数 都执行一遍
向通过父类指针 释放所有的子类资源
*/
void howToDelete(A615 *base)
{
	delete base;
}

void maind615()
{

	C615 *myC = new C615;

	howToDelete(myC);

	//delete myC;//通过子类释放不需要写虚析构函数
	
	cout << "hello..." << endl;

	system("pause");
	return;
}