#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fopenAndClose() {
	FILE* fp = fopen("E:\\coding\\clang\\txt\\111.txt", "a");

	fputs("China is great!!!", fp);  // 向111.txt 文件追加 China is great!!!
	int ret = fclose(fp);
	if (ret == 0) {
		printf("关闭成功");
	}
	else {
		printf("关闭失败");
	}
}

int fgetCAndFputc() {
	// FILE* fpw = fopen("E:\\coding\\clang\\txt\\ascii.txt", "w"); 


	for (char ch = 'a'; ch < 'z'; ch++) {
	//	printf("%3c", fputc(ch, fpw)); 	//int fputc ( int ch, FILE * stream );
	}

	printf("\n读取文件开始\n");
	FILE* fpr = fopen("E:\\coding\\clang\\txt\\ascii.txt", "r"); // r 当文件不存在时 出错
	if (NULL == fpr) {
		printf("文件不存在\n");
		return -1;
	}
	//int fgetc ( FILE * stream ); int 正常，返回读取的字符；读到文件尾或出错时，为EOF。

	char code;
	//while ((code = fgetc(fpr))!=EOF) 
	while((code=fgetc(fpr)) && !feof(fpr)) //正确的判断文件读取是否结束
	{
		printf("%3c", code);
	}

	//fclose(fpw);
	fclose(fpr);

	return 0;
}

void fgetsAndFputs() {
	
	
}

void main()
{
	fgetCAndFputc();
	system("pause");
	return;
}