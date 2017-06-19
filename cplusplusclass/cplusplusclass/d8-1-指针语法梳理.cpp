#include "iostream"
#include <stdio.h>
#include <string.h>
using namespace std;

//指针基础
void pointerBase()
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

void pointerArray()
{
	int array[10] = { 6 };//array[0]:6

	int *p = &array[0]; //p指向了数组的第一个元素的地址
	int *p1 = array;    //p1指向了数组的首地址(及数组的第一个元素的地址)

	printf("%p, %p\n", array, &array[0]);//0036FDE4, 0036FDE4
	printf("%p, %p\n", p, p1);           //0036FDE4, 0036FDE4

	printf("*p = %d\n",*p);    //6
	printf("*p1 = %d\n", *p1); //6


	/*
	sizeof(array) :40  4*10
	sizeof(p)     :4   4 32位系统 一个指针占4个字节 64位 8个字节
	*/
	printf("sizeof(array)=%d,sizeof(p1)=%d\n", sizeof(array), sizeof(p1));

	printf("%d, %d\n",sizeof(int *), sizeof(char *));

	/*
	 array  数组名称代表数组的首地址
	 *array 首地址的值
	 &array 也是数组的首地址（一不这样用） 
	 int *p1=array 等介于 int *p1=&array
	*/
	printf("array=%p,*array=%p,&array=%p\n", array,*array,&array);


	int a = 16, b = 932, c = 100;
	int *arr[3] = { &a,&b,&c };// 指针数组
	int **parr = arr;
	//定义一个指向指针数组的指针
	printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
	printf("%d, %d, %d\n", **(parr + 0), **(parr + 1), **(parr + 2));

	//指针数组还可以和字符串数组结合使用，请看下面的例子：

	char *str[3] = {
		"c.biancheng.net",
		"C语言中文网",
		"C Language"
	};
	printf("%s\n%s\n%s\n", str[0], str[1], str[2]);

	//为了便于理解，可以将上面的字符串数组改成下面的形式，它们都是等价的。
	char *str0 = "c.biancheng.net";
	char *str1 = "C语言中文网";
	char *str2 = "C Language";
	char *strR[3] = { str0, str1, str2 };
	printf("%s\n%s\n%s\n", strR[0], strR[1], strR[2]);
}

