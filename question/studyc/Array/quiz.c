#include<stdio.h>
#include<stdlib.h>
/*
	输入一个正整数n(1<n<=10)，根据以下公式生成1个n*n的方阵，然后输出此方阵对象线上元素的和
	a[i][j] = i*n+j+1; (0<=i<n, o<=j<n)

	n=3 对角和15
	1 2 3
	4 5 6
	7 8 9
*/
#define N 10

void fangzheng() {
	int num[N][N];

	// 二维数组初始化
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num[i][j] = N*i + j + 1;
			printf("%-5d", num[i][j]);
		}
		printf("\n");
	}

	//对角线和
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
