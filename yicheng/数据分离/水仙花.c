#include <stdio.h>
#include <stdbool.h>

/**

常见水仙花数
水仙花数又称阿姆斯特朗数。
三位的水仙花数共有4个：153，370，371，407；
四位的四叶玫瑰数共有3个：1634，8208，9474；
五位的五角星数共有3个：54748，92727，93084；
六位的六合数只有1个：548834；
七位的北斗七星数共有4个：1741725，4210818，9800817，9926315；
八位的八仙花数共有3个：24678050，24678051，88593477

求1000以内的水仙花数

水仙花: 153=1^3+5^3+3^

数据分离算法思想：
个位：153 % 10		= 3
十位：153 / 10 % 10	= 5
百位：153 / 100		= 1
*/

int cube(int n) {
	return n*n*n;
}

// 递归方式
void digui(int n) {
	if (n == 999) { //结束条件
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