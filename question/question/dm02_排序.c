#include<stdio.h>
#include<stdlib.h>

int main2()
{
	int i = 0, j = 0;
	int a[10] = { 3, 1, 44, 2, 3, 44, 5, 5,6, 67 };
	int tmp = 0;

	for (i = 0; i < 10; i++) {//���ѭ�� ��

		for (j = i + 1; j < 10; j++) { // �ڲ�ѭ��

			if (a[i] > a[j]) { //���С�ͽ�����λ��
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ,", a[i]);
	}

	system("pause");
	return 0;

}


int arraySort(int a[],int num) {
	int i = 0, j = 0;
	int tmp = 0; 
	
	for (i = 0; i < num; i++) {//���ѭ�� ��

		for (j = i + 1; j < num; j++) { // �ڲ�ѭ��

			if (a[i] > a[j]) { //���С�ͽ�����λ��
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ,", a[i]);
	}

	return 0;
}

int arraySort2(int *a,int num) {
	int i = 0, j = 0;
	int tmp = 0;

	int num2 = 0;
	num2 = sizeof(a) / sizeof(*a);
	printf("%d,%d,%d\n", sizeof(a), sizeof(*a),num2);//4 4 1

	/*
	Ϊʲônum2����1

	�����������������˻����� �˻�Ϊһ��ָ��
	1 ���ۣ���ȷ������Ӧ�ǰ�������ڴ��׵�ַ���������Ч���ȴ��������ú���

	����2
	Ϊʲô��1 ʵ�ε� a���β�a ���������ͱ��ʲ�һ��
	�βε����飬���������������ָ�봦�� ����C���Ե���ɫ

	����3��
	�β�д�ں����ϣ�int *a����д�ں�������һ���ģ�ֻ����д�ں������Ǿ��ж�������Զ���
	*/

	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) { 
			if (a[i] > a[j]) { 
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ,", a[i]);
	}

	return 0;
}

int mainsort()
{
	int a[10] = { 3, 1, 44, 2, 3, 44, 5, 5,6, 67 };
	
	
	int num = 0;
	num = sizeof(a) / sizeof(a[0]);
	printf("num=%d\ta=%d\ta[0]=%d\n", num,sizeof(a),sizeof(a[0])); //num=10  a=40    a[0]=4
	
	 //arraySort(a, num);
	arraySort2(a,num);

	system("pause");
	return 0;

}
