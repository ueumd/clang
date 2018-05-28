#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a;	
	int b;
	int *p;	//内存中分配空间

	//直接赋值 // cpu里面执行
	a = 10;                         
	printf("&a:%d\n", &a); //&a:3210316
	printf("a:%d\n", a);  //a:10

	//间直赋值 - 直接通过内存(变量的门牌号)
	*((int *)&a) = 200; //指针的来源
	printf("a:%d\n", a); //a:200

	 //间直赋值- 通过指针
	{
		p = &a;
		*p = 300;
		printf("a:%d\n", a); //a:300
	}
	
	system("pause");

}