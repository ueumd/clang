#include<iostream>
using namespace std;

class Singelton{
private:
	//构造函数私有化
	Singelton() {
		cout << "Singelton构造函数执行" << endl;
	}
public:
	/*
	懒汉式 只有调用该方法时才会new Singelton::getInstance()
	
	会存在多线程调用的问题，解决：线程同步+加锁+解锁
	Singelton *p1 = Singelton::getInstance(); 线程1
	Singelton *p2 = Singelton::getInstance(); 线程2

	Singelton() {
		cout << "Singelton构造函数执行begin" << endl;
		sleeep(1000);
		cout << "Singelton构造函数执行end" << endl;
	}
	*/
	static Singelton *getInstance() {
		if (NULL == m_psl) {
			m_psl = new Singelton();
		}
		return m_psl;
	}

	static void freeInstance() {
		if (NULL != m_psl) {
			delete m_psl;
			m_psl = NULL;
		}
	}
private:
	static Singelton *m_psl;
};

//静态变量初始化
Singelton* Singelton::m_psl = NULL;

void main11() {

	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2) {
		cout << "同一个对象" << endl; //同一个对象
	}
	else {
		cout << "不是同一个对象" << endl;
	}

	Singelton::freeInstance();

	cin.get();
}