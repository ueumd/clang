#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CString {
	char *str; //�����ַ����׵�ַ
	int len; // ʵ�ʳ���
} mystring;

void initString(mystring *string);															//��ʼ��
void initWithLen(mystring *string, int len);						  //���ٳ��� �ڴ���0
void initWithString(mystring *string, char *copystring);  //��ʼ�� ������
void printfMyString(mystring *string);

int main() {
	mystring str;
	initWithString(&str, "�����յ���");
	printfMyString(&str);

	system("pause");
	return 0;
}

void initString(mystring *string) {
	string ->str = NULL;
	string -> len = 0;
}

void initWithLen(mystring *string, int len) {
	// string->str = (char *)malloc(sizeof(char) * len); //�����ڴ�
	string->str = (char *)calloc(len, sizeof(char));     //�����ڴ沢����,����һЩ��������
	string->len = len;
}

void initWithString(mystring *string, char *copystring) {
	int len = strlen(copystring);
	string->str = (char *)calloc(len+1, sizeof(char));
	strcpy(string->str, copystring); //�����ַ���
}

void printfMyString(mystring *string) {
	printf("\n str = %s \n", string->str);
}
