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

void arrpointer()
{

	//ָ�� ����
	char *myArray[] = { "1111","2222","333333333" };

	//����ָ�� ��һ��ָ��ָ������
	typedef int(MyArrayType)[5]; //������һ���������� �������������
	MyArrayType myArray; //int myArray[5]
	int i = 0;

	MyArrayType *pArray;//����һ��ָ����� ���ָ����� ָ��һ������
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		int myArray2[5];
		for (i = 0; i < 5;i++)
		pArray = &myArray;
	}
}

void main()
{
	
	based41();
	typedefarr();

	
	system("pause");
	return 0;
}