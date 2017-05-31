#include "stdio.h"
#include "stdlib.h"

typedef char *String;

typedef struct Student {
	char *name;
	int age;
}Stu;

typedef struct {
	float x;
	float y;
}Point;

typedef Point *PP;

//typdef 与 define区别
typedef char *String1;
#define String2 char *

int maintypedef()
{
	Stu t;
	t.name = "shanghai";
	t.age = 20;

	String s = "hello world";

	printf("%s\n", s);

	Point pp = { 10,20 };
	PP p = &pp;

	// 利用指针变量访问结构体成员
	printf("x=%f，y=%f\n", p->x, p->y);


	String1 s1, s2;
	String2 s3, s4;

	//注意：在这种情况下，只有str1、str2、str3才是指向char类型的指针变量，str4只是个char类型的变量。
	/*
		int a,b;
		int a;
		int b;

		String1 s1, s2;

		由于String1就是char *，所以上面的两行代码等于
		char *s1;
		char *s2;

		因为宏定义纯粹是字符串替换，用char *代替String2 所以String2 s3,s4就想相当于
		char * str3, str4;
		char * s2;
		char s4;

		可以看出，只有s4是基本数据类型，s1、s2、s3都是指针类型。
		所以，以后给类型起别名，最好使用typedef，而不是使用#define
	*/

	system("pause");
	return 0;
}