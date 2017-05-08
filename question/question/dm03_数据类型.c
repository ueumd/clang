#include<stdio.h>
#include<stdlib.h>
/*
数据类型的本质：

数据类型可理解为创建变量的模具（模子）;是固定内存大小的别名

数据类型的作用：编译器预算对象（变量）分配的内存空间大小
*/
void main数据类型()
{
	int a;		//告诉c编译器分配4个字节的内存
	int b[10];  //告诉c编译器分配40个节字的内存

	printf("b:%d,   b+1:%d\n",b, b+1);
	printf("&b:%d, &b+1:%d\n",&b,&b + 1);
	 //b:2029316,  b+1:2029320 向后跳了4个字节
	//&b:2029316, &b+1:2029356 向后跳了40个字节 
	/*
		b+1 &b+1结果不一样 b  &b所代表的类据类型不一样
		b  代表数组首元素的地址 b[0]
		&b 代表的是整个数组的地址

		b &b 数组数据类型：
		1.定义一个数组类型
		2 数组指针
		3 数组类型和数组指针类型的关系
	*/	
	//求长度
	printf("sizeof(b):%d\n", sizeof(b)); //40
	printf("sizeof(a):%d\n", sizeof(a)); //4


	{
		char *p2 = NULL;
		void *p1 = NULL;
		p2 = (char *)malloc(100); //malloc返回是一个void类型
	}

	{
		//void a; 不存在void类型变量 这样写c不知道怎么分配内存
	}

	system("pause");
	
}

