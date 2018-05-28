#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void main()
{
	char c;
	//char *str = "abcdefg";
	char str[] = "abcdefg";
	int len = strlen(str);
	char *p1 = str;
	char *p2 = str + len -1;

	while(p1<p2)
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1 ++;
		p2 --;
	}

	printf("str:%s\n", str);

	system("pause");
}