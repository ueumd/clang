#include "iostream"
using namespace std;
class A 
{
public:
	A(int _a)
	{
		a = _a;
		cout << "A�Ĺ��캯�� a"<< a << endl;
	}
	~A()
	{
		cout << "A����������: a" << a << endl;
	}
private:
	int a;
};

class B
{
public:
	B(int _b):a1(100),a2(200),c(20)
	{
		b = _b;
		cout << "B�Ĺ��캯�� b" << b << endl;
	}

	B(int _b1,int m, int n) :a1(m),a2(n), c(200)
	{
		b = _b1;
		cout << "B�Ĺ��캯�� b" << b << c << endl;
	}

	~B()
	{
		cout << "B���������� b" << b << endl;
	}
private:
	int b;
	A a1;
	A a2;
	const int c; //����ʱ�����ʼ��
};

void TestA()
{
	B objB(1,3,5); // A ->B �����죩 B-A��������
}

void maind33()
{
	TestA();
	cout << "hello..." << endl;

	system("pause");
	return;
}