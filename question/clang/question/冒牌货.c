#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void constint()
{
	const int a = 10;
	//a = 11; error
	{
		int *p = &a;
		*p = 100;
		printf("a:%d\n", a);//a:100
												//����C�����е�const���εı��� �Ǽٵ� C�����е�const ��һ��ð�ƻ�
	}
}


void main()
{
	system("pause");
	return;
}