#include <stdio.h>
#include <stdlib.h>
/*
��ô�����Զ����struct������Ҫ������

������һ���������� �̶���С�ڴ��ı��� ��û�з����ڴ�
*/
// �Զ����� �����ṹ�� Desk 
struct Desk // ����
{
	float length;
	float width;
	float high;
	char mer;
	float price;
};
// �Զ����� �����ṹ�� Person
struct Person
{
	float high;
	int weight;
	char sex;
	int age;
	float score[4];
};
// �����ṹ��City
struct
{
	char *name;
	char *areaCode;
} city; //�����˱���city

/**
1 �����ṹ��һ�ζ��� �ദʹ�ã�������µ�����
2 �����ṹ�� �������͵�ͬʱ��������� �����ṹ�岻�����µ�����

�����ַ�ʽ �õ���ƫ��һЩ ��Ļ��Ǳ����ṹ��
*/

// �����ṹ��
typedef struct Student
{
	char name[100];
	char sex;
	int age;
}STU;

int main22222() {

	// �Զ��������
	struct Desk d; // �����˱��� d
	struct Person p; //�����˱��� p
	printf("%p", &p);

	d.length = 10; //��Ա����
	city.name = "ShangHai";

	printf("city.name = %s\n", city.name); //city.name = ShangHai

	STU s1;
	s1.age = 10;
	printf("s1.age=%d\n", s1.age);

	// ���ǻ������� �ȿɶ���ʱ��ʼ�� Ҳ�����ȶ��� �ٸ�ֵ
	// ���ǹ������� Ҫô�ڶ���ʱ��ʼ���� �����ԣ��ȶ��� ���Գ�ʼ���ķ�ʽ��ʼ��

	STU s2 = { "tom", 'x', 18 };      // ��ʼ�� ע�� ��������ֻ���ڶ���ʱ��Ҫ��ʼ��
	printf("s2.name=%s\n", s2.name);  // s2.name=tom

	STU s3;
	strcpy(s3.name, "hello");

	// s3.name = "Hello"; name��������׵�ַ ���鸳ֵ��Ҫ�±�ſ���
	printf("s3.name=%s\n", s3.name); //s3.name=hello


																	 //���϶��ǳ�Աʽ ������ʾָ��ʽ
	STU *ps = &s3; //ָ���ʼ��
	strcpy(ps->name, "World");
	ps->age = 20;
	printf("ps.name=%s\n", ps->name);
	printf("ps.age=%d\n", ps->age);

	system("pause");
	return 0;
}
