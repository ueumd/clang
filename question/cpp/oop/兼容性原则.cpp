#include "iostream"
using namespace std;

class Parent
{
public:
	void showParent()
	{
		cout << "我是爹" << endl;
	}
	Parent()
	{
		cout << "Parent构造函数" << endl;
	}
	Parent(const Parent &obj)
	{
		cout << "Parent copy构造函数" << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	void showChild()
	{
		cout << "我是儿子" << endl;
	}
protected:
private:
	int c;
};

void howToPrint(Parent *base)
{
	base->showParent(); //只能执行父类的 成员函数
}

void howToPrint2(Parent &base)
{
	base.showParent(); //只能执行父类的 成员函数
}

void main1()
{
	/*
	兼容规则：
	子类对象可以当作父类对象使用
	子类对象可以直接赋值给父类对象
	子类对象可以直接初始化父类对象


	父类指针可以直接指向子类对象
	父类引用可以直接引用子类对象
	*/


	Parent p1;
	p1.showParent();

	Child c1;
	c1.showChild();  //	我是儿子
	c1.showParent(); //	我是爹


	
	//赋值兼容性原则：
	//1 基类指针 （引用） 指向 子类对象 
	Parent *p = NULL;
	p = &c1;
	p->showParent(); //我是爹

	//1-2 指针做函数参数
	howToPrint(&p1);	// 我是爹
	howToPrint(&c1);  // 我是爹

	////1-3 引用做函数参数
	//howToPrint2(p1);
	//howToPrint2(c1);

	////第二层含义

	////可以让父类对象初始化 子类对象
	//Parent p3 = c1; //会调用Parent的拷贝构造函数
	cout << "hello..." << endl;

	system("pause");
	return;
}