#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void gogogo() {
	printf("gogoggo\n");
}

int main������() {

	printf("%p", gogogo); //��������ź����ĵ�ַ
	gogogo(); //ֱ�ӵ���
	//����ָ��˵�ľ���һ��ָ�룬�����ָ��ָ��ĺ�����������ͨ�Ļ����������ͻ��������
	void(*p)() = gogogo;
	p(); //��ӵ���


	char *pp = "ABCDEF"; //pp �洢�����ַ����ĵ�ַ
	printf("p=%d,\t ABCDEF=%d\n", sizeof(pp), sizeof("ABCDEF"));	// 4   8
	printf("p=%p,\tABCDEF=%p\n", &pp, pp);												//&pp ָ���ַ pp�ַ�����ַ
	/*
		��ϵ�
		p=003EF8AC,     ABCDEF=00F56B40

		�ڴ���ʾ��16���Ʋ鿴:
		0x003EF8AC  00f56b40  @k?.

		1�ֽ� ��������ʾ 8��
		0x00F56B40   +65  +66  +67  +68  +69  +70   +0   +0  ABCDEF..
	*/

	//	*pp = "cc"; //����   ������ֻ�ܶ� �����ַ����ڴ�����
	pp = "cc"; // ppָ����cc���ڴ��ַ

	system("pause");
	return 0;
}