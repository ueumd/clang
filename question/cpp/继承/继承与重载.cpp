#include <iostream>
using namespace std;

class Point {
public:
	int x=5;
	int y=5;
	
	void operator ++() {
		x++;
		y++;
	}

	void show() {
		cout << x << y << endl;
	}

};

class HuaPoint : public Point {
public:
	int z = 10;

	//覆盖
	void operator ++() {
		x++;
		y++;
		z++;
	}


	void show() {
		cout << x << y << z <<endl;
	}
};

void main3() {
	/*
		没有覆盖，父类的重载也可以继承
		覆盖了父类:  再调用父类 hp.Point::operator++();
	*/
	
	HuaPoint hp;
	cout << hp.x << hp.y << hp.z << endl; // 5 5 10

	++hp;
	cout << hp.x << hp.y << hp.z << endl; // 6 6 11


	hp.Point::operator++();
	cout << hp.x << hp.y << hp.z << endl; // 7 7 11

	//	hp.Point:: 只能访问对象或者函数
	hp.show();						// 7 7 11
	hp.Point::show();			// 7 7

	cin.get();
}