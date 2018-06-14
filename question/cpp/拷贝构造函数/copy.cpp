#include <iostream>
#include <string>
#include "copy.h"
using namespace std;
class Student {
public:
	Student(string name = "", int age = 0, float score = 0.0f);  //普通构造函数
	Student(const Student &stu);  //拷贝构造函数（声明）
	~Student() {
		cout << "析构" << endl;
	}
public:
	void display();
public:
	string m_name;
	int m_age;
	float m_score;
};
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }

//拷贝构造函数（定义） 完成对象初始化
Student::Student(const Student &stu) {
	this->m_name = stu.m_name;
	this->m_age = stu.m_age;
	this->m_score = stu.m_score;

	cout << "Copy constructor was called." << endl;
}

void Student::display() {
	cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}

void likeJava() {
	Student *stu1 = new Student("小明", 16, 90.5);
	Student *stu2 = stu1;  //调用拷贝构造函数

												 // Student stu3(stu1);   //调用拷贝构造函数

	stu1->display();
	stu1->display();

	stu1->m_age = 100;
	stu1->display();
	stu1->display();
	/*
	小明的年龄是16，成绩是90.5
	小明的年龄是16，成绩是90.5

	小明的年龄是100，成绩是90.5
	小明的年龄是100，成绩是90.5
	*/

	delete stu1;
	delete stu2;

}

void likecpp() {
	Student stu1("小明", 16, 90.5);
	Student stu2 = stu1;  //调用拷贝构造函数

	// Student stu3(stu1);   //调用拷贝构造函数

	stu1.display();
	stu2.display();

	stu1.m_age = 100;
	stu1.display();
	stu2.display();
	/*
	小明的年龄是16，成绩是90.5
	小明的年龄是16，成绩是90.5
	小明的年龄是100，成绩是90.5
	小明的年龄是16，成绩是90.5
	*/
}


// 调用场景3
void f(Student stu) {
	cout << stu.m_age << endl;
}

// 调用场景4
// 返回一个匿名对象
Student init() {
	Student stu("小明", 16, 90.5);
	return stu; //会调用拷贝构造函数
}

void testStu() {
	Student stu1("小明", 16, 90.5);
	f(stu1); //调用拷贝造构函数

					 //匿名对象初始化一个同类型对象，匿名对象会转成新的对象 调用拷贝构造函数
	Student s2 = init();
	s2.display();
}

/*
	匿名对象去留问题 结论：
  1. 初始化 匿名对象扶正
	2. 赋值 匿名对象会析构
*/
#if 1

void testInit() {
	Student s2 = init();   //初始化 匿名对象扶正
	cout << "匿名对象不会被析构" << endl;
	/*
	Copy constructor was called.
	析构
	匿名对象不会被析构
	析构
	*/

#if 0 
	Student s3("小王", 16, 90.5);
	s3 = init();					// 赋值 匿名对象会析构
	cout << "匿名对象会被析构" << endl;
	/*
	Copy constructor was called.
	析构
	析构
	匿名对象会被析构
	析构
	*/
#endif
}

#endif

void maincc() {
//	likecpp();

	testInit();
	cin.get();
}