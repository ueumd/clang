#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
fseek����;�����Ƽ�ָ��ƫ�ơ�
����ԭ�ͣ�int fseek(FILE *stream, long offset, int fromwhere)
����1���ļ���ָ��
����2��ƫ������С
����3��ƫ��ģʽ��ͨ��Ϊ1��SEEK_CUR���ļ���ǰλ�ã� SEEK_SET���ļ���ͷ�� SEEK_END���ļ���β��

����SEEK_SET,SEEK_CUR��SEEK_END������Ϊ0��1��2.
*/
long fsize(FILE *fp) {
	long n;
	fpos_t fpos;				//��ǰλ��
	fgetpos(fp, &fpos); //��ȡ��ǰλ��

	fseek(fp, 0, SEEK_END);
	n = ftell(fp); //����ȡ�ļ��ڲ�ָ�루λ��ָ�룩�����ļ���ͷ���ֽ���

	fsetpos(fp, &fpos);//�ָ�֮ǰ��λ��

	return n;
}
void main() {
	long size = 0;
	FILE *fp = NULL;
	char filename[100] = "D:\\Redis-x64-3.2.100.zip";
	if ((fp = fopen(filename, "rb")) == NULL) {
		printf("Failed to open %s...", filename);
		getch();
		exit(EXIT_SUCCESS);
	}
	printf("%ld\n", fsize(fp));
	system("pause");
}