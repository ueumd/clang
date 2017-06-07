#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

class MyClass
{
private:
	int a;
	int b;
	char *p;
public:
	MyClass()
	{
		a = 10;
		p = (char *)malloc(100);
		//p = "hello,world!";
		strcpy(p, "hello,world!");
		cout << "�޲ι��� ��ִ���� " << endl;
	}

	//�в�
	MyClass(int a, int b)
	{
		this->a = a;
		this->b = b;
		this->p = (char *)malloc(100);
		strcpy(this->p, "hello,world!");
		cout << "�вι��� ��ִ���� " << endl;
	}

	//��ֵ���캯����copy���캯����
	MyClass(const MyClass& obj)
	{
		this->a = obj.a + 1000000;
		this->b = obj.b + 1000000;
		this->p = (char *)malloc(100);
		strcpy(this->p, "hello,world! copy");
		cout << "��Ҳ�ǹ��캯��" << endl;
	}

	int getA() {
		return this->a;
	}

	void print()
	{
		cout << a << endl;
		cout << p << endl;
	}

	~MyClass()
	{
		if (p != NULL)
		{
			free(p);
		}
		cout << "�������� ��ִ���� " << endl;
	}
};

void testClass(MyClass mc)
{
	cout << "age is:" << mc.getA() << endl;
}

/*
������һ��Ԫ�ض���������MyClass(��������)
���ص���һ���µ������������Ի�������������copy���캯��
���������ȥ���� :
	������������� ��ʼ�� ����һ��ͬ��Ķ��� �������� ת����������
	������������� ��ֵ�� ����һ��ͬ��Ķ��� �������� ������
*/
MyClass g()
{
	MyClass MY(300, 300);
	return MY;
}

void runMyClass()
{
	printf("-------------mc1-----------------\n");
	//�ȴ����Ķ��� ���ͷ� 
	MyClass mc; //ֱ�ӵ����޲ι��캯��
	mc.print();

	printf("-------------mc2-----------------\n");

	MyClass mc2(1000,4);
	mc2.print();

	printf("---------------mc4---------------\n");
	MyClass mc4 = mc2; //ִ�е���copy���캯��
	mc4.print();

	testClass(mc4);//������copy���캯��

	printf("---------------mc5---------------\n");

	//�����������ʼ��m ��ʱc++������ ֱ�Ӱ���������ת�� mc5 ��������ת������ mc5
	MyClass mc5=g(); //�������󲻻ᱻ������
	mc5.print();

	//MyClass mc5 (20,1); 
	//mc5=g();//��������ֵ�� mc5�ᱻ������ ������mc5

	printf("---------------xg---------------\n");
}

void maind31()
{
	runMyClass();

	cout << "hello..." << endl;

	system("pause");
	return;
}