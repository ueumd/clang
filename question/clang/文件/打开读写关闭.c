#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
//一次只读写文件中的一个字符 stdio.h
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
	//while ((code = fgetc(fpr))!=EOF)  //EOF = -1  会多输出一个空格
	while((code=fgetc(fpr)) && !feof(fpr)) //正确的判断文件读取是否结束
	{
		printf("%3c", code);
	}

	//fclose(fpw);
	fclose(fpr);

	return 0;
}

//一次读写一行字符(文本操作)
void fgetsAndFputs() {
	FILE *fp = fopen("E:\\coding\\clang\\txt\\lines2.txt", "w+");
	if (NULL == fp) {
		printf("fopen error\n");
		return -1;
	}

	printf("%d\n", fputs("abcdefg\n", fp));
	printf("%d\n", fputs("123456789\n", fp));

	char buf[] = "xyz";
	printf("%d\n", fputs(buf, fp));


	rewind(fp);

	char buf2[1024];
	fgets(buf2, 4, fp);
	printf("%s", buf2);

	fclose(fp);
	return 0;
}


#if 0
fgets(buf, len, fp) 最多读len-1个字符，中途遇到'\n'(会被读取)，或EOF结束本次读取， 读取结束后自动追加'\0'
#endif

void main打开读写关闭()
{
	// fgetCAndFputc();

	fgetsAndFputs();
	system("pause");
	return;
}