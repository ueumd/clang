#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��
char *getMen(int num)
{
	// 
	/*
	ջ�з����ڴ�ռ� p1 ��ָ������10���ֽڵĶ��ڴ�ռ�
	��getMen�������������ջ����ʧ����ʧ֮ǰ����p1��main�����е�tmp����ʱtmpָ����е�10���ֽ��ڴ�ռ�
	*/
	char *p1 = NULL; 

	// �ڶ��￪��10�ֽڸ��ڴ�ռ�, ��10���ڴ�ռ䲻����Ϊ�Ӻ��� �������������,��Ϊ���ڶ���
	p1 = (char *)malloc(sizeof(char) * num); 
	if (p1 == NULL) {
		return NULL;
	}
	return p1;
}

//ջ ע��return���ǰ��ڴ��64���ֽڣ���return���������ǰ��ڴ����׵�ַ���ڴ�ı�ţ������ظ�tmp 
/*
���ָ��Ĺؼ����ڴ棬û���ڴ���������ָ��
ָ��ָ��˭���Ͱ�˭�ĵ�ַָ��˭
*/
char *getMen2()
{
	char buf[64]; //��ʱ���� ջ�����
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;
}

void main()
{

	char *tmp = NULL; // ջ�з����ڴ�ռ� tmp
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