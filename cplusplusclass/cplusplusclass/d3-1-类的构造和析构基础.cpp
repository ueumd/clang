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

	printf("---------------xg---------------\n");
}

void main()
{
	runMyClass();

	cout << "hello..." << endl;

	system("pause");
	return;
}