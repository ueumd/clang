#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	enum week{MON=1,Tues,Wed,Thurs,Fri,Sat,Sun} a, b, c;
	a = Sun;
	/* 使用枚举类型声明变量，再对枚举型变量赋值 */
	enum DAY yesterday, today, tomorrow;

	yesterday = MON;
	today = Tues;
	tomorrow = Wed;

	printf("%d %d %d \n", yesterday, today, tomorrow); // 1 2 3

	printf("day=%d\n", Wed);  // 3
	printf("a=%d\n", a);     // 7

	getchar();
	return 0;
}


