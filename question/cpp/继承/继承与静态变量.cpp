#include <iostream>
using namespace std;
/*
static 成员变量属于类，不属于某个具体的对象，即使创建多个对象，也只为 num 分配一份内存，所有对象使用的都是这份内存中的数据。
当某个对象修改了 num，也会影响到其他对象。

static 成员变量必须在类声明的外部初始化，具体形式为：type class::name = value;
int Hello::num = 0;
int Hello::count = 100;

父类的静态变量 ， 被所有的父类对象，子类对象共享，统计一个家族对象个数
类（父类 ，子类）名直接访问， 对象（父类 ，子类）名访问

静态变量 public 所有类对象及派生类对象都可以访问
静态变量 private 类对象内部可以访问,设定化开接口 get set
静态变量 protectd 类对象及派生类对象内部可以访问，外部必须设定接口

静态变量的接口，原则都设定为静态函数，不需要this指针，不依赖于一个对象
*/

class Hello {
private:
	static int count; // 不被继承
		
public:
	static int num; //多个对象共享，不计类的大小
	Hello() {
		num += 1;
	}
	~Hello() {
		num -= 1;
	}

public:
	static void setCount(int c) {
		count=c;
	}

	static int getCount() {
		return count;
	}

};

// static 成员变量必须在类声明的外部初始化，具体形式为：type class::name = value;
int Hello::num = 0;
int Hello::count = 100;

class World :public Hello {

};

void testHello() {
	cout << sizeof(Hello) << endl; //1
	cout << sizeof(World) << endl; //1
	cout << World::num << endl;		 //0
}

//静态变量 派生类也可以访问并累计
void testWord() {
	Hello h1, h2;
	World w1, w2;

	cout << sizeof(Hello) << endl; //1
	cout << sizeof(World) << endl; //1
	cout << World::num << endl;		 //4

	cout << h1.num << endl;	//	4
	cout << w1.num << endl;	//  4

	h1.setCount(10);
	cout << h1.getCount() << endl; // 10
	cout << w1.getCount() << endl; // 10

}

void mainstatic() {

	testWord();

	cin.get();
}