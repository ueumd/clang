#include<stdio.h>
#include<stdlib.h>

int pointerTest()
{
	int a = 7;
	int *p = &a;

	printf("a memory address:%p\n", &a);//  //0x003bfbe0

	*p = 9;

	printf("�޸ĺ�a��ֵ��%d\n", a);
}

//����������
int swap(char v1,char v2)
{
	printf("����ǰ��v1=%d, v2=%d\n", v1, v2);
	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
	printf("������v1=%d, v2=%d\n", v1, v2);
	return 0;
}

int swapPointer(char *v1,char *v2)
{
	printf("����ǰ��v1=%d, v2=%d\n", *v1, *v2);
	char temp; //�����ڴ����ڿ���һ����ַ
	temp = *v1;
	*v1 = *v2;
	*v2 = temp;
	printf("������v1=%d, v2=%d\n", *v1, *v2);
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