#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
const char* table[] 指针数组
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

	// 没有找到返回-1
	if (i == size) {
		*pos = -1;
	}

	return rv;
}

#define DIM(a) (sizeof(a)/sizeof(*a))

void main()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;

	// 自我约束能力 '\0' NULL 0
	char* c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};

	//带参数的宏
	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);


	printf("pos:%d\n", pos);

	for (i = 0; c_keyword[i] != NULL; i++) {
		printf("%s\n", c_keyword[i]);
		i++;
	}

	system("pause");
	return;
}