#include "iostream"

using namespace std;

void maind19()
{
	//普通引用
	int a = 10;
	int &b = a;
	b = 200;

	cout << a << endl;

	//常引用(变量方式 字面量方式)
	int x = 200;
	const int &y = x;
	//常引用 是 让变量 引用只读属性 不能通过y去修改x了
	//y = 100; //error

	//字面量方式
	const int z = 40;
	//int &m = 41; //error 普通引用 引用一个字面量 字面量是没有内存地址
	//引用 就是给内存取多个门牌号（多个别名）41是没有内存地址 
	//解决方案 const
	const int &m = 43;//c++编译器会分配内存空间

	cout << "hello..." << endl;

	system("pause");
	return;
}