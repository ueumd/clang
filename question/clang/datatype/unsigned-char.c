#include<stdio.h>

#if 0
char与unsigned char没有什么不同，都是一个字节，唯一的区别是，
char          最高位为符号位，因此char能表示 - 128~127, 
unsigned char 没有符号位，因此能表示0~255，这个好理解，8个bit，最多256种情况，因此无论如何都能表示256个数字。
#endif

int chartest() {
	// char 默认是有符号位- 128~127

	char  c1 = 127,
				c2 = 128,
				c3 = 129,
				c4 = 130,
				c5 = 131,
				c6 = 132;

	printf("%d\n", c1);   // 127
	printf("%d\n", c2);   // -128
	printf("%d\n", c3);   // -127
	printf("%d\n", c4);   // -126
	printf("%d\n", c5);   // -125
	printf("%d\n", c6);   // -124
	system("pause");
	return 0;
}

void printsizeof() {
	printf("char        size = %d\n", sizeof(char));
	printf("short       size = %d\n", sizeof(short));
	printf("int         size = %d\n", sizeof(int));
	printf("logn        size = %d\n", sizeof(long int));
	printf("long long   size = %d\n", sizeof(long long));
	printf("float       size = %d\n", sizeof(float));
	printf("double      size = %d\n", sizeof(double));
	printf("logn double size = %d\n", sizeof(long double));
	/*
	char        size = 1
	short       size = 2
	int         size = 4
	logn        size = 4
	long long   size = 8
	float       size = 4
	double      size = 8
	logn double size = 8
	*/
}

void printunsigned() {
	char			     uint8 = 0; //默认是有符号
	unsigned char  uint82 = 0;
	signed char    int8 = 0;
	unsigned short uint16 = 0;
	signed short   int16 = 0;
	unsigned int   uint32 = 0;
	signed int     int32 = 0;
	float          fp32 = 0;
	double         fp64 = 0;
	unsigned long  ulong = 0;

	printf("char            is %d bit\n\r", sizeof(uint8) * 8);
	printf("unsigned char   is %d bit\n\r", sizeof(uint82) * 8);
	printf("signed char     is %d bit\n\r", sizeof(int8) * 8);
	printf("unsigned short  is %d bit\n\r", sizeof(uint16) * 8);
	printf("signed short    is %d bit\n\r", sizeof(int16) * 8);
	printf("unsigned int    is %d bit\n\r", sizeof(uint32) * 8);
	printf("signed int      is %d bit\n\r", sizeof(int32) * 8);
	printf("float fp32      is %d bit\n\r", sizeof(fp32) * 8);
	printf("double fp64     is %d bit\n\r", sizeof(fp64) * 8);
	printf("unsigned long   is %d bit\n\r", sizeof(ulong) * 8);

	/*


	char        size = 1
	short       size = 2
	int         size = 4
	logn        size = 4
	long long   size = 8
	float       size = 4
	double      size = 8
	logn double size = 8

	--------------------------------------
	1 byte  = 8  bit

	char            is 8 bit
	unsigned char   is 8 bit
	signed char     is 8 bit
	unsigned short  is 16 bit
	signed short    is 16 bit
	unsigned int    is 32 bit
	signed int      is 32 bit
	float fp32      is 32 bit
	double fp64     is 64 bit
	unsigned long   is 32 bit
	*/
}

int main() {
	printsizeof();
	printf("\n--------------------------------------\n");
	printunsigned();

	system("pause");
	return 0;
}