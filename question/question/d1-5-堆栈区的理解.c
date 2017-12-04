#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//堆
char *getMen(int num)
{
	// 
	/*
	栈中分配内存空间 p1 并指向下面10个字节的堆内存空间
	在getMen函数运行完后，在栈中消失，消失之前返回p1给main函数中的tmp，这时tmp指向堆中的10个字节内存空间
	*/
	char *p1 = NULL; 

	// 在堆里开辟10字节个内存空间, 这10个内存空间不会因为子函数 运行完而被析构,因为它在堆里
	p1 = (char *)malloc(sizeof(char) * num); 
	if (p1 == NULL) {
		return NULL;
	}
	return p1;
}

//栈 注意return不是把内存块64个字节，给return出来，而是把内存块的首地址（内存的标号），返回给tmp 
/*
理解指针的关键是内存，没有内存哪里来的指针
指针指向谁，就把谁的地址指向谁
*/
char *getMen2()
{
	char buf[64]; //临时变量 栈区存放
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;
}

void main()
{

	char *tmp = NULL; // 栈中分配内存空间 tmp
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