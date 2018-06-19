#include<string.h>
#include<stdio.h>
/*
�������ͻ����﷨֪ʶ������
1 ����һ����������
2 ����һ��ָ����������
3 ����һ��ָ�� �������͵�ָ�� �������ָ��
*/

void test1() {
	int a[10]; //a ����������Ԫ�ص�ַ &a�������������ַ

	{
		//����һ����������
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("myArray[0]=%d \n", myArray[0]);
	}

	{
		// ����һ��ָ���������� �൱�ڶ���ָ��
		typedef int(*PTypeArray)[10]; // int *p
		PTypeArray myPArray; //sizeof(int)*10
		myPArray = &a;

		(*myPArray)[0] = 20;
		printf("a[0]=%d\n", a[0]);

		//��������
		int b = 10;
		int *p = NULL;
		p = &b;
	}

	{
		// ����һ��ָ�� �������͵�ָ�� �������ָ��
		int(*MyPointer)[10]; //���� ����C������ ���ҷ����ڴ�
		MyPointer = &a;
		(*MyPointer)[0] = 40;
		printf("a[0]=%d\n", a[0]);
	}
}

/*
����ָ������﷨����
1 ��ζ���һ����������
2 ��ζ���һ������ָ������
3 ��ζ��� ����ָ�루ָ��һ����������ڵ�ַ��
*/

int add(int a, int b) {
	printf("func add ... \n");
	return a + b;
}


void test2() {
	add(1, 2);

	{
		// ����һ����������
		typedef int (MyFuncType)(int a, int b); //����һ�����ͣ�������������
		MyFuncType *myPointerFunc = NULL; //������һ��ָ�� ָ��ĳһ����ĺ���

		myPointerFunc = &add;
		myPointerFunc(3, 4); //��ӵ���
	}

	{
		//����һ������ָ������
		typedef int(*MyPointerFuncType) (int a, int b);
		MyPointerFuncType myPointer;
		myPointer = add;
		myPointer(5, 6);
	}

	{
		//ֱ�Ӻ���ָ��
		int(*MyPointerFunc)(int a, int b);
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}
	
}

void main1() {
	//test1();
	test2();

	system("pause");
}