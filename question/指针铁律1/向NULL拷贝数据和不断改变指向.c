#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main1()
{
	char *p1 = NULL; // p1Ĭ�ϵ�ַ��0x00000000 �ܲ���ϵͳ����
	/*
	0x0FBD0A19 (ucrtbased.dll)��(λ�� ָ������1.exe ��)�������쳣: 0xC0000005: д��λ�� 0x00000000 ʱ�������ʳ�ͻ��
	���������ڴ��쳣�Ĵ�����򣬸ó����ɰ�ȫ�ؼ������С�
	*/
	strcpy(p1, "abcdef123"); 
	printf("p1:%s\n", p1);
	system("pause");
	return 0;
}

void main2()
{
	char *p1 = NULL; // p1Ĭ�ϵ�ַ��0x00000000 �ܲ���ϵͳ����
/*
0x0F9A0A19 (ucrtbased.dll)��(λ�� ָ������1.exe ��)�������쳣: 0xC0000005: д��λ�� 0x00000077 ʱ�������ʳ�ͻ��
���������ڴ��쳣�Ĵ�����򣬸ó����ɰ�ȫ�ؼ������С�
*/
	p1 = 0x00077;
	strcpy(p1, "abcdef123"); 
	printf("p1:%s\n", p1);
	system("pause");
	return 0;
}

// ��ȷ�ķ�ʽ
void main3()
{
	char *p1 = NULL; // p1Ĭ�ϵ�ַ��0x00000000 �ܲ���ϵͳ����							
	p1 = (char *)malloc(100);
	strcpy(p1, "abcdef123"); 
	printf("p1:%s\n", p1); // p1:abcdef123
	system("pause");
	return 0;
}

void main()
{
	int i;
	char buf[128];    // ��ջ�Ϸ����ڴ�
	char *p1 = NULL;  // ��ջ��
	char *p2 = NULL;  // ��ջ��

	p1 = &buf[0];     // ���ϸı�ָ��ָ��
	p1 = &buf[1];
	p1 = &buf[2];

	for (i = 0; i < 10; i++) {
		p1 = buf[i];
	}

	p2 = (char *)malloc(100);
	strcpy(p2, "abcde123654");

	for (i = 0; i < 10; i++) {
		p1 = p2+i;
		printf("%c ", *p1); // a b c d e 1 2 3 6 5
	}

	system("pause");
	return 0;
}