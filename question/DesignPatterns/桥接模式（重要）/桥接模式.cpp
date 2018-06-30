#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
�����ڣ�
�Ž�ģʽ��Bridge Pattern���ǽ����󲿷���ʵ�ֲ��ַ��루����ϣ���ʹ���Ƕ����Զ����ı仯��
����װ����������ͬ�ͺŵĳ�����װ��ͬ�ͺŵķ�����
��������װ����������������ʵ�ֽ��з��룻�������־���������ࣻ ���� ��������
*/

class Car {
public:
	virtual void installEngine() = 0;
};

class BMW5 :public Car {
public:
	virtual void installEngine() {
		cout << "BMW5 3500CC" << endl;
	}
};

class BMW6 : public Car{
public:
	virtual void installEngine(){
		cout << "BMW6 4000CC" << endl;
	}
};

class Jeep11 : public Car {
public:
	virtual void installEngine(){
		cout << "Jeep11 1100CC" << endl;
	}
};

class Jeep12 : public Car {
public:
	virtual void installEngine() {
		cout << "Jeep12 1200CC" << endl;
	}
};

/*
��ͬ�ĳ��ͣ���ͬ�ͺţ���װ��ͬ���͵ķ�����������������ķ���
��������
*/
void test1()
{
	Jeep12 *j12 = new Jeep12;
	j12->installEngine();
	delete j12;
	return;
}

class Car2 {
public:
	virtual void installEngine3500() = 0;
	virtual void installEngine4000() = 0;
	virtual void installEngine1100() = 0;
	virtual void installEngine1200() = 0;

};

class BMW : public Car2
{
public:
	virtual void installEngine3500()
	{
		cout << "3500CC" << endl;
	}
	virtual void installEngine4000()
	{
		cout << "4000CC" << endl;
	}
	virtual void installEngine1100()
	{
		cout << "1100CC" << endl;
	}
	virtual void installEngine1200()
	{
		cout << "1200CC" << endl;
	}
};

/*
��������Ʋ����Ͽ���ԭ�����ӷ�������Ҫ�޸�Car2��
*/
void test2()
{
	BMW *bmw5 = new BMW;
	bmw5->installEngine3500();
}

/*
��Ҫ�ѡ���װ������������£����ܺõķֽ⣻�ѳ������Ϊʵ�ַֿ�
��������һ�����Σ�ר�ų����һ���ࣻ���к���һ����Ա��������װ������
*/
class Engine {
public:
	virtual void installEngine() = 0;
};

class Engine4000 : public Engine{
public:
	virtual void installEngine(){
		cout << "��װ������ Engine4000" << endl;
	}
};

class Engine3500 : public Engine {
public:
	virtual void installEngine(){
		cout << "��װ������ Engine 3500" << endl;
	}
};

class Car3 {
public:
	Car3(Engine *pEngine) {
		m_engine = pEngine;
	}
	virtual void installEngine() = 0;
protected:
	Engine *m_engine;
};

class BMW7 :public Car3 {
public:
	BMW7(Engine *p) :Car3(p) {}

	//ע�⳵�İ�װ�ͷ������İ�װ��֮ͬ��
	virtual void installEngine() {
		cout << "BMW7";
		m_engine->installEngine();
	}
};

void test3() {
	Engine4000 *e4000 = new Engine4000;
	BMW7 *bmw7 = new BMW7(e4000);

	bmw7->installEngine();
	delete e4000;
	delete bmw7;
}

void main() {
	//test1();
	//test2();
	test3();
	cin.get();
}