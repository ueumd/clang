#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
�� fprintf() �� fscanf() ������д�����ļ�����־�ļ���ǳ����㣬���������ܹ�ʶ���û�Ҳ���Կ����������ֶ��޸ġ�
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
	//�Ӽ��̶������ݣ����浽boya
	printf("Input data:\n");
	for (i = 0; i<N; i++, pa++) {
		scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
	}
	pa = boya;
	//��boya�е�����д�뵽�ļ�
	for (i = 0; i<N; i++, pa++) {
		fprintf(fp, "%s %d %d %f\n", pa->name, pa->num, pa->age, pa->score);
	}
	//�����ļ�ָ��
	rewind(fp);
	//���ļ��ж�ȡ���ݣ����浽boyb
	for (i = 0; i<N; i++, pb++) {
		fscanf(fp, "%s %d %d %f\n", pb->name, &pb->num, &pb->age, &pb->score);
	}
	pb = boyb;
	//��boyb�е������������ʾ��
	for (i = 0; i<N; i++, pb++) {
		printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
	}
	fclose(fp);
}

/*
����� fp ����Ϊ 
stdin����ô fscanf() ��������Ӽ��̶�ȡ���ݣ��� scanf ��������ͬ��
stdout����ô fprintf() ������������ʾ��������ݣ��� printf ��������ͬ�����磺
*/
void fscanfAndFprintf2() {
	int a, b, sum;
	fprintf(stdout, "Input tow numbers: ");
	fscanf(stdin, "%d %d", &a, &b);
	sum = a + b;
	fprintf(stdout, "sum=%d\n", sum);
}

void main��ʽ����д() {
	//fscanfAndFprintf();
	fscanfAndFprintf2();
	system("pause");
}