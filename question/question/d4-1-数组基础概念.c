#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*


*/

void based41()
{
	int a[] = { 1,2 };
	int b[100] = { 1,3 };
	int c[200] = { 0 };//����ʱ ���Ѿ�ȷ�����е�ֵΪ��

	memset(c, 0, sizeof(c));//��ʾ�� �����ڴ��
							//��һά���飺
							//c  ��������Ԫ�صĵ�ַ c+1 ���� 4���ֳ�
							//&c ����������ĵ�ַ &c+1 ���� 200*4
	return;
}

//��ô�����int a[10]�����������ͣ� int []
//���ͱ��ʣ��̶���С�ڴ��ı���
void typedefarr() 
{
	typedef int(MyArrayType)[5]; //������һ���������� �������������
	MyArrayType myArray; //int myArray[5]
	int i = 0;

	for (i = 0; i < 5; i++)
	{
	
		myArray[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d", myArray[i]);
	}

	printf("\n myArray: %d, myArray+1:%d\n", myArray, myArray + 1);

	return;
}
//ͨ���������Ͷ�������ָ��
void arrpointer()
{

	//ָ�� ����
	char *myArray[] = { "1111","2222","333333333" };

	//����ָ�� ��һ��ָ��ָ������
	typedef int(MyArrayType)[5]; //������һ���������� �������������
	MyArrayType myArray3; //int myArray[5]
	int i = 0;

	MyArrayType *pArray;//����һ��ָ����� ���ָ����� ָ��һ������
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		int myArray2[5];

		pArray = &myArray2;//�൱�ڶ���ָ��

		for (i = 0; i < 5; i++)
		{
			//myArray2[i] = i + 1;
			(*pArray)[i] = i + 1;
		}

		for (i = 0; i < 5; i++)
		{
			printf("\n%d", (*pArray)[i]);
		}

		
	}
}

//��������ָ������ĵڶ��ַ���
void arrpointer2()
{
	//��������һ������ָ������
	typedef int(*PArrayType)[5];

	PArrayType pArray; //���߱��������ҷ���һ��ָ�����

	int c[5];

	int i = 0;

	pArray = &c;

	for (i = 0; i < 5; i++)
	{

		(*pArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d", (*pArray)[i]);
	}

	return;
}

//��������ָ������ĵ����ַ���
//ǰ���ַ�������ͨ�����Ͷ������ �Ƚ��鷳
void arrpointer3()
{
	int(*pMyArray)[5]; //ֱ�Ӷ���һ��ָ������� ����ָ�����

	int c[5];

	int i = 0;

	pMyArray = &c;

	for (i = 0; i < 5; i++)
	{

		(*pMyArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d", (*pMyArray)[i]);
	}

	return;
}

void maind41()
{
	
	based41();
	//typedefarr();

	//arrpointer();

	//arrpointer2();
	arrpointer3();
	
	system("pause");
	return 0;
}