#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int a = 10;
	char *p1 = 100;//����4���ֽڵ��ڴ�   �����ڴ渳ֵ��  

	char ****p2 = 100;

	int *p3 = NULL;

	p3 = &a;

	*p3 = 20;//����޸�a��ֵ

	int c = *p3;//ȡֵ

	printf("%d\n", c);

	printf("a:%d,p1:%d,p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));//4 4 4 

	system("pause");
	return;
}