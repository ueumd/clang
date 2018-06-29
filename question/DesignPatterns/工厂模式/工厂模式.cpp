#include<iostream>
using namespace std;
/*
“开放－封闭”
*/

//产品抽像类
class Fruit {
public:
	virtual void sayname() = 0;
};

//抽象工厂
class FruitFactory {
public:
	virtual Fruit *getFruit() = 0;
};


//Banana产品
class Banana :public Fruit {
public:
	virtual void sayname() {
		cout << "Banana" << endl;
	}
};

//Banana 工厂
class BananaFactory:public FruitFactory {
public:
	virtual Fruit *getFruit() {
		return new Banana();
	}
};


class Apple :public Fruit {
public:
	virtual void sayname() {
		cout << "Apple" << endl;
	}
};

//Apple 工厂
class AppleFactory :public FruitFactory {
public:
	virtual Fruit *getFruit() {
		return new Apple();
	}
};


class Pear :public Fruit {
public:
	virtual void sayname() {
		cout << "Pear" << endl;
	}
};

//建立Pear工厂 不用去修改工厂类
class PearFactory :public FruitFactory {
public:
	virtual Fruit *getFruit() {
		return new Pear();
	}
};


void main() {

	FruitFactory *ff = NULL;
	Fruit *fruit = NULL;

	ff = new BananaFactory();
	fruit = ff->getFruit();
	fruit->sayname();

	delete ff;
	delete fruit;

	ff = new AppleFactory();
	fruit = ff->getFruit();
	fruit->sayname();

	delete ff;
	delete fruit;

	//追加生产Pear
	ff = new PearFactory();
	fruit = ff->getFruit();
	fruit->sayname();

	delete ff;
	delete fruit;


	cin.get();
}