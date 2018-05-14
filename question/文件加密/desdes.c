#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "des.h"
int DesEncfile() {
	//定义字符数组
	unsigned char buf8[9] = "123456789";
	//定义明文长度
	int plainlen = 9;
	//定义密文数组
	unsigned char bufcrypt[16] = { 0 };
	//定义密文长度
	int cryptlen = 0;
	//开始加密明文
	int rest = DesEnc(buf8, plainlen, bufcrypt, &cryptlen);
	if (rest != 0)
	{
		printf("加密失败！\n");
		return 1;
	}
	else {
		printf("加密成功！\n");
		printf("密文：%s\n", bufcrypt);
	}
	//解密文件
	//定义字符数组
	//之所以定义数组长度是10，是为了在末尾加上一个'\0'方便打印
	unsigned char buf82[10] = { 0 };
	//定义明文长度
	int plainlen2 = 0;
	int rest2 = DesDec(bufcrypt, cryptlen, buf82, &plainlen2);
	if (rest2 != 0)
	{
		printf("解密失败！\n");
		return 1;
	}
	else {
		printf("解密成功！,明文是%s\n", buf82);
	}
	//比较解密之后的明文是否和原来的明文相同
	//memcmp()比较buf8和buf82在plainlen2长度上的内容是否相同
	if (memcmp(buf8, buf82, plainlen2) == 0)
	{
		printf("两者内容相同！\n");
	}
	return 0;
}

int main() {
	DesEncfile();
	system("pause");
	return 0;
}