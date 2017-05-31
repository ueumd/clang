#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct AdvTeacher
{
	char name[64]; //64
	int age;  //4
	int p;   //4
	char *pname2;
}AdvTeacher;

void maind491()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;

	p - 1; //编译通过 运行通过 这句话在 cpu中计算
	p - 2;
	p - 3;

	p - p;

	{
		int offsize = (int)&(p->age);
		printf("%d \n", offsize); //64
	}
	
	system("pause");
	return;
}

void main()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;

	p - 1; //编译通过 运行通过 这句话在 cpu中计算
	p - 2;
	p - 3;

	

	{
	//	int offsize = (int)&(p->age);
		int offsize = (int)&((((AdvTeacher *)0)->age));
		printf("%d \n", offsize); //64
	}

	system("pause");
	return;
}