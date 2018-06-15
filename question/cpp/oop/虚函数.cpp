#include<iostream>
using namespace std;
/*
C++中的虚函数是用于解决动态多态性的问题。
所谓虚函数(virtual function)，就是在基类声明函数是虚拟的，并不是实际存在的函数，然后在派生类中才正式定义此函数。

虚函数跟虚继承是不同的概念

简单的总结
1. 指向基类的指针（注只能使用指针或者引用才能实现）在操作它的多态类对象时，会根据不同的类对象，调用其相应的函数，这个函数就是虚函数。
2. 当使用基类指针调用非虚方法时，调用的是基类方法。
3. 综上，只有将方法属性设置virtua并且使用基类指针进行方法调用时，才能实现多态。

不过引用不像指针灵活，指针可以随时改变指向，而引用只能指代固定的对象，在多态性方面缺乏表现力，所以以后我们再谈及多态时一般是说指针。

下面是构成多态的条件：
1. 必须存在继承关系；
2. 继承关系中必须有同名的虚函数，并且它们是遮蔽（覆盖）关系。
2/ 存在基类的指针，通过该指针调用虚函数。
*/

class A {
public:
	virtual void print() {
		cout << "This is A" << endl;
	}
};

class B :public A {
public:
	void print() {
		cout << "This is B" << endl;
	}
};

void testA() {
	A a;
	B b;

	a.print();  // This is A
	b.print();  // This is B

	// 多态还有个关键之处就是一切用指向基类的指针或引用来操作对象

	A *p1, *p2;

	p1 = &a;
	p2 = &b;

	// 结果却是两个This is A
	p1->print(); // This is A

	// 解决方法 父类方法加上 virtual 关键字
	p2->print(); // This is A 调用了A类的方法 

}

class Base {
public:
	virtual void func() {
		cout << "void Base::func()" << endl;
	}

	virtual void func(int n) {
		cout << "void Base::func(int)" << endl;
	}
};

class Derived : public Base {
public:
	virtual void func() {
		cout << "void Derived::func()" << endl;
	}

	virtual void func(char *str) {
		cout << "void Derived::func(char *)" << endl;
	}
};

void testB() {
	Base *p = new Base();
	p->func();			// void Base::func()
	p->func(100);		// void Base::func(int)

	cout << "----------------" << endl;

	p = new Derived();
	p->func();			// void Derived::func()
	p->func(100);   // void Base::func(int)

	// 通过基类的 指针 只能访问从基类继承过去的成员，不能访问派生类新增的成员。
	//p->func("Hello"); //compile error

}

void main() {
	testB();
	cin.get();
}