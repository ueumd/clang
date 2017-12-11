#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char *pname2;
}Teacher;

void copyTeacherStruct(Teacher *to, Teacher *from)
{

	/*
	= �� memcpy ֻ��ǳ���� ֻ����ַָ������ֵ����ַ��
	��û�п���ָ�����ָ��� �ڴ�ռ� ��������ȥ

	*to = *from;
	memcpy(to, from, sizeof(Teacher));
	*/

	// ���

	*to = *from;
	to->pname2 = (char *)malloc(100); //Ҫ��t2.pname2�����ڴ�
	strcpy(to->pname2, from->pname2);

}

void main()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name, "name1");

	t1.pname2 = (char *)malloc(100); //��Ҫ��t1.pname2 �����ڴ�

	strcpy(t1.pname2, "namess");

	//t1 copy t2
	copyTeacherStruct(&t2, &t1);

	printf("%s", t2.pname2);

	if (t1.pname2 != NULL)
	{
		free(t1.pname2);
		t1.pname2 = NULL;
	}

	//ǳ����ʱ�ᱨ�� ��Ϊt1 t2����ָ��ͬһ����ڴ�ռ�
	if (t2.pname2 != NULL)
	{
		free(t2.pname2);
		t2.pname2 = NULL;
	}

	system("pause");
	return;
}