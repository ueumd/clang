#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 �ȼ۹�ϵ

 �������                        ��Ч��ָ�����

 һά���� char a[30]             ָ�� char*
 ָ������ char *a[30]			ָ���ָ�� char **a
 �������� char a[10][30]			�����ָ�� char(*a)[30]
 
 ***/
void printfArrayd43(int *array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ",array[i]);
	}
	return;
}

void maind43()
{
	int a[3][5];
	int i = 0, j = 0, tmp = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}
	
	//�Ѷ�ά���� ���� 1ά���� ����ӡ ֤�����Դ洢
	printfArrayd43((int *)a, 15);
	system("pause");
	return;
}