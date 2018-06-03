#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//C����ַ���
void cstyleChar() {
	char str[30] = "calc";

	// '\0' ASCII�� 0
	printf("%x \n", str);  //��ӡ�ַ���������׵�ַ �ַ����ڴ�����ASCII�� 
	// 0x0033FD24   +99  +97 +108  +99   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0   +0  -52  -52  calc..........................??
	printf("%s\n", str);   // calc

	char strArr[4] = { 'c', 'a', 'l', 'c' };				 //���ܴ�ӡ û��'\0'��β��������%s��ӡ
	char strArr1[] = { 'c', 'a', 'l', 'c' };				 // ͬ��

	char strArr2[5] = { 'c', 'a', 'l', 'c', '\0' };  //��ȷ��ӡ����'\0'��β
	char strArr3[5] = { 'c', 'a', 'l', 'c' };				 //��ȷ��ӡ������Զ���0�����Ϊ0���ַ�����'\0' 


	// %sֻ������'\0���Ż������û������һֱ����ǰ

	printf("%s \n", strArr);	// calc��������calc
	printf("%s \n", strArr1); // calc��������calc

	printf("%s \n", strArr2); // calc
	printf("%s \n", strArr3); // calc
}


//�ڴ��еĴ�С
void testsizeof() {
	//������main������ϵ�
	char str[10] = "AB";
	printf("sizeof(str) = %d\n", sizeof(str));	// 10
	printf("strlen(AB) = %d\n", strlen("AB"));  // 2

	//�ڴ��ַ���Զ�����8��0  AB........
	printf("%x\n", str); //0x004EFE38   +65  +66   +0   +0   +0   +0   +0   +0   +0   +0  -52  -52  -52  -52  -52  -52  AB........??????

}


//�ַ��������ַ���ָ���ӡ
void printString() {
	char str[10] = "ABCDEF";

	//forѭ��
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
	//whle + ָ�벽��
	while (*strP != '\0') {
		printf("str[%d] = [%c]\n", strP, *strP);
		strP++; //����+1
	}

	printf("---------------------------------\n");
	

	char *strP2 = "ABCDEF";
	/*
		һ��ҪŪ�����ָ����� ��ָ�����ָ����ڴ�ռ���������
		strP  -> ָ�����
		*strP -> ָ�����ָ����ڿմ�ռ�
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

// ��ʼ�� �����ʾ
void initChar() {
	//�ַ�����ʼ��
	char c = { "calc" }; // �Ƚ�������
	char c2 = "calc";
	

	time_t ts; //����ʱ��
	srand((unsigned int)time(&ts)); //ȡʱ����������
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

// ��ʼ�� ָ��NULL����
void initCharPoint() {
	char *strP = NULL;	// p1Ĭ�ϵ�ַ��0x00000000 �ܲ���ϵͳ����	
	// strP ָ�����
	// *strP ָ�����ָ����ڴ�ռ�����

	// *strP = "AAAA"; //��ָ�����ָ����ڴ�ռ�д������ strPĬ�ϵ�ַ��0x00000000 �ܲ���ϵͳ����	
	// strcpy(strP, "AAAA");	
	
	
	strP = (char *)malloc(100); //��ȷ�ķ�ʽ���ȿ��ٿռ�
 // *strP = "AAAA";						//�������������  strP:���������������������������������������������������������������������������������������������������������z�j?
  strcpy(strP, "AAAA");				// strP:AAAA
	printf("strP:%s\n", strP);  // strP:AAAA
}

void main()
{
	
	printString();
	// initChar();
	//initCharPoint();

	char c;         // 1���ֽ�
	char *name;     // 4���ֽ�

	printf("sizeof(c)=%d\n",		sizeof(c));
	printf("sizeof(name)=%d\n", sizeof(name));

	system("pause");
	return;
}

