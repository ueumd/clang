#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
��������ʱ��ctrl + z �ٻس�
*/

void main111()
{
	FILE *pf;
	char path[40] = "C:\\1.txt";
	pf = fopen(path, "w"); //����д��ģʽ��·��

	if (pf == NULL) {
		printf("�ļ���ʧ��");
	}
	else {
		char ch = getchar(); //��ȡ�ִ�����
		while (ch != EOF) {
			fputc(ch, pf); //д��һ���ַ�
			ch = getchar();
		}
		fclose(pf);
		//fclose ��һ�����������ǽ��ļ�������������д�뵽�ı�
		//�����������رգ�û�е���fclose�ļ����ݶ�ʧ ���������
	//	while (1) {}
	}
	
	system("pause");
	return;
}