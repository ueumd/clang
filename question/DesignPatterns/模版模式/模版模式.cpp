#include<iostream>
using namespace std;
/*
它把具有特定步骤算法中的某些必要的处理委让给抽象方法，通过子类继承对抽象方法的不同实现改变整个算法的行为。

应用场景
Template Method模式一般应用在具有以下条件
的应用中：
- 具有统一的操作步骤或操作过程
- 具有不同的操作细节
- 存在多个具有同样操作步骤的应用场景，但某些具体的操作细节却各不相同

总结：
在抽象类中统一操作步骤，并规定好接口；让子类实现接口。这样可以把各个具体的子类和操作步骤接耦合

*/

class MakeCar {
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;
public:
	//模版函数 把业务逻辑处理好
	void Make() {
		MakeTail();
		MakeBody();
		MakeHead();
	}
};

class Jeep : public MakeCar {
public:
	virtual void MakeHead() {
		cout << "Jeep Head" << endl;
	}
	virtual void MakeBody() {
		cout << "Jeep Body" << endl;
	}
	virtual void MakeTail() {
		cout << "Jeep Tail" << endl;
	}
};

class BMW : public MakeCar {
public:
	virtual void MakeHead() {
		cout << "BMW Head" << endl;
	}
	virtual void MakeBody() {
		cout << "BMW Body" << endl;
	}
	virtual void MakeTail() {
		cout << "BMW Tail" << endl;
	}
};


void main() {

	MakeCar *car = new Jeep;
	car->Make();

	car = new BMW;
	car->Make();

	delete car;

	cin.get();
}