#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main野指针产生的原因()
{
	char *p1 = NULL;	// p1栈中分配内存空间 NULL默认是0 p1的地址是0
	p1 = (char *)malloc(100); // p1指向了堆中开辟的空间 叫 0xaa11吧 p1的地址变成了0xaa11
	strcpy(p1, "123654");			// 把常量区的123654 拷贝到p1所指向的堆中空间

	if (NULL == p1) {
		return;
	}
	printf("p1:%s\n", p1);

	if (p1 != NULL) {
		free(p1);  // 释放p1指向堆中的空间 但p1变量的地址还是0xaa11，乱指向了一个垃圾空间
		p1 = NULL; // 必须要把p1的地址
	}

	/*
		如果前面已经释放了，再free(p1)这里会有问题的，也就产生了野指针，解决办法：p1=NULL
	*/
	if (p1 != NULL) {
		free(p1);
	}

	system("pause");
	return;
}