#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
װ�Σ�Decorator ��ģʽ�ֽ�����װģʽ��ͨ��һ�ֶԿͻ���͸���ķ�ʽ����չ����Ĺ��ܣ��Ǽ̳й�ϵ��һ���滻������
װ��ģʽ���ǰ�Ҫ��ӵĸ��ӹ��ֱܷ���ڵ��������У���������������Ҫװ�εĶ��󣬵���Ҫִ��ʱ���ͻ��˾Ϳ�����ѡ��ء���˳���ʹ��װ�ι��ܰ�װ����

�����ڣ�
װ����ģʽ��Decorator Pattern����̬�ĸ�һ���������һЩ�����ְ�𡣾����ӹ�����˵����ģʽ�����������Ϊ��
�ײ���� ���������
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