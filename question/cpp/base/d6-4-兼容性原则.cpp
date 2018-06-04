#include "iostream"

using namespace std;

class Parent
{
public:
	void printP()
	{
		cout << "���ǵ�" << endl;
	}
	Parent()
	{
		cout << "Parent���캯��" << endl;
	}
	Parent(const Parent &obj)
	{
		cout << "Parent copy���캯��" << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
protected:
private:
	int c;
};

void howToPrint(Parent *base)
{
	base->printP(); //ֻ��ִ�и���� ��Ա����
}

void howToPrint2(Parent &base)
{
	base.printP(); //ֻ��ִ�и���� ��Ա����
}

void maind64()
{
	/*
		���ݹ���
		���������Ե����������ʹ��
		����������ֱ�Ӹ�ֵ���������
		����������ֱ�ӳ�ʼ���������
		����ָ�����ֱ��ָ���������
		�������ÿ���ֱ�������������
	*/


	Parent p1;
	p1.printP();

	Child c1;
	c1.printC();
	c1.printP();

	//��ֵ������ԭ��
	//1 ����ָ�� �����ã� ָ�� ������� 
	Parent *p = NULL;
	p = &c1;
	p->printP();

	//1-2 ָ������������

	howToPrint(&p1);
	howToPrint(&c1);

	//1-3 ��������������
	howToPrint2(p1);
	howToPrint2(c1);

	//�ڶ��㺬��

	//�����ø�������ʼ�� �������
	Parent p3 = c1; //�����Parent�Ŀ������캯��

	cout << "hello..." << endl;

	system("pause");
	return;
}