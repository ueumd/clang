#include "iostream"

using namespace std;
struct Teacher {
	char name[64];
	int age;
};

//ָ����ָ����ڴ�ռ䣬���ܱ��޸�
int operatorTeacher01(const Teacher *pT)
{
	//pT->age=10; //error
	return 0;
}

//ָ������������޸�
int operatorTeacher02(Teacher * const pT)
{
	pT->age=10;
	//pT = NULL;//error
	return 0;
}

//ָ������������޸�,ָ����ڴ�ռ�Ҳ���ܱ��޸�
int operatorTeacher03(const Teacher * const pT)
{
	//pT->age = 10; //error
	//pT = NULL;//error

	printf("age:%d\n", pT->age); //���Զ� age:100
	return 0;
}



void maind14()
{
	Teacher t1;
	t1.age = 100;

	operatorTeacher03(&t1);

	cout << "hello..." << endl;

	system("pause");
	return;
}

/*

2 const �� define��֮ͬ��

��ͬ #define �ڱ���Ԥ����׶� ����   const �����ڴ��ʱ�� �����������ڼ�

*/

#define xyzb 100
void maind143()
{
	int a;
	const int b = 10;

	int c;

	printf("&a:%d, &b:%d, &c:%d\n", &a, &b, &c);

	/*int x = 10;
	int y = 20;
	int array[x + y];*/
	//linux�ں����ǳ����� linux�ں˵�gcc������֧��  ��c��c++��������֧�� 

	const int x = 10;
	const int y = 20;
	int array2[x + y + xyzb];


	system("pause");
	return;
}