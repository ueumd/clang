#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// 有名结构体
struct UserInfo {
	char name[50];		// 50	
	char *alisaName;	// 8
	char phone[50];   // 50
	int num;				  // 4
};

//结构体内的指针
typedef struct  Student
{
	char *name;        //从节省空间的角度出发，名字多长，占多少空间
	int score;
}Stu;

int structPointer(){

	//开辟空间

	Stu *ps = (Stu*)malloc(sizeof(Stu));
	ps->name = (char*)malloc(100);					//name同样需要开辟空间

	ps->score = 100;
	strcpy(ps->name, "i love you only you"); //如果不开辟空间， 这样是非法的。有的平台可以，有的不可以

	printf("name = %s score = %d\n", ps->name, ps->score);

	//释放
	free(ps->name);
	free(ps);

	return 0;
}


int main222() {

	struct UserInfo u1;
	u1.num = 100;
	
	//	u1.name = "aaa"; error 不能等号赋值
	strcpy(u1.name, "aaa"); //字符串数组只能这样形式
	u1.alisaName = "AAA";

	printf("%d\n", u1.num);
	printf("%s\n", u1.name);
	printf("%s\n", u1.alisaName);


	//动态分配内存
	struct UserInfo *p = (struct Userinfo *)malloc(sizeof(struct UserInfo) * 1);
	p->alisaName = "AAAA";
	p->num = 200;

	printf("%d\n", p->num);				//200
	printf("%s\n", p->alisaName);	//AAAA

	printf("%d\n", sizeof(struct UserInfo)); //112

	system("pause");
	return 0;
}