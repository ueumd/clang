#include "iostream"
using namespace std;
/*
至少满足下面一个条件：

参数个数不同
参数类型不同
参数顺序不同

函数返回值不是函数重载的判断标准
*/



#if 1
//函数重载和函数参数默认编译是可以通过，但是调用时非产生二义性 不知道该调哪个
//这样的 重载会产生二意性 myPrintx(a) 有默认参数，不知道选哪个
void myPrintx(int x = 2) {
	cout << "x=" << x << endl;
}

void myPrintx(int x = 2, int y = 4) {
	cout << "x=" << x << y << endl;
}

#endif


void myFunPrint(int a=1)
{
	cout << a << endl;
}

void myFunPrint(char *a)
{
	cout << a << endl;
}

void myFunPrint(int a, int b)
{
	cout << a + b << endl;
}



//函数重载遇到函数指针
typedef int(*PFUNC)(int a, int b); //int(int a)
int funp(char a, char b) {
	return a;
}

int funp(int a, int b) {
	return a + b;
}

//声明一个函数类型
typedef void (myTypeFunc)(int a, int b);

// 声明一个函数指针类型
typedef void(*myTypeFunc)(int a, int b);
void main()
{
	int a = 10, b = 200;
	myFunPrint(a);

	PFUNC p = funp;
	int c = 0;
	c = p(a, b);
	cout << c << endl;


	cin.get();
}