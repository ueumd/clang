#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
sprintf()函数用于将格式化的数据写入字符串，其原型为：
int sprintf(char *str, char * format [, argument, ...]);
str为要写入的字符串；
format为格式化字符串，
argument为变量。

char buf[10];
sprintf(buf, "The length of the string is more than 10");
printf("%s", buf);

屏幕上输出”The length of the string is more than 10“ buf的长度不够
*/

/*
windows
遍历C盘下所有txt
for /r c:\ %i in (*.txt) do @echo %i

在C盘下搜索所有文件内容包含hello的文件
for /r c:\ %a in (*) do @findstr /im "hello" "%a"
*/
void searfile() {
	char path[100] = "E:\\coding\\clang\\question\\文件例子";

	char filename[30] = "*.txt";

	//保存输出结果文件output.c中
	char outputpath[100] = "E:\\coding\\clang\\question\\文件例子\\output.c";


	char cmd[512];

	//打印字符串
	// for /r 查找
	sprintf(cmd, "for /r \"%s\" %%i in (%s) do @echo %%i >> \"%s\"", path, filename, outputpath);

	system(cmd);//执行查找，并将结果输入到outputpath这个文件

	char show[200];

	sprintf(show, "type %s", outputpath);

	system(show);
}

void findContent() {
	char path[100] = "E:\\coding\\clang\\question\\文件例子";
	char str[20] = "hello";
	char outputpath[100] = "E:\\coding\\clang\\question\\文件例子\\output2.c";
	char cmd[100];

	sprintf(cmd, "for /r %s %%a in (*) do @findstr /im \"%s\" \"%%a\" >> %s ", path, str, outputpath);

	system(cmd);
	char show[400];
	sprintf(show, "type %s", outputpath);
	system(show);
	system("pause");
}
void main按照文件名搜索() {
	//searfile();
	findContent();

	system("pause");
}