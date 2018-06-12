#include <stdio.h>	// c
#include<iostream>  // c++ 没有.h
#include<iomanip>

#if 0
结构体 & 类
C++中的 struct 和 class 基本是通用的，唯有几个细节不同：
使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public 属性的。
class 继承默认是 private 继承，而 struct 继承默认是 public 继承（《C++继承与派生》一章会讲解继承）。
class 可以使用模板，而 struct 不能（《模板、字符串和异常》一章会讲解模板）。
#endif
typedef struct Student {
	char *name;
	int age;
	float score;
}Stu;

void display(struct Student stu)
{
	printf("%s的年龄是 %d，成绩是 %0.2f\n", stu.name, stu.age, stu.score);
}

// 命名空间
namespace Diy {
	class MyStudent {
	public:
		char *name;
		int age;
		float score;
		void display() {
			//printf("%s的年龄是 %d，成绩是 %0.2f\n", name, age, score);
			// std::setiosflags(std::ios::fixed) << std::setprecision(2) 输出浮点数
			std::cout << name << "的年龄是 " << age << " ,成绩是 " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << score << std::endl;
		}
	};
}

void testClass() {
	Stu stu1;
	stu1.name = "小明";
	stu1.age = 10;
	stu1.score = 99.9;

	display(stu1); // 小明的年龄是 10，成绩是 99.90

	Diy::MyStudent stu;
	stu.name = "小明";
	stu.age = 10;
	stu.score = 99.9;

	stu.display(); //小明的年龄是 10，成绩是 99.90
}

#if 1
//动态分配内存
void testmemory() {
	//c lang
	int *c = (int *)malloc(sizeof(int) * 10); // 分配10个int类型空间
	free(c);		//释放内存

	// cpp
	int *cpp = new int;			//分配1个int型的内存空间
	delete cpp;

	int *cc = new int[10];  // /分配10个int型的内存空间
	delete[] cpp;
}

#endif

#if 2
// 函数声明
// void func(int n = 100, float b, char c = '$'); 每个参数只能指定一次默认参数。
// void func(int n, float b=1.2, char c);   两次声明，是没有问题的，当前两次声明下面函数定义在同一作用域中，是不行的

// 默认参数 指的是当函数调用中省略了实参时自动使用的一个值，这个值就是给形参指定的默认值
// C++ 规定，在给定的作用域中， 每个参数只能指定一次默认参数。
void func(int n = 100, float b = 1.2, char c = '$') {
	std::cout << n << '\t' << b << '\t' << c << std::endl;
}
#endif

int main2() {

	testClass();

	func(200); // 200,	1.2,	$

	getchar();
	return 0;
}