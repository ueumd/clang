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
	for (表达式1; 表达式2; 表达式3) {
	语句块
	}
	它的运行过程为：
	1) 先执行“表达式1”。

	2) 再执行“表达式2”，如果它的值为真（非0），则执行循环体，否则结束循环。

	3) 执行完循环体后再执行“表达式3”。

	4) 重复执行步骤 2) 和 3)，直到“表达式2”的值为假，就结束循环。
	*/
	int i = 4; //如果初始化时5 什么都不打印
	int j = 5;
	for (i/*表达式1*/; i < j/*表达式2*/; i++/*表达式3*/) // 
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
	while(表达式){
	语句块
	}

	先计算“表达式”的值，当值为真（非0）时， 执行“语句块”；
	执行完“语句块”，再次计算表达式的值，如果为真，继续执行“语句块”……

	这个过程会一直重复，直到表达式的值为假（0），就退出循环，执行 while 后面的代码。

	我们通常将
	“表达式”称为循环条件，
	“语句块”称为循环体，
	整个循环的过程就是不停判断循环条件、并执行循环体代码的过程。
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

	printf("%d的叠乘值为 %d \n", n, sum);
}

int dowhile()
{
	/*
	do{
	语句块
	}while(表达式);
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