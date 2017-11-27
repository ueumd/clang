#include<stdio.h>
#include<stdlib.h>
#pragma comment(lib, "3lib的调用.lib") //调用lib方式的一种，lib文件在当前项目文件夹内，
void msg();
int main() {
	msg();
	system("pause");
	return 0;
}
