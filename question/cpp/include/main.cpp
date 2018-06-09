#include<iostream>
using namespace std;
/*
cpp 从上往下编译，要提前使用类，就要先声明类
类的声明，拓展作用域，只能创建指针或引用
A *p;
A &p;
A p;错误
*/
class A;
class B;

A *p;
void go(A &a) {

}

class A {
public:
	//B b; //要先声明
	B *b; //只能是指针或引用
};

class B {
public:
	// 正确 A类在B类前定义
	A *a;
	A aa;
};

void main() {
	cin.get();
}