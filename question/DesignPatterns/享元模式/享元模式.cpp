#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "string"
#include "map"
using namespace std;

/*
使用场景：
是以共享的方式，高效的支持大量的细粒度的对象。

CS 游戏玩家
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
	int		sex;   //1男 2女
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
享元工厂
*/
class TeacherFactory {
public:
	TeacherFactory() {
		m_tpool.empty();
	}
	~TeacherFactory(){
		//内存管理永远是c++程序员的痛
		while (!m_tpool.empty()) //在工厂中创建老师结点，在工厂中销毁老师结点
		{
			Teacher *tmp = NULL;
			map<string, Teacher *>::iterator it = m_tpool.begin();
			tmp = it->second;
			m_tpool.erase(it);
			delete tmp;
		}
	}

	//通过Teacher的pool，来存放老师结点，在TeacherFactory中创建老师、销毁老师
	Teacher *getTeacher(string id) {
		string	name;
		int		age;
		int		sex;
		Teacher *tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(id);

		//不存在就创建
		if (it == m_tpool.end()) {
			cout << "id为: " << id << " 的老师不存在,系统为你创建该老师，请输入以下信息" << endl;
			cout << "请输入老师姓名：";
			cin >> name;
			cout << "请输入老师年龄：";
			cin >> age;
			cout << "请输入老师性别 1男 2女：";
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
	//Teacher *t1 = new Teacher("001", "小李", 30, 1);
	//Teacher *t2 = new Teacher("002", "小张", 30, 1);
	//Teacher *t3 = new Teacher("001", "小李", 30, 1);
	//Teacher *t4 = new Teacher("004", "小吴", 30, 1);

	//cout << "t1 t3的工号一样，但是也不是同一个人 " << endl;

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