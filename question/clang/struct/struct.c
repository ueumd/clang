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

int main() {

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