#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1.txt tasklist&pause
E:\coding\clang\question\Debug>
	文件.exe<1.txt				：文件.exe会从1.txt 中读取内容并打印
  文件.exe<1.txt>2.txt ：打印结果会存到2.txt文件中

*/
void main00() {
	char str[100] = { 0 };
	scanf("%s", str);
	printf("str = %s", str);
	system(str);
	system("pause");
}

void main文件重定向() {
	char str[100] = { 0 };
	fscanf(stdin, "%s", str);
	fprintf(stdout, "str = %s", str); //stdout可以重定向，输出到文件中
	system(str);
	system("pause");
}