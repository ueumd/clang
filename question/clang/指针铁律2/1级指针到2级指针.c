#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getFileLen(int *p)
{
	*p = 41; //����޸�a��ֵ
}

int getFileLen2()
{
	int a = 100;
	return a;
}
int getFileLen3(int b)
{
	b = 100;
}
//1��ָ�뼼������
void mainOneLevel()
{
	int a = 10;
	int *p = NULL;

	a = 20; //ֱ���޸�

	p = &a;

	*p = 30;//p��ֵ��a�ĵ�ַ *����һ��Կ�� ͨ����ַ �ҵ�һ���ڴ�ռ� �ͼ�ӵ��޸���a��ֵ

	printf("a:%d \n", a);//a:30

	{
		*p = 40;
		printf("a:%d \n", a); //40
	}

	getFileLen(&a);
	printf("getFileLen��a:%d \n", a);//a:41

	getFileLen3(a); // a�ͷ�����bû�й�ϵ
	printf("getFileLen3��a:%d \n", a);//a:41

	system("pause");
	return;

}


void getMem(char **p2)
{
	*p2 = 400; //��Ӹ�ֵ p2��p1�ĵ�ַ
}

void getMem2(char *p2)
{
	p2 = 400; // p2��p1û�й�ϵ������Ӱ��ʵ��
}

//����ָ��
void main1��ָ�뵽2��ָ��()
{
	char *p1 = NULL;
	char **p2 = NULL; //����ָ��

	p1 = 0x11;
	p2 = 0x22;

	//ֱ���޸�p1��ֵ (ջ)
	p1 = 0x111;

	//����޸�p1��ֵ
	p2 = &p1;
	*p2 = 100;//��Ӹ�ֵ p2��p1�ĵ�ַ

	printf("p1:%d \n", p1); //100

	getMem(&p1);
	printf("getMem  p1:%d \n", p1); //400

	getMem2(&p1);
	printf("getMem2 p1:%d \n", p1); //400

	system("pause");
	return;
}