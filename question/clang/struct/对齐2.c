#include <stdio.h>

#pragma  pack(8) //默认为8

#if 0
x86(linux 默认#pragma pack(4), 
window    默认#pragma pack(8))。
linux最大支持 4字节对齐。
方法：
	① 取 pack(n)的值（n = 1 2 4 8--), 取结构体中类型最大值m。两者取小即为外对齐大小 Y = (m<n:m, n)。
	② 将每一个结构体的成员大小与 Y 比较取小者为 X, 作为内对齐大小.
	③ 所谓按 X对齐，即为地址(设起始地址为0)能被x 整除的地方开始存放数据。
	④ 外部对齐原则是依据 Y 的值(Y的最小整数倍)，进行补空操作。
#endif

#if 0

type2 内存对齐规则：

1. 取pack(n), 取结构体中最大变量类型的大小m
n = 8   m = 4;  两者（n,m）取小  Y = 4值    外对齐

2. 将每一个结构体的成员大小与 Y 比较取小者为 X, 作为内对齐大小.
1  2  4  比出一系列的内对齐规则 X 1  2  4

3，所谓的内对齐(起始地址为0), 就是地址值能被X整除的地方开始存放数据。 8
4，所谓的外对齐，就是结束地址，是外对齐的最小整数倍

n 1   m 8    Y  1

1 8 4  2     X  1 1 1 1

#endif
//8 n=8 m=4 Y=4
struct type1
{
	char a;		// 1
	short c;  // 2
	int b;    // 4
};

// 24 n=8 m=8
struct type2
{
	char   a;			// 1
	double b;     // 8 最宽
	float  c;     // 4
	short  d;     // 2
};

//大小端模式
void bigSmallEndian() {
	int data = 0x12345678;
	if (*(char *)&data == 0x78) {
		printf("小端序");
	}
	else {
		printf("大端序");
	}
}

int main(void)
{
	printf("size = %d\n", sizeof(struct type1));
	system("pause");
	return 0;
}
