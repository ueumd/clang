#include<stdio.h>
#include<stdlib.h>

//结构体
int struct1()
{
	struct stu {
		char *name;  //姓名
		int num;  //学号
		int age;  //年龄
		char group;  //所在小组 
		float score;  //成绩
	}stu1;

	stu1.name = "Tom";
	stu1.num = 12;
	stu1.age = 18;
	stu1.group = 'A';
	stu1.score = 136.5;

	printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);
	return 0;
}

//结构体数组,结构体数组指针的使用。
int structArray()
{
	struct MyStruct
	{
		char *name;  //姓名
		int num;  //学号
		int age;  //年龄
		char group;  //所在小组 
		float score;  //成绩
	}stus[5] = {
		{ "Li ping", 5, 18, 'C', 145.0 },
		{ "Zhang ping", 4, 19, 'A', 130.5 },
		{ "He fang", 1, 18, 'A', 148.5 },
		{ "Cheng ling", 2, 17, 'F', 139.0 },
		{ "Wang ming", 3, 17, 'B', 144.5 }
	},*ps;

	//计算全班学生的总成绩、平均成绩和以及 140 分以下的人数。

	int i, num_140 = 0;
	float average, sum = 0;

	for (i = 0; i < 5; i++) {
		sum += stus[i].score;
		if (stus[i].score < 140) {
			num_140++;
		}
	}

	printf("总成绩：%.2f\,平均成绩：%.2f,140分数以下人数是：%d\n", sum,sum/5,num_140);

	int len = sizeof(stus) / sizeof(struct MyStruct);
	printf("len=%d\n", len);
	//printf(stus);
	//ps=class[0]

	printf("Name\t\tNum\tAge\tGroup\tScore\t\n");
	for (ps = stus; ps < stus+len; ps++) {
		printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
	}

	return 0;
}

int structPointer()
{
	struct stu{
		char *name;  //姓名
		int num;  //学号
		int age;  //年龄
		char group;  //所在小组 
		float score;  //成绩
	}stu1 = { "Li ping", 5, 18, 'C', 145.0 }, *pstu = &stu1;


	//读取结构体成员的值
	printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, 
		(*pstu).score);

	//推荐这种写法
	printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", pstu->name,pstu->num,pstu->age,pstu->group,pstu->score);
}
int mainstruct()
{

	//struct1();
	structArray();
	//structPointer();
	system("pause");
	return 0;
}