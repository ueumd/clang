#include <stdio.h>
#include <stdbool.h>

/**

����ˮ�ɻ���
ˮ�ɻ����ֳư�ķ˹��������
��λ��ˮ�ɻ�������4����153��370��371��407��
��λ����Ҷõ��������3����1634��8208��9474��
��λ�������������3����54748��92727��93084��
��λ��������ֻ��1����548834��
��λ�ı�������������4����1741725��4210818��9800817��9926315��
��λ�İ��ɻ�������3����24678050��24678051��88593477

��1000���ڵ�ˮ�ɻ���

ˮ�ɻ�: 153=1^3+5^3+3^

���ݷ����㷨˼�룺
��λ��153 % 10		= 3
ʮλ��153 / 10 % 10	= 5
��λ��153 / 100		= 1
*/

int cube(int n) {
	return n*n*n;
}

// �ݹ鷽ʽ
void digui(int n) {
	if (n == 999) { //��������
		return;
	}

	int ones = n % 10;
	int tens = n / 10 % 10;
	int hundreds = n / 100;

	if (ones*ones*ones + tens*tens*tens + hundreds*hundreds*hundreds == n) {
		printf("%d^3 + %d^3 + %d^3 = %d\n", ones, tens, hundreds, n);
	}
	digui(n+1);

}

int main1() {

	int i = 100;
#if 0
	for (; i < 1000; i++) {
		int ones = i % 10;
		int tens = i / 10 % 10;
		int hundreds = i / 100;

		if (cube(ones) + cube(tens) + cube(hundreds) == i) {
			printf("%d^3 + %d^3 + %d^3 = %d\n", ones, tens, hundreds, i);
		}
	}
	while (i<1000)
	{
		int ones = i % 10;
		int tens = i / 10 % 10;
		int hundreds = i / 100;

		if (cube(ones) + cube(tens) + cube(hundreds) == i) {
			printf("%d^3 + %d^3 + %d^3 = %d\n", ones, tens, hundreds, i);
		}
		i++;
	}

	do {
		int ones = i % 10;
		int tens = i / 10 % 10;
		int hundreds = i / 100;

		if (cube(ones) + cube(tens) + cube(hundreds) == i) {
			printf("%d^3 + %d^3 + %d^3 = %d\n", ones, tens, hundreds, i);
		}
		i++;
	} 
	while (i < 1000);
#endif

	digui(i);

	system("pause");
	return 0;
}