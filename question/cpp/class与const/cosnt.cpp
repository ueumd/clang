#include<iostream>
using namespace std;

/*
const��Ա����

const��Ա���� ����Ա����
	const ��Ա��������ʹ�����е����г�Ա���������ǲ����޸����ǵ�ֵ

const����
	const Ҳ�����������ζ��󣬳�Ϊ������һ����������Ϊ������֮�󣬾�ֻ�ܵ������ const ��Ա�ˡ�

	const  class  object(params);
	class const object(params);

	��Ȼ��Ҳ���Զ��� const ָ�룺
	const class *p = new class(params);
	class const *p = new class(params);
*/

class Student {
public:
	Student(char *name, int age, float score);
	void show();
	//��������Ա����
	char *getname() const;
	int getage() const;
	float getscore() const;
private:
	char *m_name;
	int m_age;
	float m_score;
};
Student::Student(char *name, int age, float score) : m_name(name), m_age(age), m_score(score) { }
void Student::show() {
	cout << m_name << "��������" << m_age << "���ɼ���" << m_score << endl;
}
//���峣��Ա����
char * Student::getname() const {
	return m_name;
}
int Student::getage() const {
	return m_age;
}
float Student::getscore() const {
	return m_score;
}

void main() {

	const Student stu("С��", 15, 90.6);
	//stu.show();  //error

	cout << stu.getname() << "��������" << stu.getage() << "���ɼ���" << stu.getscore() << endl;

	const Student *pstu = new Student("����", 16, 80.5);
	//pstu -> show();  //error

	cout << pstu->getname() << "��������" << pstu->getage() << "���ɼ���" << pstu->getscore() << endl;

	cin.get();
}