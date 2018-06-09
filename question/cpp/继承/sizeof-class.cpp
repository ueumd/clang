#include <iostream>
using namespace std;
class E {
	//空类占1个字节
};
class A {
	int a;
};

class B : public A {
	int b;
};

class C : public A, public B {
	int c;

};

void main11() {
	cout << sizeof(E) << endl; //1
	cout << sizeof(A) << endl; //4
	cout << sizeof(B) << endl; //8
	cout << sizeof(C) << endl; //16
	cin.get();
}