#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main2222()
{
	/*
		int a=10;
		char *p=NULL;

	   *p = 100   ����ı�ָ�������ֵ��ֻ��ı���ָ���ڴ���ֵ
	    p = &a;   p��ֵ p=&a; ֻ��ı�ָ�����ֵ������ı���ָ������
		c = *p    �ڵ����ұ� ȡֵ

	*/
	
	int a = 10;
	char *p1 = 100;//ָ����� ����4���ֽڵ��ڴ�   �����ڴ渳ֵ��  

	char ****p2 = 100;

	int *p3 = NULL;

	p3 = &a;

	*p3 = 20;//����޸�a��ֵ

	int c = *p3;//ȡֵ

	printf("%d\n", c);

	printf("a:%d,p1:%d,p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));//4 4 4 

	{
	//	char *p4 = NULL;
		//p4 = (char *)mollac(100);
		//p4 = (char *)mollac(200);
		/*
			һ��ʼp4��ջ�� ָ����� 100���ڴ�ռ��ַ
			����ָ����� 200���ڴ�ռ��ַ

			�ܽ᣺���ϵĸ�ָ��丳ֵ���൱�ڲ�ͣ�ĸı�ָ�뷽��  
		*/
	}


	system("pause");
	return;
}


/*
int getAbc1(char *p1);
int getAbc2(char **p2);
int getAbc3(char ***p3);
int getAbc4(char (*p4)[30]);
int getAbc5(char p5[10][30]);

ָ���������������β��ж༶ָ���ʱ��
վ�ڱ������ĽǶȣ�ֻ��Ҫ����4���ֽڵ��ڴ棨32bitƽ̨��
������ʹ���ڴ��ʱ�����ǲŹ���ָ����ָ����ڴ���һά�Ļ��Ƕ�ά��

�ص㣺
ָ����һ���������ͣ���ָ��ָ����ڴ�ռ����������
*/

//����1��ָ
//��ָ��д��
void errorOne()
{
	char *p1 = NULL;
	p1 = 0x00000007;
	strcpy(p1, "abcdefg"); 
	/*
		��ָ�����*p1ָ����ڴ�ռ�0д������ 0���ڳ�����������ϵͳ����
		���Իᵯ����ʾд��λ�ó�ͻ
	*/
	return;
}

void errorTwo()
{
	
	char buf[128]; //c������ջ�Ϸ����ڴ�
	int i;
	int j = 0;    //������(0û�з���ջ�� Ҳû�з��ڶ��� ȫ������������������˵)

	char *p1 = NULL;
	char *p2 = NULL;

	//���ϵĸı�p1��ֵ���൱�ڲ��ϸı�ָ���ָ��
	p1 = &buf[0];
	p1 = &buf[1];
	p1 = &buf[2];

	for (i = 3; i < 10; i++) {
		//p1 =p1[i];
	}

	p2 = (char *)malloc(100);
	strcpy(p2, "abcdefg1234567891012");
	
	/*
		p1��ָ����p2��ָ����ڴ�ռ䣨�ѣ�
	*/

	for (i = 0; i < 10; i++) {
		p1 = p2+i;
		printf("%c ", *p1);
	}

}

void maintilv111()
{
	
	//errorOne();
	errorTwo();
	system("pause");
	return;
}