#include "iostream"

using namespace std;

int d17getAA1()
{
	int a;
	a = 10;
	return a;
}

//���ص���ջ���� ���ܳɹ��������õĳ�ʼֵ
int& d17getAA2()
{
	int a; //�������ջ�ϵ����� �п��ܻ������� 
	a = 100;
	return a;
}

//������static ������ȫ�ֱ��� �ǿ��Գ�Ϊ�������õĳ�ʼֵ
int& d17getAA2Static()
{
	static int a; // 
	a = 100;
	return a;
}

int* d17getAA3()
{
	int a;
	a = 1001;
	return &a;
}

//��������ֵ c++�к���Ҫ�ĸ���

//���ر�����ֵ
int d17g1()
{
	static int x = 999;
	x++;
	return x;

}

//���ر������� 
int& d17g2()
{
	static int x = 999;
	x++;
	printf("x:%d\n", x);
	return x;

}

void maind17()
{
	int a1 = 0;
	int a2 = 0;

	a1 = d17getAA1();
	a2 = d17getAA2();

	int &a3 = d17getAA2();//��x86  Debug �����Ǳ��bug ����

	int &a4 = d17getAA2Static();

	printf("a1:%d, a2:%d, a3:%d,a4:%d\n", a1, a2, a3,a4);

	//d17g1() = 100; //����
	d17g2() = 200; //�൱�� a = 200;
	d17g2(); //201

	cout << "hello..." << endl;

	system("pause");
	return;
}