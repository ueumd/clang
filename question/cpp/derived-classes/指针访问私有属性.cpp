#include <iostream>
using namespace std;
class A {
public:
	A(int a, int b, int c);
private:
	int m_a;
	int m_b;
	int m_c;
};

A::A(int a, int b, int c) : m_a(a), m_b(b), m_c(c) { }

int main() {
	A obj(1, 2, 3);
	// int a = obj.m_a;

	A *p = new A(40, 50, 60);
	// int p = pObj->m_a;   // compile error

	int p2 = * (int *)p;				//将p这个指针强制转换成int类型指针(int *)p，前*号表示再取值
	int c = *(int *)((int)p + sizeof(int) * 2);	//60

	cout << "p2 = " << p2 <<", c=" << c << endl; // 40 60


	system("pause");
	return 0;
}