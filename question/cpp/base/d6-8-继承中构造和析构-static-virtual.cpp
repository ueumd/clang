#include "iostream"

using namespace std;
/*
���ྲ̬��Ա�����������๲��
���ݾ�̬��Ա�ķ������Ժ�������ļ̳з�ʽ���������о��в�ͬ�ķ������ʣ�����������ķ��ʿ��ƣ�
��������ʾ�̬��Ա��
����������Ա
*/
class A68
{
	/*A68() //�����дpublic ��������ģ������ڵ���ģʾ�����ʹ��˽�е�
	{

	}*/
public:
	int a;
	int b;
	static int c;
public://����ķ��������д���� Ĭ����˽�е� ��Ҫ
	virtual void get()
	{
		cout <<"A68:"<< b << endl;
	}
	void getC()
	{
		cout << "A68:" << c << endl;
	}
};

int A68::c = 100;//���Ǽ򵥵ĸ�ֵ����Ҫ���Ǹ���c++������Ҫ�����ڴ棬���ټ̳����õ���c����Ȼ�ᱨ��

class B68 : public A68
{
public:
	int a;
	int b;
public:
	virtual	void get()
	{
		cout << "B68:" << b << endl;
	}

};

void rund68()
{
	A68 a1;

	B68 b1;
	b1.b = 100;
	/*
	����������Ա�����ͳ�Ա����ͬ��ʱ�ĵ��÷���:

	B.A::a=100;

	*/

	b1.A68::b = 300;

	b1.get();
	b1.A68::get();
}

void rund68static()
{
	
	B68 b1;
	b1.c = 200; //�����˽�м̳��ǲ��ܷ��� c
	b1.A68::getC(); //20

	A68 *a2 = NULL;
	A68 a3;
	a3.b = 1000;
	a2 = &a3;

	a2->get(); // �����

	B68 b2;
	b2.b = 2000;

	a2 = &b2;

	/*
	������಻�� virtaul  a2.get() ����ʱ���������

	��vitraul���� ��̬����Դvirtual
	*/
	a2->get();//��ִ��˭�� 

	

}

void maind68()
{
	
	//rund68();
	rund68static();

	cout << "hello..." << endl;

	system("pause");
	return;
}