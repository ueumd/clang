#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��
char *getMen(int num)
{
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if (p1 == NULL) {
		return NULL;
	}
	return p1;

}

//ջ
char *getMen2()
{
	char buf[64]; //��ʱ���� ջ�����
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;
}

void main155()
{
	char *tmp = NULL;
	tmp = getMen(10); 
	/*
		�������������������getMenp p1���ڴ棨ջ�����б������� ������main�����tmpû�б�������,����ָ����p1ָ���(����ϵͳ����)
	*/

	if (tmp == NULL) {
		return;
	}

	strcpy(tmp, "111222");//��tmpָ����ڴ�ռ�copy����

	//tmp = getMen2();

	printf("tmp:%d\n",*tmp);
	printf("tmp:%s.\n", tmp);// �е�ϵͳ�����ĳ�����ܻ���� debug��relaseЧ���ǲ�һ���� ԭ�������ʱ��
	system("pause");
}