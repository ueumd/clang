#include<iostream>
using namespace std;
/*
cpp �������±��룬Ҫ��ǰʹ���࣬��Ҫ��������
�����������չ������ֻ�ܴ���ָ�������
A *p;
A &p;
A p;����
*/
class A;
class B;

A *p;
void go(A &a) {

}

class A {
public:
	//B b; //Ҫ������
	B *b; //ֻ����ָ�������
};

class B {
public:
	// ��ȷ A����B��ǰ����
	A *a;
	A aa;
};

void main() {
	cin.get();
}