#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CString {
	char *str; //保存字符串首地址
	int len; // 实际长度
} mystring;

void initString(mystring *string);															//初始化
void initWithLen(mystring *string, int len);						  //开辟长度 内存清0
void initWithString(mystring *string, char *copystring);  //初始化 并拷贝
void printfMyString(mystring *string);

int main() {
	mystring str;
	initWithString(&str, "锄禾日当午");
	printfMyString(&str);

	system("pause");
	return 0;
}

void initString(mystring *string) {
	string ->str = NULL;
	string -> len = 0;
}

void initWithLen(mystring *string, int len) {
	// string->str = (char *)malloc(sizeof(char) * len); //分配内存
	string->str = (char *)calloc(len, sizeof(char));     //分配内存并清零,避免一些垃圾数据
	string->len = len;
}

void initWithString(mystring *string, char *copystring) {
	int len = strlen(copystring);
	string->str = (char *)calloc(len+1, sizeof(char));
	strcpy(string->str, copystring); //拷贝字符串
}

void printfMyString(mystring *string) {
	printf("\n str = %s \n", string->str);
}
