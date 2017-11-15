#include<stdio.h>
#include<stdlib.h>
//http://tool.oschina.net/commons?type=4  常用对照表

void testNum() {
	
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


	// 字符串  puts 函数和通用的 printf 对应的格式控制符是%s。
	// 在C语言中，字符串总是以'\0'作为串的结束符。
	char web_url[] = "http://c.biancheng.net";
	char *web_name = "C语言中文网";

	puts(web_url);
	puts(web_name);
	printf("%s\n", web_url);
	printf("%s\n", web_name);
}

void compare() {
	char ch1 = 'Z';
	char ch2 = '9';

	if (ch1 > '9') { // 比较的是ASCII值 90>57
		printf("ch1=%d \t ch1=%c\n", ch1, ch1); // 90 Z
		printf("ch2=%d \t ch2=%c\n", ch2, ch2); // 57 9
	}
	else {
		printf("ch2=%d \t ch2=%c\n", ch2, ch2);
		printf("ch1=%d \t ch1=%c\n", ch1, ch1);
	}
}

/**
	字符串数字转换整数
*/
int toNum(char *str) {
	int lastres = 0;   //12345  1  12  123 1234 12345
	int num = 0;
	char *backupStr = str; // 保留幅本


	while (*str != '\0')
	{
		if ((*str) < '\0' && (*str) > '9') {
			return -1;
		}
		//printf("%p \t %c\n", *str);//取出每一个字符
		*str++;
		num++;
	}

	for (int i = 0; i < num; i++) {
		lastres *= 10;
		int wei = backupStr[i] - 48;
		lastres += wei;
		printf("wei=%d\n", wei);//打印字符转换为整数的位
	}

	return lastres;
}

int main() {
	//testNum();
	compare();

	char num[] = "1234567";
	//printf("%p\n", num);

	/* char num[] = "1234567" 内存存储
	内存地址			ASCII	 字符
	0x004DF810		+49		 1
	0x004DF811		+50		 2
	0x004DF812		+51		 3
	0x004DF813		+52		 4
	0x004DF814		+53		 5
	0x004DF815		+54		 6
	0x004DF816		+55		 7
	0x004DF817		 +0		 .
	*/
	int res = toNum(num);
	printf("res = %d\n", res);


	system("pause");
	return 0;
}
