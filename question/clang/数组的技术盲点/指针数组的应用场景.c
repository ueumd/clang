#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
const char* table[] ָ������
*/
int searchKeyTable(const char* table[], const int size, const char* key, int *pos)
{
	int rv = 0;
	int i = 0;
	int inum = 0;
	if (table == NULL || key == NULL || pos == NULL) {
		rv = -1;
		printf("func searchKeyTable:%d", rv);
		return rv;
	}

	inum = (sizeof(table) / sizeof(*table));

	for (i = 0; i < size; i++) {
		if (strcmp(key, table[i]) == 0) {
			*pos = i;
			return rv;
		}
	}

	// û���ҵ�����-1
	if (i == size) {
		*pos = -1;
	}

	return rv;
}

#define DIM(a) (sizeof(a)/sizeof(*a))
/*
a ��һ��int�����飬��10��Ԫ�أ�
sizeof(a)				���� a���������Ĵ洢�ֽ�����10*4=40���ⲻ����⡣
*a�൱��a[0]��   �����һ��Ԫ�أ�
sizeof(*a)  ���൱��sizeof(a[0]) =4��
sizeof(a) / sizeof(*(a)) =10�����൱�ڼ��������ڳ�Ա������
*/

void main()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;

	// ����Լ������ '\0' NULL 0
	char* c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};

	//�������ĺ�
	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);


	printf("pos:%d\n", pos);

	for (i = 0; c_keyword[i] != NULL; i++) {
		printf("%s\n", c_keyword[i]);
		i++;
	}

	system("pause");
	return;
}