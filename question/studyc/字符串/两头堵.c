#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//char *p = "       abcd11111abcd2222abcdqqqqq       "; 
//main---》头
void main41()
{
	int count = 0;
	int i = 0, j = 0;

	char *p = "   abcd       ";
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j - i + 1;

	printf("count:%d", count);

	system("pause");
}

//一级指针的输入模型
//没有内存块，那有指针啊。。。
int trimSpace_很不ok的做法(char *mybuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j - i + 1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(mybuf, mybuf + i, count);
	mybuf[count] = '\0';
	return 0;
	//system("pause");
}

//一般情况下不要修改输入的内存块的值
int trimSpace_ok(char *mybuf, char *outbuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j - i + 1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(outbuf, mybuf + i, count);
	outbuf[count] = '\0';
	return 0;
	//system("pause");
}


void main2333()
{
	int ret = 0;
	char *p = NULL;
	char buf2[100];

	//对于字符串分配内存有三种方式，可以在堆、栈、全局区（常量区），你要知道你的内存是怎么分配的

	char *buf = "       abcd11111abcd2222abcdqqqqq       ";
	//char buf[] = "       abcd11111abcd2222abcdqqqqq       ";
	/*
	ret = trimSpace(buf);
	if (ret != 0)
	{
	printf("func trimSpace() err:%d\n", ret);
	return ;
	}
	*/

	ret = trimSpace_ok(buf, buf2);
	if (ret != 0)
	{
		printf("func trimSpace() err:%d\n", ret);
		return;
	}
	printf("buf2:%s \n", buf2);
	system("pause");

}