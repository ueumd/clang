#include<iostream>
using namespace std;
/*
继承：父类不依赖子类，子类依赖于父类

构造: 父类 => 子类 => 孙类;子类依赖于父类构造
析构：孙类 => 子类 => 父类; 子类依赖于父类
*/

class Animal {
	int x;
	int y;
public:
	//Animal() {
	//	cout << "Animal构造" << endl;
	//}

	Animal(int a, int b) :x(a), y(b) {
		cout << "Animal有参构造" << endl;
	}
	~Animal() {
		cout << "Animal析构" << endl;
	}
};

class People : public Animal {
	int z;
public:
	/*People() {
		cout << "People构造" << endl;
	}*/

	//带参构造继承
	People(int a, int b, int c) :Animal(a, b),z(c) 
	{
		cout << "People有参构造" << endl;
	}

	~People()
	{
		cout << "People析构" << endl;
	}
};


class Student : public People {
	int l;
public:
	/*Student() {
		cout << "Student构造" << endl;
	}*/
	Student(int a, int b, int c, int d): People(a,b,c),l(d) 
	{
		cout << "Student有参构造" << endl;
	}
	~Student() {
		cout << "Student析构" << endl;
	}
};

void testAnimal() {
	/*
	 testAnimal() 方法运行完就消失， 就会有析构
	 直接在main函数中，main函数没有消失，只有结束进程才会
	*/
	//	People p(10, 20, 30);
	Student s(100, 200, 300, 400);
	/*
	Animal有参构造
	People有参构造
	Student有参构造
	Student析构
	People析构
	Animal析构
	*/
}

void main() {
	testAnimal();
	cin.get();
}
