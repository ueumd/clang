#include<stdio.h>
#include<stdlib.h>

int pointerTest()
{
	int a = 7;
	int *p = &a;

	printf("a memory address:%p\n", &a);//  //0x003bfbe0

	*p = 9;

	printf("修改后，a的值：%d\n", a);
}

//笨方法交换
int swap(char v1,char v2)
{
	printf("更换前：v1=%d, v2=%d\n", v1, v2);
	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
	printf("更换后：v1=%d, v2=%d\n", v1, v2);
	return 0;
}

int swapPointer(char *v1,char *v2)
{
	printf("更换前：v1=%d, v2=%d\n", *v1, *v2);
	char temp; //会在内存中在开辟一个地址
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
	printf("更换后：v1=%d, v2=%d\n", *v1, *v2);
}

int main()
{
	//pointerTest();
	char v1 = 10, v2 = 90;
	//swap(v1, v2);
	swapPointer(&v1,&v2);
	system("pause");
	return 0;
}