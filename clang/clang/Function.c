#include<stdio.h>
#include<stdlib.h>



//省略类型默认为int
sum(int x,int y,int c) //形参 定义时要指明参数类型和参数名称
{
	int a = x + y;
	return a;
}
//递归
int factorial(int num)
{
	/*
	问题：计算n！
	数学上的计算公式为：n！=n×(n-1)×(n-2)……2×1

	以递归的方式计算4！

	F(4)=4×F(3)　　　　　　　　　　  递归阶段
	　　　　F(3)=3×F(2)
		　　　　 F(2)=2×F(1)

				 　　F(1)=1　　     终止条件

				F(2)=(2)×(1)　　　  回归阶段
			F(3)=(3)×(2)
	F(4)=(4)×(6)
	24　　　　　　　　　　　　　　　　递归完成
	*/

	long result;

	if (num == 0 || num == 1) {
		result = 1;
	}
	else {
		result = num * factorial(num - 1);  //4!=4x3x2x1=24
	}

	return result;
}

int mainfunction()
{
	//printf("%d\n", sum(1, 5, 0));//实参 实参和形参的类型、数目要一致！！！
	printf("3!:\t%d", factorial(4));
	system("pause");
	return 0;
}