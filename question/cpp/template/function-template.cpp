#include<iostream>
using namespace std;

/*
函数模版
template<typename 参数类型1, 参数类型2...>  返回值类型  函数名(形参列表){
    //在函数体中可以使用类型参数
}
类型参数可以有多个，它们之间以逗号,分隔。类型参数列表以< >包围，形式参数列表以( )包围。
*/

#if 0
// 重载
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif

//类似泛型

//上面两个方法压缩成 函数模板 template<typename T>被称为模板头。
template<typename T> void swap(T *a, T*b) { //指针
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
普通函数调用：可以进行隐式的类型转换
模版函数重载调用（本质：类型叁数化）：将严格的按类型进行匹配，不会进行自动类型转换
*/
template<class  T> void pSwap(T &a, T &b) { //引用
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T> void pSwap(T a[], T b[], int len) { //重载：交换两个数组
	T temp;
	for (int i = 0; i<len; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}



void printArray(int arr[], int len) {
	for (int i = 0; i<len; i++) {
		if (i == len - 1) {
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

void test1() {
	int a = 100, b = 200;
	swap(&a, &b);
	cout << a << ", " << b << endl;  // 200 100

	char a1 = 'Z', b1 = 'A';
	pSwap(a1, b1);
	cout << a1 << ", " << b1 << endl; // A Z

	char a2 = 'x', b2 = 'y';
	pSwap(a2, b2);
	cout << a2 << ", " << b2 << endl; // y x
}

//函数模版重载
void test2() {

	char a3 = 'Y', b3 = 'X';
	pSwap(a3, b3);
	cout << a3 << ", " << b3 << endl; // A Z

	cout << "----------------------------------------" << endl;

	//交换两个数组
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 10, 20, 30, 40, 50 };

	int len = sizeof(a) / sizeof(int);  //数组长度
	
	//
	int *c = a; //c指向数组a首地址 
	cout << "c=" << c << endl;
	printArray(c, len); // 1, 2, 3, 4, 5

	

	pSwap(a, b, len);									  //匹配模板②
	printArray(a, len);
	printArray(b, len);

	/*
	X, Y
	----------------------------------------
	10, 20, 30, 40, 50
	1, 2, 3, 4, 5
	*/

}

// 返回类型也是T
template<typename T> T max(T a, T b, T c) {
	T max_num = a;
	if (b > max_num) max_num = b;
	if (c > max_num) max_num = c;
	return max_num;
}

void test3() {
	int a = 1, b = 5, c = 100;
	int max_num = max(a, b, c);
	cout << max_num << endl;
}

/*
普陀函数与函数模版重载(当符合条件时 普通函数优先选择)，若显示使用函数模版<>  mySwap<>(a, b);
普通函数调用：可以进行隐式的类型转换
模版函数重载调用（本质：类型叁数化）：将严格的按类型进行匹配，不会进行自动类型转换
*/
template<typename T> void mySwap(T &a, T &b) {
	T c = 0;
	c = a;
	a = b;
	b = c;
}

void mySwap(int a, int c) {
	cout << "a: " << a << "c:" << c << endl;
}

int main111() {
//	test2();

	int a = 10;
	int b = 10;
	char c = 'A';

	mySwap(a, c); //普通函数 隐式的类型转换

	mySwap(a, b);//函数模版

	system("pause");
	return 0;
}

