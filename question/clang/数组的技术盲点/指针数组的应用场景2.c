#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main2222(int argc, char* argv[], char**env)
{
	int i = 0;
	printf("************* Begin argv ***************\n");
	for (i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	printf("************* End argv ***************\n");
	printf("\n");
	printf("\n");
	system("pause");
	return;
}