#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//堆
char *getMen(int num)
{
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if (p1 == NULL) {
		return NULL;
	}
	return p1;

}

//栈
char *getMen2()
{
	char buf[64]; //临时变量 栈区存放
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;
}

void main155()
{
	char *tmp = NULL;
	tmp = getMen(10); 
	/*
		所以在主调函数里调用getMenp p1在内存（栈区）中被析构掉 ，但是main函里的tmp没有被析构掉,而是指向了p1指向堆(操作系统管理)
	*/

	if (tmp == NULL) {
		return;
	}

	strcpy(tmp, "111222");//向tmp指向的内存空间copy数据

	//tmp = getMen2();

	printf("tmp:%d\n",*tmp);
	printf("tmp:%s.\n", tmp);// 有的系统这样的程序可能会崩溃 debug和relase效果是不一样的 原因就是临时区
	system("pause");
}