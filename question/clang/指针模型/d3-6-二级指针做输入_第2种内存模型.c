#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void maind361()
{
	char myBuf[30];
	char myArray[10][30] = { "aaaa", "cccc", "bbbb", "1111111111" };

	char tmpBuf[30];

	int i = 0, j = 0;
	int num = 4;

	//printf
	for (i = 0;i < num;i++)
	{
		printf("%s\n", myArray[i]);
	}

	//sort
	for (i = 0;i < num;i++)
	{
		for (j = i + 1;j < num;j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				strcpy(tmpBuf, myArray[i]);//���������ڴ��
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}

	//sort
	for (i = 0;i < num;i++)
	{
		printf("%s\n", myArray[i]);
	}

	system("pause");
	return 0;
}

/*
����ı�����:myArray+1 �͵�һ�ֵ�myArray+1 �ڴ�ģ�Ͳ�һ��
Ҳ����ָ��Ĳ�����һ�� ָ����ָ����ڴ�ռ�����ݲ�һ��
printfMyArrayd36()�в�ͨ
*/

void printfMyArrayd360(char **myArray, int num)
{
	int i = 0;
	for (i = 0;i < num;i++)
	{
		printf("%s \n", *(myArray + i));
	}
}

void sortMyArrayd360(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp = NULL;

	//����
	for (i = 0;i < num;i++)
	{
		for (j = i;j < num;j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				tmp = myArray[i];//������������Ԫ�� ��������ָ���ֵ �ȸı�ָ��ָ�� ���ͼ 
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}


}

//������
void printfMyArrayd36(char myArray[10][30], int num)
{
	int i = 0;
	for (i = 0;i < num;i++)
	{
		printf("%s \n", *(myArray + i));
	}
}
void sortMyArrayd36(char myArray[10][30], int num)
{
	int i = 0, j = 0;
	char tmpBuf[30];

	//����
	for (i = 0;i < num;i++)
	{
		for (j = i + 1;j < num;j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				strcpy(tmpBuf, myArray[i]);//���������ڴ��
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}


}

void maind36()
{
	char myBuf[30];
	char myArray[10][30]= { "aaaa", "cccc", "bbbb", "1111111111" };

	char tmpBuf[30];

	int i = 0, j = 0;
	int num = 4;
	/*
		������ֻ�������10�� ÿ��30��
	*/
	{
		int len1 = sizeof(myArray);//300
		int len2 = sizeof(myArray[0]);//30
		int size = len1 / len2;
		printf("len1:%d, len2:%d, size:%d \n", len1, len2, size);
	}
	printfMyArrayd36(myArray, num);
	sortMyArrayd36(myArray, num);

	//sort
	for (i = 0;i < num;i++)
	{
		printf("%s\n", myArray[i]);
	}
	system("pause");
	return 0;
}