#include "stdio.h"
#include "stdlib.h"

typedef char *String;

typedef struct Student {
	char *name;
	int age;
}Stu;

typedef struct {
	float x;
	float y;
}Point;

typedef Point *PP;

//typdef �� define����
typedef char *String1;
#define String2 char *

int maintypedef()
{
	Stu t;
	t.name = "shanghai";
	t.age = 20;

	String s = "hello world";

	printf("%s\n", s);

	Point pp = { 10,20 };
	PP p = &pp;

	// ����ָ��������ʽṹ���Ա
	printf("x=%f��y=%f\n", p->x, p->y);


	String1 s1, s2;
	String2 s3, s4;

	//ע�⣺����������£�ֻ��str1��str2��str3����ָ��char���͵�ָ�������str4ֻ�Ǹ�char���͵ı�����
	/*
		int a,b;
		int a;
		int b;

		String1 s1, s2;

		����String1����char *��������������д������
		char *s1;
		char *s2;

		��Ϊ�궨�崿�����ַ����滻����char *����String2 ����String2 s3,s4�����൱��
		char * str3, str4;
		char * s2;
		char s4;

		���Կ�����ֻ��s4�ǻ����������ͣ�s1��s2��s3����ָ�����͡�
		���ԣ��Ժ����������������ʹ��typedef��������ʹ��#define
	*/

	system("pause");
	return 0;
}