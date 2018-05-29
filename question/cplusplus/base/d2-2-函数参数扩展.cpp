#include "iostream"

using namespace std;
//参数扩展
void func1(int x = 10, int y = 100)
{
	cout << x + y << endl;
	return;
}

//参数扩展 和占位参数(没意义)
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