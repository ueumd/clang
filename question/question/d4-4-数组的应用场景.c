#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void maind44()
{
	//ָ������ char *a[30]			ָ���ָ�� char **a
	//ָ�����������Լ�� ���Լ� '\0' 0 NULL

	//ָ������

	char* c_keyword[] = { "while","case","static","do",'\0' };

	int i = 0;
	for (i = 0; c_keyword[i] != NULL; i++)
	{
		printf("%s \n", c_keyword[i]); //���� \0 �ᱨ��
	}
	
	system("pause");
	return;
}