#include "iostream"

using namespace std;
/*
������������һ��������
����������ͬ
�������Ͳ�ͬ
����˳��ͬ

��������ֵ���Ǻ������ص��жϱ�׼
*/

void myFunPrint(int a)
{
	cout << a << endl;
}
void myFunPrint(char *a)
{
	cout << a << endl;
}
void myFunPrint(int a,int b)
{
	cout << a+b << endl;
}

//�������غͺ�������Ĭ�ϱ����ǿ���ͨ�������ǵ���ʱ�ǲ��������� ��֪���õ��ĸ�
void myFunPrint(int a, int b, int c = 0)
{
	cout << a + b << endl;
}
void main()
{


	cout << "hello..." << endl;

	system("pause");
	return;
}