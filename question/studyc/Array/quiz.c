#include<stdio.h>
#include<stdlib.h>
/*
	����һ��������n(1<n<=10)���������¹�ʽ����1��n*n�ķ���Ȼ������˷����������Ԫ�صĺ�
	a[i][j] = i*n+j+1; (0<=i<n, o<=j<n)

	n=3 �ԽǺ�15
	1 2 3
	4 5 6
	7 8 9
*/
#define N 10

void fangzheng() {
	int num[N][N];

	// ��ά�����ʼ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num[i][j] = N*i + j + 1;
			printf("%-5d", num[i][j]);
		}
		printf("\n");
	}

	//�Խ��ߺ�
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += num[i][i];
	}
	printf("result= %d\n", result);
}

int main() {

	fangzheng();

	system("pause");
	return 0;
}
