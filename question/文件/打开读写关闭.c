#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
//һ��ֻ��д�ļ��е�һ���ַ� stdio.h
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
	//while ((code = fgetc(fpr))!=EOF)  //EOF = -1  ������һ���ո�
	while((code=fgetc(fpr)) && !feof(fpr)) //��ȷ���ж��ļ���ȡ�Ƿ����
	{
		printf("%3c", code);
	}

	//fclose(fpw);
	fclose(fpr);

	return 0;
}

//һ�ζ�дһ���ַ�(�ı�����)
void fgetsAndFputs() {
	FILE *fp = fopen("E:\\coding\\clang\\txt\\lines2.txt", "w+");
	if (NULL == fp) {
		printf("fopen error\n");
		return -1;
	}

	printf("%d\n", fputs("abcdefg\n", fp));
	printf("%d\n", fputs("123456789\n", fp));

	char buf[] = "xyz";
	printf("%d\n", fputs(buf, fp));


	rewind(fp);

	char buf2[1024];
	fgets(buf2, 4, fp);
	printf("%s", buf2);

	fclose(fp);
	return 0;
}


#if 0
fgets(buf, len, fp) ����len-1���ַ�����;����'\n'(�ᱻ��ȡ)����EOF�������ζ�ȡ�� ��ȡ�������Զ�׷��'\0'
#endif

void main�򿪶�д�ر�()
{
	// fgetCAndFputc();

	fgetsAndFputs();
	system("pause");
	return;
}