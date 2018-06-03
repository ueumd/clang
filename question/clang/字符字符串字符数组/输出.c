#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//C风格字符串
void cstyleChar() {
	char str[30] = "calc";

	// '\0' ASCII码 0
	printf("%x \n", str);  //打印字符串数组的首地址 字符在内存中以ASCII码 
	// 0x0033FD24   +99  +97 +108  +99   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0  -52  -52  calc..........................??
	printf("%s\n", str);   // calc

	char strArr[4] = { 'c', 'a', 'l', 'c' };				 //不能打印 没有'\0'结尾，不能用%s打印
	char strArr1[] = { 'c', 'a', 'l', 'c' };				 // 同上

	char strArr2[5] = { 'c', 'a', 'l', 'c', '\0' };  //正确打印，有'\0'结尾
	char strArr3[5] = { 'c', 'a', 'l', 'c' };				 //正确打印后面会自动补0，编号为0的字符就是'\0' 


	// %s只有遇到'\0’才会结束，没有遇到一直会往前

	printf("%s \n", strArr);	// calc烫烫烫烫calc
	printf("%s \n", strArr1); // calc烫烫烫烫calc

	printf("%s \n", strArr2); // calc
	printf("%s \n", strArr3); // calc
}


//内存中的大小
void testsizeof() {
	//拷贝到main函数打断点
	char str[10] = "AB";
	printf("sizeof(str) = %d\n", sizeof(str));	// 10
	printf("strlen(AB) = %d\n", strlen("AB"));  // 2

	//内存地址中自动补了8个0  AB........
	printf("%x\n", str); //0x004EFE38   +65  +66   +0   +0   +0   +0   +0   +0   +0   +0  -52  -52  -52  -52  -52  -52  AB........??????

}


//字符数组与字符串指针打印
void printString() {
	char str[10] = "ABCDEF";

	//for循环
	for (int i = 0; i < 10; i++) {
		printf("str[%d] = [%c]\n", i, str[i]);
	}
	/*
	str[0] = [A]
	str[1] = [B]
	str[2] = [C]
	str[3] = [D]
	str[4] = [E]
	str[5] = [F]
	str[6] = []
	str[7] = []
	str[8] = []
	str[9] = []
	*/


	printf("---------------------------------\n");

	char *strP = "ABCDEF";
	//whle + 指针步长
	while (*strP != '\0') {
		printf("str[%d] = [%c]\n", strP, *strP);
		strP++; //步长+1
	}

	printf("---------------------------------\n");
	

	char *strP2 = "ABCDEF";
	/*
		一定要弄清楚：指针变量 和指针变量指向的内存空间是两回事
		strP  -> 指针变量
		*strP -> 指针变量指向的内空存空间
	*/
	for (char *pStr = strP2; *pStr != '\0'; pStr++) {
		printf("str[%d] = [%c]\n", pStr, *pStr);
	}

	/*
	str[3636044] = [A]
	str[3636045] = [B]
	str[3636046] = [C]
	str[3636047] = [D]
	str[3636048] = [E]
	str[3636049] = [F]
	*/
}

// 初始化 随机显示
void initChar() {
	//字符串初始化
	char c = { "calc" }; // 等介于下面
	char c2 = "calc";
	

	time_t ts; //保存时间
	srand((unsigned int)time(&ts)); //取时间的随机种子
	int num = rand() % 10;
	printf("num = %d\n", num);

	char str[10][10] = {
		{"calc"},
		{"notepad"},
		{"write"},
		{"tasklist"},
		{"ipconfig"},
		{"color 4f"},
		{"mspaint"},
		{"mstsc"},
		{"msconfig"},
		{"C:\\" },
	};
	system(str[num]);
}

// 初始化 指针NULL问题
void initCharPoint() {
	char *strP = NULL;	// p1默认地址是0x00000000 受操作系统保护	
	// strP 指针变量
	// *strP 指针变量指向的内存空间数据

	// *strP = "AAAA"; //向指针变量指向的内存空间写入数据 strP默认地址是0x00000000 受操作系统保护	
	// strcpy(strP, "AAAA");	
	
	
	strP = (char *)malloc(100); //正确的方式，先开辟空间
 // *strP = "AAAA";						//奇怪这样是乱码  strP:斖屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯屯竮簀?
  strcpy(strP, "AAAA");				// strP:AAAA
	printf("strP:%s\n", strP);  // strP:AAAA
}

void main()
{
	
	printString();
	// initChar();
	//initCharPoint();

	char c;         // 1个字节
	char *name;     // 4个字节

	printf("sizeof(c)=%d\n",		sizeof(c));
	printf("sizeof(name)=%d\n", sizeof(name));

	system("pause");
	return;
}

