#include<stdio.h>
#include<stdlib.h>
//http://tool.oschina.net/commons?type=4  常用对照表

void main() {

	printf("\n-------------------字符-------------------\n");
	/**
	字符 putchar  printf 对应的格式控制符是%c。
	*/
	int one = 1;
	char first = '1';
	char code = 'A';
	char b = 70;
	int c = 71;
	//char x = '中';  //char 类型不能包含 ASCII 编码之外的字符
	putchar(one);
	putchar(first);
	putchar("\n");

	printf("%d\t %c\n", one, one);		// 1  	SOH %dASCII码值1 %c ASCII码控制字符SOH  

	printf("%d\t %c\n", first, first);	// 49	1 %dASCII码值49 %c ASCII码控制字符1 

	printf("%d\t %c\n", code, code);	// 65   A  %dASCII码值65 %c ASCII码控制字符A   
	printf("%d\t %c\n", b, b);			// 70   F  %dASCII码值65 %c ASCII码控制字符A   
	printf("%d\t %c\n", c, c);			// 71   G  %dASCII码值65 %c ASCII码控制字符A   

	char p1, p2;
	p1 = 120;
	p2 = 121;
	printf("%c,%c\n", p1, p2);
	printf("%d,%d\n", p1, p2);



	printf("\n-------------------字符串-------------------\n");
	// 字符串  puts 函数和通用的 printf 对应的格式控制符是%s。
	// 在C语言中，字符串总是以'\0'作为串的结束符。

	char web_url[] = "http://c.biancheng.net";
	char *web_name = "C语言中文网";

	puts(web_url);							// http://c.biancheng.net
	puts(web_name);							//C语言中文网
	printf("%s\n", web_url);    // http://c.biancheng.net
	printf("%s\n", web_name);   //C语言中文网



	printf("\n-------------------字符数组-------------------\n");
	char arrCh[] = { 'A','B','1', '中' };
	for (int i = 0; i < 4; i++) {
		printf("i=%c\t", arrCh[i]); // i=A     i=B     i=1     i=?  '中'是打印不出来的 ASCII码表里不存在
	}

	system("pause");
	return 0;
}