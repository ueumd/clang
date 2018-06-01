#include<stdio.h>
#define MAX 10

void testArr() {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		if (i == 0 || i == 4) {
			arr[i] = i+1;
		}
	}

	for (int j = 0; j < sizeof(arr) / sizeof(int); j++) {
		printf("%4d", arr[j]); //   1   0   0   0   5 中间自动补0
	}
	printf("\n");
}
/*
请输入要打印的行数：10
10行杨辉三角如下：
									 1
								1     1
							1     2     1
						1     3     3     1
					1     4     6     4     1
				1     5    10    10     5     1
			1     6    15    20    15     6     1
		1     7    21    35    35    21     7     1
	1     8    28    56    70    56    28     8     1
1     9    36    84   126   126    84    36     9     1

*/
int main() {
	//testArr();

	int i, j, k, n = MAX;
	int arr[MAX][MAX] = { 0 };

	for (i = 0; i < n; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	// 计算剩余单元格（中间是0的）
	for (i = 2; i < n; i++) {
		for (j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
		
	// 打印三角形
	//for (i = 0; i < n; i++) {
	//	for (j = 0; j <= i; j++) {
	//		printf("%5d", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	for (i = 0; i < n; i++) {
		for (k = 0; k < n - i; k++) {
			printf("  ");  /*这一行主要是在输出数之前打上空格占位，让输出的数更美观*/
		}

		for (j = 0; j <= i; j++) /*j<=i的原因是不输出其它的数，只输出我们想要的数*/
		{
			printf("%4d", arr[i][j]); 
		}
		printf("\n");  /*当一行输出完以后换行继续下一行的输出*/
	}
	system("pause");
	return 0;
}
