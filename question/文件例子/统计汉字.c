#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void testbyte() {
	printf("%d\n", sizeof("��")); // 3 һ������2���ֽڣ��ټ� '\0'

	char str[5] = "����";
	printf("%d\n", sizeof("����"));
	printf("%c%c\n", str[0], str[1]); //�ַ�����һ������������
}

void main() {
	

	testbyte();
	
	system("pause");
}