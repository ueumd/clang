#include<stdio.h>
#include<stdlib.h>

/*
#define ���� �ַ���
�������ĺ�ͺ��������ƣ����б����ϵ�����
��չ���������ַ������滻������Ա��ʽ���м��㣻���ڱ���֮ǰ�ͱ�������ˣ���û�л��������룬Ҳ����ռ���ڴ档
��������һ�ο����ظ�ʹ�õĴ��룬�ᱻ���룬����������ڴ棬ÿ�ε��ú���������ִ������ڴ��еĴ��롣
*/
#define PI 3.1415926

#define M (n*n+3*n) 
#define MAX(a,b) (a>b)?a:b

int definefn()
{
	int n = 10, sum;
	sum = 3 * M + 4 * M + 5 * M;
	printf("sum=%d\n", sum);//1560

	int max, a = 10, b = 5;
	max = MAX(a, b); //�����ֻ�Ǽ򵥵��ַ����滻 max=(a>b)?a:b
	printf("max=%d\n", max);//10
	return 0;
}

int ansic()
{
	/*

	ANSI C �涨�����¼���Ԥ����꣬�����ڸ����������¶�����ʹ�ã�
	__LINE__����ʾ��ǰԴ������кţ�
	__FILE__����ʾ��ǰԴ�ļ������ƣ�
	__DATE__����ʾ��ǰ�ı������ڣ�
	__TIME__����ʾ��ǰ�ı���ʱ�䣻
	__STDC__����Ҫ������ϸ���ѭANSI C��׼ʱ�ñ�ʶ����ֵΪ1��
	__cplusplus������дC++����ʱ�ñ�ʶ�������塣
	*/
	printf("Date : %s\n", __DATE__);
	printf("Time : %s\n", __TIME__);
	printf("File : %s\n", __FILE__);
	printf("Line : %d\n", __LINE__);
	return 0;
}

int ifendiffn()
{
	//#if��#elif��#else �� #endif ����Ԥ��������
	/*
	#if ���������������ʽΪ��

	#if ���ͳ������ʽ1
		�����1
	#elif ���ͳ������ʽ2    (��ʡ)
		�����2
	#elif ���ͳ������ʽ3
		�����3
	#else                    ����ʡ��
		�����4
	#endif
	*/

	#if __WIN32
		system("color 0c");
		printf("http://c.biancheng.net\n");
	#elif __linux
		printf("\033[22;31mhttp://c.biancheng.net\n\033[22;30m");
	#else 
		printf("http://c.biancheng.net\n");
	#endif

	return 0;
}


int ifdeffn() 
{
	/*
	�����ǰ�ĺ��ѱ����������ԡ������1�����б��룬����ԡ������2�����б��롣
	#ifdef ����ĸ�ʽΪ��
	#ifdef  ����
		�����1
	#else
		�����2
	#endif
	*/

	#ifdef _DEBUG
		printf("����ʹ�� Debug ģʽ�������...\n");
	#else
		printf("����ʹ�� Release ģʽ�������...\n");
	#endif

	return 0;
}
/*
����
#if ��������ǡ����ͳ������ʽ��      #if NUM == 10 || NUM == 20
#ifdef �� #ifndef �������ֻ����һ�������������������ġ�
*/

int errorfn()
{
	#ifdef WIN32
	#error This programme cannot compile at Windows Platform
	#endif
	return 0;
}

int main()
{

	definefn();
	ansic();
	ifendiffn();
	ifdeffn();
	errorfn();
	system("pause");
	return 0;
}