#include<iostream>
using namespace std;

/*
Ĭ�ϲ���
1 Ĭ�ϲ������������ұ�
2 û��ָ�����������ֵ�����������Զ���Ĭ��ֵ����
3 ��������
*/
#if 1
void myPrint(int x = 2) {
	cout << "x=" << x << endl;
}

void myPrint2(int x = 2, int y = 4) {
	cout << "x=" << x << endl;
}

void myPrint3(int m, int x = 2, int y = 4) {
	cout << "x=" << x << endl;
}

void test1() {
	int a = 1;
	int b = 3;

	myPrint(b);
}

#endif

/*
����ռλ�� (���������ʱ)
*/
#if 2
void func1(int a, int b, int =0) {
	cout << "a=" << a << "b=" << b << endl;
}

void testFunc() {
	func1(1, 2);
	func1(1, 2, 3);
}

#endif

void main2() {

	testFunc();

	cin.get();
}