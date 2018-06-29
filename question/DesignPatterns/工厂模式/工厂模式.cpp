#include<iostream>
using namespace std;
/*
�����ţ���ա�
*/

//��Ʒ������
class Fruit {
public:
	virtual void sayname() = 0;
};

//���󹤳�
class FruitFactory {
public:
	virtual Fruit *getFruit() = 0;
};


//Banana��Ʒ
class Banana :public Fruit {
public:
	virtual void sayname() {
		cout << "Banana" << endl;
	}
};

//Banana ����
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

//Apple ����
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

//����Pear���� ����ȥ�޸Ĺ�����
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

	//׷������Pear
	ff = new PearFactory();
	fruit = ff->getFruit();
	fruit->sayname();

	delete ff;
	delete fruit;


	cin.get();
}