#include<iostream>

using namespace std;

#if 0
C语言中，表达式的结果，放在寄存器，表达式返回的值 是变量的值
int a = 10;
int b = 20;
(a < b ? a : b) = 30;
三目运算符是一个表达式，表达式不可能做左值 20 = 30
要实现C++效果：
*(a < b ? &a : &b) = 1000;
#endif

#if 0
C++中，表达式返回的是变量的本身
(a < b ? a : b) = 30;
a = 30;
#endif

void main222() {
	int a = 10;
	int b = 20;
	//c++返回变量本身
	(a < b ? a : b) = 30;
	cout << a << "\t" << b << endl; // 30 20

	//原理
	*(a < b ? &a : &b) = 1000;
	cout << a << "\t" << b << endl; // 30 1000

	cin.get();
}