#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
"name111"
"name222"
"name333"
*/
typedef struct Teacher
{

	char name[64];
	char *aliasname; // 套一级指针
					 //char stuname[10][30];
	char **stuname; //套二级指针
	int age;
	int id;
}Teacher;

//二级指针
int createTeacher2(Teacher **pT, int num)
{
	int i = 0, j = 0;
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num); //Teacher Array[3]
	if (tmp == NULL)
	{
		return -1;
	}

	memset(tmp, 0, sizeof(Teacher) * num);

	for (i = 0; i < num; i++)
	{
		char **p = NULL;
		
		//malloc一级指针
		tmp[i].aliasname = (char *)malloc(60); // 要分配内存空间

											   //二级指针的第三种内存模型
		{
			p = (char **)malloc(3 * sizeof(char *)); //打造二维内存

			for (j = 0; j < 3; j++)
			{
				p[j] = (char *)malloc(120);
			}

			tmp[i].stuname = p;
		}

	}

	*pT = tmp; //二级指针 形参 去间接修改的 实参 的值 
	return 0;
}

void freeTeacher2(Teacher *p, int num)
{
	int i = 0,j=0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		//释放一级指针
		if (p[i].aliasname != NULL)
		{
			free(p[i].aliasname);
		}

		//释放二级指针
		if (p[i].stuname != NULL)
		{
			char **myp = p[i].stuname;
			for (j = 0; j < num; j++)
			{
				if (myp[j] != NULL)
				{
					free(myp[j]);
				}
			}

			free(myp);
			p[i].stuname = NULL;
		}

	}
	free(p);
}

void maind47()
{
	int i = 0, j = 0;
	int ret = 0;
	//Teacher Array[3]; //在栈中分配内存

	Teacher *pArray = NULL;

	ret = createTeacher2(&pArray, 3);
	if (ret != 0)
	{
		printf("createTeacher error %d\n", ret);
	}

	for (i = 0; i < 3; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", &(pArray[i].age));

		//printf("\nplease enter name:");
		//scanf("%s", pArray[i].name); //向指针所指向的内存空间拷贝数据

		printf("\nplease enter aliasname:");
		scanf("%s", pArray[i].aliasname); //向指针所指向的内存空间拷贝数据

		for (j = 0; j < 3; j++)
		{
			printf("please enter stuname:");
			scanf("%s", pArray[i].stuname[j]); 
		}

	}

	for (i = 0; i < 3; i++)
	{
		printf("age:%d-talisname:%s\n", pArray[i].age, pArray[i].aliasname);
	}

	freeTeacher2(pArray, 3);

	system("pause");
	return;
}