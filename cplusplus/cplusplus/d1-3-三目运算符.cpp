#include "iostream"

using namespace std;

/*
C语言中 表达式的结果 放在寄存器
C语言中，表达式返回值 是变量的值
C++中， 表达式返回的是变量的本身
*/
void maind3m()
{
	int a = 10;
	int b = 30;

	(a > b?a:b) = 100; //在C中是报错的 在C中相当于 10=100

	printf("a:%d b:%d \n", a, b);//100 30

	cout << "hello..." << endl;

	system("pause");
	return;
}