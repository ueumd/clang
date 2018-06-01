#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void testEnum() {
	enum week { MON = 1, Tues, Wed, Thurs, Fri, Sat, Sun } a, b, c;
	a = Sun;
	/* 使用枚举类型声明变量，再对枚举型变量赋值 */
	enum DAY yesterday, today, tomorrow;

	yesterday = MON;
	today = Tues;
	tomorrow = Wed;

	printf("%d %d %d \n", yesterday, today, tomorrow); // 1 2 3

	printf("day=%d\n", Wed);  // 3
	printf("a=%d\n", a);     // 7
}

void testUnion() {
	union untest { 
		char c;  
		short s; 
		long long i; 
	}myun;

	printf("sizeof(myun) = %d\n", sizeof(myun)); // 8
	//union 地址是一样的， 结构体不是
	printf("%p \n", &myun.c);		// 0029F93C
	printf("%p \n", &myun.s);   // 0029F93C
	printf("%p \n", &myun.i);   // 0029F93C

	/*
	union untest {
		char c;
		short s;
		long long i;
	}myun;

	sizeof(myun) = 8
	0031F828
	0031F828
	0031F828
	*/

	/*
	struct untest {
		char c;
		short s;
		long long i;
	}myun;

	sizeof(myun) = 16
	001CF8EC
	001CF8EE
	001CF8F4
	*/

}

int main() {
	
	testUnion();
	getchar();
	return 0;
}


