#include "iostream"

using namespace std;
//������չ
void func1(int x = 10, int y = 100)
{
	cout << x + y << endl;
	return;
}

//������չ ��ռλ����(û����)
void func2(int x = 10, int y = 100, int = 0)
{
	cout << x + y << endl;
	return;
}

void maind22()
{
	func1();
	func2(1, 2, 3);
	cout << "hello..." << endl;

	system("pause");
	return;
}