#include<stdio.h>
#include<stdlib.h>
//http://tool.oschina.net/commons?type=4  ���ö��ձ�

void testNum() {
	
	/**
	�ַ� putchar  printf ��Ӧ�ĸ�ʽ���Ʒ���%c��
	*/
	int one = 1;
	char first = '1';
	char code = 'A';
	char b = 70;
	int c = 71;
	//char x = '��';  //char ���Ͳ��ܰ��� ASCII ����֮����ַ�
	putchar(one);
	putchar(first);
	putchar("\n");

	printf("%d\t %c\n", one, one);		// 1  	SOH %dASCII��ֵ1 %c ASCII������ַ�SOH  

	printf("%d\t %c\n", first, first);	// 49	1 %dASCII��ֵ49 %c ASCII������ַ�1 

	printf("%d\t %c\n", code, code);	// 65   A  %dASCII��ֵ65 %c ASCII������ַ�A   
	printf("%d\t %c\n", b, b);			// 70   F  %dASCII��ֵ65 %c ASCII������ַ�A   
	printf("%d\t %c\n", c, c);			// 71   G  %dASCII��ֵ65 %c ASCII������ַ�A   


	// �ַ���  puts ������ͨ�õ� printf ��Ӧ�ĸ�ʽ���Ʒ���%s��
	// ��C�����У��ַ���������'\0'��Ϊ���Ľ�������
	char web_url[] = "http://c.biancheng.net";
	char *web_name = "C����������";

	puts(web_url);
	puts(web_name);
	printf("%s\n", web_url);
	printf("%s\n", web_name);
}

void compare() {
	char ch1 = 'Z';
	char ch2 = '9';

	if (ch1 > '9') { // �Ƚϵ���ASCIIֵ 90>57
		printf("ch1=%d \t ch1=%c\n", ch1, ch1); // 90 Z
		printf("ch2=%d \t ch2=%c\n", ch2, ch2); // 57 9
	}
	else {
		printf("ch2=%d \t ch2=%c\n", ch2, ch2);
		printf("ch1=%d \t ch1=%c\n", ch1, ch1);
	}
}

/**
	�ַ�������ת������
*/
int toNum(char *str) {
	int lastres = 0;   //12345  1  12  123 1234 12345
	int num = 0;
	char *backupStr = str; // ��������


	while (*str != '\0')
	{
		if ((*str) < '\0' && (*str) > '9') {
			return -1;
		}
		//printf("%p \t %c\n", *str);//ȡ��ÿһ���ַ�
		*str++;
		num++;
	}

	for (int i = 0; i < num; i++) {
		lastres *= 10;
		int wei = backupStr[i] - 48;
		lastres += wei;
		printf("wei=%d\n", wei);//��ӡ�ַ�ת��Ϊ������λ
	}

	return lastres;
}

int main() {
	//testNum();
	compare();

	char num[] = "1234567";
	//printf("%p\n", num);

	/* char num[] = "1234567" �ڴ�洢
	�ڴ��ַ			ASCII	 �ַ�
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
