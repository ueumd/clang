#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�
void getmem201(const char *p)
{
	p = 1;
	p = 3;
	// p[1] = 'a'; // �����ڴ����ݲ������޸�,����������޸� ���ʽ�Ǳ�����޸ĵ���ֵ
	return;
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

int main2()
{
	char *p1 = NULL;
	const char *p2 = NULL;
  constint();
	system("pause");
	return 0;
}