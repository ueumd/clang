#include<stdio.h>
#include<stdlib.h>
int main() {
	printf("char \t\t size = %d\n", sizeof(char));
	printf("short \t\t size = %d\n", sizeof(short));
	printf("int \t\t size = %d\n", sizeof(int));
	printf("long\t\t size = %d\n", sizeof(long int));
	printf("long long\t size = %d\n", sizeof(long long));
	printf("float \t\t size = %d\n", sizeof(float));
	printf("double \t\t size = %d\n", sizeof(double));
	printf("long double\t size = %d\n", sizeof(long double));

	/*
	char             size = 1
	short            size = 2
	int              size = 4
	long             size = 4
	long long        size = 8
	float            size = 4
	double           size = 8
	long double      size = 8
	*/

	unsigned char a; // 用有符号来打印，则容易溢出
	for (a = 0; a <128; a++)
	{
		printf("%d-->%c\t\t", a, a);
		if (a % 8 == 0)
			printf("\n");
	}

	unsigned char b = -100;
	printf("b = %d-->%c\t\t", b, b);

	system("pause");
	return 0;
}
