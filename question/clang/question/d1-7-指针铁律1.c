#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main2222()
{
	/*
		int a=10;
		char *p=NULL;

	   *p = 100   不会改变指针变量的值，只会改变所指的内存块的值
	    p = &a;   p赋值 p=&a; 只会改变指针变量值，不会改变所指的内容
		c = *p    在等于右边 取值

	*/
	
	int a = 10;
	char *p1 = 100;//指针变量 分配4个字节的内存   （给内存赋值）  

	char ****p2 = 100;

	int *p3 = NULL;

	p3 = &a;

	*p3 = 20;//间接修改a的值

	int c = *p3;//取值

	printf("%d\n", c);

	printf("a:%d,p1:%d,p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));//4 4 4 

	{
	//	char *p4 = NULL;
		//p4 = (char *)mollac(100);
		//p4 = (char *)mollac(200);
		/*
			一开始p4在栈中 指向堆中 100的内存空间地址
			后又指向堆中 200的内存空间地址

			总结：不断的给指针变赋值，相当于不停的改变指针方向  
		*/
	}


	system("pause");
	return;
}


/*
int getAbc1(char *p1);
int getAbc2(char **p2);
int getAbc3(char ***p3);
int getAbc4(char (*p4)[30]);
int getAbc5(char p5[10][30]);

指针做函数参数，形参有多级指针的时候
站在编译器的角度，只需要分配4个字节的内存（32bit平台）
当我们使用内存的时候，我们才关心指针所指向的内存是一维的还是二维的

重点：
指针是一种数据类型，是指它指向的内存空间的数据类型
*/

//犯错1空指
//空指针写入
void errorOne()
{
	char *p1 = NULL;
	p1 = 0x00000007;
	strcpy(p1, "abcdefg"); 
	/*
		向指针变量*p1指向的内存空间0写入数据 0是在常量区，操作系统保护
		所以会弹出提示写入位置冲突
	*/
	return;
}

void errorTwo()
{
	
	char buf[128]; //c可以在栈上分配内存
	int i;
	int j = 0;    //字面量(0没有放在栈区 也没有放在堆区 全局区？代码区？不好说)

	char *p1 = NULL;
	char *p2 = NULL;

	//不断的改变p1的值，相当于不断改变指针的指向
	p1 = &buf[0];
	p1 = &buf[1];
	p1 = &buf[2];

	for (i = 3; i < 10; i++) {
		//p1 =p1[i];
	}

	p2 = (char *)malloc(100);
	strcpy(p2, "abcdefg1234567891012");
	
	/*
		p1又指向了p2所指向的内存空间（堆）
	*/

	for (i = 0; i < 10; i++) {
		p1 = p2+i;
		printf("%c ", *p1);
	}

}

void maintilv111()
{
	
	//errorOne();
	errorTwo();
	system("pause");
	return;
}