#include "iostream"

using namespace std;
/*
��׼����������cin
cin.get() һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������)//��һ���ַ�
cin.get(��������)//���Զ�ȡ�ַ���

cin.getline()
cin.ignore()
cin.peek()
cin.puback()
*/

void cintest()
{
	char mybuf[1024];
	int myInt;
	long myLong;

	cin >> myInt;
	cin >> myLong;

	cin >> mybuf; //�����ո��ֹͣ���� ����

	cout << "myInt" << myInt << endl;
	cout << "myLong" << myLong << endl;
	cout << "mybuf" << mybuf << endl;
}

void cinget()
{
	//�ַ�����ڻ�����
	char ch;
	while ((ch = cin.get()) != EOF) //������ctrl+z
	{
		cout << ch << endl;
	}
}

int main()
{
	cintest();
	//cinget();

	cin.get();
	return 0;
}