#include "iostream"

using namespace std;
//泛型编程
template<typename T>
void myswap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "我是函数模版" << endl;
}

/*
函数模版遇上函数重载
*/
void myswap(int a, char c)
{
	cout << "a:" << a << "   c:" << c << endl;
	cout << "我是普通函数" << endl;
}
/*
调用：
显示类型 调用
自动类型 推导 (不常用)myswap(x, y)
*/
void main91()
{

	int a = 100, b = 200; char z = 'z';
	
	myswap(a, z);//普通函数调用 会进行隐式的类型转换 调一次函数模版

	myswap<int>(a, b); //函数模版显示调用
	printf("a:%d, b:%d\n", a, b);

	char x = 10, y = 20;

	myswap<char>(x, y); //函数模版显示调用

	printf("x:%d, y:%d\n", x, y);

	cout << "hello..." << endl;

	system("pause");
	return;
}