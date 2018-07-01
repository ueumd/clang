#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "string"
#include "map"
using namespace std;

/*
ʹ�ó�����
���Թ���ķ�ʽ����Ч��֧�ִ�����ϸ���ȵĶ���

CS ��Ϸ���
*/
class Person{
public:
	Person(string name, int age, int sex){
		this->name = name;
		this->age = age;
		this->sex = sex;
	}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	int getSex(){
		return sex;
	}
protected:
	string	name;
	int		age;
	int		sex;   //1�� 2Ů
};

class Teacher : public Person{
public:
	Teacher(string id, string name, int age, int sex) : Person(name, age, sex){
		this->id = id;
	}

	string getId(){
		return id;
	}

	void printT(){
		cout << "id:" << id << "\t" << "name:" << name << "\t" << "age:" << age << "\t" << "sex:" << sex << "\t" << endl;
	}
private:
	string id;
};

/*
��Ԫ����
*/
class TeacherFactory {
public:
	TeacherFactory() {
		m_tpool.empty();
	}
	~TeacherFactory(){
		//�ڴ������Զ��c++����Ա��ʹ
		while (!m_tpool.empty()) //�ڹ����д�����ʦ��㣬�ڹ�����������ʦ���
		{
			Teacher *tmp = NULL;
			map<string, Teacher *>::iterator it = m_tpool.begin();
			tmp = it->second;
			m_tpool.erase(it);
			delete tmp;
		}
	}

	//ͨ��Teacher��pool���������ʦ��㣬��TeacherFactory�д�����ʦ��������ʦ
	Teacher *getTeacher(string id) {
		string	name;
		int		age;
		int		sex;
		Teacher *tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(id);

		//�����ھʹ���
		if (it == m_tpool.end()) {
			cout << "idΪ: " << id << " ����ʦ������,ϵͳΪ�㴴������ʦ��������������Ϣ" << endl;
			cout << "��������ʦ������";
			cin >> name;
			cout << "��������ʦ���䣺";
			cin >> age;
			cout << "��������ʦ�Ա� 1�� 2Ů��";
			cin >> sex;

			tmp = new Teacher(id, name, age, sex);
			m_tpool.insert(pair<string, Teacher*>(id, tmp));
		}
		else {
			tmp = (it->second);
		}
		return tmp;
	}

private:
	map<string, Teacher *> m_tpool;
};


void main() {
	//Teacher *t1 = new Teacher("001", "С��", 30, 1);
	//Teacher *t2 = new Teacher("002", "С��", 30, 1);
	//Teacher *t3 = new Teacher("001", "С��", 30, 1);
	//Teacher *t4 = new Teacher("004", "С��", 30, 1);

	//cout << "t1 t3�Ĺ���һ��������Ҳ����ͬһ���� " << endl;

	//delete t1;
	//delete t2;
	//delete t3;
	//delete t4;

	TeacherFactory *tf = new TeacherFactory;

	Teacher *t5 = tf->getTeacher("001");
	t5->printT();

	Teacher *t2 = tf->getTeacher("001");
	t2->printT();

	delete tf;

	system("pause");
	return;

}