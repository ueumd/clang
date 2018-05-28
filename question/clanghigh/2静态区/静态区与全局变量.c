#include<stdio.h>
#include<stdlib.h>

int num = 10;//静态区
						 //静态区与栈区，静态区与程序共存亡，静态区分配优先于main函数
						 //栈区，反复回收，反复释放

void test()
{
	int  data = 3;//栈区
	printf("%p,%p\n", &num, &data);
	num = 101;
	data = 34;
	printf("\n");

}

int main() {
	system("pause");
	return 0;
}