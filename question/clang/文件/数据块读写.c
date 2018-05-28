#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
fgets() �о����ԣ�ÿ�����ֻ�ܴ��ļ��ж�ȡһ�����ݣ���Ϊ fgets �������з��ͽ�����ȡ��
���ϣ����ȡ�������ݣ���Ҫʹ�� fread ��������Ӧ��д�뺯��Ϊ fwrite��
fread() ����������ָ���ļ��ж�ȡ�����ݡ���ν�����ݣ�Ҳ�������ɸ��ֽڵ����ݣ�������һ���ַ���������һ���ַ����������Ƕ������ݣ���û��ʲô���ơ�
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

	// fwrite()/fread() ����ֱ�Ӳ����ֽڣ�����ʹ�ö����Ʒ�ʽ���ļ�
	if ((fp = fopen("D:\\demo.txt", "rb+")) == NULL) {
		printf("Cannot open file, press any key to exit!\n");
		getch();
		exit(1);
	}

	//�Ӽ����������� �����浽����a
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	// ������aд���ı��ļ���
	fwrite(a, size, N, fp);

	//���ļ��е�λ��ָ�����¶�λ���ļ���ͷ
	rewind(fp);

	//���ļ���ȡ���ݲ����浽����b
	fread(b, size, N, fp);

	for (i = 0; i < N; i++) {
		printf("%d ", b[i]);
	}

	printf("\n");
	fclose(fp);
}

// �Ӽ�����������ѧ�����ݣ�д��һ���ļ��У��ٶ���������ѧ����������ʾ����Ļ�ϡ�
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
	for (i = 0; i < S; i++, pa++) { //ע��ָ��pa++
		scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
	}
	//������ boya ������д���ļ�
	fwrite(boya, sizeof(struct stu), S, fp);

	rewind(fp);

	//���ļ���ȡ���ݲ����浽���� boyb
	fread(boyb, sizeof(struct stu), S, fp);


	//������� boyb �е�����
	for (i = 0; i<S; i++, pb++) {
		printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
	}


	fclose(fp);
}

void main���ݿ��д() {
//	freadFwrite();
	freadFwriteStu();

	system("pause");
}