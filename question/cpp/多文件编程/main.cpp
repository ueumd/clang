#include"Aclass.h"
#include"Bclass.h"


/*
#pragma once 必须注意，否则成死锁互相包含
include最深层是1024
*/


void test() {
	Aclass a;
	Bclass b;


	// 从下往上销毁
	/*
	Aclass::Aclass()
	Bclass::Bclass()

	Bclass::~Bclass()
	Aclass::~Aclass()
	*/
}

void test2(){
	Bclass b;
	/*
		Aclass::Aclass()
		Bclass::Bclass()
		Aclass::~Aclass()
		Bclass::~Bclass()
	*/
}

void test3() {
	Aclass a;
	Bclass b;

	a.show(&b);
//	b.show(a);
}

/*
互相包含问题很多，尤其是死锁
构造函数 不可以互相包含，造成死锁，栈溢出
头文件互相包含，互相引用对象，引用 指针，可以编译不能执行
*/

void main() {
	test3();
	cin.get();
}