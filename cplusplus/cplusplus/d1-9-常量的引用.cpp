#include "iostream"

using namespace std;

void maind19()
{
	//��ͨ����
	int a = 10;
	int &b = a;
	b = 200;

	cout << a << endl;

	//������(������ʽ ��������ʽ)
	int x = 200;
	const int &y = x;
	//������ �� �ñ��� ����ֻ������ ����ͨ��yȥ�޸�x��
	//y = 100; //error

	//��������ʽ
	const int z = 40;
	//int &m = 41; //error ��ͨ���� ����һ�������� ��������û���ڴ��ַ
	//���� ���Ǹ��ڴ�ȡ������ƺţ����������41��û���ڴ��ַ 
	//������� const
	const int &m = 43;//c++������������ڴ�ռ�

	cout << "hello..." << endl;

	system("pause");
	return;
}