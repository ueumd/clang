#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printfArr1(int a[3][5])
{
	int i, j, tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	return;
}

void printfArr2(int a[][5])
{
	int i, j, tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	return;
}

//��ά��������������������
void printfArr3(int(*b)[5])
{
	int i, j, tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", b[i][j]);
		}
	}

	return;
}

void main��������ı���()
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
	printf("\n-------------------\n");
	printfArr3(a);
	printf("\n-------------------\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ,", a[i][j]);
		}
	}

	printf("\na:%d , a+1:%d\n ", a, a + 1);//a+1�Ĳ�����20���ֽ� 5*4
	printf("&a:%d , &a+1:%d\n ", &a, &a + 1);

	{
		//����һ��ָ�������ָ�����
		int(*pArray)[5];//���߱����� ����4���ֵ��ڴ� 32bitƽ̨��
		pArray = a;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				printf("%d,", pArray[i][j]);
			}
		}
	}
	/*
	��ά����ı��� ����ָ�� ������ һά�ĳ���

	 (a)    �����ǵ�0�е�������ַ ����һ�еĵ�ַ �� ��һ����Ԫ�صĵ�ַ���ص��ġ�������
	 (a+i)  �����ǵ�i�е��׵�ַ 2��ָ��
	*(a+i)  ���� 1��ָ�� ��i�е���Ԫ�صĵ�ַ
	*/

	/*
	ת�����ݣ�

	*( *(a+i) + j) ===>a[i][j]     Ԫ�ص�ֵ
	a[i][j] <===> *(*(a+i)+j)
	a[i] ===> a[0+i] ===>*(a+i)    0��ռλ��
	a[i][j]===a[0+i][j] ==> *(a+i)[j] ===>*(a+i)[0+j] ===>* ( *(a+i) + j)

	**/

	system("pause");
	return;
}