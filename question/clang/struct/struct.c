#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// �����ṹ��
struct UserInfo {
	char name[50];		// 50	
	char *alisaName;	// 8
	char phone[50];   // 50
	int num;				  // 4
};

//�ṹ���ڵ�ָ��
typedef struct  Student
{
	char *name;        //�ӽ�ʡ�ռ�ĽǶȳ��������ֶ೤��ռ���ٿռ�
	int score;
}Stu;

int structPointer(){

	//���ٿռ�

	Stu *ps = (Stu*)malloc(sizeof(Stu));
	ps->name = (char*)malloc(100);					//nameͬ����Ҫ���ٿռ�

	ps->score = 100;
	strcpy(ps->name, "i love you only you"); //��������ٿռ䣬 �����ǷǷ��ġ��е�ƽ̨���ԣ��еĲ�����

	printf("name = %s score = %d\n", ps->name, ps->score);

	//�ͷ�
	free(ps->name);
	free(ps);

	return 0;
}


int main222() {

	struct UserInfo u1;
	u1.num = 100;
	
	//	u1.name = "aaa"; error ���ܵȺŸ�ֵ
	strcpy(u1.name, "aaa"); //�ַ�������ֻ��������ʽ
	u1.alisaName = "AAA";

	printf("%d\n", u1.num);
	printf("%s\n", u1.name);
	printf("%s\n", u1.alisaName);


	//��̬�����ڴ�
	struct UserInfo *p = (struct Userinfo *)malloc(sizeof(struct UserInfo) * 1);
	p->alisaName = "AAAA";
	p->num = 200;

	printf("%d\n", p->num);				//200
	printf("%s\n", p->alisaName);	//AAAA

	printf("%d\n", sizeof(struct UserInfo)); //112

	system("pause");
	return 0;
}