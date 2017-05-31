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
	char *aliasname; // ��һ��ָ��
					 //char stuname[10][30];
	char **stuname; //�׶���ָ��
	int age;
	int id;
}Teacher;

//����ָ��
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
		
		//mallocһ��ָ��
		tmp[i].aliasname = (char *)malloc(60); // Ҫ�����ڴ�ռ�

											   //����ָ��ĵ������ڴ�ģ��
		{
			p = (char **)malloc(3 * sizeof(char *)); //�����ά�ڴ�

			for (j = 0; j < 3; j++)
			{
				p[j] = (char *)malloc(120);
			}

			tmp[i].stuname = p;
		}

	}

	*pT = tmp; //����ָ�� �β� ȥ����޸ĵ� ʵ�� ��ֵ 
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
		//�ͷ�һ��ָ��
		if (p[i].aliasname != NULL)
		{
			free(p[i].aliasname);
		}

		//�ͷŶ���ָ��
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
	//Teacher Array[3]; //��ջ�з����ڴ�

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
		//scanf("%s", pArray[i].name); //��ָ����ָ����ڴ�ռ俽������

		printf("\nplease enter aliasname:");
		scanf("%s", pArray[i].aliasname); //��ָ����ָ����ڴ�ռ俽������

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