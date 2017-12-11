#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char *pname2;
}Teacher;

void copyTeacherStruct(Teacher *to, Teacher *from)
{

	/*
	= 和 memcpy 只会浅拷贝 只拷贝指址变量的值（地址）
	而没有拷贝指针变量指向的 内存空间 给拷贝过去

	*to = *from;
	memcpy(to, from, sizeof(Teacher));
	*/

	// 深拷贝

	*to = *from;
	to->pname2 = (char *)malloc(100); //要给t2.pname2分配内存
	strcpy(to->pname2, from->pname2);

}

void main()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name, "name1");

	t1.pname2 = (char *)malloc(100); //先要给t1.pname2 分配内存

	strcpy(t1.pname2, "namess");

	//t1 copy t2
	copyTeacherStruct(&t2, &t1);

	printf("%s", t2.pname2);

	if (t1.pname2 != NULL)
	{
		free(t1.pname2);
		t1.pname2 = NULL;
	}

	//浅拷贝时会报错 因为t1 t2都是指向同一块的内存空间
	if (t2.pname2 != NULL)
	{
		free(t2.pname2);
		t2.pname2 = NULL;
	}

	system("pause");
	return;
}