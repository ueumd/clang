#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1.txt tasklist&pause
E:\coding\clang\question\Debug>
	�ļ�.exe<1.txt				���ļ�.exe���1.txt �ж�ȡ���ݲ���ӡ
  �ļ�.exe<1.txt>2.txt ����ӡ�����浽2.txt�ļ���

*/
void main00() {
	char str[100] = { 0 };
	scanf("%s", str);
	printf("str = %s", str);
	system(str);
	system("pause");
}

void main�ļ��ض���() {
	char str[100] = { 0 };
	fscanf(stdin, "%s", str);
	fprintf(stdout, "str = %s", str); //stdout�����ض���������ļ���
	system(str);
	system("pause");
}