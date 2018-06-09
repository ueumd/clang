#include <iostream>
using namespace std;
/*
继承的本质：拷贝一分父类，子类与父类发生冲突，覆盖父类,制定拷贝父类的内存调用
*/

class Father {
public:
	int age = 30;
	void show() {
		cout << "father" << endl;
	}
};

class Son : public Father {
public:
	int age = 5;
	void show() {
		cout << "son" << endl;
	}
};

//多继承
class MyClass : public Father, public Son
{
public:
	int age = 0;
	void show() {
		cout << "MyClass" << endl;
	}
};

void main2() {
	Son son;
	cout << son.age << endl;				//5

	cout << son.Father::age << endl;	//30

	son.show();	//son
	son.Father::show(); //father

	MyClass m;
	cout << m.age << endl;  // 0
	m.show();								//MyClass

	m.Father::show();	//father
	m.Son::show();    //son


	cin.get();
}