#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
sprintf()�������ڽ���ʽ��������д���ַ�������ԭ��Ϊ��
int sprintf(char *str, char * format [, argument, ...]);
strΪҪд����ַ�����
formatΪ��ʽ���ַ�����
argumentΪ������

char buf[10];
sprintf(buf, "The length of the string is more than 10");
printf("%s", buf);

��Ļ�������The length of the string is more than 10�� buf�ĳ��Ȳ���
*/

/*
windows
����C��������txt
for /r c:\ %i in (*.txt) do @echo %i

��C�������������ļ����ݰ���hello���ļ�
for /r c:\ %a in (*) do @findstr /im "hello" "%a"
*/
void searfile() {
	char path[100] = "E:\\coding\\clang\\question\\�ļ�����";

	char filename[30] = "*.txt";

	//�����������ļ�output.c��
	char outputpath[100] = "E:\\coding\\clang\\question\\�ļ�����\\output.c";


	char cmd[512];

	//��ӡ�ַ���
	// for /r ����
	sprintf(cmd, "for /r \"%s\" %%i in (%s) do @echo %%i >> \"%s\"", path, filename, outputpath);

	system(cmd);//ִ�в��ң�����������뵽outputpath����ļ�

	char show[200];

	sprintf(show, "type %s", outputpath);

	system(show);
}

void findContent() {
	char path[100] = "E:\\coding\\clang\\question\\�ļ�����";
	char str[20] = "hello";
	char outputpath[100] = "E:\\coding\\clang\\question\\�ļ�����\\output2.c";
	char cmd[100];

	sprintf(cmd, "for /r %s %%a in (*) do @findstr /im \"%s\" \"%%a\" >> %s ", path, str, outputpath);

	system(cmd);
	char show[400];
	sprintf(show, "type %s", outputpath);
	system(show);
	system("pause");
}
void main�����ļ�������() {
	//searfile();
	findContent();

	system("pause");
}