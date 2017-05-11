#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void findStr2DoWhile()
{
	// ���ַ���p�� abcd���ֵĴ���
	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	int ncount = 0;
	do
	{	/*
		strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
		����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
		*/
		p = strstr(p, "abcd");
		if (p != NULL) 
		{
			ncount++;
			p = p + strlen("abcd");
		}
		else
		{
			break;
		}
	} while (*p != "\0");
	printf("ncound:%d\n", ncount);

}

void findStr2While()
{
	// ���ַ���p�� abcd���ֵĴ���
	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	int ncount = 0;
	while (p = strstr(p, "abcd"))
	{
		ncount++;
		p = p + strlen("abcd");
		if (*p == '\0')
		{
			break;
		}
	}
	printf("ncound:%d\n", ncount);//4

}

//�Ƽ�
int findStr2Pointer(char *mystr, char *sub, int *count)
{
	char *p = mystr;
	int ret = 0;
	int tmpcount = 0;

	if (mystr == NULL || sub == NULL || count == NULL)
	{
		ret = -1;
		printf("func findStr2Pointer() err:%d\n",ret);
		return ret;
	}
	
	do
	{	/*
		strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
		����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
		*/
		p = strstr(p, sub);
		if (p != NULL)
		{
			tmpcount++;
			p = p + strlen(sub);
		}
		else
		{
			break;
		}
	} while (*p != "\0");
	//��Ӹ�ֵ��ָ����ڵ��������
	*count = tmpcount;
	return ret;
}

void main()
{
	//findStr2();
	//findStr2While();

	char *p = "123cabcdXYZabcdYUKabcd456789qqabcd";
	char sub[] = "abcd";
	int count = 0;
	int ret = 0;
	ret=findStr2Pointer(p,sub,&count);
	if (ret != 0) {
		printf("func findStr2Pointer() err:%d", ret);
		return ret;
	}
	printf("count:%d\n", count);
	system("pause");
	return;
}