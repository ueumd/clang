#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
Facade模式为一组具有类似功能的类群，比如类库，子系统等等，提供一个一致的简单的界面。这个一致的简单的界面被称作facade。

适用于：
为子系统中统一一套接口，让子系统更加容易使用。
*/

class SystemA{
public:
	void doThing(){
		cout << "systemA do...." << endl;
	}
};

class SystemB{
public:
	void doThing(){
		cout << "systemB do...." << endl;
	}
};

class SystemC{
public:
	void doThing(){
		cout << "systemC do...." << endl;
	}
};

class Facade {
public:
	Facade() {
		a = new SystemA;
		b = new SystemB;
		c = new SystemC;
	}
	~Facade() {
		delete a;
		delete b;
		delete c;
	}

	void doThing() {
		a->doThing();
		b->doThing();
		c->doThing();
	}
private:
	SystemA *a;
	SystemB *b;
	SystemC *c;
};

void main() {

	SystemA  *a = new SystemA;
	SystemB  *b = new SystemB;
	SystemC  *c = new SystemC;
	a->doThing();
	b->doThing();
	c->doThing();

	delete a;
	delete b;
	delete c;

	//外观模式
	Facade *f = new Facade;
	f->doThing();
	delete f;

	cin.get();
}