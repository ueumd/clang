#include "iostream"

using namespace std;
/*
����һ����������
int a[10]

����һ��ָ����������

����һ��ָ�� �������͵�ָ�� �������ָ��
*/

void maind812()
{

	/*
	a�������������Ԫ�ص�ַ 
	&a�������������ַ
	a+1 ������ 4�� &a+1 �����ǣ�40
	*/
	int a[10];

	{
		//����һ���������� 
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n", myArray[0]);
	}
	{
		//����һ��ָ����������(�鷳)
		typedef int (*PTypeArray)[10]; //int *p=NULL
		PTypeArray myPArray;//sizeof(int)*10
		myPArray = &a;
		(*myPArray)[0] = 400;
		printf("a[0]:%d\n", a[0]);

		//����������

		int b = 10;
		int *p = NULL;
		p = &b;
		*p = 200;
		printf("b:%d\n", b);
	}

	{
		//����һ��ָ�� �������͵�ָ�� �������ָ��

		int(*MyPointer)[10];// ���� ����C������ ���ҷ����ڴ� ���� 	typedef int (*PTypeArray)[10];PTypeArray myPArray; 

		MyPointer = &a;
		(*MyPointer)[0] = 1000;
		printf("a[0]:%d\n", a[0]);

	}

	cout << "hello..." << endl;

	system("pause");
	return;
}

/*
����ָ������﷨֪������
1 ��ζ���һ�� ��������
2 ��ζ���һ�� ����ָ������
3 ��ζ���һ�� ����ָ�� ��ָ��һ��������ڵ�ַ��
*/

int add(int a, int b)
{
	printf("func add...\n");
	return a + b;
}
void main()
{

	add(1, 2);//ֱ�ӵ��� ���������Ǻ��������

	//��ζ���һ�� ��������
	{
		typedef int (MyFuncType)(int a, int b); //����һ������

		MyFuncType *myPointerFunc = NULL;//������һ��ָ�룬ָ��ĳһ����ĺ���

		myPointerFunc = &add;
		myPointerFunc(3, 4); //��ӵ���

		myPointerFunc = add; //��ȡ��ַ ������ʷ�汾
		myPointerFunc(3, 4); //��ӵ���
	}

	//��ζ���һ�� ����ָ������
	{
		typedef int(*MyPointerFuncType)(int a, int b); // int *a=NULL;
		MyPointerFuncType myPointerFunc; //����һ��ָ��
		myPointerFunc = add;
		myPointerFunc(5, 6);
	}

	//��ζ���һ�� ����ָ��
	{
		int(*MyPointerFunc)(int a, int b);//������һ������
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}

	cout << "hello..." << endl;

	system("pause");
	return;
}