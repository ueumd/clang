#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;


void sortTeacherByAge(Teacher *array, int num)
{
	int i = 0, j = 0;
	Teacher tmp;

	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (array[i].age > array[j].age)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

}

// ������Ϊ�������˻�Ϊָ��
void printTeacherArr(Teacher *array, int num) {
	int i = 0;
	for (i = 0; i < num; i++) {
		printf("age:%d\n", array[i].age);
	}
}

void main�ṹ������()
{
	int i = 0;
	Teacher Array[3]; //ջ�Ϸ����ڴ�
	for (i = 0; i < 3; i++) {
		printf("please enter age:");
		scanf("%d", &(Array[i].age));
	}

	for (i = 0; i < 3; i++) {
	//	printf("age:%d\n", Array[i].age);
	}
	printf("����ǰ\n");
	printTeacherArr(Array, 3);

	printf("\n�����\n");
	sortTeacherByAge(Array, 3);
	printTeacherArr(Array, 3);

	printf("hello...\n");
	system("pause");
	return;
}