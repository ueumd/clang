#include<iostream>
using namespace std;

/*
�������
Type &name = data; �����

1 ���û���
2 ���õ���ֵ
3 ָ�������
4 const ����
*/

// ���������������� ��ͨ�������ʼ�� 
void r1() {
	int a = 10;
	int &b = a;  //int * const b = &a;
	// int &c; complie error 

	printf("a=%d, b=%d\n", a, b); // 10 10
	
	b = 200;    // *b=200;
	printf("a=%d, b=%d\n", a, b); // 20 200

#if 0
	c lang
	int a = 10;
	int * const b = &a;
	*b = 200;
#endif
}

// ������������
struct Teacher
{
	char name[60];
	int age;
};

void printTea1(Teacher *t) {
	t->age = 500;
	cout << t->age << endl;
}


void printTea2(Teacher &t) {
//	t.age = 300;
	cout << t.age << endl;
}

void printTea3(Teacher t) {
	t.age = 200;
	cout << t.age << endl;
}

void r2() {
	Teacher t1;
	t1.age = 10;

	printTea1(&t1);	//ָ�� 
	cout << t1.age << endl;

	printTea2(t1);  //����
	printTea3(t1);  //t���βΣ� t1 ����һ�����ݸ�t t=t1;
	
	cout << t1.age << endl;
}


//���õı���
//������c++���ڲ�ʵ����һ����ָ�� Type& name <->Type * const name
#if 1
//cpp
void func(int &a) {
	a = 5;
}
//c a���������޸ģ�����aָ����ڴ�ռ�����޸�
void func(int *const a) {
	//a = 100;
	*a = 5;
}
#endif

/*
const���ý��ۣ�
1. const& �൱��const int* cont e
2. ��ͨ���� �൱�� int * cont e
3. ��ʹ�ó���������������const���ý��г�ʼ��ʱ��c++��������Ϊ����ֵ����ռ䣬������������Ϊ��οռ�ı���
4. ʹ����������const���ó�ʼ���󣬽�����һ��ֻ������
*/

void main() {
	r2();
	cin.get();
}