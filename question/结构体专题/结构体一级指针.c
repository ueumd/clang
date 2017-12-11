#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	char *aliasname; // 套一级指针
	int age;
	int id;
}Teacher;

//二级指针
int createTeacher(Teacher **pT, int num)
{
	int i = 0;
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num); //Teacher Array[3]
	if (tmp == NULL)
	{
		return -1;
	}
	/*
	void *memset(void *s, int ch, size_t n);
	函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
	memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法[1]  。
	*/
	memset(tmp, 0, sizeof(Teacher) * num); //填充0

	for (i = 0; i < num; i++)
	{
		tmp[i].aliasname = (char *)malloc(60);  // 结构体中的一级指针 分配内存空间
	}

	*pT = tmp; //二级指针 形参 去间接修改的 实参 的值 
	return 0;
}

void freeTeacher(Teacher *p, int num)
{
	int i = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (p[i].aliasname != NULL)
		{
			free(p[i].aliasname);
		}
	}
	free(p);
}

void main()
{
	int i = 0;
	int ret = 0;
	//Teacher Array[3]; //在栈中分配内存

	Teacher *pArray = NULL; //被调函数里去接收空间

	ret = createTeacher(&pArray, 3);

	if (ret != 0)
	{
		printf("createTeacher error %d\n", ret);
	}

	for (i = 0; i < 3; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", &(pArray[i].age));

		printf("\nplease enter name:");
		scanf("%s", pArray[i].name);      //向指针所指向的内存空间拷贝数据

		printf("\nplease enter aliasname:");
		scanf("%s", pArray[i].aliasname);  //向指针所指向的内存空间拷贝数据
	}

	for (i = 0; i < 3; i++)
	{
		printf("age:%d-talisname:%s\n", pArray[i].age, pArray[i].aliasname);
	}

	freeTeacher(pArray, 3);

	system("pause");
	return;
}