#include<stdio.h>
#include<stdlib.h>

void main��������()
{
	int a;	
	int b;
	int *p;							//�ڴ��з���ռ�

	//ֱ�Ӹ�ֵ
	a = 10;                         // cpu����ִ��

	printf("&a:%d\n", &a);//&a:3210316
	printf("a:%d\n", a); //a:10

	//��ֱ��ֵ - ֱ��ͨ���ڴ�(���������ƺ�)
	*((int *)&a) = 200; //ָ�����Դ
	printf("a:%d\n", a); //a:200

	 //��ֱ��ֵ- ͨ��ָ��
	{
		p = &a;
		*p = 300;
		printf("a:%d\n", a); //a:300
	}
	
	system("pause");

}