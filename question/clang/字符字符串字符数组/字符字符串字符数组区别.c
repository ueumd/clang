#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void teststring()
{
	int  i = 0;
	char *p = NULL;
	char buf[100] = "ABCDE";
	printf("%p\n", buf);
	/*
	0x0041F708  41  A
	0x0041F709  42  B
	0x0041F70A  43  C
	0x0041F70B  44  D
	0x0041F70C  45  E
	0x0041F70D  00  .
	*/
	// 数组下标形式
	for (i = 0; i < strlen(buf); i++) {
		//printf("buf[%d]=%d\n", i, buf[i]);
		/*
		buf[0]=65
		buf[1]=66
		buf[2]=67
		buf[3]=68
		buf[4]=69
		*/
		printf("buf[%d]=%c\n", i, buf[i]);
		/*
		buf[0]=A
		buf[1]=B
		buf[2]=C
		buf[3]=D
		buf[4]=E
		*/
	}

	// 指针
	p = buf; // buf代表数组首元素的地址
	for (i = 0; i < strlen(buf); i++) {
		printf("buf[%d]=%c\n", i, *p++); // 这里是步长+1
																		 /*
																		 buf[0]=A
																		 buf[1]=B
																		 buf[2]=C
																		 buf[3]=D
																		 buf[4]=E
																		 */
	}

	// [] *的推导过程
	// buf[i] ===>buf[0+i] ===> *(buf+i)
}

int main字符字符串字符数组区别() {
	//整形数组 sizeof
	int intArr[10] = { 0 };

	//字符数组 sizeof
	char charArr[] = { 'A','B','C','D' };

	//字符串数组 strlen
	char strArr[7] = "ABCDEF"; 		//因为有'\0' 7不是6  推荐 char strArr[] = "ABCDEF"; 

																//字符串常量 strlen
	char *pStr = "ABCDEF";

	strArr[1] = 'H';
	printf("%s\n", strArr);   //AHCDEF

														// pStr[1] = 'H'; 只能读，不能改写
	pStr = "HELLO";					//指针变量指向新的内容
	printf("%s\n", pStr);   //HELLO

	int len = sizeof(intArr) / sizeof(int);
	printf("intArr = %d\n", len);               //10
	printf("charArr = %d\n", sizeof(charArr));	//4
	printf("strArr = %ld\n", strlen(strArr));		//6
	printf("pStr = %ld\n", strlen(pStr));				//6

	getchar();
	return 0;
}

