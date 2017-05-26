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

void printTeacher(Teacher *array, int num)
{
	int i = 0;

	//print age

	for (i = 0; i < num; i++)
	{
		printf("age:%d\n", array[i].age);
	}
}

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

void maind46()
{
	int i = 0;
	Teacher Array[3]; //在栈中分配内存

	for (i = 0; i < 3; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", &(Array[i].age));
	}

	//print age

	for (i = 0; i < 3; i++)
	{
		//printf("age:%d\n", Array[i].age);
	}

	printTeacher(Array, 3);
	sortTeacherByAge(Array, 3);
	for (i = 0; i < 3; i++)
	{
		printf("age:%d\n", Array[i].age);
	}


	system("pause");
	return;
}