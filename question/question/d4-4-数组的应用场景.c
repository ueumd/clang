#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void maind44()
{
	//指针数组 char *a[30]			指针的指针 char **a
	//指针数组的自我约束 可以加 '\0' 0 NULL

	//指针数组

	char* c_keyword[] = { "while","case","static","do",'\0' };

	int i = 0;
	for (i = 0; c_keyword[i] != NULL; i++)
	{
		printf("%s \n", c_keyword[i]); //不加 \0 会报错
	}
	
	system("pause");
	return;
}