#include"Aclass.h"
#include"Bclass.h"


/*
#pragma once ����ע�⣬����������������
include�������1024
*/


void test() {
	Aclass a;
	Bclass b;


	// ������������
	/*
	Aclass::Aclass()
	Bclass::Bclass()

	Bclass::~Bclass()
	Aclass::~Aclass()
	*/
}

void test2(){
	Bclass b;
	/*
		Aclass::Aclass()
		Bclass::Bclass()
		Aclass::~Aclass()
		Bclass::~Bclass()
	*/
}

void test3() {
	Aclass a;
	Bclass b;

	a.show(&b);
//	b.show(a);
}

/*
�����������ܶ࣬����������
���캯�� �����Ի�����������������ջ���
ͷ�ļ�����������������ö������� ָ�룬���Ա��벻��ִ��
*/

void main() {
	test3();
	cin.get();
}