#include<iostream>
using namespace std;
/*
C++�е��麯�������ڽ����̬��̬�Ե����⡣
��ν�麯��(virtual function)�������ڻ�����������������ģ�������ʵ�ʴ��ڵĺ�����Ȼ�����������в���ʽ����˺�����

�麯������̳��ǲ�ͬ�ĸ���

�򵥵��ܽ�
1. ָ������ָ�루עֻ��ʹ��ָ��������ò���ʵ�֣��ڲ������Ķ�̬�����ʱ������ݲ�ͬ������󣬵�������Ӧ�ĺ�����������������麯����
2. ��ʹ�û���ָ����÷��鷽��ʱ�����õ��ǻ��෽����
3. ���ϣ�ֻ�н�������������virtua����ʹ�û���ָ����з�������ʱ������ʵ�ֶ�̬��

�������ò���ָ����ָ�������ʱ�ı�ָ�򣬶�����ֻ��ָ���̶��Ķ����ڶ�̬�Է���ȱ���������������Ժ�������̸����̬ʱһ����˵ָ�롣

�����ǹ��ɶ�̬��������
1. ������ڼ̳й�ϵ��
2. �̳й�ϵ�б�����ͬ�����麯���������������ڱΣ����ǣ���ϵ��
2/ ���ڻ����ָ�룬ͨ����ָ������麯����
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

	// ��̬���и��ؼ�֮������һ����ָ������ָ�����������������

	A *p1, *p2;

	p1 = &a;
	p2 = &b;

	// ���ȴ������This is A
	p1->print(); // This is A

	// ������� ���෽������ virtual �ؼ���
	p2->print(); // This is A ������A��ķ��� 

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

	// ͨ������� ָ�� ֻ�ܷ��ʴӻ���̳й�ȥ�ĳ�Ա�����ܷ��������������ĳ�Ա��
	//p->func("Hello"); //compile error

}

void main() {
	testB();
	cin.get();
}