#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
fgets() 有局限性，每次最多只能从文件中读取一行内容，因为 fgets 遇到换行符就结束读取。
如果希望读取多行内容，需要使用 fread 函数；相应地写入函数为 fwrite。
fread() 函数用来从指定文件中读取块数据。所谓块数据，也就是若干个字节的数据，可以是一个字符，可以是一个字符串，可以是多行数据，并没有什么限制。
*/


#define N 5
#define S 2

struct stu {
	char name[10];
	int num;
	int age;
	float score;
}boya[S], boyb[S], *pa, *pb;

void freadFwrite() {
	int a[N], b[N];
	int i, size = sizeof(int);
	FILE *fp;

	// fwrite()/fread() 函数直接操作字节，建议使用二进制方式打开文件
	if ((fp = fopen("D:\\demo.txt", "rb+")) == NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
		exit(1);
	}

	//从键盘输入数据 并保存到数组a
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	// 将数组a写到文本文件中
	fwrite(a, size, N, fp);

	//将文件中的位置指针重新定位到文件开头
	rewind(fp);

	//从文件读取内容并保存到数组b
	fread(b, size, N, fp);

	for (i = 0; i < N; i++) {
		printf("%d ", b[i]);
	}

	printf("\n");
	fclose(fp);
}

// 从键盘输入两个学生数据，写入一个文件中，再读出这两个学生的数据显示在屏幕上。
void freadFwriteStu() {
	FILE *fp;
	int i;
	pa = boya;
	pb = boyb;

	if ((fp = fopen("d:\\student.txt", "wb+")) == NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
		exit(1);
	}

	printf("Input data: \n");
	for (i = 0; i < S; i++, pa++) { //注意指针pa++
		scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
	}
	//将数组 boya 的数据写入文件
	fwrite(boya, sizeof(struct stu), S, fp);

	rewind(fp);

	//从文件读取数据并保存到数据 boyb
	fread(boyb, sizeof(struct stu), S, fp);


	//输出数组 boyb 中的数据
	for (i = 0; i<S; i++, pb++) {
		printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
	}


	fclose(fp);
}

void main数据块读写() {
//	freadFwrite();
	freadFwriteStu();

	system("pause");
}