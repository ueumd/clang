#include "iostream"

using namespace std;
/*
�������أ�
	������ͬһ�����н���
	�����޷����ظ���ĺ���������ͬ�������������Ƹ��� ��Ҫ���ʼ�.:: ��÷� ��ʾ����  B.AA::.c
	�������ڱ����ڼ���ݲ������ͺ͸���������������

������д��
	���뷢���ڸ��������֮��
	���Ҹ���������ĺ�������������ͬ��ԭ��
	ʹ�� virtual����֮���ܹ�������̬�������ʹ�� �ǽ� �ض��壩
	��̬���������ڼ���ݾ����������;�����������

*/
class Parent1616
{
public:
	int abc()
	{
		printf("parent abc");
		return 0;
	}
	//���������������ع�ϵ
	virtual void func()
	{
		cout << "func() do.." << endl;
	}
	virtual void func(int i)
	{
		cout << "func() do.." << i << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "func() do.." << i << j <<endl;
	}

};

class Child1616 : public Parent1616
{
public:
	//��������д ���ض���
	int abc()
	{
		printf("child abc");
		return 0;
	}

	int abc(int i)
	{

		printf("child abc");
		return 0;
	}

	//�麯����д�����func ��������̬
	virtual void func(int i)
	{
		cout << "func() do.." << i << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "func() do.." << i << j << endl;
	}

	virtual void func(int i, int j, int k)
	{
		cout << "func() do.." << i << j << k << endl;
	}

};


void maind616()
{

	Child1616 c1;
	c1.Parent1616::func(); //�����func�Ѹ����func�޲κ����������ˣ�����Ҫ��ʾ����
	c1.func(100);

	//vs2015���������ʣ�
	c1.func(100, 200, 300);

	cout << "hello..." << endl;

	system("pause");
	return;
}