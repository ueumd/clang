#include<iostream>
using namespace std;

class Person {
public:
	virtual Person *clone()=0;
	virtual void print()=0;
};

class CppProgamer : public Person {
public:
	CppProgamer() {
		m_name = "";
		m_age = 0;
	}

	CppProgamer(string name, int age) {
		m_name = name;
		m_age = age;
	}

	virtual Person *clone() {
		CppProgamer *tmp = new CppProgamer;
		//tmp->m_name = this->m_name;
		*tmp = *this;
		return tmp;
	}

	virtual void print() {
		cout << "name: " << m_name.c_str() << "  age:" << m_age << endl;
	}

private:
	string m_name;
	int m_age;
};

void main() {
	CppProgamer *c1 = new CppProgamer("张三", 20);
	c1->print();	//name: 张三  age:20


	Person *c2 = c1->clone();
	c2->print(); //name: 张三  age:20

	cin.get();
}