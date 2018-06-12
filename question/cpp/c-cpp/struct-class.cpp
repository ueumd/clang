#include <stdio.h>	// c
#include<iostream>  // c++ û��.h
#include<iomanip>

#if 0
�ṹ�� & ��
C++�е� struct �� class ������ͨ�õģ�Ψ�м���ϸ�ڲ�ͬ��
ʹ�� class ʱ�����еĳ�ԱĬ�϶��� private ���Եģ���ʹ�� struct ʱ���ṹ���еĳ�ԱĬ�϶��� public ���Եġ�
class �̳�Ĭ���� private �̳У��� struct �̳�Ĭ���� public �̳У���C++�̳���������һ�»ὲ��̳У���
class ����ʹ��ģ�壬�� struct ���ܣ���ģ�塢�ַ������쳣��һ�»ὲ��ģ�壩��
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

#if 1
//��̬�����ڴ�
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

#endif

#if 2
// ��������
// void func(int n = 100, float b, char c = '$'); ÿ������ֻ��ָ��һ��Ĭ�ϲ�����
// void func(int n, float b=1.2, char c);   ������������û������ģ���ǰ�����������溯��������ͬһ�������У��ǲ��е�

// Ĭ�ϲ��� ָ���ǵ�����������ʡ����ʵ��ʱ�Զ�ʹ�õ�һ��ֵ�����ֵ���Ǹ��β�ָ����Ĭ��ֵ
// C++ �涨���ڸ������������У� ÿ������ֻ��ָ��һ��Ĭ�ϲ�����
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