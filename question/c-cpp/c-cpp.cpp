#include <stdio.h>	// c
#include<iostream>  // c++ û��.h
#include<iomanip>

#define SQ(y) (y*y)


#if 0
�ṹ��
��
#endif
typedef struct Student {
	char *name;
	int age;
	float score;
}Stu;

void display(struct Student stu)
{
	printf("%s�������� %d���ɼ��� %0.2f\n", stu.name, stu.age, stu.score);
}

// �����ռ�
namespace Diy {
	class MyStudent {
	public:
		char *name;
		int age;
		float score;
		void display() {
			//printf("%s�������� %d���ɼ��� %0.2f\n", name, age, score);
			// std::setiosflags(std::ios::fixed) << std::setprecision(2) ���������
			std::cout << name << "�������� " << age << " ,�ɼ��� " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << score << std::endl;
		}
	};
}

void testClass() {
	Stu stu1;
	stu1.name = "С��";
	stu1.age = 10;
	stu1.score = 99.9;

	display(stu1); // С���������� 10���ɼ��� 99.90

	Diy::MyStudent stu;
	stu.name = "С��";
	stu.age = 10;
	stu.score = 99.9;

	stu.display(); //С���������� 10���ɼ��� 99.90
}

void testmemory() {
	//c lang
	int *c = (int *)malloc(sizeof(int) * 10); // ����10��int���Ϳռ�
	free(c);		//�ͷ��ڴ�

	// cpp
	int *cpp = new int;			//����1��int�͵��ڴ�ռ�
	delete cpp;

	int *cc = new int[10];  // /����10��int�͵��ڴ�ռ�
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