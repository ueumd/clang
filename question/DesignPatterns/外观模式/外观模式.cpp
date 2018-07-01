#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
FacadeģʽΪһ��������ƹ��ܵ���Ⱥ��������⣬��ϵͳ�ȵȣ��ṩһ��һ�µļ򵥵Ľ��档���һ�µļ򵥵Ľ��汻����facade��

�����ڣ�
Ϊ��ϵͳ��ͳһһ�׽ӿڣ�����ϵͳ��������ʹ�á�
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

	//���ģʽ
	Facade *f = new Facade;
	f->doThing();
	delete f;

	cin.get();
}