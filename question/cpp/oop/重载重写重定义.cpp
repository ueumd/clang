#include <iostream>
using namespace std;
/*
重载 重写 重定义：

重载：
	1. 重载必须在 1 个类之间
	2. 子类无法重载父类的函数，父类同名函数将被名称覆盖
	3. 重载是在编译期间根据参数类型和个数决定函数调用

重写
	1. 重写发生在 2 个类之间（父类子类）
	2. 并且父类与子类中函数必须同有完全相同的原型（函名 类型 个数）

重写分 2 类：
	1. 虚函数重写 发生多态
	2. 非虚函数重写 （重定义）
*/
class Base {
public:
	void set() {
		cout << "void Base::set()" << endl;
	}

	void set(int a, int b) {
		cout << "void Base::set()" << endl;
	}

	void setBase() {
		cout << "void Base::setBase()" << endl;
	}

	virtual void func() {
		cout << "void Base::func()" << endl;
	}

	virtual void func(int n) {
		cout << "void Base::func(int)" << endl;
	}
};

class Derived : public Base {
public:
	// 重写了父类set方法
	void set() {
		cout << "void Derived::set()" << endl;
	}

	void setDerived() {
		cout << "void Derived::setDerived()" << endl;
	}

	// 重写了父类func虚方法 实现了多态
	virtual void func() {
		cout << "void Derived::func()" << endl;
	}

	virtual void func(char *str) {
		cout << "void Derived::func(char *)" << endl;
	}
};

void testBB() {
	Base *b = new Base();
	b->set();					// 	void Base::set()
	//b->setDerived(); //错误 父类不存在此方法


	Derived d;
	d.setBase();			// void Base::setBase() 继承过来的父类方法
	d.setDerived();		// void Derived::setDerived()

	d.Base::set();    // void Base::set()
	d.set();					// void Derived::set()  父类子类都有，优先调用子类中的方法

	// c++编译器看到set名子，在子类中已经存在了，不会在去找父类中带2个参数的名字的位置，只会在子类中找，但是子类没有带2个参数的，所以报错
	// d.set(10, 20);
	
	// 域作用符 显示的调用
	d.Base::set(10, 20);
}

void testB() {
	Base *p = new Base();
	p->func();			// void Base::func()
	p->func(100);		// void Base::func(int)AZS

	cout << "----------------" << endl;

	p = new Derived();
	p->func();			// void Derived::func()
	p->func(100);   // void Base::func(int)

  // 通过基类的 指针 只能访问从基类继承过去的成员，不能访问派生类新增的成员。
	//p->func("Hello"); //compile error

}

void main1ddd() {
	testBB();
	cin.get();
}