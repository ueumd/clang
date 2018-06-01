#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//const
int getNum() {
	return 100;
}

//��ʼ��
void constBae()
{
	int n = 90;
	const int MaxNum1 = getNum();  //����ʱ��ʼ��
	const int MaxNum2 = n;         //����ʱ��ʼ��
	const int MaxNum3 = 80;       //����ʱ��ʼ��
  //MaxNum2 = 200;���� ������Ͳ������޸���
	printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);
}

void constAndPointer()
{
	int a = 10, b = 20;

	const int *p1; //�������p1�� �����ε���ָ��ָ������ݲ��ܱ��޸ģ���ָ�뱾��ָ������޸�
	int const *p2;
	int * const p3 = &a;  // ����ָ��

	p1 = &a;
	p2 = &a;

	p1 = &b;
	p2 = &b;

	/*
	����
	*p1 = 20;
	*p2 = 20;
	 p3 = 100;
	 p3 = &b;
	*/

	/*
	�����һ������£�ָ����ֻ���ģ�Ҳ���� p3 �����ֵ���ܱ��޸ģ�
	��ǰ����������£�ָ����ָ���������ֻ���ģ�Ҳ���� p1��p2 �����ֵ�����޸ģ�ָ��ͬ�����ݣ���������ָ������ݲ��ܱ��޸ġ�
	*/

	//ֻ�������޸�
	const int * const p4 = &a;
	int const * const p5 = &b;

	{
		const int a;  //
		int const b;

		const char *c;
		char * const d; char buf[100];
		const char *const e;
		/*
		��һ���ڶ�����˼һ������һ���������� ͨ��ָ������޸�

		������ c��һ��ָ����������ָ��(��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�)
		���ĸ� d ��ָ�루ָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸ģ�
		����� eһ��ָ�����εĳ�ָ�루ָ�������ָ����ڴ�ռ䣬�����ܱ��޸ģ�

		���䷽��
		const ����������������� ���� ָ�����
		�� ������ Զ �������� ���� ָ��ָ�������
		��� ���ĺ�Զ�� ���У���ô�� ͬʱ ���� ָ����� �Լ��� ָ�������
		*/
	}

	{
		/*
		��C�����У��������� const ����û�����Ե����ƣ���ȫ����ʹ��#define������档

		const ͨ�����ں����β��У�����β���һ��ָ�룬Ϊ�˷�ֹ�ں����ڲ��޸�ָ��ָ������ݣ��Ϳ����� const �����ơ�
		��C���Ա�׼���У��кܶຯ�����βζ��� const �����ˣ������ǲ��ֺ�����ԭ�ͣ�
		*/
		size_t strlen(const char * str);
		int strcmp(const char * str1, const char * str2);
		char * strcat(char * destination, const char * source);
		char * strcpy(char * destination, const char * source);
		int system(const char* command);
		int puts(const char * str);
		int printf(const char * format, ...);
	}

}

//ʹ�� const ���βμ������ƣ���������ַ�����ĳ���ַ����ֵĴ�����
size_t strnchr(const char * const str, char ch) {
	// str[1] = 's'; //���������const ���� ���Ըı� ʵ�����ڴ�ռ������ �β�Ҳ��ı�
	//str = "I Love C"; //������const˫������ strֻ�ܶ�
	int i, n = 0, len = strlen(str);

	for (i = 0; i<len; i++) {
		if (str[i] == ch) {
			n++;
		}
	}

	return n;
}

/*
const �ͷ� const ����ת��
Ҳ����˵��const char *��char *�ǲ�ͬ�����ͣ����ܽ�const char *���͵����ݸ�ֵ��char *���͵ı�����
���������ǿ��Եģ�����������char *���͵����ݸ�ֵ��const char *���͵ı�����

�������ƺ�������⣬char *ָ��������ж�ȡ��д��Ȩ�ޣ�
��const char *ָ�������ֻ�ж�ȡȨ�ޣ��������ݵ�Ȩ�޲�������κ����⣬���������ݵ�Ȩ�޾��п��ܷ���Σ�ա�
*/

void func(char *str) { }


void test() {
	char str[] = "http://c.biancheng.net";
	char ch = 't';
	int n = strnchr(str, ch);
	printf("%d\n", n);
	printf("%s\n", str);

	const char *str1 = "c.biancheng.net";
	//char *str2 = str1; // const ��ֵ���� const
	//func(str1); // const ��ֵ���� const

	char *str2 = "Hello";
	str1 = str2; //�� const ��ֵ��  const����
	printf("%s\n", str2);
}

int main()
{
	constAndPointer();



	system("pause");
	return 0;
}