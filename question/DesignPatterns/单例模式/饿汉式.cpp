#include<iostream>
using namespace std;

class Singelton2 {
private:
	//构造函数私有化
	Singelton2() {
		cout << "Singelton2构造函数执行" << endl;
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

//俄汉式
//不管你创建不创建实例，均把实例new出来，会存在浪费内存
Singelton2* Singelton2::m_psl = new Singelton2;

void main() {

	Singelton2 *p1 = Singelton2::getInstance();
	Singelton2 *p2 = Singelton2::getInstance();

	if (p1 == p2) {
		cout << "同一个对象" << endl; //同一个对象
	}
	else {
		cout << "不是同一个对象" << endl; 
	}

	Singelton2::freeInstance();

	cin.get();
}