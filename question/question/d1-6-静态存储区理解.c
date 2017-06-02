#include<stdio.h>
#include<stdlib.h>

char * getStr1()
{
	char *p1 = "abcdefg2";
	return p1;
}

char * getStr2()
{
	char *p2 = "abcdefg2";
	return p2;
	/*int a = 10;
	int *pa = &a;
	return *pa;*/
}

void main静态区()
{
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = getStr1();
	p2 = getStr2();

	//p1 p2所指向的内存空间数据
	printf("p1:%s, p2:%s\n",p1,p2);//abcdefg2 abcdefg2

	// p1 p2的值
	printf("p1:%d, p2:%d\n", p1, p2);
	/*
	相等 因为在内存的静态区 归操作系管理
	所以在主调函数里调用getStr1() getStr2() p1 p2在内存（栈区）中被析构掉 ，但是main函数里的p1 p2没有被析构掉

	*/

	system("pause");
}