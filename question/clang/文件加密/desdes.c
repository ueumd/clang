#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "des.h"
int DesEncfile() {
	//�����ַ�����
	unsigned char buf8[9] = "123456789";
	//�������ĳ���
	int plainlen = 9;
	//������������
	unsigned char bufcrypt[16] = { 0 };
	//�������ĳ���
	int cryptlen = 0;
	//��ʼ��������
	int rest = DesEnc(buf8, plainlen, bufcrypt, &cryptlen);
	if (rest != 0)
	{
		printf("����ʧ�ܣ�\n");
		return 1;
	}
	else {
		printf("���ܳɹ���\n");
		printf("���ģ�%s\n", bufcrypt);
	}
	//�����ļ�
	//�����ַ�����
	//֮���Զ������鳤����10����Ϊ����ĩβ����һ��'\0'�����ӡ
	unsigned char buf82[10] = { 0 };
	//�������ĳ���
	int plainlen2 = 0;
	int rest2 = DesDec(bufcrypt, cryptlen, buf82, &plainlen2);
	if (rest2 != 0)
	{
		printf("����ʧ�ܣ�\n");
		return 1;
	}
	else {
		printf("���ܳɹ���,������%s\n", buf82);
	}
	//�ȽϽ���֮��������Ƿ��ԭ����������ͬ
	//memcmp()�Ƚ�buf8��buf82��plainlen2�����ϵ������Ƿ���ͬ
	if (memcmp(buf8, buf82, plainlen2) == 0)
	{
		printf("����������ͬ��\n");
	}
	return 0;
}

int main() {
	DesEncfile();
	system("pause");
	return 0;
}