#include "iostream"

using namespace std;

/*
C������ ���ʽ�Ľ�� ���ڼĴ���
C�����У����ʽ����ֵ �Ǳ�����ֵ
C++�У� ���ʽ���ص��Ǳ����ı���
*/
void maind3m()
{
	int a = 10;
	int b = 30;

	(a > b?a:b) = 100; //��C���Ǳ���� ��C���൱�� 10=100

	printf("a:%d b:%d \n", a, b);//100 30

	cout << "hello..." << endl;

	system("pause");
	return;
}