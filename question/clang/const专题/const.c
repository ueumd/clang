#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 所指向的内存数据不能被修改，但是本身可以修改
void getmem201(const char *p)
{
	p = 1;
	p = 3;
	// p[1] = 'a'; // 错误内存数据不可以修改,但本身可以修改 表达式是必须可修改的左值
	return;
}

// 常指针（指针变量不能被修改，但是它所指向内存空间可以被修改）
void getmem202(char *const p)
{
	// p = 250; // 错误本身是不可以修改的 表达式是必须可修改的左值
	p[1] = 'a';
	return;
}

// 指针和它所指向的内存空间，均不能被修改
void getmen203(const char *const p)
{
	//p = 1;
	//p = 3;
	//p[1] = a;
	printf("%c", p[1]);
	return;
}

//结论C语言中的const修饰的变量 是假的 C语言中的const 是一个冒牌货
void constint()
{
	const int a = 10;
	//a = 11; error
	{
		int *p = &a;
		*p = 100;
		printf("a:%d\n", a); //a:100								
	}
}

int main2()
{
	char *p1 = NULL;
	const char *p2 = NULL;
  constint();
	system("pause");
	return 0;
}