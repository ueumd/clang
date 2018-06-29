#include<iostream>
using namespace std;
//������
class Fruit {
public:
	virtual void getFruit() = 0;
};

//��Ʒ
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
	���� ����ˮ��
	˼�룺����˼������һ�����������������������������ͬ���࣬Ȼ����ݲ�ͬ���virtual�����õ���ͬ�Ľ����
	Ԫ�ط�����
	�����Ʒ�ࣺˮ����
	�����ˮ���ˣ��㽶�ࡢƻ���ࡢ����
	�ŵ������ڲ�ͬ���������ͬ����ʱ
	ȱ��ͻ��˱���Ҫ֪������͹����࣬����Բ�����һ����Ʒ����Ҫ�޸Ĺ����࣬��������Ҫ���� ����

	���ڹ����༯��������ʵ���Ĵ����߼������ԡ����ھۡ��������Ĳ����á�
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
		...��������ˮ��, ��չ�Բ����ܺ�
		*/
		else {
			cout << "û���豸����������" << endl;
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