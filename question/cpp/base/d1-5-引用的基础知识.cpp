#include "iostream"

using namespace std;

//1 ���õĸ��� 
void refbase()
{
	int a = 10;
	//���õ��﷨ Type& name=var;
	int &b = a;
	//int &c; //��ͨ���ñ���Ҫ��ʼ�� ��Ȼ����

	b = 100; //�൱�ڰ�a�޸ĳ���100



	printf("a:%d, b:%d\n", a, b);//100 100 

	a = 200;

	printf("a:%d, b:%d\n", a, b);// 200 200
}

//2 �ô�
//��������������ʱ�����г�ʼ�� ��ͨ�ı���
int myswap(int &a,int &b)
{
	int c = 0;

	c = a;
	a = b;
	b = c;
	
	return 0;
}

//����������������

struct MyTeacher
{
	char name[64];
	int age;
};
//ָ�뷽ʽ
void printT(MyTeacher *pT)
{
	cout << pT->age << endl;
}

void printT2(MyTeacher &pT)
{
	cout << pT.age << endl; //����Ҫ��.
	pT.age = 10; //��Ӱ��t1
}

void printT3(MyTeacher pT)
{
	cout << pT.age << endl;//Ԫ��Ҫ��.
	pT.age = 1; //����Ӱ��ʵ�����t1
}

void maind15()
{
	int x = 100;
	int y = 10;
	refbase();

	//a����x�ı��� 
	myswap(x,y);
	printf("x:%d, y:%d\n", x, y);// 10 100

	MyTeacher t1;
	t1.age = 100;

	printT(&t1); //100
	printT2(t1); //100 pT��t1������
	printT3(t1); //100 pT���βΣ�t1 ����һ�����ݸ� pT �൱�� pT=t1;

	cout << t1.age << endl; //����Ҫ��.
	cout << "hello..." << endl;

	system("pause");
	return;
}