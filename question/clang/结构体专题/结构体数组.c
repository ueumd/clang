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

// 数组做为参数会退化为指针
void printTeacherArr(Teacher *array, int num) {
	int i = 0;
	for (i = 0; i < num; i++) {
		printf("age:%d\n", array[i].age);
	}
}

void main结构体数组()
{
	int i = 0;
	Teacher Array[3]; //栈上分配内存
	for (i = 0; i < 3; i++) {
		printf("please enter age:");
		scanf("%d", &(Array[i].age));
	}

	for (i = 0; i < 3; i++) {
	//	printf("age:%d\n", Array[i].age);
	}
	printf("排序前\n");
	printTeacherArr(Array, 3);

	printf("\n排序后\n");
	sortTeacherByAge(Array, 3);
	printTeacherArr(Array, 3);

	printf("hello...\n");
	system("pause");
	return;
}