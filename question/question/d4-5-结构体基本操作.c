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
}s1, s2; // �������͵�ͬʱ �������

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

void main()
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

	

	system("pause");
	return;
}