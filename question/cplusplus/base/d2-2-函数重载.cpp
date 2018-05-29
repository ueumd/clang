#include "iostream"

using namespace std;
/*
至少满足下面一个条件：
参数个数不同
参数类型不同
参数顺序不同

函数返回值不是函数重载的判断标准
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

//函数重载和函数参数默认编译是可以通过，但是调用时非产生二义性 不知道该调哪个
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