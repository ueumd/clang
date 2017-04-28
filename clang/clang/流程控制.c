//http://www.cnblogs.com/pharen/archive/2012/02/06/2340257.html
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void forfn()
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

void forfn2()
{
	int i, sum = 0;
	for (i = 1; i <= 100; i++) {
		sum += i;
	}
	printf("sum=%d\n", sum);//5050

}

void whilefun()
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

void dowhile()
{
	/*
	do{
		语句块
	}while(表达式);
	*/

	int i = 1, sum = 0;
	
	do {
		sum+=i;
		i++;
	} while (i <= 100);

	printf("sum=%d\n", sum); //5050
}

int threeop()
{
	int a=10, b=30;
	
	printf("max=%d\n", a > b ? a : b);//max=30
	return 0;
}

int switchcase()
{
	int a;
	printf("Please input a number:\n");
	scanf("%d", &a);

	switch (a) {
		case 1:printf("Monday\n");break;
		case 2:printf("Tuesday\n");break;
		case 3:printf("Wednesday\n");break;
		case 4:printf("Thursday\n");break;
		case 5:printf("Friday\n");break;
		case 6:printf("Saturday\n");break;
		case 7:printf("Sunday\n");break;

		//由于 default 是最后一个分支，匹配后不会再执行其他分支，所以也可以不添加break;语句。
		//default 不是必须的。当没有 default 时，如果所有 case 都匹配失败，那么就什么都不执行。
		default:printf("error\n");break; 
	}
	return 0;

}

/*
break; continue语句
break 关键字用于 while、for 循环时，会终止循环而执行整个循环语句后面的代码。
break 关键字通常和 if 语句一起使用，即满足条件时便跳出循环。

continue语句只用在 while、for 循环中，常与 if 条件语句一起使用，判断条件是否成立。
*/
int breaktest()
{
	/*
	4*4整数矩阵
	1   2   3   4
	2   4   6   8
	3   6   9   12
	4   8   12  16
	*/
	
	int i = 1, j;
	while (1) //外
	{
		j = 1;
		
		while (1)//内
		{
			printf("%-4d", i*j);
			j++;
			if (j > 4) break;
		}

		printf("\n");
		i++;
		if (i > 4) break;
	}

	return 0;
}
//乘法表
int jiujiu() {
	int i = 1, j;
	//左三角形
	for (i;i <= 9;i++) { //列
		for (j = 1;j <= i;j++) {//行
			printf("%dx%d=%2d  ",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}

int jiujiu2()
{
	int i = 1,n, j;
	for (i;i <= 9;i++) { //列
		//右三角形
		for (n = 1; n <= 9-i;n++) {
			printf("        ");
		}
		for (j = 1;j <= i;j++) {//行
			printf("%dx%d=%2d  ", i, j, i*j);
		}
		printf("\n");
	}
	return 0;
}

int continuetest()
{
	//continue语句只用在 while、for 循环中，常与 if 条件语句一起使用，判断条件是否成立。
	char c=0;
	while (c!='\n')
	{
		c = getchar();
		if (c == '4' || c == '5') {
			continue;
		}
		putchar(c); 
		/*
		input:123456789
		out:  1236789
		*/
	}

	return 0;
}

int main流程()
{
	//whilefun();
	//forfn();
	//forfn2();
	//dowhile();
	//threeop();
	//switchcase();
	//breaktest();
	//jiujiu2();

	continuetest();
	system("pause");
	return 0;
}