#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
适用于：
桥接模式（Bridge Pattern）是将抽象部分与实现部分分离（解耦合），使它们都可以独立的变化。
车安装发动机；不同型号的车，安装不同型号的发动机
将“车安装发动机”这个抽象和实现进行分离；两个名字就设计两个类； 车类 发动机类
*/

class Car {
public:
	virtual void installEngine() = 0;
};

class BMW5 :public Car {
public:
	virtual void installEngine() {
		cout << "BMW5 3500CC" << endl;
	}
};

class BMW6 : public Car{
public:
	virtual void installEngine(){
		cout << "BMW6 4000CC" << endl;
	}
};

class Jeep11 : public Car {
public:
	virtual void installEngine(){
		cout << "Jeep11 1100CC" << endl;
	}
};

class Jeep12 : public Car {
public:
	virtual void installEngine() {
		cout << "Jeep12 1200CC" << endl;
	}
};

/*
不同的车型，不同型号，安装不同类型的发动机，会引起子类的泛滥
问题引出
*/
void test1()
{
	Jeep12 *j12 = new Jeep12;
	j12->installEngine();
	delete j12;
	return;
}

class Car2 {
public:
	virtual void installEngine3500() = 0;
	virtual void installEngine4000() = 0;
	virtual void installEngine1100() = 0;
	virtual void installEngine1200() = 0;

};

class BMW : public Car2
{
public:
	virtual void installEngine3500()
	{
		cout << "3500CC" << endl;
	}
	virtual void installEngine4000()
	{
		cout << "4000CC" << endl;
	}
	virtual void installEngine1100()
	{
		cout << "1100CC" << endl;
	}
	virtual void installEngine1200()
	{
		cout << "1200CC" << endl;
	}
};

/*
这样的设计不符合开闭原则，增加发动机还要修改Car2类
*/
void test2()
{
	BMW *bmw5 = new BMW;
	bmw5->installEngine3500();
}

/*
需要把“安装发动机”这个事，做很好的分解；把抽象和行为实现分开
发动机是一个名次，专门抽象成一个类；类中含有一个成员函数，安装发动机
*/
class Engine {
public:
	virtual void installEngine() = 0;
};

class Engine4000 : public Engine{
public:
	virtual void installEngine(){
		cout << "安装发动机 Engine4000" << endl;
	}
};

class Engine3500 : public Engine {
public:
	virtual void installEngine(){
		cout << "安装发动机 Engine 3500" << endl;
	}
};

class Car3 {
public:
	Car3(Engine *pEngine) {
		m_engine = pEngine;
	}
	virtual void installEngine() = 0;
protected:
	Engine *m_engine;
};

class BMW7 :public Car3 {
public:
	BMW7(Engine *p) :Car3(p) {}

	//注意车的安装和发动机的安装不同之处
	virtual void installEngine() {
		cout << "BMW7";
		m_engine->installEngine();
	}
};

void test3() {
	Engine4000 *e4000 = new Engine4000;
	BMW7 *bmw7 = new BMW7(e4000);

	bmw7->installEngine();
	delete e4000;
	delete bmw7;
}

void main() {
	//test1();
	//test2();
	test3();
	cin.get();
}