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

void printTea1(Teacher *t) {
	t->age = 500;
	cout << t->age << endl;
}


void printTea2(Teacher &t) {
//	t.age = 300;
	cout << t.age << endl;
}

void printTea3(Teacher t) {
	t.age = 200;
	cout << t.age << endl;
}

void r2() {
	Teacher t1;
	t1.age = 10;

	printTea1(&t1);	//指针 
	cout << t1.age << endl;

	printTea2(t1);  //引用
	printTea3(t1);  //t是形参， t1 拷贝一份数据给t t=t1;
	
	cout << t1.age << endl;
}


//引用的本质
//引用在c++中内部实现是一个常指针 Type& name <->Type * const name
#if 1
//cpp
void func(int &a) {
	a = 5;
}
//c a本身不可以修改，但是a指向的内存空间可以修改
void func(int *const a) {
	//a = 100;
	*a = 5;
}
#endif

/*
const引用结论：
1. const& 相当于const int* cont e
2. 普通引用 相当于 int * cont e
3. 当使用常量（字面量）对const引用进行初始化时，c++编译器会为常量值分配空间，并将引用名作为这段空间的别名
4. 使用字面量对const引用初始化后，将生成一个只读变量
*/

void main() {
	r2();
	cin.get();
}