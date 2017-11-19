#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void gogogo() {
	printf("gogoggo\n");
}

int main代码区() {

	printf("%p", gogogo); //函数名存放函数的地址
	gogogo(); //直接调用
	//函数指针说的就是一个指针，但这个指针指向的函数，不是普通的基本数据类型或者类对象。
	void(*p)() = gogogo;
	p(); //间接调用


	char *pp = "ABCDEF"; //pp 存储常量字符串的地址
	printf("p=%d,\t ABCDEF=%d\n", sizeof(pp), sizeof("ABCDEF"));	// 4   8
	printf("p=%p,\tABCDEF=%p\n", &pp, pp);												//&pp 指针地址 pp字符串地址
	/*
		打断点
		p=003EF8AC,     ABCDEF=00F56B40

		内存显示按16进制查看:
		0x003EF8AC  00f56b40  @k?.

		1字节 带符号显示 8列
		0x00F56B40   +65  +66  +67  +68  +69  +70   +0   +0  ABCDEF..
	*/

	//	*pp = "cc"; //错误   代码区只能读 常量字符串在代码区
	pp = "cc"; // pp指向了cc的内存地址

	system("pause");
	return 0;
}