#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fopenAndClose() {
	FILE* fp = fopen("E:\\coding\\clang\\txt\\111.txt", "a");

	fputs("China is great!!!", fp);  // ��111.txt �ļ�׷�� China is great!!!
	int ret = fclose(fp);
	if (ret == 0) {
		printf("�رճɹ�");
	}
	else {
		printf("�ر�ʧ��");
	}
}

int fgetCAndFputc() {
	// FILE* fpw = fopen("E:\\coding\\clang\\txt\\ascii.txt", "w"); 


	for (char ch = 'a'; ch < 'z'; ch++) {
	//	printf("%3c", fputc(ch, fpw)); 	//int fputc ( int ch, FILE * stream );
	}

	printf("\n��ȡ�ļ���ʼ\n");
	FILE* fpr = fopen("E:\\coding\\clang\\txt\\ascii.txt", "r"); // r ���ļ�������ʱ ����
	if (NULL == fpr) {
		printf("�ļ�������\n");
		return -1;
	}
	//int fgetc ( FILE * stream ); int ���������ض�ȡ���ַ��������ļ�β�����ʱ��ΪEOF��

	char code;
	//while ((code = fgetc(fpr))!=EOF) 
	while((code=fgetc(fpr)) && !feof(fpr)) //��ȷ���ж��ļ���ȡ�Ƿ����
	{
		printf("%3c", code);
	}

	//fclose(fpw);
	fclose(fpr);

	return 0;
}

void fgetsAndFputs() {
	
	
}

void main()
{
	fgetCAndFputc();
	system("pause");
	return;
}