#include<iostream>
using namespace std;
//抽像类
class Fruit {
public:
	virtual void getFruit() = 0;
};

//产品
class Banana :public Fruit {
public:
	void getFruit() {
			cout << "Banana" << endl;
	}
};

class Apple :public Fruit {
public:
	void getFruit() {
		cout << "Apple" << endl;
	}
};

class Pear :public Fruit {
public:
	void getFruit() {
		cout << "Pear" << endl;
	}
};


/*
	工厂 生产水果
	思想：核心思想是用一个工厂，来根据输入的条件产生不同的类，然后根据不同类的virtual函数得到不同的结果。
	元素分析：
	抽象产品类：水果类
	具体的水果了：香蕉类、苹果类、梨子
	优点适用于不同情况创建不同的类时
	缺点客户端必须要知道基类和工厂类，耦合性差增加一个产品，需要修改工厂类，比如现在要生产 梨子

	由于工厂类集中了所有实例的创建逻辑，所以“高内聚”方面做的并不好。
*/

class Factory {
public:
	static Fruit *Create(char *name) {
		Fruit *tmp = NULL;
		if (strcmp(name, "apple") ==0) {
			tmp = new Apple();
		}
		else if (strcmp(name, "banana") == 0) {
			tmp = new Banana();
		}
		/*
		...生产其他水果, 扩展性并不很好
		*/
		else {
			cout << "没有设备，不能生产" << endl;
			return NULL;
		}
		return tmp;
	}
};


void main() {

	Fruit *apple = Factory::Create("apple");
	apple->getFruit();

	Fruit *banana = Factory::Create("banana");
	banana->getFruit();

	Fruit *pear = Factory::Create("pear");
	if (NULL != pear) {
		pear->getFruit();
	}

	delete apple;
	delete banana;
	delete pear;

	cin.get();
}