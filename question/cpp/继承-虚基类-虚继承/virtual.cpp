#include<iostream>
using namespace std;

//�����
class A {
public:
	A(int a) :m_a(a) {}
protected:
	int m_a;
};


// ֱ��������B
class B: virtual public A {
public:
	B(int a, int b) :A(a), m_b(b) {}

	void display() {
		cout << "m_a=" << m_a << ", m_b=" << m_b << endl;
	}

protected:
	int m_b;
};

// ֱ��������C
class C : virtual public A {
public:
	C(int a, int c) :A(a), m_c(c) {}

	void display() {
		cout << "m_a=" << m_a << ", m_c=" << m_c << endl;
	}

protected:
	int m_c;
};

//���������D
class D : public B, public C {
protected:
	int m_d;
public:
	void seta(int a) { m_a = a; }   // ��ʹ����̳� ��Ϊ�� B ���� C �ж��г�Ա���� m_a���� A ��̳ж���������������֪��ѡ����һ�������Բ��������塣������
	void setb(int b) { m_b = b; }  //��ȷ
	void setc(int c) { m_c = c; }  //��ȷ
	void setd(int d) { m_d = d; }  //��ȷ

	void setAa(int a) { A::m_a = a; } //

public:
	D(int a, int b, int c, int d) :A(a), B(90, b), C(100, c), m_d(d) {}
	void display() {
		cout << "m_a=" << m_a << ", m_b=" << m_b << ", m_c=" << m_c << ", m_d=" << m_d << endl;
	}
};

void testA() {
	
}

void main() {
	B b(10, 20);
	b.display();

	C c(30, 40);
	c.display();

	D d(50, 60, 70, 80);
	d.display();

	/*
	m_a=10, m_b=20
	m_a=30, m_c=40
	m_a=50, m_b=60, m_c=70, m_d=80
	*/

	cin.get();
}