// 字符数组 int数组排序
int pointerArraySort(int *array, int size)
{
	int tmp;
	int i = 0, j = 0;
	if (array == NULL)
	{
		return -1;
	}
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void pointerArrayPrint(int *array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}


//字符数组 char[]
void pointerChar()
{
	//字符数组归根结底还是一个数组
	char str[] = "http://c.biancheng.net";
	char *pstr = str;
	int len = strlen(str), i;

	printf("%s\n", str);

	//使用*(pstr+i)
	for (i = 0; i<len; i++) {
		printf("%c", *(pstr + i));
	}
	printf("\n");

	//使用pstr[i]
	for (i = 0; i<len; i++) {
		printf("%c", pstr[i]);
	}
	printf("\n");

	//使用*(str+i)
	for (i = 0; i<len; i++) {
		printf("%c", *(str + i));
	}
	printf("\n");

}

//字符串
void pointerString()
{
	/*除了字符数组，C语言还支持另外一种表示字符串的方法，就是直接使用一个指针指向字符串，例如：

	字符串中的所有字符在内存中是连续排列的，
	str 指向的是字符串的第 0 个字符；
	我们通常将第 0  个字符的地址称为字符串的首地址。
	字符串中每个字符的类型都是char，所以 str 的类型也必须是char *。
	*/

	/*
	char *str;
	str = "http://c.biancheng.net";

	//我们将这种形式的字符串称为字符串常量,字符串是双引号
	*/ 

	//等价于
	char *str = "http://c.biancheng.net2";

	//int *p = 200;error 不能初始化 

	int len = strlen(str), i;

	//直接输出
	printf("%s\n", str);

	for (i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	for (i = 0; i < len; i++)
	{
		printf("%c", *(str+i));
	}
	printf("\n");

	/*
	字符数组与字符串的区别：

	它们最根本的区别是在内存中的存储区域不一样，字符数组存储在全局数据区或栈区，第二种形式的字符串存储在常量区。
	全局数据区和栈区的字符串（也包括其他数据）  有读取和写入的权限，
	而常量区的字符串（也包括其他数据）只有读取权限， 没有写入权限。我们将第二种形式的字符串称为字符串常量
	*/

	{
		char *str2 = "Hello World!"; //常量区
		str2 = "I love C!";  //正确
		//str2[3] = 'P';  //错误 只能读 不能写入
		printf("%s\n", str2);

		char str3[] = "http://c.biancheng.net";//全局数据区或栈区
		str3[3] = 's';
		printf("%s\n", str3); //htts://c.biancheng.net

	}
}

void main8111()
{
	//pointerBase();
	//pointerChar();
	//pointerString();

	//pointerArray();

	int myarray[] = { 11,34,44,33,22,2,3,6,9 };
	int size = sizeof(myarray) / sizeof(*myarray);
	pointerArraySort(myarray, size);
	pointerArrayPrint(myarray, size);

	cout << "hello..." << endl;

	system("pause");
	return;
}

/*---------------------------------------------指针函数 - 函数指针-------------------------------------------------------------*/

//指针函数: C语言允许函数的返回值是一个指针（地址），我们将这样的函数称为指针函数 
char *strlong(char *str1, char *str2)
{
	if (strlen(str1) > strlen(str2))
	{
		return str1;
	}
	else
	{
		return str2;
	}
}


//返回两个数中较大的一个
int max(int a, int b)
{
	return a>b ? a : b;
}

//指针变量做为函数参数
void swap(int *p1, int *p2)
{
	int temp;//临时变量
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}

int pointerMax2(int *a, int *b)
{
	return *a >*b ? *a : *b;
}

int main82() {
	char str1[30] = "abcefg";
	char str2[30] = "xyz1";

	char *str;

	//指针函数
	str = strlong(str1, str2);
	/*
		char *str
		str="abcdefg"	
	*/

	printf("Longer string: %s\n", str);


	int a = 100, b = 200;
	int x = 10, y = 30;

	//swap 指针变量做为函数参数
	printf("a:%d, b:%d\n", a, b);
	swap(&a,&b);

	printf("a:%d, b:%d\n", a, b);

	int zz = pointerMax2(&x, &y);
	printf("x:%d, y:%d, zz:%d\n", x, y, zz);

	//函数指针  定义形式  returnType (*pointerName)(param list);
	/*
		returnType 为函数返回值类型，
		pointerNmae 为指针名称，
		param list 为函数参数列表。
		参数列表中可以同时给出参数的类型和名称，也可以只给出参数的类型，省略参数的名称，这一点和函数原型非常类似。
	*/
	

	int (*pointerMax)(int a, int b) = max;
	int z = (*pointerMax)(x, y);
	printf("x:%d, y:%d, z:%d\n", x,y,z);



	system("pause");
	return 0;
}


/*---------------------------------------------cosnt and pointer-------------------------------------------------------------*/
//const
int getNum() {
	return 100;
}

void constBae()
{

	int n = 90;
	const int MaxNum1 = getNum();  //运行时初始化
	const int MaxNum2 = n;  //运行时初始化
	const int MaxNum3 = 80;  //编译时初始化

	//MaxNum2 = 200;错误 创建后就不能再修改了
	printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);
}

void constAndPointer()
{
	int a = 10, b = 20;

	const int *p1;
	int const *p2;
	int * const p3 = &a; //c++中必须要初始化

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

	/*
	记忆方法
	const 离变量名近就是用来 修饰 指针变量
	离 变量名 远 就是用来 修饰 指针指向的数据
	如果 近的和远的 都有，那么就 同时 修饰 指针变量 以及它 指向的数据
	*/

}

void constAndPointerParameter()
{
	/*
	在C语言中，单独定义 const 变量没有明显的优势，完全可以使用#define命令代替。
	const 通常用在函数形参中，如果形参是一个指针，为了防止在函数内部修改指针指向的数据，就可以用 const 来限制。

	在C语言标准库中，有很多函数的形参都被 const 限制了，下面是部分函数的原型：
	size_t strlen(const char * str);
	int strcmp(const char * str1, const char * str2);
	char * strcat(char * destination, const char * source);
	char * strcpy(char * destination, const char * source);
	int system(const char* command);
	int puts(const char * str);
	int printf(const char * format, ...);

	*/
	
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

//const 和非 const 类型转换
/*
也就是说，const char *和char *是不同的类型，不能将const char *类型的数据赋值给char *类型的变量。
但反过来是可以的，编译器允许将char *类型的数据赋值给const char *类型的变量。

这种限制很容易理解，char *指向的数据有读取和写入权限，
而const char *指向的数据只有读取权限，降低数据的权限不会带来任何问题，但提升数据的权限就有可能发生危险。
*/

void func(char *str) { }
int main8122()
{
	constBae();

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


	system("pause");
	return 0;
}