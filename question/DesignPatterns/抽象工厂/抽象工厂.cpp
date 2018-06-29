#include<iostream>
using namespace std;
/*
工厂模式 一次只能生产一个产品，要么Banana 要么Apple 要么Pear
抽象工厂 能同时生产一个产品族。===》抽象工厂存在原因
*/

//产品抽像类
class Fruit {
public:
	virtual void sayname() = 0;
};

//抽象工厂
class FruitFactory {
public:

	// 工厂模式 
	// virtual Fruit *getFruit() = 0;

	// 抽象工厂 产品线写死了！！！
	virtual Fruit *getApple() = 0;
	virtual Fruit *getBanana() = 0;
};


//南方香蕉
class SouthBanana :public Fruit {
public:
	virtual void sayname() {
		cout << "SouthBanana" << endl;
	}
};

//北方香蕉
class NorthBanana :public Fruit {
public:
	virtual void sayname() {
		cout << "NorthBanana" << endl;
	}
};

class SouthApple :public Fruit {
public:
	virtual void sayname() {
		cout << "SouthApple" << endl;
	}
};

class NorthApple :public Fruit {
public:
	virtual void sayname() {
		cout << "NorthApple" << endl;
	}
};

//南方工厂
class SouthFactory :public FruitFactory {
public:
	virtual Fruit *getApple() {
		return new SouthApple();
	}
	virtual Fruit *getBanana() {
		return new SouthBanana();
	}
};

//北方工厂
class NorthFactory :public FruitFactory {
public:
	virtual Fruit *getApple() {
		return new NorthApple();
	}
	virtual Fruit *getBanana() {
		return new NorthBanana();
	}
};



void main() {

	FruitFactory *ff = NULL;
	Fruit *fruit = NULL;

	ff = new SouthFactory();
	fruit = ff->getApple();
	fruit->sayname();

	fruit = ff->getBanana();
	fruit->sayname();

	delete ff;
	delete fruit;

	ff = new NorthFactory();
	fruit = ff->getApple();
	fruit->sayname();

	fruit = ff->getBanana();
	fruit->sayname();

	delete ff;
	delete fruit;


	cin.get();
}