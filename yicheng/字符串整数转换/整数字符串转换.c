#include<stdio.h>
#include<stdlib.h>
//http://tool.oschina.net/commons?type=4  ���ö��ձ�

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

int main1() {
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
