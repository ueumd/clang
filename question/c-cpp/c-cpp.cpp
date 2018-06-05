#include <stdio.h>	// c
#include<iostream>  // c++ 没有.h
#include<iomanip>

#define SQ(y) (y*y)


#if 0
结构体
类
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

void testdefined() {
	int n = 10;
	int sq = SQ(n + 1); // sq = (n+1)*(n+1);
	printf("%d\n", sq);
}

int main() {

	//testClass();
	testdefined();
	getchar();
	return 0;
}