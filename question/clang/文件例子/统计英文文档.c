#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mainͳ��Ӣ���ĵ�() {
	char path[100] ="E:\\coding\\clang\\question\\�ļ�����\\1.txt";
	FILE *pf;

	pf = fopen(path, "r"); //ֻ��

	if (NULL == pf) {
		printf("���ļ�ʧ��");
	} else {
		char ch;
		int numA = 0;
		int numa = 0;
		int num0 = 0;
		int numn = 0;
		int numo = 0;
		int numk = 0;

		while ((ch=getc(pf))!=EOF)
		{
			if (ch >= 'A' && ch <= 'Z') {
				numA++;
			}
			else if (ch >= 'a' && ch <= 'z') {
				numa++;
			}
			else if (ch >= '0' && ch <= '9') {
				num0++;
			}
			else if (ch == ' ') {
				numk++;
			}
			else if (ch == '\n') {
				numn++;
			}
			else {
				numo++;
			}
		}
		
		printf("��д��ĸ��%d,Сд��ĸ��%d, ���֣�%d, �ո�%d, ���з���%d,�����ַ���%d", numA, numa, num0, numk, numn, numo);
		fclose(pf);
	}

	system("pause");
}
