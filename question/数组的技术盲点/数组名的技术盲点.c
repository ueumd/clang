#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main�������ļ���ä��()
{
	int a[] = { 1, 2};
	int b[100] = { 1, 3 };

	int c[200] = { 0 };      //����ʱ ���Ѿ�ȷ�� ���е�ֵ Ϊ��
	memset(c, 0, sizeof(c)); //��ʾ�� �����ڴ��
	// ��һά����C�涨��
	// c  ��������Ԫ�صĵ�ַ c+1    ���� 4���ֽ�
	// &c ����������ĵ�ַ   &c+1   ���� 200*4
	
	system("pause");
	return;
}

void main��������()
{
	typedef int(MyArrayType)[5]; // ������һ���������� ������������
	int i = 0;
	MyArrayType lessons;

	for (i = 0; i < 5; i++) {
		lessons[i] = i + 1;
	}

	printf("lessons:%d lessons+1:%d\n", lessons, lessons + 1);			// lessons  : 4193968   lessons + 1 : 4193972   ����4
	printf("&lessons:%d &lessons+1:%d\n", &lessons, &lessons + 1);  // &lessons : 4193968  &lessons + 1 : 4193988   ����20

	system("pause");
	return;
}

// ��������ָ������ķ���1 
// ���������� ��*
void main��������ָ������ķ���1()
{
	char *MyArray[] = { "111","2222","3333" }; // ָ�� ����

	typedef int(MyArrayType)[5]; // ������һ���������� ������������
	int i = 0;
	MyArrayType lessons;    // �������� �������

	MyArrayType *pLessons; // �������� ����һ��ָ����� ���ָ����� ָ��һ������
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		int lessons2[5];
		// ����ͨ��ָ�����pLessons������lessons2���ڴ�ռ�
		pLessons = &lessons2; // pLessons = &lessons;
		for (i = 0; i < 5; i++) {
			// lessons2[i] = i + 1;
			(*pLessons)[i] = i + 1;
		}
		for (i = 0; i < 5; i++) {
			printf("%d ", (*pLessons)[i]); // 1 2 3 4 5
		}
	}

	system("pause");
	return;
}

//��������ָ������ķ���2
void main��������ָ������ķ���()
{
	
	typedef int (*MyArrayType)[5]; // ������һ������ָ������
	MyArrayType pLessons;          // ���߱����� ����һ��ָ�����
	int c[5];
	int i = 0;

	pLessons = &c;

	for (i = 0; i < 5; i++) {
		(*pLessons)[i] = i + 1;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", (*pLessons)[i]); // 1 2 3 4 5
	}

	system("pause");
	return;
}

//��������ָ������ķ���3
//ǰ�����ַ��� ͨ�����Ͷ��� �Ƚ��鷳 
// ֱ�Ӷ���
void main��������ָ������ķ���3()
{
	int c[5];
	int i = 0;

	int (*pLessons)[5]; // ֱ�Ӷ�����һ��ָ������� ָ�����
	pLessons = &c;

	for (i = 0; i < 5; i++) {
		(*pLessons)[i] = i + 1;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", (*pLessons)[i]); // 1 2 3 4 5
	}

	system("pause");
	return;
}