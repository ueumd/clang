#include "iostream"

using namespace std;
class ComplexA
{
public:
	int a;
	int b;
public:
	ComplexA(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}
public:
	//��Ա����ʵ������
	ComplexA operator-(ComplexA &c2)
	{
		ComplexA tmp(1, 3);
		return tmp;
	}
}

//ȫ�ֺ���
ComplexA myAdd( ComplexA &c1,  ComplexA &c2) {
	//Complex2 tmp(1, 2);
	ComplexA tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

// ȫ�ֺ���ʵ��ʵ�� c1+c2  �����  operator�ؼ��� 
ComplexA operator+(ComplexA &c1, ComplexA &c2)
{
	//Complex2 tmp(1, 2);
	ComplexA tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

void ComplexA()
{
	ComplexA c1(1, 2), c2(3, 4);
	ComplexA c3;
	//c3 = c1 + c2; �û��Զ������� c++��������֪������ν��м����

	//��������ػ���


	//Complex2 c4 = myAdd(c1, c2);
	//c4.printCom();

	//Complex2 c5 = operator+(c1, c2);
	//c5.printCom();

	ComplexA c5 = c1 + c2; //�Զ�ȥ��operator+
	c5.printCom();

}

void runComplex2()
{
	ComplexA c1(1, 2);
	ComplexA c2(100, 10);

	ComplexA c3 = c1.operator-(c2);

	c3.printCom();
}

void maind45()
{
	//runComplex();
	runComplex2();

	/*
	�ܽ᣺��������صı��� �� ��������
	*/

	cout << "hello..." << endl;

	system("pause");
	return;
}