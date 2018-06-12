#include<iostream>
using namespace std;

/*
引用语语：
Type &name = data; 起别名

1 引用基础
2 引用当左值
3 指针的引用
4 const 引用
*/

// 基本数据类型引用 普通引必须初始化 
void r1() {
	int a = 10;
	int &b = a;  //int * const b = &a;
	// int &c; complie error 

	printf("a=%d, b=%d\n", a, b); // 10 10
	
	b = 200;    // *b=200;
	printf("a=%d, b=%d\n", a, b); // 20 200

#if 0
	c lang
	int a = 10;
	int * const b = &a;
	*b = 200;
#endif
}

// 复杂数据类型
struct Teacher
{
	char name[60];
	int age;
};



void r2() {
	Teacher t1;
	t1.age = 10;
}



void main() {
	r1();
	cin.get();
}