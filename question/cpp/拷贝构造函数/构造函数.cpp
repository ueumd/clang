#include<iostream>
using namespace std;

class Teacher {
public:
	Teacher() {
		cout << "无参构造 被执行了 " << endl;
	}

	Teacher(int a, int b) {
		m_a = a;
		m_b = b;
		cout << "有参构造 被执行了 " << endl;
	}

	Teacher(int a) {
		m_a = a;
		m_b = 0;
		cout << "有参构造 被执行了 " << endl;
	}

	~Teacher() {
		cout << "析构函数 被执行了 " << endl;
	}

	int m_a;		
	int m_b;	  

	void say() {
		cout << "的年龄是" << m_a << "，成绩是" << m_b << endl;
	}
};

void testStudent() {
	int a = 99, b = 10;
	// CPP编译器自动调用构造函数

	//1括号法
	Teacher t1;				  //无参
	Teacher t2(a, b);		//有参
	
	//2等号法
	Teacher t3 = (3, 4);//有参 Teacher t3 = 4 (3, 4)逗号表达式


	//3手动调用
	Teacher t = Teacher(1, 2); //匿名对象

	//函数执行完 生命周期 结束

// 对象初始化 和 对象赋值 两个不同概念
}

void maincccc() {
	testStudent();

	cin.get();
}