#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�
char * getmem201(const char *p)
{
	p = 1;
	p = 3;
	// p[1] = 'a'; // �����ڴ����ݲ������޸�,����������޸� ���ʽ�Ǳ�����޸ĵ���ֵ
	return p;
}

// ��ָ�루ָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸ģ�
void getmem202(char *const p)
{
	// p = 250; // �������ǲ������޸ĵ� ���ʽ�Ǳ�����޸ĵ���ֵ
	p[1] = 'a';
	return;
}

// ָ�������ָ����ڴ�ռ䣬�����ܱ��޸�
void getmen203(const char *const p)
{
	//p = 1;
	//p = 3;
	//p[1] = a;
	printf("%c", p[1]);
	return;
}

//����C�����е�const���εı��� �Ǽٵ� C�����е�const ��һ��ð�ƻ�
void constint()
{
	const int a = 10;
	//a = 11; error
	{
		int *p = &a;
		*p = 100;
		printf("a:%d\n", a); //a:100								
	}
}

int main()
{
	char *p1 = NULL;
	const char *p2 = NULL;
 // constint();

	char buf[7] = "3.1415";
	char cbuf[] = "AAAA";
	char * const PI = cbuf;
	const char *PI2 = cbuf;
	const char * const PI3 = "3.1415";

	buf[0] = '4';
	PI[0] = 'G'; 
	// PI = "aaa";ָ��������������޸�
	PI2="AA";
	// PI2 ��ָ��ָ��Ŀռ���� �������ǲ������޸�
	// PI2[1] = 'G';
	// *PI2 = 'G'; 

	// PI3 = "BBB"; // ֻ��

	printf("buf=%s\n", buf); //4.1415
	printf("PI=%s\n", PI);	 //GAAA
	printf("PI2=%s\n", PI2); //AA
	printf("PI3=%s\n", PI3); //3.1415

	system("pause");
	return 0;
}