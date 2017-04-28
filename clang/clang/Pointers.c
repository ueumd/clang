#include<stdio.h>
#include<stdlib.h>

int pointerTest()
{
	int a = 7;
	int *p = &a;

	printf("a memory address:%p\n", &a);//  //0x003bfbe0
	//p = 10;//不可以把一个整数值直接赋值给指针变量
	*p = 9;

	printf("修改后，a的值：%d\n", a);
	return 0;
}

//笨方法交换
int swap(char v1,char v2)
{
	printf("更换前：v1=%d, v2=%d\n", v1, v2);
	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
	printf("更换后：v1=%d, v2=%d\n", v1, v2);
	return 0;
}

int swapPointer(char *v1,char *v2)
{
	printf("更换前：v1=%d, v2=%d\n", *v1, *v2);
	char temp; //会在内存中在开辟一个地址
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
	printf("更换后：v1=%d, v2=%d\n", *v1, *v2);
	return 0;
}

int studyPointer()
{
	
	int b = NULL;
	int *p = NULL;//空指针不指向任何变量

	int i = 10;
	int *p3;//定一义指向int类型的指针变量 内存地址 野指针，不知道指向什么内存
	
	//p3=100;不可以把一个整数值直接赋值给指针变量
	p3 = &i;//p3指向i的内存地址

	int a = *p3;//a指向p3的内存地址

	*p3 = 100;//把p3指向的内存区域的值赋值为100 那么 i=100;

	printf("%x\n", p3);
	printf("i=%d\n", i);  //i=100
	printf("p3=%d\n", *p3);//p3=100
	printf("a=%d\n", a);  //a=10
	return 0;
}

//传递指针给函数

//函数的声明
int triplePointer(int *pointerNumber);
int triplePointer(int *pointerNumber)
{
	/*
		pointerNumber 地址
		*pointerNumber 指针指向的值
		pointerNumber=&pointerNum
	*/
	*pointerNumber = *pointerNumber * 3;
	return 0;
}

int triplePointer2(int *pointerNumber)
{
	*pointerNumber = *pointerNumber * 3;
	return 0;
}
/*
我们给它输入的参数是一个分钟数，它返回给我们两个值：小时数和分钟数。
例如：
传给函数30，它返回0小时30分钟
传给函数60，它返回1小时0分钟
传给函数90，它返回1小时30分钟
*/
int transformMinutes(int *hours,int *minutes)
{
	*hours = *minutes / 60;
	*minutes = *minutes % 60; //分钟取余
	return 0;
}

int mainpointer()
{
	int pointerNum = 10;
	int pointerNum2 = 10;
	int *p = &pointerNum2;
	//pointerTest();
	char v1 = 10, v2 = 90;
	//swap(v1, v2);
	//swapPointer(&v1,&v2);
	//studyPointer();
	//arrPointer();
	//triplePointer(&pointerNum); //这里要传递pointerNum的地址
	//triplePointer2(p); //p存的是pointerNum2内存地址
	//printf("*pointerNum =%d\n", pointerNum); //30
	//printf("*pointerNum2 =%d\n", pointerNum2); //30


	int hours = 0, minutes = 90;

	/* 这一次我们传递了hours和minutes的地址 */
	transformMinutes(&hours, &minutes);

	// 这一次，数值如我们所愿改变了
	printf("%d 小时 : %d 分钟\n", hours, minutes);

	system("pause");
	return 0;
}