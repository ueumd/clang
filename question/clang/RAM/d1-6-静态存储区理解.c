#include<stdio.h>
#include<stdlib.h>

char * getStr1()
{
	char *p1 = "abcdefg2";
	return p1;
}

char * getStr2()
{
	char *p2 = "abcdefg2";
	return p2;
	/*int a = 10;
	int *pa = &a;
	return *pa;*/
}

void main��̬��()
{
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = getStr1();
	p2 = getStr2();

	//p1 p2��ָ����ڴ�ռ�����
	printf("p1:%s, p2:%s\n",p1,p2);//abcdefg2 abcdefg2

	// p1 p2��ֵ
	printf("p1:%d, p2:%d\n", p1, p2);
	/*
	��� ��Ϊ���ڴ�ľ�̬�� �����ϵ����
	�������������������getStr1() getStr2() p1 p2���ڴ棨ջ�����б������� ������main�������p1 p2û�б�������

	*/

	system("pause");
}