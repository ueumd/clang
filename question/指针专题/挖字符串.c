#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//"abcdef,accd,eeee,aaa,ssss"; �ָ�ɶ�ά����
int spitString(const char *buf1, char c, char buf2[10][30], int *count) {
	/*strcpy(buf2[0], "aaaa");
	strcpy(buf2[1], "bbbb");
	*count = 2;*/

	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	//1 ��ʼ��
	p = buf1;
	pTmp = buf1;

	do {
		p = strchr(p, c); //2 ��������������λ�� p���� �γɲ�ֵ ���ַ���
		if (p != NULL) {
			if (p - pTmp > 0) {
				strncpy(buf2[tmpcount], pTmp, p - pTmp);
				buf2[tmpcount][p - pTmp] = '\0';//�ѵ�һ�����ݱ��C����ַ���
				tmpcount++;

				//3 ���� ��p��ptm�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else {
			break;
		}
	} while (*p != '\0');
	*count = tmpcount;
	return 0;
}

void main�ָ�ɶ�ά����()
{
	int ret = 0, i = 0;
	char *p1 = "abcdef,accd,eeee,aaa,ssss";
	char cTem = ',';
	int nCount;
	char myArray[10][30];

	ret = spitString(p1, cTem, myArray, &nCount);
	if (ret != 0) {
		printf("fucn spitString() err:%d\n", ret);
	}
	for (i = 0; i < nCount; i++) {
		printf("%s \n", myArray[i]);
	}

	system("pause");
	return 0;
}
/*
 �ڴ���ڱ����ú�����ִ��
*/
int spitString2(const char *buf1, char c, char **myp/*in*/, int *count) {
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	//1 ��ʼ��
	p = buf1;
	pTmp = buf1;

	do {
		p = strchr(p, c); //2 ��������������λ�� p���� �γɲ�ֵ ���ַ���
		if (p != NULL) {
			if (p - pTmp > 0) {
				strncpy(myp[tmpcount], pTmp, p - pTmp);
				myp[tmpcount][p - pTmp] = '\0';//�ѵ�һ�����ݱ��C����ַ���
				tmpcount++;

				//3 ���� ��p��ptm�ﵽ��һ�μ���������
				pTmp = p = p + 1;
			}
		}
		else {
			break;
		}
	} while (*p != '\0');

	*count = tmpcount;
	return 0;
}

void main()
{
	int ret = 0, i = 0;
	char *p1 = "abcdef,accd,eeee,aaa,ssss";
	char cTem = ',';
	int nCount;

	// char myArray[10][30];
	char **p = NULL; //�������������ڴ� char myArray[10][30];
	p = (char **)malloc(10 * sizeof(char *)); // һά char * array[10]

	if (p == NULL) {
		return;
	}
	for (i = 0; i < 10; i++) {
		p[i] = (char *)malloc(30 * sizeof(char)); //�ٶ�ά
	}


	ret = spitString2(p1, cTem, p, &nCount);
	if (ret != 0) {
		printf("fucn spitString() err:%d\n", ret);
	}
	for (i = 0; i < nCount; i++) {
		printf("%s \n", p[i]);
	}
	// �ͷ��ڴ�
	for (i = 0; i < nCount; i++) {
		free(p[i]);
	}
	free(p);

	system("pause");
	return 0;
}