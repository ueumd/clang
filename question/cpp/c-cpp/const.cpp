#include<iostream>
using namespace std;
//const �����ڴ�ʱ���������������ڼ�
void test() {
	int a;
	const int b = 10;
	int c;

	// int *p = &b; //�������
	printf("&a:%d, &b:%d, &c:%d\n", &a, &b, &c);
}



//const �� define��֮ͬ��; define�ڱ��� Ԥ����׶�
void test2() {
#if 0
	int a = 10;
	int b = 20;
	int array[a + b]; //linux�ں�֧�� gcc������֧�֣�c/c++��������֧��
#endif
	
	//����ͨ��
	const int c = 10;
	const int d = 20;
	int array[c + d];

}

/*
��֮ͬ��
const �������ɱ���������ģ��ṩ���ͼ���������
�궨����Ԥ�����������������ı��滻
*/
void fun1() {
	#define TESTA 10;
	const int test3B = 20;
}


void fun2() {
	//printf("test3B = %d", test3B);
	//printf("define a =  %d", TESTA);
}

void main() {

	cin.get();
}