#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long fsize(FILE *fp) {
	long n;
	fpos_t fpos;				//当前位置
	fgetpos(fp, &fpos); //获取当前位置

	fseek(fp, 0, SEEK_END);
	n = ftell(fp); //来获取文件内部指针（位置指针）距离文件开头的字节数

	fsetpos(fp, &fpos);//恢复之前的位置

	return n;
}
void main() {
	long size = 0;
	FILE *fp = NULL;
	char filename[100] = "D:\\Redis-x64-3.2.100.zip";
	if ((fp = fopen(filename, "rb")) == NULL) {
		printf("Failed to open %s...", filename);
		getch();
		exit(EXIT_SUCCESS);
	}
	printf("%ld\n", fsize(fp));
	system("pause");
}