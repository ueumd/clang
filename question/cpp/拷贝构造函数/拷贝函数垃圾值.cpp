#include <iostream>
using namespace std;
class Hello {
public:
	Hello(int a, int b) :m_a(a), m_b(b) {
		
	}
	Hello(const Hello &stu) {
		//这里没有赋值操作 m_a m_b都会是垃圾值
		cout << "拷贝构造函数" << endl;
	}
public:
	void display() {
		cout << "a=" << m_a << "b=" << m_b << endl;
	}
public:
	int m_a;
	int m_b;
};


void main11111() {
	Hello h(1, 3);    //初始化
	h.display(); // 1 3

	Hello h3(h);			//调用拷贝构造函数
	h3.display();

	/*
	调用拷贝构造函数,如果未定义拷贝构造函数 c++调用默认拷贝构造函数，如果定义了，调用定义的构造函数
	*/
	Hello h2 = h;		// 调用拷贝构造函数 赋值
	h2.display();   // 默认拷贝构造函数 1 3
	/*
	调用拷贝构造函数，里面没有赋值操作，所以垃圾值
	a=-858993460b=-858993460
	*/

	cin.get();
}