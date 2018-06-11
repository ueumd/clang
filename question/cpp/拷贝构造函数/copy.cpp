#include <iostream>
#include <string>
#include "copy.h"
using namespace std;
class Student {
public:
	Student(string name = "", int age = 0, float score = 0.0f);  //��ͨ���캯��
	//Student(const Student &stu);  //�������캯����������
public:
	void display();
public:
	string m_name;
	int m_age;
	float m_score;
};
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }

//�������캯�������壩
//Student::Student(const Student &stu) {
//	this->m_name = stu.m_name;
//	this->m_age = stu.m_age;
//	this->m_score = stu.m_score;
//
//	cout << "Copy constructor was called." << endl;
//}

void Student::display() {
	cout << m_name << "��������" << m_age << "���ɼ���" << m_score << endl;
}

void likeJava() {
	Student *stu1 = new Student("С��", 16, 90.5);
	Student *stu2 = stu1;  //���ÿ������캯��

												 // Student stu3(stu1);   //���ÿ������캯��

	stu1->display();
	stu1->display();

	stu1->m_age = 100;
	stu1->display();
	stu1->display();
	/*
	С����������16���ɼ���90.5
	С����������16���ɼ���90.5

	С����������100���ɼ���90.5
	С����������100���ɼ���90.5
	*/
}

void likecpp() {
	Student stu1("С��", 16, 90.5);
	Student stu2 = stu1;  //���ÿ������캯��

	// Student stu3(stu1);   //���ÿ������캯��

	stu1.display();
	stu2.display();

	stu1.m_age = 100;
	stu1.display();
	stu2.display();
	/*
	С����������16���ɼ���90.5
	С����������16���ɼ���90.5
	С����������100���ɼ���90.5
	С����������16���ɼ���90.5
	*/
}

void main() {
	likecpp();

	cin.get();
}