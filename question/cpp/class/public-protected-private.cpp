#include<iostream>
using namespace std;

class Person
{
								 // Ĭ�� private
public:					 // ���� �ڲ����ⶼ���Է���
	Person();
	~Person();

	void setName(char *name);
	void setAge(int age);
	void setScore(float score);
	void SetHobbies(char hobbies[]);
	void say();

private:				// ���ڲ�ʹ�ã����ⶼ����Ч
	char *m_name;
	int m_age;
	float m_score;

protected:		 // �ࡢ�̳��� �ڲ�ʹ�ã�������Ч
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
	cout << m_name << "�������ǣ�" << m_age << "���ɼ��ǣ�" << m_score << "���ţ�" << hobbies << endl;
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
	cout << "���ţ�" << hobbies  << "нˮ��" << salary << endl;
}
