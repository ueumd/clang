#include<iostream>
using namespace std;

/*
默认参数
1 默认参数必须是最右边
2 没有指定这个参数的值，编译器会自动用默认值代替
3 不能重载
*/
#if 1
void myPrint(int x = 2) {
	cout << "x=" << x << endl;
}

void myPrint2(int x = 2, int y = 4) {
	cout << "x=" << x << endl;
}

void myPrint3(int m, int x = 2, int y = 4) {
	cout << "x=" << x << endl;
}

void test1() {
	int a = 1;
	int b = 3;

	myPrint(b);
}

#endif

/*
函数占位参 (重载运算符时)
*/
#if 2
void func1(int a, int b, int =0) {
	cout << "a=" << a << "b=" << b << endl;
}

void testFunc() {
	func1(1, 2);
	func1(1, 2, 3);
}

#endif

void main2() {

	testFunc();

	cin.get();
}