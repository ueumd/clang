#include<stdio.h>
#include<stdlib.h>

int num = 10;//��̬��
						 //��̬����ջ������̬������򹲴�������̬������������main����
						 //ջ�����������գ������ͷ�

void test()
{
	int  data = 3;//ջ��
	printf("%p,%p\n", &num, &data);
	num = 101;
	data = 34;
	printf("\n");

}

int main() {
	system("pause");
	return 0;
}