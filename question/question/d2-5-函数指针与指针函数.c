#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

1.ָ�뺯��
�ȿ�����ĺ���������ע�⣬�˺����з���ֵ������ֵΪint *��������ֵ��ָ�����͵ġ�

2.����ָ��
����˼�壬����ָ��˵�ľ���һ��ָ�룬�����ָ��ָ��ĺ�����������ͨ�Ļ����������ͻ��������

����:����ָ��ĺ�������һ��ָ�룬��������ǰ����һ��ָ�����͵ı�־�ͺš�*����
*/

int *f(int a, int b); // ����ָ�뺯��   Ҳ����д�� 

int(*g)(int a, int b); // ��������ָ

/*
* �����ֵ
* ����ֵ��int���ͣ��������������нϴ��һ��
*/
int maxmax(int a, int b) {
	return a > b ? a : b;
}

/*
* ����Сֵ
* ����ֵ��int���ͣ��������������н�С��һ��
*/
int minmin(int a, int b) {
	return a < b ? a : b;
}

/*
* ָ�뺯���Ķ���
* ����ֵ��ָ������int *
*/

int *f(int a, int b) {
	int *p = (int *)malloc(sizeof(int));

	printf("The memeory address of p = 0x%x \n", p);

	memset(p, 0, sizeof(int));

	*p = a + b;

	printf("*p = %d \n", *p);

	return p;
}

void maind25()
{
	printf("-------------ָ�뺯��----------------- Start\n");

	int *p1 = NULL;
	printf("The memeory address of p1 = 0x%x \n", p1);

	p1 = f(1, 2);

	printf("The memeory address of p1 = 0x%x \n", p1);
	printf("*p1 = %d \n", *p1);

	printf("------------------------------ End\n");



	printf("---------------����ָ��--------------- Start\n");

	g = maxmax; // ����ָ��gָ�������ֵ�ĺ���max  
	int c = (*g)(1, 2);

	printf("The max value is %d \n", c);

	g = minmin; // ����ָ��gָ������Сֵ�ĺ���min  
	c = (*g)(1, 2);

	printf("The min value is %d \n", c);

	printf("------------------------------ End\n");
	
	system("pause");
	return;
}