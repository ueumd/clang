#include "iostream"

using namespace std;
//���ͱ��
template<typename T>
void myswap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "���Ǻ���ģ��" << endl;
}

/*
����ģ�����Ϻ�������
*/
void myswap(int a, char c)
{
	cout << "a:" << a << "   c:" << c << endl;
	cout << "������ͨ����" << endl;
}
/*
���ã�
��ʾ���� ����
�Զ����� �Ƶ� (������)myswap(x, y)
*/
void main91()
{

	int a = 100, b = 200; char z = 'z';
	
	myswap(a, z);//��ͨ�������� �������ʽ������ת�� ��һ�κ���ģ��

	myswap<int>(a, b); //����ģ����ʾ����
	printf("a:%d, b:%d\n", a, b);

	char x = 10, y = 20;

	myswap<char>(x, y); //����ģ����ʾ����

	printf("x:%d, y:%d\n", x, y);

	cout << "hello..." << endl;

	system("pause");
	return;
}