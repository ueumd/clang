#include <iostream>
using namespace std;
/*
���� ��д �ض��壺

���أ�
	1. ���ر����� 1 ����֮��
	2. �����޷����ظ���ĺ���������ͬ�������������Ƹ���
	3. �������ڱ����ڼ���ݲ������ͺ͸���������������

��д
	1. ��д������ 2 ����֮�䣨�������ࣩ
	2. ���Ҹ����������к�������ͬ����ȫ��ͬ��ԭ�ͣ����� ���� ������

��д�� 2 �ࣺ
	1. �麯����д ������̬
	2. ���麯����д ���ض��壩
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
	// ��д�˸���set����
	void set() {
		cout << "void Derived::set()" << endl;
	}

	void setDerived() {
		cout << "void Derived::setDerived()" << endl;
	}

	// ��д�˸���func�鷽�� ʵ���˶�̬
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
	//b->setDerived(); //���� ���಻���ڴ˷���


	Derived d;
	d.setBase();			// void Base::setBase() �̳й����ĸ��෽��
	d.setDerived();		// void Derived::setDerived()

	d.Base::set();    // void Base::set()
	d.set();					// void Derived::set()  �������඼�У����ȵ��������еķ���

	// c++����������set���ӣ����������Ѿ������ˣ�������ȥ�Ҹ����д�2�����������ֵ�λ�ã�ֻ�����������ң���������û�д�2�������ģ����Ա���
	// d.set(10, 20);
	
	// �����÷� ��ʾ�ĵ���
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

  // ͨ������� ָ�� ֻ�ܷ��ʴӻ���̳й�ȥ�ĳ�Ա�����ܷ��������������ĳ�Ա��
	//p->func("Hello"); //compile error

}

void main1ddd() {
	testBB();
	cin.get();
}