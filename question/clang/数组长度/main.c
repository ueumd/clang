#include<stdio.h>
#include<stdlib.h>

#define DIM(a) (sizeof(a)/sizeof(*a))
#if 0
int a[10] = {0}
sizeof(a)				���������Ĵ洢�ֽ�����10 * 4 = 40���ⲻ����⡣
*a              �൱��a[0]�������һ��Ԫ�أ�*a+1 �ڶ�Ԫ��
sizeof(*a)       ���൱��sizeof(a[0]) = 4��
sizeof(a) / sizeof(*(a)) = 40/4=10�����൱�ڼ��������ڳ�Ա������
#endif
int main() {

	// ����Լ������ '\0' NULL 0
	char* str[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};


	printf("%d\n", DIM(str)); //5

	getchar();
	return 0;
}
