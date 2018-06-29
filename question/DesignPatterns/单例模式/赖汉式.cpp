#include<iostream>
using namespace std;

class Singelton{
private:
	//���캯��˽�л�
	Singelton() {
		cout << "Singelton���캯��ִ��" << endl;
	}
public:
	/*
	����ʽ ֻ�е��ø÷���ʱ�Ż�new Singelton::getInstance()
	
	����ڶ��̵߳��õ����⣬������߳�ͬ��+����+����
	Singelton *p1 = Singelton::getInstance(); �߳�1
	Singelton *p2 = Singelton::getInstance(); �߳�2

	Singelton() {
		cout << "Singelton���캯��ִ��begin" << endl;
		sleeep(1000);
		cout << "Singelton���캯��ִ��end" << endl;
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

//��̬������ʼ��
Singelton* Singelton::m_psl = NULL;

void main11() {

	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2) {
		cout << "ͬһ������" << endl; //ͬһ������
	}
	else {
		cout << "����ͬһ������" << endl;
	}

	Singelton::freeInstance();

	cin.get();
}