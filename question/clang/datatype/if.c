//http://www.cnblogs.com/pharen/archive/2012/02/06/2340257.html

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
	//whilefun();
	//forfn();
	//forfn2();
	//dowhile();
	threeop();
	system("pause");
	return 0;
}

int forfn()
{
	/*
	for (���ʽ1; ���ʽ2; ���ʽ3) {
	����
	}
	�������й���Ϊ��
	1) ��ִ�С����ʽ1����

	2) ��ִ�С����ʽ2�����������ֵΪ�棨��0������ִ��ѭ���壬�������ѭ����

	3) ִ����ѭ�������ִ�С����ʽ3����

	4) �ظ�ִ�в��� 2) �� 3)��ֱ�������ʽ2����ֵΪ�٣��ͽ���ѭ����
	*/
	int i = 4; //�����ʼ��ʱ5 ʲô������ӡ
	int j = 5;
	for (i/*���ʽ1*/; i < j/*���ʽ2*/; i++/*���ʽ3*/) // 
	{
		printf("i=%d\n", i); //i=4
	}
}

int forfn2()
{
	int i, sum = 0;
	for (i = 1; i <= 100; i++) {
		sum += i;
	}
	printf("sum=%d\n", sum);//5050
	return 0;
}

int whilefun()
{
	int n = 10;
	int sum = 1;
	bool flag = false;

	int num = n;

	/*
	while(���ʽ){
	����
	}

	�ȼ��㡰���ʽ����ֵ����ֵΪ�棨��0��ʱ�� ִ�С����顱��
	ִ���ꡰ���顱���ٴμ�����ʽ��ֵ�����Ϊ�棬����ִ�С����顱����

	������̻�һֱ�ظ���ֱ�����ʽ��ֵΪ�٣�0�������˳�ѭ����ִ�� while ����Ĵ��롣

	����ͨ����
	�����ʽ����Ϊѭ��������
	�����顱��Ϊѭ���壬
	����ѭ���Ĺ��̾��ǲ�ͣ�ж�ѭ����������ִ��ѭ�������Ĺ��̡�
	*/

	while (!flag)
	{
		printf("sum=%d num=%d \n", sum, num);
		sum = sum*(num--);//1 * 10 10*9 

		if (num == 1)
		{
			flag = true;
		}
	}

	printf("%d�ĵ���ֵΪ %d \n", n, sum);
}

int dowhile()
{
	/*
	do{
	����
	}while(���ʽ);
	*/

	int i = 1, sum = 0;

	do {
		sum += i;
		i++;
	} while (i <= 100);

	printf("sum=%d\n", sum); //5050
}

int threeop()
{
	int a = 10, b = 30;

	printf("max=%d\n", a > b ? a : b);//max=30
	return 0;
}