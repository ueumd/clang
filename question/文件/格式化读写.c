#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
用 fprintf() 和 fscanf() 函数读写配置文件、日志文件会非常方便，不但程序能够识别，用户也可以看懂，可以手动修改。
*/
void fscanfAndFprintf() {
#define N 2
	struct stu {
		char name[10];
		int num;
		int age;
		float score;
	} boya[N], boyb[N], *pa, *pb;
	FILE *fp;
	int i;
	pa = boya;
	pb = boyb;
	if ((fp = fopen("D:\\demo.txt", "wt+")) == NULL) {
		printf("Cannot open file, press any key exit!");
		getch();
		exit(1);
	}
	//从键盘读入数据，保存到boya
	printf("Input data:\n");
	for (i = 0; i<N; i++, pa++) {
		scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
	}
	pa = boya;
	//将boya中的数据写入到文件
	for (i = 0; i<N; i++, pa++) {
		fprintf(fp, "%s %d %d %f\n", pa->name, pa->num, pa->age, pa->score);
	}
	//重置文件指针
	rewind(fp);
	//从文件中读取数据，保存到boyb
	for (i = 0; i<N; i++, pb++) {
		fscanf(fp, "%s %d %d %f\n", pb->name, &pb->num, &pb->age, &pb->score);
	}
	pb = boyb;
	//将boyb中的数据输出到显示器
	for (i = 0; i<N; i++, pb++) {
		printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
	}
	fclose(fp);
}

/*
如果将 fp 设置为 
stdin，那么 fscanf() 函数将会从键盘读取数据，与 scanf 的作用相同；
stdout，那么 fprintf() 函数将会向显示器输出内容，与 printf 的作用相同。例如：
*/
void fscanfAndFprintf2() {
	int a, b, sum;
	fprintf(stdout, "Input tow numbers: ");
	fscanf(stdin, "%d %d", &a, &b);
	sum = a + b;
	fprintf(stdout, "sum=%d\n", sum);
}

void main格式化读写() {
	//fscanfAndFprintf();
	fscanfAndFprintf2();
	system("pause");
}