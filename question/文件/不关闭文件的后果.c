#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
结束输入时按ctrl + z 再回车
*/

void main111()
{
	FILE *pf;
	char path[40] = "C:\\1.txt";
	pf = fopen(path, "w"); //按照写入模式打开路径

	if (pf == NULL) {
		printf("文件打开失败");
	}
	else {
		char ch = getchar(); //获取字答输入
		while (ch != EOF) {
			fputc(ch, pf); //写入一个字符
			ch = getchar();
		}
		fclose(pf);
		//fclose 有一个动作，就是将文件缓冲区的内容写入到文本
		//如果程序意外关闭，没有调用fclose文件数据丢失 如结束进程
	//	while (1) {}
	}
	
	system("pause");
	return;
}