#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mainҰָ�������ԭ��()
{
	char *p1 = NULL;	// p1ջ�з����ڴ�ռ� NULLĬ����0 p1�ĵ�ַ��0
	p1 = (char *)malloc(100); // p1ָ���˶��п��ٵĿռ� �� 0xaa11�� p1�ĵ�ַ�����0xaa11
	strcpy(p1, "123654");			// �ѳ�������123654 ������p1��ָ��Ķ��пռ�

	if (NULL == p1) {
		return;
	}
	printf("p1:%s\n", p1);

	if (p1 != NULL) {
		free(p1);  // �ͷ�p1ָ����еĿռ� ��p1�����ĵ�ַ����0xaa11����ָ����һ�������ռ�
		p1 = NULL; // ����Ҫ��p1�ĵ�ַ
	}

	/*
		���ǰ���Ѿ��ͷ��ˣ���free(p1)�����������ģ�Ҳ�Ͳ�����Ұָ�룬����취��p1=NULL
	*/
	if (p1 != NULL) {
		free(p1);
	}

	system("pause");
	return;
}