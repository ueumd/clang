#include<stdio.h>
#include<stdlib.h>

//�ṹ��
int struct1()
{
	struct stu {
		char *name;  //����
		int num;  //ѧ��
		int age;  //����
		char group;  //����С�� 
		float score;  //�ɼ�
	}stu1;

	stu1.name = "Tom";
	stu1.num = 12;
	stu1.age = 18;
	stu1.group = 'A';
	stu1.score = 136.5;

	printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);
	return 0;
}

//�ṹ������,�ṹ������ָ���ʹ�á�
int structArray()
{
	struct MyStruct
	{
		char *name;  //����
		int num;  //ѧ��
		int age;  //����
		char group;  //����С�� 
		float score;  //�ɼ�
	}stus[5] = {
		{ "Li ping", 5, 18, 'C', 145.0 },
		{ "Zhang ping", 4, 19, 'A', 130.5 },
		{ "He fang", 1, 18, 'A', 148.5 },
		{ "Cheng ling", 2, 17, 'F', 139.0 },
		{ "Wang ming", 3, 17, 'B', 144.5 }
	},*ps;

	//����ȫ��ѧ�����ܳɼ���ƽ���ɼ����Լ� 140 �����µ�������

	int i, num_140 = 0;
	float average, sum = 0;

	for (i = 0; i < 5; i++) {
		sum += stus[i].score;
		if (stus[i].score < 140) {
			num_140++;
		}
	}

	printf("�ܳɼ���%.2f\,ƽ���ɼ���%.2f,140�������������ǣ�%d\n", sum,sum/5,num_140);

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
		char *name;  //����
		int num;  //ѧ��
		int age;  //����
		char group;  //����С�� 
		float score;  //�ɼ�
	}stu1 = { "Li ping", 5, 18, 'C', 145.0 }, *pstu = &stu1;


	//��ȡ�ṹ���Ա��ֵ
	printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, 
		(*pstu).score);

	//�Ƽ�����д��
	printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", pstu->name,pstu->num,pstu->age,pstu->group,pstu->score);
}
int mainstruct()
{

	//struct1();
	structArray();
	//structPointer();
	system("pause");
	return 0;
}