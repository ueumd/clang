#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
һ�����Ӷ��󣬾������Ҹ��ƹ��ܣ�ͳһһ�׽ӿ�
�൱�ڱ�д�������캯��
*/

//ԭ��
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

	void setResume(char *resume) { //ע�������ǳ��������
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
		*tmp = *this;  // =�ȺŲ���Ĭ��ǳ����

		//���ǳ��������
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
	CppProgamer *c1 = new CppProgamer("����", 20);
	c1->setResume("cpp programer");
	c1->print();	//name: ����  age: 20  resume: cpp programer


	Person *c2 = c1->clone(); //����������Ҹ��ƹ���, ע�������ǳ��������
	c2->print(); //name: ����  age: 20  resume: cpp programer
	
	int age = 18;
	c1->setAge(age);
	c1->setResume("java programer");

	c1->print(); //name: ����  age: 18  resume: java programer
	c2->print(); //name: ����  age: 20  resume: cpp programer

	delete c1;

	cin.get();
}