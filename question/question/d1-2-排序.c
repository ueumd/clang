#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int i = 0, j = 0;
	int a[10] = { 3, 1, 44, 2, 3, 44, 5, 5,6, 67 };
	int tmp = 0;

	for (i = 0; i < 10; i++) {//外层循环 行

		for (j = i + 1; j < 10; j++) { // 内层循环

			if (a[i] > a[j]) { //如果小就交互换位置
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ,", a[i]);
	}

	system("pause");
	return 0;

}


int arraySort(int a[],int num) {
	int i = 0, j = 0;
	int tmp = 0; 
	
	for (i = 0; i < num; i++) {//外层循环 行

		for (j = i + 1; j < num; j++) { // 内层循环

			if (a[i] > a[j]) { //如果小就交互换位置
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ,", a[i]);
	}

	return 0;
}

int arraySort2(int *a,int num) {
	int i = 0, j = 0;
	int tmp = 0;

	int num2 = 0;
	num2 = sizeof(a) / sizeof(*a);
	printf("%d,%d,%d\n", sizeof(a), sizeof(*a),num2);//4 4 1

	/*
	为什么num2会是1

	数组做函数参数的退回问题 退回为一个指针
	1 结论：正确的做法应是把数组的内存首地址和数组的有效长度传给被调用函数

	结论2
	为什么是1 实参的 a和形参a 的数据类型本质不一样
	形参的数组，编译器会把它当成指针处理 这是C语言的特色

	结论3：
	形参写在函数上（int *a）和写在函数内是一样的，只不过写在函数上是具有对外的属性而已
	*/

	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) { 
			if (a[i] > a[j]) { 
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ,", a[i]);
	}

	return 0;
}

int mainsort()
{
	int a[10] = { 3, 1, 44, 2, 3, 44, 5, 5,6, 67 };
	
	
	int num = 0;
	num = sizeof(a) / sizeof(a[0]);
	printf("num=%d\ta=%d\ta[0]=%d\n", num,sizeof(a),sizeof(a[0])); //num=10  a=40    a[0]=4
	
	 //arraySort(a, num);
	arraySort2(a,num);

	system("pause");
	return 0;

}
