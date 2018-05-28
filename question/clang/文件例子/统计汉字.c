#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void testbyte() {
	printf("%d\n", sizeof("我")); // 3 一个汉字2个字节，再加 '\0'

	char str[5] = "你是";
	printf("%d\n", sizeof("你是"));
	printf("%c%c\n", str[0], str[1]); //字符连在一起可以输出汉字
}

void main() {
	

	testbyte();
	
	system("pause");
}