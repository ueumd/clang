#include<iostream>
using namespace std;
//const 分配内存时机，编译器编译期间
void test() {
	int a;
	const int b = 10;
	int c;

	// int *p = &b; //编译错误
	printf("&a:%d, &b:%d, &c:%d\n", &a, &b, &c);
}



//const 和 define相同之处; define在编译 预处理阶段
void test2() {
#if 0
	int a = 10;
	int b = 20;
	int array[a + b]; //linux内核支持 gcc编译器支持；c/c++编译器不支持
#endif
	
	//编译通过
	const int c = 10;
	const int d = 20;
	int array[c + d];

}

/*
不同之处
const 常量是由编译器处理的，提供类型检查和作用域
宏定义由预处理器处理，单纯的文本替换
*/
void fun1() {
	#define TESTA 10;
	const int test3B = 20;
}


void fun2() {
	//printf("test3B = %d", test3B);
	//printf("define a =  %d", TESTA);
}

void main() {

	cin.get();
}