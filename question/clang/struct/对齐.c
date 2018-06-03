#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*
结构体变量的大小能够被其最宽基本类型成员大小所整除
结构体的总大小为结构体最宽基本类型成员大小的整数倍，首先需要装下所有，不够就填充
*/
// 共11 1是11的倍数，可以整除
struct st1 {
	char c;				// 1个字节
	char str[10]; // 10个字节

};

// 共14 2是14的倍数，可以整除, 会自动填充字节,所不是13
struct st2 {
	short c;				// 2个字节
	char str[11];   // 11个字节						
};

// 共14 8是24的倍数，可以整除, 会自动填充字节,所不是19
struct st3 {
	double c;				// 8个字节
	char str[11];   // 11个字节						
};



/*
结构体每个成员相对于结构体首地址的偏移量都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节；
*/

// 8
struct st4 {
	char c;				// 1个字节
	int num;      // 4个字节		int 是 最宽 基本类型	
};

//0+8+4 = 12
struct st5 {
	char c;				// 1个字节												 300500 0
	int num;      // 4个字节		int 是 最宽 基本类型	 300504 4
	short sh;			// 2														 300508 8

};

//0+2+4 = 6 不是int倍数 再填充2个字节 8
struct st6 {
	char c;				// 1个字节												 300500 0
	short sh;			// 2														 300502	2
	int num;      // 4个字节		int 是 最宽 基本类型	 300504 4
};

// 1+2+8+4+19 = 34 不够8除 40
struct st7 {												// 305000
	char c;				// 1									 305000
	short sh;			// 2									 305002		
	double x;			// 8  最宽 基本类型     305008
	int num;      // 4                   305016
	char str[19]; // 19                  305020
};

// 24
typedef struct
{
	char c;    // 1
	int i[2];  // 4
	double v;  // 8
}S;

//union 同样也是

//8
union u1 {
	int num;
	double data;
};

// 12 能被4整除  又能装下11
union u2 {
	int num;			//最宽基本类型 4
	char str[11]; // 11
};

// 16 能被8整除  又能装下11
union u3 {
	double num;			//最宽基本类型 8
	char str[11]; // 11
};

//11
union u4 {
	char num;			//最宽基本类型 1
	char str[11]; // 11
};

int main333() {

	
	printf("st1=%d\n", sizeof(struct st1)); // 11
	printf("st2=%d\n", sizeof(struct st2)); // 14
	printf("st3=%d\n", sizeof(struct st3)); // 24

	printf("st5=%d\n", sizeof(struct st5)); // 8
	printf("st7=%d\n", sizeof(struct st7)); // 40

	printf("size of S = %d\n", sizeof(S));
	system("pause");
	return 0;
}