#include "iostream"
using namespace std;
/*
������������һ��������

����������ͬ
�������Ͳ�ͬ
����˳��ͬ

��������ֵ���Ǻ������ص��жϱ�׼
*/



#if 1
//�������غͺ�������Ĭ�ϱ����ǿ���ͨ�������ǵ���ʱ�ǲ��������� ��֪���õ��ĸ�
//������ ���ػ���������� myPrintx(a) ��Ĭ�ϲ�������֪��ѡ�ĸ�
void myPrintx(int x = 2) {
	cout << "x=" << x << endl;
}

void myPrintx(int x = 2, int y = 4) {
	cout << "x=" << x << y << endl;
}

#endif


void myFunPrint(int a=1)
{
	cout << a << endl;
}

void myFunPrint(char *a)
{
	cout << a << endl;
}

void myFunPrint(int a, int b)
{
	cout << a + b << endl;
}



//����������������ָ��
typedef int(*PFUNC)(int a, int b); //int(int a)
int funp(char a, char b) {
	return a;
}

int funp(int a, int b) {
	return a + b;
}

//����һ����������
typedef void (myTypeFunc)(int a, int b);

// ����һ������ָ������
typedef void(*myTypeFunc)(int a, int b);
void main()
{
	int a = 10, b = 200;
	myFunPrint(a);

	PFUNC p = funp;
	int c = 0;
	c = p(a, b);
	cout << c << endl;


	cin.get();
}