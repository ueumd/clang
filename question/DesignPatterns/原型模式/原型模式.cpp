#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
一个复杂对象，具有自我复制功能，统一一套接口
相当于编写拷贝构造函数
*/

//原形
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
		m_resume = NULL;
	}

	CppProgamer(string name, int age) {
		m_name = name;
		m_age = age;
		m_resume = NULL;
	}

	~CppProgamer() {
		if (m_resume != NULL)
		{
			free(m_resume);
			m_resume = NULL;
		}
	}

	virtual void print() {
		cout << "name: " << m_name.c_str() << "  age: " << m_age;
		if (m_resume!=NULL) {
			cout<< "  resume: " << m_resume << endl;
		}
		cout << endl;
	}

	void setResume(char *resume) { //注意深拷贝和浅拷贝问题
		if (m_resume != NULL) {
			delete m_resume;
		}
		m_resume = new char[strlen(resume) + 1];
		strcpy(m_resume, resume);
	}

	void setAge(int age) {
		m_age = age;
	}

	virtual Person *clone() {
		CppProgamer *tmp = new CppProgamer;
		//tmp->m_name = this->m_name;
		*tmp = *this;  // =等号操作默认浅拷贝

		//解决浅拷贝问题
		tmp->m_resume = new char[strlen(this->m_resume)];
		strcpy(tmp->m_resume, this->m_resume);
		return tmp;
	}



private:
	string m_name;
	int m_age;
	char *m_resume;
};

void main() {
	CppProgamer *c1 = new CppProgamer("张三", 20);
	c1->setResume("cpp programer");
	c1->print();	//name: 张三  age: 20  resume: cpp programer


	Person *c2 = c1->clone(); //对象具有自我复制功能, 注意深拷贝和浅拷贝问题
	c2->print(); //name: 张三  age: 20  resume: cpp programer
	
	int age = 18;
	c1->setAge(age);
	c1->setResume("java programer");

	c1->print(); //name: 张三  age: 18  resume: java programer
	c2->print(); //name: 张三  age: 20  resume: cpp programer

	delete c1;

	cin.get();
}