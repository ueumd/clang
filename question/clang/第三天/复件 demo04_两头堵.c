#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//char *p = "       abcd11111abcd2222abcdqqqqq       "; 

//main---��ͷ


void main41()
{
	int count = 0;
	int i = 0, j = 0;

	char *p = "   abcd       ";
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j-i +1;
	
	printf("count:%d", count);

	system("pause");
}

//һ��ָ�������ģ��
//û���ڴ�飬����ָ�밡������
int trimSpace_�ܲ�ok������(char *mybuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j-i +1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(mybuf, mybuf+i, count);
	mybuf[count] = '\0';
	return 0;
	//system("pause");
}

//һ������²�Ҫ�޸�������ڴ���ֵ
int trimSpace_ok(char *mybuf, char *outbuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) -1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j-i +1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(outbuf, mybuf+i, count);
	outbuf[count] = '\0';
	return 0;
	//system("pause");
}


void main()
{
	int ret = 0;
	char *p = NULL;
	char buf2[100];

	//�����ַ��������ڴ������ַ�ʽ�������ڶѡ�ջ��ȫ������������������Ҫ֪������ڴ�����ô�����

	char *buf = "       abcd11111abcd2222abcdqqqqq       ";	
	//char buf[] = "       abcd11111abcd2222abcdqqqqq       ";
	/*
	ret = trimSpace(buf);
	if (ret != 0)
	{
		printf("func trimSpace() err:%d\n", ret);
		return ;
	}
	*/

	ret = trimSpace_ok(buf, buf2);
	if (ret != 0)
	{
		printf("func trimSpace() err:%d\n", ret);
		return ;
	}
	printf("buf2:%s \n", buf2);
	system("pause");

}