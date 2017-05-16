#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main栈的属性和buf地址增长()
{
	//栈的开口可能朝上 可能朝下  一般认为:开口朝下
	//不管栈开口向上还是向下,buf的内存地址buf+1永远向上的

	int a;
	int b;

	char buf[128]; //静态编译 buf所代表的内存空间编号就已经定义下来了

	printf("&a:%d, &b:%d\n", &a, &b);//debug模式 &a:1505780, &b:1505768 b的值小 说明开口朝下
	system("pause");
}