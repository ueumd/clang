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

//����ָ��
int arrPointer()
{
	int array[10] = { 6 };//array[0]=6;
	int *p = &array[0];
	int *p3 = array;

	printf("%p,  %p\n", array, &array[0]);
	//pintf("*p=%d\n", *p);
	//getchar();

	return 0;
}

int main()
{
	//pointerTest();
	char v1 = 10, v2 = 90;
	//swap(v1, v2);
	//swapPointer(&v1,&v2);
	studyPointer();
	//arrPointer();
	system("pause");
	return 0;
}