#include "iostream"

using namespace std;

void refone()
{
	int a = 10;
	int &b = a;

	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b); //��ӡ��һ���� a��b����ͬһ���ڴ�ռ�����ƺ�
	return;
}

//��ͨ�������Լ��Ŀռ�����
struct MyStruct
{
	char name[64]; //64
	int age;//4	
	int &a;//4 0 ����ָ����ռ���ڴ�ռ�
	int &b;//4 0
};

//���õı���
//������c++���ڲ�ʵ����һ����ָ�� Type& name <-> Type * const name

int modifyA(int &a1) 
{
	a1 = 100;
	return 0;
}

int modifyA2(int * const a1)
{
	*a1 = 101;
	return 0;
}

void main()
{
	refone();
	printf("MyStruct:%d\n", sizeof(MyStruct)); //76

	int a = 10000;
	modifyA(a);
	cout << a << endl; //100

	modifyA2(&a);//�����ָ�룬��Ҫ�����Լ��ֹ�ȡʵ�εĵ�ַ

	cout << a << endl; //101

	cout << "hello..." << endl;

	system("pause");
	return;
}