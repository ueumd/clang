#include<stdio.h>
#include<stdlib.h>

int arr()
{
	int i;
	int arr[7];
	char letter[] = { 'A','B', 'C', 'D', 'E' };

	for (i = 1;i < 4;i++) {
		arr[i] = (i * 1) + (i * 1);
		printf("arr[%d=%d\n", i, arr[i]);
	}

	for (i = 0;i < 5;i++) {//length?
		printf("letter[%d]=%c\n", i, letter[i]);
	}

	return 0;
}

int arrAddress(){
	int  i;
	int  iArr[7];
	int  iNum[4] = { 100, 150 };  //后两个被填上0
	char cArr[] = { 'Q','U','A','N','X','U','E' };

	printf("iNum=%p\n",iNum);

	//输出iArr数组和cArr数组的地址
	//printf("iArr=%p, cArr=%p\n\n", iArr, cArr);

	//输出iArr[i]数组和cArr[i]数组的地址
	for (i = 0; i<7; i++) {
		//printf("iArr[%d]=%p, cArr[%d]=%p\n", i, &iArr[i], i, &cArr[i]);
	}

	return 0;
}

//字符串数组
int charArr()
{
	char a[] = { 'A','B','C'};
	char cArr[] = { 'Q','U','A','N','X','U','E' };
	char letterA = 65;//A
	char str[] = "nodejs"; //字符串双引号

	//sizeof()只能求字符串数组的长度
	printf("a的长度=%d\n", sizeof(a));		   //3
	printf("cArr的长度=%d\n", sizeof(cArr));   //长度为7

	//%s
	printf("%s\n", cArr); //不能正确打印
	printf("%s\n", str);//能正确打印 输出nodejs

						//用strlen()求长度
	printf("cArr的长度=%d\n", strlen(cArr));   //不正确的结果 31
	printf("sArr的长度=%d\n", strlen(str));   //NULL不在计算范围 6

	/*
	从上面例子看来，还要注意以下几点：
		char sArr[] = "quanxue";这种方式，编译时会自动在末尾增加一个NULL字符。
		NULL字符也就是'\0'，在ASCII表中排在第一个，用16进制表示为0x00。
		sizeof()运算符求的是字符数组的长度，而不是字符串长度。
		strlen()函数求的是字符串长度，而不是字符数组。它不适用于字符串以外的类型。
		char sArr[] = "quanxue";也可以写成char sArr[8] = "quanxue";（注意：是8而不是7）
	*/

	return 0;
}

int putsgets()
{
	char code[] = { 'js', 'c' };
	
}

int arrMaxMin()
{
	int arr[5] = { 88,30,100,40,99 };
	int i = 0, max = 0, min = arr[0];
	int index = 0;

	//求最大值
	for (i; i < 5; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	//求最小值
	for (i=0; i < 5; i++) {
		if (min > arr[i]) {
			index = i;//记住下标
			min = arr[i];
		}
	}

	printf("max=%d\t min=%d\t index=%d\n", max, min, index);

	return 0;
}

int mainArr()
{
	//arr();
	//arrAddress();
	//charArr();
	arrMaxMin();
	system("pause");
	return 0;
}