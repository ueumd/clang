#include <iostream>
#include <string>
#include "copy.h"
using namespace std;
class Student {
public:
	Student(string name = "", int age = 0, float score = 0.0f);  //��ͨ���캯��
	Student(const Student &stu);  //�������캯����������
	~Student() {
		cout << "����" << endl;
	}
public:
	void display();
public:
	string m_name;
	int m_age;
	float m_score;
};
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }

//�������캯�������壩 ��ɶ����ʼ��
Student::Student(const Student &stu) {
	this->m_name = stu.m_name;
	this->m_age = stu.m_age;
	this->m_score = stu.m_score;

	cout << "Copy constructor was called." << endl;
}

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

	delete stu1;
	delete stu2;

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


// ���ó���3
void f(Student stu) {
	cout << stu.m_age << endl;
}

// ���ó���4
// ����һ����������
Student init() {
	Student stu("С��", 16, 90.5);
	return stu; //����ÿ������캯��
}

void testStu() {
	Student stu1("С��", 16, 90.5);
	f(stu1); //���ÿ����칹����

					 //���������ʼ��һ��ͬ���Ͷ������������ת���µĶ��� ���ÿ������캯��
	Student s2 = init();
	s2.display();
}

/*
	��������ȥ������ ���ۣ�
  1. ��ʼ�� �����������
	2. ��ֵ �������������
*/
#if 1

void testInit() {
	Student s2 = init();   //��ʼ�� �����������
	cout << "�������󲻻ᱻ����" << endl;
	/*
	Copy constructor was called.
	����
	�������󲻻ᱻ����
	����
	*/

#if 0 
	Student s3("С��", 16, 90.5);
	s3 = init();					// ��ֵ �������������
	cout << "��������ᱻ����" << endl;
	/*
	Copy constructor was called.
	����
	����
	��������ᱻ����
	����
	*/
#endif
}

#endif

void maincc() {
//	likecpp();

	testInit();
	cin.get();
}