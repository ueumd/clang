#include<stdio.h>
#include<stdlib.h>

/*
#define 宏名 字符串
带参数的宏和函数很相似，但有本质上的区别：
宏展开仅仅是字符串的替换，不会对表达式进行计算；宏在编译之前就被处理掉了，它没有机会参与编译，也不会占用内存。
而函数是一段可以重复使用的代码，会被编译，会给它分配内存，每次调用函数，就是执行这块内存中的代码。
*/
#define PI 3.1415926

#define M (n*n+3*n) 
#define MAX(a,b) (a>b)?a:b

int definefn()
{
	int n = 10, sum;
	sum = 3 * M + 4 * M + 5 * M;
	printf("sum=%d\n", sum);//1560

	int max, a = 10, b = 5;
	max = MAX(a, b); //宏操作只是简单的字符串替换 max=(a>b)?a:b
	printf("max=%d\n", max);//10
	return 0;
}

int ansic()
{
	/*

	ANSI C 规定了以下几个预定义宏，它们在各个编译器下都可以使用：
	__LINE__：表示当前源代码的行号；
	__FILE__：表示当前源文件的名称；
	__DATE__：表示当前的编译日期；
	__TIME__：表示当前的编译时间；
	__STDC__：当要求程序严格遵循ANSI C标准时该标识被赋值为1；
	__cplusplus：当编写C++程序时该标识符被定义。
	*/
	printf("Date : %s\n", __DATE__);
	printf("Time : %s\n", __TIME__);
	printf("File : %s\n", __FILE__);
	printf("Line : %d\n", __LINE__);
	return 0;
}

int ifendiffn()
{
	//#if、#elif、#else 和 #endif 都是预处理命令
	/*
	#if 命令命令的完整格式为：

	#if 整型常量表达式1
		程序段1
	#elif 整型常量表达式2    (可省)
		程序段2
	#elif 整型常量表达式3
		程序段3
	#else                    （可省）
		程序段4
	#endif
	*/

	#if __WIN32
		system("color 0c");
		printf("http://c.biancheng.net\n");
	#elif __linux
		printf("\033[22;31mhttp://c.biancheng.net\n\033[22;30m");
	#else 
		printf("http://c.biancheng.net\n");
	#endif

	return 0;
}


int ifdeffn() 
{
	/*
	如果当前的宏已被定义过，则对“程序段1”进行编译，否则对“程序段2”进行编译。
	#ifdef 命令的格式为：
	#ifdef  宏名
		程序段1
	#else
		程序段2
	#endif
	*/

	#ifdef _DEBUG
		printf("正在使用 Debug 模式编译程序...\n");
	#else
		printf("正在使用 Release 模式编译程序...\n");
	#endif

	return 0;
}
/*
区别
#if 后面跟的是“整型常量表达式”      #if NUM == 10 || NUM == 20
#ifdef 和 #ifndef 后面跟的只能是一个宏名，不能是其他的。
*/

int errorfn()
{
	#ifdef WIN32
	#error This programme cannot compile at Windows Platform
	#endif
	return 0;
}

int main()
{

	definefn();
	ansic();
	ifendiffn();
	ifdeffn();
	errorfn();
	system("pause");
	return 0;
}