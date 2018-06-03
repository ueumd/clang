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
/*
a 是一个int型数组，有10个元素，
sizeof(a)				就是 a数组整个的存储字节数，10*4=40，这不难理解。
*a相当于a[0]，   数组第一个元素，
sizeof(*a)  就相当于sizeof(a[0]) =4。
sizeof(a) / sizeof(*(a)) =10，就相当于计算数组内成员个数。
*/

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