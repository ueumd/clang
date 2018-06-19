#include "iostream"
using namespace std;
template <typename T> class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "a: " << a << endl;
	}
protected:
	T a;
};

void useA(A<int> &a)
{
	a.printA();
}

//��ģ����������ͨ��
//��Ҫ֪��������ռ���ڴ��С�Ƕ��� ֻ�й̶���������֪����η����ڴ�
class B : public A<int>
{
public:
	B(int a = 10, int b = 20) :A<int>(a)
	{
		this->b = b;
	}
	void printB()
	{
		cout << "a: " << a << "b: " << b << endl;
	}
protected:
private:
	int b;
};

template <typename T>class C : public A<T>
{
public:
	C(T c, T a) :A<T>(a)
	{
		this->c = c;
	}
	void printC()
	{
		cout << "a: " << a << " c: " << c << endl;
	}
protected:
	T c;
};

void m1()
{
	//ģ���ࣨ����������ͻ��� == ������� ===>�������ı�����
	A<int> a1(11); //ģ�����ǳ���� ===>��Ҫ���� ���;���
	A<int> a2(20), a3(30);
	a1.printA();


	useA(a2);
	useA(a3);
}

void m2()
{
	B b1(1, 2);
	b1.printB();
}

void m3()
{
	C<int> c1(1, 2);
	c1.printC();
}

void main() {
	m1();
	cin.get();
}