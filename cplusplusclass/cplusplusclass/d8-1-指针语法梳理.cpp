#include "iostream"

using namespace std;

void pointBase()
{
	int abc = 100;

	int *p5 = NULL;
	//*p5 = 200;//空指在内存特殊区域0X00000000  这段区域系统保护 不能直接整数值，只能接授变量的地址

	p5 = &abc;

	int i = 10; 
	int *p=NULL;// 定义了一个指向int类型的 指针变量(只能存 变量的地址)
	//p = 10;错误，不可以把一个整数直接赋值给 指针变量
	//C语言中每个变量都有内存地址。&答号就是取变量地址
	&i;//取变量i的地址
	p = &i;//将 指针变量p 指向 i的地址

	*p = 100;//把p 指向的内存区域的值赋值为100；即i=100;

	printf("i:%d, p:%d\n", i,*p);

	int *p1 = &i;

	int a = *p;//*号是在c当中是 指针 指向 内存的 值

	printf("i:%d, p:%d, a:%d\n", i, *p, a);

	int b = NULL; //0
	int *p2 = NULL;//空指指 指向内存中特殊的区域0
	int ab = 10;
	char c = 'a';

	/*
	定义一个指向 int类型的 指针变量 ，没有赋初值，就是一个野指针，指向什么内存不知道
	野指针危害很大
	*/
	int *p3; 
	//*p3 = 10;//错误 野指针也叫悬空指针，不能给野指针指向的内存区域赋值
	// p3 = &c; //错误 char => int
	p3 = &ab; //?这样能编译通过~~~ 兼容？

	printf("*p3:%d\n" ,*p3); //10

	/*
	无类型指针 C中可以将任何地一种地址赋值给无类型指针
	无类型指针在使用时必须强转
	*/
	void *p4;//定义了一个无类型的指针

	p4 = &c;

	//printf("*p4:%d\n", *p4); //错误 虽然前面已经将&c内存地址给p4，但在使用的时候不知道指向什么类型的数据,可以强转
	printf("*p4:%d\n", *(char *)p4); //先转成char类型指针(char *) 再通过指针去找指针变量所指向的内存空间

	
}

void pointArray()
{

}

void main()
{
	pointBase();


	cout << "hello..." << endl;

	system("pause");
	return;
}