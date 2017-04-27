#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define RADIUS 100  // 宏定义 常量


int main常()
{
	defineconst();
	varibale();
	operator();
	system("pause");
	
	return 0;
}

int defineconst()
{
	const int RADIUS2 = 100; //const 定义常量

	printf("%d\n", RADIUS);


	printf("%d\n", RADIUS2);

	// RADIUS2 = 200;const常量是不能修改的
}

/*
type variable_list
type variable_list=value

变量定义要注意以下几方面：
	1. 变量定义必须有一数据类型。
	2. 变量定义时可以赋初值，也可以不赋初值。
	3. 几个变量可以同时定义。
	4. 不同类型的变量赋值时，小类型的变量可以直接赋给大的，大类型的变量赋给小类型的变量时必须强制转换

变量声明
	1、一种是需要建立存储空间的。例如：int a 在声明的时候就已经建立了存储空间。
	2、另一种是不需要建立存储空间的，通过使用extern关键字声明变量名而不定义它。 
	例如：extern int a 其中变量 a 可以在别的文件中定义的。
	除非有extern关键字，否则都是变量的定义。
*/
extern int a, b;
extern int c;
extern float f;
int varibale()
{
	/* 变量定义 */
	int a, b;
	int c;
	float f;

	int rmb = 1000000000;

	/* 初始化 */
	a = 10;
	b = 20;

	c = a + b;
	printf("value of c : %d \n", c);

	f = 70.0 / 3.0;
	printf("value of f : %f \n", f);

	printf("rmb=%d\n", rmb);
	return 0;
	
}

int operator()
{
	int rmb = 100;
	rmb++; //rmb=rmb+1 rmb+=1
	printf("rmb=%d\n",rmb); //101

	int rmb2 = 100;
	++rmb2;
	printf("rmb=%d\n", rmb2);//101

	//上面结果是一样的
	int a = 10, b = 20;

	int a2 = a++; //a++先计算表达式的值的再++ a2=a ;a++
	int b2= ++b;  //++b先++再计算表达的值	  b=b+1; b2=b;

	printf("a2=%d\n", a2); //10
	printf("b2=%d\n", b2); //21

	int i = 5;
	int i2 = i++ + ++i;  //i2=5 i++=6 ++i=7   5+7=12
	printf("i2=%d\n", i2); //12
	printf("i=%d\n", i);//7

	//逗号表达式先求逗号左边的值，然后再求右边的值，整个语句的值是逗号右边的值
	int h = 1, l = 2, j = 3, k = 4;
	int h2 = (h + l, j + k); //7

	int h3 = (h = j, h + k);//7 h=3 k=4
	printf("h2=%d\n", h2);
	printf("h3=%d\n", h3);

	//运算符的优先级Precedence
	/*
	C99还提供了一个头文件 <stdbool.h> 定义了bool代表_Bool
	true代表1，false代表
	*/
	bool isTrue = 100 == 100; //先算100==100

	printf("isTrue=%d\n", isTrue);//1

	double f = (double)3 / 2; //(double)3 先将整数强制转换为double型 再除以2 
	printf("f=%f\n", f);//1.500000
	return 0;
}

int 