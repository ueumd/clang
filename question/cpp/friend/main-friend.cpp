#include <iostream>
using namespace std;

#if 0
关键字：friend
友元函数 可以访问当前类中的所有成员，包括 public、protected、private 属性的。
友元类
#endif

#if 0
注意的地方：
- 提前声明Address类
- 先定义类，再定义类成员函数
#endif

class Address;  //提前声明Address类

class Student {
public:
	Student(char *name, int age, float score);

public:
	//友元函数
	friend  void show(Student *pStu);

public:
	void setName(char *name);
	char* getName() const;
	void showAddr(Address *addr);

private:
	char *m_name;
	int m_age;
	float m_score;
};

class Address {
public:
	Address(char *province, char *city, char *district);
public:
	friend class Student; //友元类 Student是Address的右元累
private:
	char *m_province;   //省份
	char *m_city;				//城市
	char *m_district;   //区（市区）
};

Address::Address(char *province, char *city, char *district) {
	m_province = province;
	m_city = city;
	m_district = district;
}

Student::Student(char *name, int age, float score) : m_name(name), m_age(age), m_score(score) { }

//类成员函数
void Student::setName(char *name) {
	m_name = name;
}

//常成员函数
char * Student::getName() const {
	return m_name;
}

//友元函数不同于类的成员函数，在友元函数中不能直接访问类的成员，必须要借助对象
//show同时也是一个全局函数，不属于任何类

void show(Student *pStu) {
	cout << pStu->m_name << "的年龄是 " << pStu->m_age << "，成绩是 " << pStu->m_score << endl;
}

void Student::showAddr(Address *addr) {
	cout << m_name << "的年龄是 " << m_age << "，成绩是 " << m_score << endl;
	cout << "家庭住址：" << addr->m_province << "省" << addr->m_city << "市" << addr->m_district << "区" << endl;
}

// 普通的全局方法，但只能访问Student的public成员变量 或 成员函数
void showTest(Student *pStu) {
	cout << pStu->getName() << endl;
}

int main() {
	Student stu("小明", 15, 90.6);
	show(&stu);

	Student *pstu = new Student("李磊", 16, 80.5);
	show(pstu);  //调用友元函数


	Address *paddr = new Address("河北", "衡水", "桃城");
	pstu->showAddr(paddr);

	showTest(&stu); //小明

	/*
	小明的年龄是 15，成绩是 90.6
	李磊的年龄是 16，成绩是 80.5
	李磊的年龄是 16，成绩是 80.5
	家庭住址：河北省衡水市桃城区
	小明
	*/

	system("pause");
	return 0;
}