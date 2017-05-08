#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void arrfn()
{
	int arr[] = { 99, 15, 100, 888, 252 };
	int len = sizeof(arr) / sizeof(int); //sizeof(arr) 会获得整个数组所占用的字节数
	int i = 0;
	for (i;i < len;i++) {
		printf("%d ,", *(arr + i));//99, 15, 100, 888, 252  arr是数组首个地址
		/*
		arr 是数组名，指向数组的第 0 个元素，表示数组首地址， arr+i 指向数组的第 i 个元素，
		*(arr+i)等价于 arr[i]。
		*/
	}
}

void stringArr()
{
	//这是字符数组赋初值的方法
	char cArr[] = { 'Q','U','A','N','X','U','E' };
	//这是字符串赋初值的方法
	char sArr[] = "quanxue";

	//用sizeof()求长度
	printf("cArr的长度=%d\n", sizeof(cArr));   //长度为7
	printf("sArr的长度=%d\n", sizeof(sArr));   //长度为8，最后一位是NULL

											//用printf的%s打印内容
//	printf("cArr的内容=%s\n", cArr);   //不能正确显示
	printf("sArr的内容=%s\n", sArr);   //可以正确显示

									//用strlen()求长度
	//printf("cArr的长度=%d\n", strlen(cArr));   //不正确的结果
	printf("sArr的长度=%d\n", strlen(sArr));   //NULL不在计算范围

	/*
	char sArr[] = "quanxue";这种方式，编译时会自动在末尾增加一个NULL字符。
	NULL字符也就是'\0'，在ASCII表中排在第一个，用16进制表示为0x00。
	sizeof()运算符求的是字符数组的长度，而不是字符串长度。
	strlen()函数求的是字符串长度，而不是字符数组。它不适用于字符串以外的类型。
	char sArr[] = "quanxue";也可以写成char sArr[8] = "quanxue";（注意：是8而不是7）
	*/
}

void stringfn()
{
	char str[] = "http://c.biancheng.net";
	int i = 0;
	int len = strlen(str);
	char *p = str; //str是字符串首个地址

	//直接输出
	printf("%s\n", str);
	//遍历输出
	for (i = 0;i < len;i++) {
		printf("%c", str[i]);
	}
	
	printf("\n");
	//指针方式
	for (i = 0;i < len;i++) {
		printf("%c", *(p+i));
	}
	printf("\n");
	for (i = 0;i < len;i++) {
		printf("%c", *(str + i));
	}
	
}

//除了字符数组，C语言还支持另外一种表示字符串的方法，就是直接使用一个指针指向字符串
void stringPointer()
{
	/*
		char cArr[] = { 'Q','U','A','N','X','U','E' };    //这是字符数组赋初值的方法

	    char sArr[] = "quanxue";						  //这是字符串赋初值的方法                 栈区
		char *str = "http://c.biancheng.net";             //指针指向字符串 字符串另一种定义方式     str在栈区 值在常量区 只有读取权限，没有写入权限

		char *str;
		str = "http://c.biancheng.net";
		字符串中的所有字符在内存中是连续排列的，str 指向的是字符串的第 0 个字符；
		我们通常将第 0 个字符的地址称为字符串的首地址。
		字符串中每个字符的类型都是char，所以 str 的类型也必须是char *。
	*/
	
	char *str = "http://c.biancheng.net";
	int len = strlen(str), i;

	printf("%s\n", str);

	//使用*(str+i)
	for (i = 0; i<len; i++) {
		printf("%c", *(str + i));
	}

}

//字符串的定义方式
void defineString()
{
	char cArr[] = { 'Q','U','A','N','X','U','E' };   //这是字符数组赋初值的方法

	char sArr[] = "quanxue";					 //这是字符串赋初值的方法  栈区   
	
	char *str = "http://c.biancheng.net";         //指针指向字符串  字符串常量     str在栈区 值在常量区 只有读取权限，没有写入权限
	char *pstr = NULL;

	int a = 300;
	int *pint = NULL;

	str = "A"; //str 指向了常量区 ABCDEF的地址

	printf("%s\n", str); //ABCDEF
	printf("%d\n", a); //100

	pstr = str;
	printf("%s\n", pstr);//A
	printf(" str:%p\n", str); //:010E8CD8
	printf("pstr:%p\n", pstr);//:010E8CD8

	

	//pint = a;
	//printf("%d\n", pint);//300  这样定义 地址是的不一样的
	

	pint = &a;
	printf("%d\n", *pint);//300

	printf("   a:%p\n", &a);    //0x003bfbe0
	printf("pint:%p\n", pint);  //0x003bfbe0
}
void main()
{
	//arrfn();
	//stringfn();
	//stringArr();
	//stringPointer();
	defineString();
	printf("\n");
	system("pause");
}