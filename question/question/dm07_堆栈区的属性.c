#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mainջ�����Ժ�buf��ַ����()
{
	//ջ�Ŀ��ڿ��ܳ��� ���ܳ���  һ����Ϊ:���ڳ���
	//����ջ�������ϻ�������,buf���ڴ��ַbuf+1��Զ���ϵ�

	int a;
	int b;

	char buf[128]; //��̬���� buf��������ڴ�ռ��ž��Ѿ�����������

	printf("&a:%d, &b:%d\n", &a, &b);//debugģʽ &a:1505780, &b:1505768 b��ֵС ˵�����ڳ���
	system("pause");
}