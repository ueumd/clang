#pragma once
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char c1 = 127, c2 = 128, c3 = 129, c4 = 130, c5 = 131, c6 = 132;
	printf("%d\n", c1);   // 127
	printf("%d\n", c2);   // -128
	printf("%d\n", c3);   // -127
	printf("%d\n", c4);   // -126
	printf("%d\n", c5);   // -125
	printf("%d\n", c6);   // -124
	system("pause"); 
	return 0;
}
