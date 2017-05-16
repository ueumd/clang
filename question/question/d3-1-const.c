#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void getmem201(const char *p)
{
	p = 1;
	p = 3;
	//p[1] = 'a';
	return;
}
void getmem202( char *const p)
{
	p[1] = 'a';
	return;
}

void getmen203(const char *const p)
{
	//p = 1;
	//p = 3;
	//p[1] = a;
	printf("%c", p[1]);
	return;
}


void constint()
{
	const int a = 10;
	
	//a = 11; error

	{
		int *p = &a;
		*p = 100;
		printf("a:%d\n", a);//a:100
       //结论C语言中的const修饰的变量 是假的 C语言中的const 是一个冒牌货
	}
}

int maind33()
{
	char *p1 = NULL;
	const char *p2 = NULL;
	constint();
	system("pause");
	return 0;
}