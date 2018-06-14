#include<iostream>
using namespace std;

/*
const成员变量

const成员函数 常成员函数
	const 成员函数可以使用类中的所有成员变量，但是不能修改它们的值

const对象
	const 也可以用来修饰对象，称为常对象。一旦将对象定义为常对象之后，就只能调用类的 const 成员了。

	const  class  object(params);
	class const object(params);

	当然你也可以定义 const 指针：
	const class *p = new class(params);
	class const *p = new class(params);
*/

class Student {
public:
	Student(char *name, int age, float score);
	void show();
	//声明常成员函数
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
	cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}
//定义常成员函数
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

	const Student stu("小明", 15, 90.6);
	//stu.show();  //error

	cout << stu.getname() << "的年龄是" << stu.getage() << "，成绩是" << stu.getscore() << endl;

	const Student *pstu = new Student("李磊", 16, 80.5);
	//pstu -> show();  //error

	cout << pstu->getname() << "的年龄是" << pstu->getage() << "，成绩是" << pstu->getscore() << endl;

	cin.get();
}