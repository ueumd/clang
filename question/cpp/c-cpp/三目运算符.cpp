#include<iostream>

using namespace std;

#if 0
C�����У����ʽ�Ľ�������ڼĴ��������ʽ���ص�ֵ �Ǳ�����ֵ
int a = 10;
int b = 20;
(a < b ? a : b) = 30;
��Ŀ�������һ�����ʽ�����ʽ����������ֵ 20 = 30
Ҫʵ��C++Ч����
*(a < b ? &a : &b) = 1000;
#endif

#if 0
C++�У����ʽ���ص��Ǳ����ı���
(a < b ? a : b) = 30;
a = 30;
#endif

void main222() {
	int a = 10;
	int b = 20;
	//c++���ر�������
	(a < b ? a : b) = 30;
	cout << a << "\t" << b << endl; // 30 20

	//ԭ��
	*(a < b ? &a : &b) = 1000;
	cout << a << "\t" << b << endl; // 30 1000

	cin.get();
}