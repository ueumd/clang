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



void r2() {
	Teacher t1;
	t1.age = 10;
}



void main() {
	r1();
	cin.get();
}