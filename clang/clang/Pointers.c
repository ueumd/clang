#include<stdio.h>
#include<stdlib.h>

int pointerTest()
{
	int a = 7;
	int *p = &a;

	printf("a memory address:%p\n", &a);//  //0x003bfbe0
	//p = 10;//�����԰�һ������ֱֵ�Ӹ�ֵ��ָ�����
	*p = 9;

	printf("�޸ĺ�a��ֵ��%d\n", a);
	return 0;
}

//����������
int swap(char v1,char v2)
{
	printf("����ǰ��v1=%d, v2=%d\n", v1, v2);
	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
	printf("������v1=%d, v2=%d\n", v1, v2);
	return 0;
}

int swapPointer(char *v1,char *v2)
{
	printf("����ǰ��v1=%d, v2=%d\n", *v1, *v2);
	char temp; //�����ڴ����ڿ���һ����ַ
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
	printf("������v1=%d, v2=%d\n", *v1, *v2);
	return 0;
}

int studyPointer()
{
	
	int b = NULL;
	int *p = NULL;//��ָ�벻ָ���κα���

	int i = 10;
	int *p3;//��һ��ָ��int���͵�ָ����� �ڴ��ַ Ұָ�룬��֪��ָ��ʲô�ڴ�
	
	//p3=100;�����԰�һ������ֱֵ�Ӹ�ֵ��ָ�����
	p3 = &i;//p3ָ��i���ڴ��ַ

	int a = *p3;//aָ��p3���ڴ��ַ

	*p3 = 100;//��p3ָ����ڴ������ֵ��ֵΪ100 ��ô i=100;

	printf("%x\n", p3);
	printf("i=%d\n", i);  //i=100
	printf("p3=%d\n", *p3);//p3=100
	printf("a=%d\n", a);  //a=10
	return 0;
}

//����ָ�������

//����������
int triplePointer(int *pointerNumber);
int triplePointer(int *pointerNumber)
{
	/*
		pointerNumber ��ַ
		*pointerNumber ָ��ָ���ֵ
		pointerNumber=&pointerNum
	*/
	*pointerNumber = *pointerNumber * 3;
	return 0;
}

int triplePointer2(int *pointerNumber)
{
	*pointerNumber = *pointerNumber * 3;
	return 0;
}
/*
���Ǹ�������Ĳ�����һ���������������ظ���������ֵ��Сʱ���ͷ�������
���磺
��������30��������0Сʱ30����
��������60��������1Сʱ0����
��������90��������1Сʱ30����
*/
int transformMinutes(int *hours,int *minutes)
{
	*hours = *minutes / 60;
	*minutes = *minutes % 60; //����ȡ��
	return 0;
}

int mainpointer()
{
	int pointerNum = 10;
	int pointerNum2 = 10;
	int *p = &pointerNum2;
	//pointerTest();
	char v1 = 10, v2 = 90;
	//swap(v1, v2);
	//swapPointer(&v1,&v2);
	//studyPointer();
	//arrPointer();
	//triplePointer(&pointerNum); //����Ҫ����pointerNum�ĵ�ַ
	//triplePointer2(p); //p�����pointerNum2�ڴ��ַ
	//printf("*pointerNum =%d\n", pointerNum); //30
	//printf("*pointerNum2 =%d\n", pointerNum2); //30


	int hours = 0, minutes = 90;

	/* ��һ�����Ǵ�����hours��minutes�ĵ�ַ */
	transformMinutes(&hours, &minutes);

	// ��һ�Σ���ֵ��������Ը�ı���
	printf("%d Сʱ : %d ����\n", hours, minutes);

	system("pause");
	return 0;
}