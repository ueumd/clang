#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*
�ṹ������Ĵ�С�ܹ��������������ͳ�Ա��С������
�ṹ����ܴ�СΪ�ṹ�����������ͳ�Ա��С����������������Ҫװ�����У����������
*/
// ��11 1��11�ı�������������
struct st1 {
	char c;				// 1���ֽ�
	char str[10]; // 10���ֽ�

};

// ��14 2��14�ı�������������, ���Զ�����ֽ�,������13
struct st2 {
	short c;				// 2���ֽ�
	char str[11];   // 11���ֽ�						
};

// ��14 8��24�ı�������������, ���Զ�����ֽ�,������19
struct st3 {
	double c;				// 8���ֽ�
	char str[11];   // 11���ֽ�						
};



/*
�ṹ��ÿ����Ա����ڽṹ���׵�ַ��ƫ�������ǳ�Ա��С����������������Ҫ���������ڳ�Ա֮���������ֽڣ�
*/

// 8
struct st4 {
	char c;				// 1���ֽ�
	int num;      // 4���ֽ�		int �� ��� ��������	
};

//0+8+4 = 12
struct st5 {
	char c;				// 1���ֽ�												 300500 0
	int num;      // 4���ֽ�		int �� ��� ��������	 300504 4
	short sh;			// 2														 300508 8

};

//0+2+4 = 6 ����int���� �����2���ֽ� 8
struct st6 {
	char c;				// 1���ֽ�												 300500 0
	short sh;			// 2														 300502	2
	int num;      // 4���ֽ�		int �� ��� ��������	 300504 4
};

// 1+2+8+4+19 = 34 ����8�� 40
struct st7 {												// 305000
	char c;				// 1									 305000
	short sh;			// 2									 305002		
	double x;			// 8  ��� ��������     305008
	int num;      // 4                   305016
	char str[19]; // 19                  305020
};

// 24
typedef struct
{
	char c;    // 1
	int i[2];  // 4
	double v;  // 8
}S;

//union ͬ��Ҳ��

//8
union u1 {
	int num;
	double data;
};

// 12 �ܱ�4����  ����װ��11
union u2 {
	int num;			//���������� 4
	char str[11]; // 11
};

// 16 �ܱ�8����  ����װ��11
union u3 {
	double num;			//���������� 8
	char str[11]; // 11
};

//11
union u4 {
	char num;			//���������� 1
	char str[11]; // 11
};

int main333() {

	
	printf("st1=%d\n", sizeof(struct st1)); // 11
	printf("st2=%d\n", sizeof(struct st2)); // 14
	printf("st3=%d\n", sizeof(struct st3)); // 24

	printf("st5=%d\n", sizeof(struct st5)); // 8
	printf("st7=%d\n", sizeof(struct st7)); // 40

	printf("size of S = %d\n", sizeof(S));
	system("pause");
	return 0;
}