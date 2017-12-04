#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getMemPt(char **myp1, int *mylen1, char **myp2, int *mylen2) {
	int ret = 0;
	char *tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "abcde");

	*mylen1 = strlen(tmp1); // 1级指针
	*myp1 = tmp1;						// 2级指针

	tmp2 = (char *)malloc(200);
	strcpy(tmp2, "123456987");

	*mylen2 = strlen(tmp2); // 1级指针
	*myp2 = tmp2;					 // 2级指针

	return ret;

}

void main()
{
	int   ret = 0;

	char	*p1 = NULL;
	int		len1 = 0;
	char	*p2 = NULL;
	int		len2 = 0;

	ret = getMemPt(&p1, &len1, &p2, &len2);
	if (ret != 0) {
		printf("func getMemPt() err: %d\n", ret);
		return ret;
	}
	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	if (p1 != NULL) {
		free(p1);
		p1 = NULL;
	}

	if (p2 != NULL) {
		free(p2);
		p2 = NULL;
	}

	printf("p1: %d \t p2: %d\n", p1, p2);
	/*
	输出结果：
	p1:abcde
	p2:123456987
	p1: 0    p2: 0
	*/
	system("pause");
	return;
}