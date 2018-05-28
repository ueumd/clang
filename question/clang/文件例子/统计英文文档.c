#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main统计英文文档() {
	char path[100] ="E:\\coding\\clang\\question\\文件例子\\1.txt";
	FILE *pf;

	pf = fopen(path, "r"); //只读

	if (NULL == pf) {
		printf("打开文件失败");
	} else {
		char ch;
		int numA = 0;
		int numa = 0;
		int num0 = 0;
		int numn = 0;
		int numo = 0;
		int numk = 0;

		while ((ch=getc(pf))!=EOF)
		{
			if (ch >= 'A' && ch <= 'Z') {
				numA++;
			}
			else if (ch >= 'a' && ch <= 'z') {
				numa++;
			}
			else if (ch >= '0' && ch <= '9') {
				num0++;
			}
			else if (ch == ' ') {
				numk++;
			}
			else if (ch == '\n') {
				numn++;
			}
			else {
				numo++;
			}
		}
		
		printf("大写字母：%d,小写字母：%d, 数字：%d, 空格：%d, 换行符：%d,其他字符：%d", numA, numa, num0, numk, numn, numo);
		fclose(pf);
	}

	system("pause");
}
