#include<iostream>
using namespace std;
/*
����ģʽ һ��ֻ������һ����Ʒ��ҪôBanana ҪôApple ҪôPear
���󹤳� ��ͬʱ����һ����Ʒ�塣===�����󹤳�����ԭ��
*/

//��Ʒ������
class Fruit {
public:
	virtual void sayname() = 0;
};

//���󹤳�
class FruitFactory {
public:

	// ����ģʽ 
	// virtual Fruit *getFruit() = 0;

	// ���󹤳� ��Ʒ��д���ˣ�����
	virtual Fruit *getApple() = 0;
	virtual Fruit *getBanana() = 0;
};


//�Ϸ��㽶
class SouthBanana :public Fruit {
public:
	virtual void sayname() {
		cout << "SouthBanana" << endl;
	}
};

//�����㽶
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

//�Ϸ�����
class SouthFactory :public FruitFactory {
public:
	virtual Fruit *getApple() {
		return new SouthApple();
	}
	virtual Fruit *getBanana() {
		return new SouthBanana();
	}
};

//��������
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