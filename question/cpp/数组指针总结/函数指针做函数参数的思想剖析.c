#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int myadd(int a, int b) { //�������ʵ����
	printf("func add ... \n");
	return a + b;
}

int myadd2(int a, int b) { //�������ʵ����
	printf("func add ... \n");
	return a + b;
}

int myadd3(int a, int b) { //�������ʵ����
	printf("func add ... \n");
	return a + b;
}

// ����һ������ָ������
typedef int(*MyTypeFuncAdd)(int a, int b);

//����ָ�� �� ��������
int MainOp(MyTypeFuncAdd myFuncAdd) {
	int c = myFuncAdd(5, 6);
	return c;
}

int MainOp2(int(*MyPointerFuncAdd)(int a, int b)) {
	int c = MyPointerFuncAdd(5, 6);
	return c;
}

/*
Ϊʲô������ƣ�
������� �������д�ֿ�
*/

//���������
void test() {
	MyTypeFuncAdd myFuncAdd = NULL;
	myFuncAdd = myadd;

	myadd(1, 2);		// ֱ�ӵ���	
	myFuncAdd(3, 4); //��ӵ���

	MainOp(myadd);
	MainOp2(myadd);

	//��MainOp��� û�з����κα仯�������
	MainOp(myadd2);
	MainOp(myadd3);
}

void main() {
	test();

	system("pause");
}