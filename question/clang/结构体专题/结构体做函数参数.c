#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**

����һ���ṹ������

������һ���������͡��̶���С�ڴ��ı��� ��û�з����ڴ�

���͵��ض���
**/

//�����Ͷ�������ķ���3��
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

//2
struct Student
{
	char name[64];
	int age;
}s1, s2; // �������͵�ͬʱ D

//3
struct
{
	char name[64];
	int age;
	int id;
}s3, s4; // �������� �������

//��ʼ�����������ַ��� 2
struct Student2
{
	char name[64];
	int age;
}s5 = { "aaa",10 };

//��ʼ�����������ַ��� 3
struct
{
	char name[64];
	int age;
}s6 = { "aaa",10 };

void struct1()
{

	//��ʼ�����������ַ���

	//struct Teacher t1;//����C��������������ڴ�

	Teacher t1;//����C��������������ڴ�  ǰ���Ѿ���typedef�ض����� ����struct����ȥ��

	Teacher t2 = { "aaaa", 30, 01 };

	t1.age = 12; // t1. �������Ǹ�ʲô ��û�в����ڴ�  -> ��Ѱַ���� ���� age ����� t1������� ƫ���� ===������ cpu�н���  û�в��������ڴ�

							 //ͨ��ָ������ķ�ʽ ���� �ڴ�ռ�
	{
		Teacher *p = NULL;
		p = &t2;
		printf("p->age:%d\n", p->age); //  ��Ѱַ���� ���� cpu�н���  û�в��������ڴ�
	}

	strcpy(t1.name, "t1name");

	printf("t1.name:%s \n", t1.name);


	return;
}

void copyTeacher(Teacher to, Teacher from)
{
	to = from; // ���ﲻ��ı�ʵ��
}

void copyTeacher2(Teacher *to, Teacher *from)
{
	*to = *from;
}

void main3333()
{

//	struct1();

	Teacher t3 = { "Hello",18,22 };
	Teacher t4;
	Teacher t5;
	Teacher t6;

	memset(&t5, 0, sizeof(t5));

	t4 = t3;
	printf("t4.name:%s \n", t4.name); // hello
	printf("t4.age:%d \n", t4.age);   // 18

	printf("copyTeacher()\n\n");
	copyTeacher(t5, t3);              // �ββ���ı�ʵ��
	printf("t5.name:%s \n", t5.name); // ''
	printf("t5.age:%d \n", t5.age);   // 0

	printf("copyTeacher2()\n\n");
	copyTeacher2(&t6, &t3);           // �βλ�ı�ʵ��
	printf("t6.name:%s \n", t6.name); // hello
	printf("t6.age:%d \n", t6.age);   // 18

	system("pause");
	return;
}