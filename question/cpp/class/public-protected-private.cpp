#include<iostream>
using namespace std;

class Person
{
								 // 默认 private
public:					 // 共有 内部外外都可以访问
	Person();
	~Person();

	void setName(char *name);
	void setAge(int age);
	void setScore(float score);
	void SetHobbies(char hobbies[]);
	void say();

private:				// 类内部使用，类外都是无效
	char *m_name;
	int m_age;
	float m_score;

protected:		 // 类、继承类 内部使用，其他无效
	char hobbies[100];
};

Person::Person()
{
}

Person::~Person()
{
}

void Person::setName(char *name) {
	this->m_name = name;
}

void Person::setAge(int age) {
	m_age = age;
}

void Person::setScore(float score) {
	m_score = score;
}

void Person::SetHobbies(char hobbies[]) {
	hobbies = hobbies;
}

void Person::say() {
	cout << m_name << "的年龄是：" << m_age << "，成绩是：" << m_score << "爱号：" << hobbies << endl;
}


class Employee : protected Person {
public:
	Employee();
	~Employee();

	void show();

private:
	float salary;
};

Employee::Employee()
{
}

Employee::~Employee()
{
}

void Employee::show() {
	cout << "爱号：" << hobbies  << "薪水：" << salary << endl;
}
