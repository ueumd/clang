#include <stdio.h>

#pragma  pack(8) //Ĭ��Ϊ8

#if 0
x86(linux Ĭ��#pragma pack(4), 
window    Ĭ��#pragma pack(8))��
linux���֧�� 4�ֽڶ��롣
������
	�� ȡ pack(n)��ֵ��n = 1 2 4 8--), ȡ�ṹ�����������ֵm������ȡС��Ϊ������С Y = (m<n:m, n)��
	�� ��ÿһ���ṹ��ĳ�Ա��С�� Y �Ƚ�ȡС��Ϊ X, ��Ϊ�ڶ����С.
	�� ��ν�� X���룬��Ϊ��ַ(����ʼ��ַΪ0)�ܱ�x �����ĵط���ʼ������ݡ�
	�� �ⲿ����ԭ�������� Y ��ֵ(Y����С������)�����в��ղ�����
#endif

#if 0

type2 �ڴ�������

1. ȡpack(n), ȡ�ṹ�������������͵Ĵ�Сm
n = 8   m = 4;  ���ߣ�n,m��ȡС  Y = 4ֵ    �����

2. ��ÿһ���ṹ��ĳ�Ա��С�� Y �Ƚ�ȡС��Ϊ X, ��Ϊ�ڶ����С.
1  2  4  �ȳ�һϵ�е��ڶ������ X 1  2  4

3����ν���ڶ���(��ʼ��ַΪ0), ���ǵ�ֵַ�ܱ�X�����ĵط���ʼ������ݡ� 8
4����ν������룬���ǽ�����ַ������������С������

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
	double b;     // 8 ���
	float  c;     // 4
	short  d;     // 2
};

//��С��ģʽ
void bigSmallEndian() {
	int data = 0x12345678;
	if (*(char *)&data == 0x78) {
		printf("С����");
	}
	else {
		printf("�����");
	}
}

int main(void)
{
	printf("size = %d\n", sizeof(struct type1));
	system("pause");
	return 0;
}
