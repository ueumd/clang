#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
https://www.cnblogs.com/melons/p/5791874.html
����ԭ�ͣ�
size_t   fread(   void   *buffer,   size_t   size,   size_t   count,   FILE   *stream   )
buffer   �Ƕ�ȡ�����ݴ�ŵ��ڴ��ָ�루���������飬Ҳ�������¿��ٵĿռ䣬buffer����һ��������
size       ��ÿ�ζ�ȡ���ֽ���
count     �Ƕ�ȡ����
strean   ��Ҫ��ȡ���ļ���ָ��
����   ���ļ�fp���ȡ100���ֽ�   �����������

fread(buffer,100,1,fp)
fread(buffer,50,2,fp)
fread(buffer,1,100,fp)
**************************************************************************************
�Զ����Ķ��������ǲ�����strlen()����sizeof()���䳤�Ⱥʹ�С�ġ�
**************************************************************************************
*/
int copyFile(char *fileRead, char *fileWrite);

void maincopyfile() {
	char fileRead[100];
	char fileWrite[100];

	printf("Ҫ���Ƶ��ļ�:");
	scanf("%s", fileRead);

	printf("���ļ����Ƶ�:");
	scanf("%s", fileWrite);

	if (copyFile(fileRead, fileWrite)) {
		printf("��ϲ�㣬�ļ����Ƴɹ���\n");
	}
	else {
		printf("�ļ�����ʧ��");
	}

	/*
	Ҫ���Ƶ��ļ���d://1.mp4
	���ļ����Ƶ���d://2.mp4
	��ϲ�㣬�ļ����Ƴɹ���
	*/

	system("pause");

}

int copyFile(char *fileRead, char *fileWrite) {
	FILE *fpRead;
	FILE *fpWrite;

	int buferlen = 1024 * 4; // ����������

	char *buffer = (char *)malloc(buferlen);// ���ٻ���

	int readCount;// ʵ�ʶ�ȡ���ֽ���

	if ((fpRead = fopen(fileRead, "rb")) == NULL || (fpWrite = fopen(fileWrite, "wb")) == NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
		exit(1);
	}
	// ���ϴ�fileRead��ȡ���ݣ����ڻ��������ٽ�������������д��fileWrite
	while ((readCount = fread(buffer, 1, buferlen, fpRead)) > 0) {
		fwrite(buffer, readCount, 1, fpWrite);
	}

	free(buffer);
	fclose(fpRead);
	fclose(fpWrite);
	
	return 1;

}