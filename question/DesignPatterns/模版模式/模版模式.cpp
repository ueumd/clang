#include<iostream>
using namespace std;
/*
���Ѿ����ض������㷨�е�ĳЩ��Ҫ�Ĵ���ί�ø����󷽷���ͨ������̳жԳ��󷽷��Ĳ�ͬʵ�ָı������㷨����Ϊ��

Ӧ�ó���
Template Methodģʽһ��Ӧ���ھ�����������
��Ӧ���У�
- ����ͳһ�Ĳ���������������
- ���в�ͬ�Ĳ���ϸ��
- ���ڶ������ͬ�����������Ӧ�ó�������ĳЩ����Ĳ���ϸ��ȴ������ͬ

�ܽ᣺
�ڳ�������ͳһ�������裬���涨�ýӿڣ�������ʵ�ֽӿڡ��������԰Ѹ������������Ͳ�����������

*/

class MakeCar {
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;
public:
	//ģ�溯�� ��ҵ���߼������
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