#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getNum() {
	return 100;
}

//��ʼ��
void constBae()
{
	int n = 90;
	const int MaxNum1 = getNum();  //����ʱ��ʼ��
	const int MaxNum2 = n;         //����ʱ��ʼ��
	const int MaxNum3 = 80;        //����ʱ��ʼ��
  //MaxNum2 = 200;���� ������Ͳ������޸���
	printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);
}

void constAndPointer()
{
	int x = 10, y = 20;

	//ֻ�������޸�
	const int * const p4 = &x;
	int const * const p5 = &y;

	{
		
		// ����һ��,��ʼ��ʱ����Ҫ��ֵ�����治�����ٴθ�ֵ
		const int a;  
		int const b;

		/*const��ָָ  ҪŪ��� ���ε��Ǳ��� �����ڴ�ռ�*/

		char *const p = "ABC";	 //const���ε���ָ�����, �����ܱ��޸ģ��������ݿ����޸ģ��ȼ��� char d[100];
		//d = 1;
		p[0] = 'D';

		const char *c ='A';   //ָ��ָ����ڴ�ռ䲻�����޸ģ����ǿ��Ը�ָ�븳ֵ
		//c[1] = 1;
		c = 1;

		const char * const e; //������ֻ��
		/*
		��һ���ڶ�����˼һ������һ���������� ͨ��ָ������޸�
		������ d ��ָ�루ָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸ģ�
		���ĸ� c��һ��ָ����������ָ��(��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�)
		����� eһ��ָ�����εĳ�ָ�루ָ�������ָ����ڴ�ռ䣬�����ܱ��޸ģ�

		���䷽��
		const 
		������� �� ���� ָ�����,	    �����ܱ��޸�		�ռ����ݿ����޸�
		������� Զ ���� ָ��ָ��ռ䣬  ������Ա��޸�   �ռ����ݲ����޸�
		���ĺ�Զ�Ķ��У�ֻ��

		��constλ��*����߻����ұ� , ���������ָ����ڴ�ռ���� �ұ�����ָ���������
		*/
	}

	{
		/*
		��C�����У��������� const ����û�����Ե����ƣ���ȫ����ʹ��#define������档

		const ͨ�����ں����β��У�����β���һ��ָ�룬Ϊ�˷�ֹ�ں����ڲ��޸�ָ��ָ������ݣ��Ϳ����� const �����ơ�
		��C���Ա�׼���У��кܶຯ�����βζ��� const �����ˣ������ǲ��ֺ�����ԭ�ͣ�
		*/
		/*size_t strlen(const char * str);
		int strcmp(const char * str1, const char * str2);
		char * strcat(char * destination, const char * source);
		char * strcpy(char * destination, const char * source);
		int system(const char* command);
		int puts(const char * str);
		int printf(const char * format, ...);*/
	}

}

//ʹ�� const ���βμ������ƣ���������ַ�����ĳ���ַ����ֵĴ�����
size_t strnchr(const char * const str, char ch) {
	// str[1] = 's';     // ���������const ���� ���Ըı� ʵ�����ڴ�ռ������ �β�Ҳ��ı�
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

int main11()
{
	constAndPointer();


	system("pause");
	return 0;
}