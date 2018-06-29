#include<iostream>
using namespace std;

class Singelton2 {
private:
	//���캯��˽�л�
	Singelton2() {
		cout << "Singelton2���캯��ִ��" << endl;
	}
public:
	static Singelton2 *getInstance() {
		return m_psl;
	}

	static void freeInstance() {
		if (NULL != m_psl) {
			delete m_psl;
			m_psl = NULL;
		}
	}
private:
	static Singelton2 *m_psl;
};

//��ʽ
//�����㴴��������ʵ��������ʵ��new������������˷��ڴ�
Singelton2* Singelton2::m_psl = new Singelton2;

void main() {

	Singelton2 *p1 = Singelton2::getInstance();
	Singelton2 *p2 = Singelton2::getInstance();

	if (p1 == p2) {
		cout << "ͬһ������" << endl; //ͬһ������
	}
	else {
		cout << "����ͬһ������" << endl; 
	}

	Singelton2::freeInstance();

	cin.get();
}