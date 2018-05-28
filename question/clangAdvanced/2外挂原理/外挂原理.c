#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num = 100;
void add(int x);

void add(int x) {
	num += x;
}

void msg() {
	MessageBoxA(0, "1", "2", 0);
}

int main() {

	printf("add=%p \t msg=%p\n", add, msg); //函数名存放的函数的地址 在代码区 add=008A1113     msg=008A1136

	while (1) {
		printf("num=%d\n", num);
		Sleep(5000);
	}

	system("pause");
	return 0;
}