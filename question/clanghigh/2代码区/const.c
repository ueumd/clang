#include<stdio.h>
#include<stdlib.h>

#define N 10   //CPU������10 . 1010 ����ȡ��ַ��
//const��α�������޶�������������ֱ���޸�
int main() {
	const int num = 100;
	const int *pnum = &num;//����ָ��ָ��const int 
	int *pnum2 = (int *)pnum;

	*pnum2 = 200;

	printf("%d", num); // 200
	system("pause");
	return 0;
}