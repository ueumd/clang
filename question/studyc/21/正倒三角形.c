#include <stdio.h>
/*
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/


int main正倒三角形() {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4 - i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

	// 倒三角形
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < i + 1; j++)
			printf(" ");

		for (j = 0; j < 2 * (4- i) - 1; j++)
			printf("*");

		printf("\n");
	}


	system("pause");
	return 0;
}

#define LINE 31

int main正倒三角形2()
{
	int i, j;
	int n;
	for (i = 0; i < LINE; i++)
	{
		if (i <= LINE / 2)
			n = i;
		else
			n = LINE - i - 1;

		for (j = 0; j < (LINE / 2 - n); j++)
			printf(" ");

		for (j = 0; j < 2 * n + 1; j++)
			printf("*");

		printf("\n");
	}
	system("pause");
	return 0;
}