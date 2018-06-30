#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
装饰（Decorator ）模式又叫做包装模式。通过一种对客户端透明的方式来扩展对象的功能，是继承关系的一个替换方案。
装饰模式就是把要添加的附加功能分别放在单独的类中，并让这个类包含它要装饰的对象，当需要执行时，客户端就可以有选择地、按顺序地使用装饰功能包装对象。

适用于：
装饰者模式（Decorator Pattern）动态的给一个对象添加一些额外的职责。就增加功能来说，此模式比生成子类更为灵活。
底层类库 输入输出流
*/

class Car
{
public:
	virtual void show() = 0;
};

class RunCar :public Car {
public:
	virtual void show(){
		run();
	}

	void run() {
		cout << "run..." << endl;
	}
};

class SwimCar :public Car {
public:
	SwimCar(Car *p) {
		m_car = p;
	}
	virtual void show() {
		m_car->show();
		swim();
	}
	void swim() {
		cout << "swim..." << endl;
	}

private:
	Car *m_car;
};

class FlyCar :public Car {
public:
	FlyCar(Car *p) {
		m_car = p;
	}
	virtual void show() {
		m_car->show();
		fly();
	}
	void fly() {
		cout << "fly..." << endl;
	}

private:
	Car *m_car;
};

void main() {
	Car *car = NULL;

	car = new RunCar();
	car->show();

	cout << "----------------------" << endl;
	SwimCar *sc = new SwimCar(car);
	sc->show();

	cout << "----------------------" << endl;
	FlyCar *fc = new FlyCar(sc);
	fc->show();
	/*
	
	run...
	----------------------
	run...
	swim...
	----------------------
	run...
	swim...
	fly...
	*/

	delete car;
	delete sc;
	delete fc;

	cin.get();
}