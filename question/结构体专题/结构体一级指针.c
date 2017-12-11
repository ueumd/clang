#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	char *aliasname; // ��һ��ָ��
	int age;
	int id;
}Teacher;

//����ָ��
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
	�������ͣ���s�е�ǰλ�ú����n���ֽ� ��typedef unsigned int size_t ���� ch �滻������ s ��
	memset����������һ���ڴ�������ĳ��������ֵ�����ǶԽϴ�Ľṹ�������������������һ����췽��[1]  ��
	*/
	memset(tmp, 0, sizeof(Teacher) * num); //���0

	for (i = 0; i < num; i++)
	{
		tmp[i].aliasname = (char *)malloc(60);  // �ṹ���е�һ��ָ�� �����ڴ�ռ�
	}

	*pT = tmp; //����ָ�� �β� ȥ����޸ĵ� ʵ�� ��ֵ 
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
	//Teacher Array[3]; //��ջ�з����ڴ�

	Teacher *pArray = NULL; //����������ȥ���տռ�

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
		scanf("%s", pArray[i].name);      //��ָ����ָ����ڴ�ռ俽������

		printf("\nplease enter aliasname:");
		scanf("%s", pArray[i].aliasname);  //��ָ����ָ����ڴ�ռ俽������
	}

	for (i = 0; i < 3; i++)
	{
		printf("age:%d-talisname:%s\n", pArray[i].age, pArray[i].aliasname);
	}

	freeTeacher(pArray, 3);

	system("pause");
	return;
}