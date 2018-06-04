#define _CRT_SECURE_NO_WARNINGS

#include "iostream"

using namespace std;

class A615
{
public:
	A615()
	{
		p = new char[20];
		strcpy(p, "ojba");
		printf("A615()\n");
	}
	virtual ~A615()
	{
		delete[] p;
		printf("~A615()\n");
	}

private:
	char *p;
};

class B615 : public A615
{
public:
	B615()
	{
		p = new char[20];
		strcpy(p, "ojbb");
		printf("B615()\n");
	}
	~B615()
	{
		delete[] p;
		printf("~B615()\n");
	}

private:
	char *p;
};


class C615 : public B615
{
public:
	C615()
	{
		p = new char[20];
		strcpy(p, "ojbc");
		printf("C615()\n");
	}
	~C615()
	{
		delete[] p;
		printf("~C615()\n");
	}

private:
	char *p;
};


/*
//�����ͷ���������� ͨ��

ִֻ���˸�������� ����ڴ�й© //delete base; ��仰������ֶ�̬ ��������
����취���ڸ������������ϼ� virtual ����������������Ĺ���

�������������ܣ�
��ͨ������ָ�� �� ���е����������������� ��ִ��һ��
��ͨ������ָ�� �ͷ����е�������Դ
*/
void howToDelete(A615 *base)
{
	delete base;
}

void maind615()
{

	C615 *myC = new C615;

	howToDelete(myC);

	//delete myC;//ͨ�������ͷŲ���Ҫд����������
	
	cout << "hello..." << endl;

	system("pause");
	return;
}