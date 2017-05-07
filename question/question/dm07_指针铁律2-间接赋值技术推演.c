#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getFileLen(int *p)
{
	*p = 41; //间接修改a的值
}

int getFileLen2()
{
	int a = 100;
	return a;
}
int getFileLen3(int b)
{
	b = 100;
}
//1级指针技术推演
void mainOneLevel()
{
	int a = 10;
	int *p = NULL;

	a = 20; //直接修改

	p = &a;

	*p = 30;//p的值是a的地址 *就像一把钥匙 通过地址 找到一块内存空间 就间接的修改了a的值

	printf("a:%d \n", a);//a:30

	{
		*p = 40;
		printf("a:%d \n", a); //40
	}

	getFileLen(&a);
	printf("getFileLen后a:%d \n", a);//a:41

	getFileLen3(a); // a和方法里b没有关系
	printf("getFileLen3后a:%d \n", a);//a:41

	system("pause");
	return;

}


void getMem(char **p2)
{
	*p2 = 400;
	//printf("p2:%d \n",p2);
}

//二级指针
void main()
{
	char *p1 = NULL;

	char **p2 = NULL; //二级指针

	p1 = 0x11;
	p2 = 0x22;

	//直接修改p1的值 (栈)
	p1 = 0x111;

	//间接修改p1的值
	p2 = &p1;
	*p2 = 100;//间接赋值 p2是p1的地址

	printf("p1:%d \n", p1);//100
	
	getMem(&p1);
	printf("p1:%d \n", p1);//400

	system("pause");
	return;
}