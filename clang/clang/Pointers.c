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

//数组指针
int arrPointer()
{
	int array[10] = { 6 };//array[0]=6;
	int *p = &array[0];
	int *p3 = array;

	printf("%p,  %p\n", array, &array[0]);
	//pintf("*p=%d\n", *p);
	//getchar();

	return 0;
}

int main()
{
	//pointerTest();
	char v1 = 10, v2 = 90;
	//swap(v1, v2);
	//swapPointer(&v1,&v2);
	studyPointer();
	//arrPointer();
	system("pause");
	return 0;
}