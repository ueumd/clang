#include<stdio.h>
#include<stdlib.h>

#define DIM(a) (sizeof(a)/sizeof(*a))
#if 0
int a[10] = {0}
sizeof(a)				数组整个的存储字节数，10 * 4 = 40，这不难理解。
*a              相当于a[0]，数组第一个元素，*a+1 第二元素
sizeof(*a)       就相当于sizeof(a[0]) = 4。
sizeof(a) / sizeof(*(a)) = 40/4=10，就相当于计算数组内成员个数。
#endif
int main() {

	// 自我约束能力 '\0' NULL 0
	char* str[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};


	printf("%d\n", DIM(str)); //5

	getchar();
	return 0;
}
