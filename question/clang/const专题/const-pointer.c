#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//const
int getNum() {
	return 100;
}

//初始化
void constBae()
{
	int n = 90;
	const int MaxNum1 = getNum();  //运行时初始化
	const int MaxNum2 = n;         //运行时初始化
	const int MaxNum3 = 80;       //编译时初始化
  //MaxNum2 = 200;错误 创建后就不能再修改了
	printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);
}

void constAndPointer()
{
	int a = 10, b = 20;

	const int *p1; //离变量名p1近 ，修饰的是指针指向的数据不能被修改，但指针本身指向可以修改
	int const *p2;
	int * const p3 = &a;  // 修饰指变

	p1 = &a;
	p2 = &a;

	p1 = &b;
	p2 = &b;

	/*
	错误
	*p1 = 20;
	*p2 = 20;
	 p3 = 100;
	 p3 = &b;
	*/

	/*
	在最后一种情况下，指针是只读的，也就是 p3 本身的值不能被修改；
	在前面两种情况下，指针所指向的数据是只读的，也就是 p1、p2 本身的值可以修改（指向不同的数据），但它们指向的数据不能被修改。
	*/

	//只读不能修改
	const int * const p4 = &a;
	int const * const p5 = &b;

	{
		const int a;  //
		int const b;

		const char *c;
		char * const d; char buf[100];
		const char *const e;
		/*
		第一个第二个意思一样代表一个常整形数 通过指针可以修改

		第三个 c是一个指向常整形数的指针(所指向的内存数据不能被修改，但是本身可以修改)
		第四个 d 常指针（指针变量不能被修改，但是它所指向内存空间可以被修改）
		第五个 e一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）

		记忆方法
		const 离变量名近就是用来 修饰 指针变量
		离 变量名 远 就是用来 修饰 指针指向的数据
		如果 近的和远的 都有，那么就 同时 修饰 指针变量 以及它 指向的数据
		*/
	}

	{
		/*
		在C语言中，单独定义 const 变量没有明显的优势，完全可以使用#define命令代替。

		const 通常用在函数形参中，如果形参是一个指针，为了防止在函数内部修改指针指向的数据，就可以用 const 来限制。
		在C语言标准库中，有很多函数的形参都被 const 限制了，下面是部分函数的原型：
		*/
		size_t strlen(const char * str);
		int strcmp(const char * str1, const char * str2);
		char * strcat(char * destination, const char * source);
		char * strcpy(char * destination, const char * source);
		int system(const char* command);
		int puts(const char * str);
		int printf(const char * format, ...);
	}

}

//使用 const 对形参加以限制，例如查找字符串中某个字符出现的次数：
size_t strnchr(const char * const str, char ch) {
	// str[1] = 's'; //如果不加以const 修饰 可以改变 实参里内存空间的数据 形参也会改变
	//str = "I Love C"; //加两个const双重限制 str只能读
	int i, n = 0, len = strlen(str);

	for (i = 0; i<len; i++) {
		if (str[i] == ch) {
			n++;
		}
	}

	return n;
}

/*
const 和非 const 类型转换
也就是说，const char *和char *是不同的类型，不能将const char *类型的数据赋值给char *类型的变量。
但反过来是可以的，编译器允许将char *类型的数据赋值给const char *类型的变量。

这种限制很容易理解，char *指向的数据有读取和写入权限，
而const char *指向的数据只有读取权限，降低数据的权限不会带来任何问题，但提升数据的权限就有可能发生危险。
*/

void func(char *str) { }


void test() {
	char str[] = "http://c.biancheng.net";
	char ch = 't';
	int n = strnchr(str, ch);
	printf("%d\n", n);
	printf("%s\n", str);

	const char *str1 = "c.biancheng.net";
	//char *str2 = str1; // const 赋值给非 const
	//func(str1); // const 赋值给非 const

	char *str2 = "Hello";
	str1 = str2; //非 const 赋值给  const可以
	printf("%s\n", str2);
}

int main()
{
	constAndPointer();



	system("pause");
	return 0;
}