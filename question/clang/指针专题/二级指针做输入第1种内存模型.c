#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printfMyArray()
{

	//���� �����е�ÿһԪ����ָ�� ָ������
	char *myArray[] = { "aaaa","cccc","bbbb","1111111111" };
	char *tmp = NULL;
	int i = 0, j = 0;
	int num = 0;

	num = sizeof(myArray) / sizeof(myArray[0]);

	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

	//����
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				tmp = myArray[i];//������������Ԫ�� ָ���ֵ
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	printf("�����\n");
	for (i = 0; i < num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));
	}

}

void printfMyArray1(char **myArray, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s \n", *(myArray + i));
	}
}

void sortMyArray1(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp = NULL;

	//����
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j])>0)
			{
				tmp = myArray[i];  //������������Ԫ�� ��������ָ���ֵ �ȸı�ָ��ָ�� ���ͼ 
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void main111()
{
	//printfMyArray();

	//���� �����е�ÿһԪ����ָ�� ָ������
	char *myArray[] = { "aaaa","cccc","bbbb","1111111111" };
	char *tmp = NULL;
	int i = 0, j = 0;
	int num = 0;

	num = sizeof(myArray) / sizeof(myArray[0]);

	printfMyArray1(myArray, num);

	sortMyArray1(myArray, num);

	printf("�����\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", *(myArray + i));
	}

	system("pause");
	return 0;
}