#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int chartest()
{
	char c1 = 127, c2 = 128, c3 = 129, c4 = 130, c5 = 131, c6 = 132, c7 = -128;
	printf("c1=%d\n", c1);   // 127

	printf("c2=%d\n", c2);   // -128  
	printf("c3=%d\n", c3);   // -127
	printf("c4=%d\n", c4);   // -126
	printf("c5=%d\n", c5);   // -125
	printf("c6=%d\n", c6);   // -124
	printf("c7=%d\n", c7); // 为什么是-128http://blog.csdn.net/daiyutage/article/details/8575248
}

int opeatorstr()
{
	char love[] = "love";
	char big[] = "";
	strcpy(big, love);
	printf("%s\n", big);
	return 0;
}

int mainChar()
{
	
	//chartest();
	//putchar(65+"\n");//A

	opeatorstr();
	system("pause"); 
	return 0;
}