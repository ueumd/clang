#include "iostream"
#include <stdio.h>
#include <string.h>
using namespace std;

//ָ�����
void pointerBase()
{
	int abc = 100;

	int *p5 = NULL;
	//*p5 = 200;//��ָ���ڴ���������0X00000000  �������ϵͳ���� ����ֱ������ֵ��ֻ�ܽ��ڱ����ĵ�ַ

	p5 = &abc;

	int i = 10; 
	int *p=NULL;// ������һ��ָ��int���͵� ָ�����(ֻ�ܴ� �����ĵ�ַ)

	//p = 10;���󣬲����԰�һ������ֱ�Ӹ�ֵ�� ָ�����
	//C������ÿ�����������ڴ��ַ��&��ž���ȡ������ַ
	&i;//ȡ����i�ĵ�ַ
	p = &i;//�� ָ�����p ָ�� i�ĵ�ַ

	*p = 100;//��p ָ����ڴ������ֵ��ֵΪ100����i=100;

	printf("i:%d, p:%d\n", i,*p);

	int *p1 = &i;

	int a = *p;//*������c������ ָ�� ָ�� �ڴ�� ֵ

	printf("i:%d, p:%d, a:%d\n", i, *p, a);

	int b = NULL; //0
	int *p2 = NULL;//��ָָ ָ���ڴ������������0
	int ab = 10;
	char c = 'a';

	/*
	����һ��ָ�� int���͵� ָ����� ��û�и���ֵ������һ��Ұָ�룬ָ��ʲô�ڴ治֪��
	Ұָ��Σ���ܴ�
	*/
	int *p3; 
	//*p3 = 10;//���� Ұָ��Ҳ������ָ�룬���ܸ�Ұָ��ָ����ڴ�����ֵ
	// p3 = &c; //���� char => int
	p3 = &ab; //?�����ܱ���ͨ��~~~ ���ݣ�

	printf("*p3:%d\n" ,*p3); //10

	/*
	������ָ�� C�п��Խ��κε�һ�ֵ�ַ��ֵ��������ָ��
	������ָ����ʹ��ʱ����ǿת
	*/
	void *p4;//������һ�������͵�ָ��

	p4 = &c;

	//printf("*p4:%d\n", *p4); //���� ��Ȼǰ���Ѿ���&c�ڴ��ַ��p4������ʹ�õ�ʱ��֪��ָ��ʲô���͵�����,����ǿת
	printf("*p4:%d\n", *(char *)p4); //��ת��char����ָ��(char *) ��ͨ��ָ��ȥ��ָ�������ָ����ڴ�ռ�

	
}

void pointerArray()
{

}

//�ַ����� char[]
void pointerChar()
{
	//�ַ���������׻���һ������
	char str[] = "http://c.biancheng.net";
	char *pstr = str;
	int len = strlen(str), i;

	printf("%s\n", str);

	//ʹ��*(pstr+i)
	for (i = 0; i<len; i++) {
		printf("%c", *(pstr + i));
	}
	printf("\n");

	//ʹ��pstr[i]
	for (i = 0; i<len; i++) {
		printf("%c", pstr[i]);
	}
	printf("\n");

	//ʹ��*(str+i)
	for (i = 0; i<len; i++) {
		printf("%c", *(str + i));
	}
	printf("\n");

}

//�ַ���
void pointerString()
{
	/*�����ַ����飬C���Ի�֧������һ�ֱ�ʾ�ַ����ķ���������ֱ��ʹ��һ��ָ��ָ���ַ��������磺

	�ַ����е������ַ����ڴ������������еģ�
	str ָ������ַ����ĵ� 0 ���ַ���
	����ͨ������ 0  ���ַ��ĵ�ַ��Ϊ�ַ������׵�ַ��
	�ַ�����ÿ���ַ������Ͷ���char������ str ������Ҳ������char *��
	*/

	/*
	char *str;
	str = "http://c.biancheng.net";

	//���ǽ�������ʽ���ַ�����Ϊ�ַ�������,�ַ�����˫����
	*/ 

	//�ȼ���
	char *str = "http://c.biancheng.net2";

	//int *p = 200;error ���ܳ�ʼ�� 

	int len = strlen(str), i;

	//ֱ�����
	printf("%s\n", str);

	for (i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	for (i = 0; i < len; i++)
	{
		printf("%c", *(str+i));
	}
	printf("\n");

	/*
	�ַ��������ַ���������

	��������������������ڴ��еĴ洢����һ�����ַ�����洢��ȫ����������ջ�����ڶ�����ʽ���ַ����洢�ڳ�������
	ȫ����������ջ�����ַ�����Ҳ�����������ݣ�  �ж�ȡ��д���Ȩ�ޣ�
	�����������ַ�����Ҳ�����������ݣ�ֻ�ж�ȡȨ�ޣ� û��д��Ȩ�ޡ����ǽ��ڶ�����ʽ���ַ�����Ϊ�ַ�������
	*/

	{
		char *str2 = "Hello World!"; //������
		str2 = "I love C!";  //��ȷ
		//str2[3] = 'P';  //���� ֻ�ܶ� ����д��
		printf("%s\n", str2);

		char str3[] = "http://c.biancheng.net";//ȫ����������ջ��
		str3[3] = 's';
		printf("%s\n", str3); //htts://c.biancheng.net

	}
}

void main81()
{
	//pointerBase();
	pointerChar();
	//pointerString();

	cout << "hello..." << endl;

	system("pause");
	return;
}

/*---------------------------------------------ָ�뺯�� - ����ָ��-------------------------------------------------------------*/

//ָ�뺯��: C�����������ķ���ֵ��һ��ָ�루��ַ�������ǽ������ĺ�����Ϊָ�뺯�� 
char *strlong(char *str1, char *str2)
{
	if (strlen(str1) > strlen(str2))
	{
		return str1;
	}
	else
	{
		return str2;
	}
}


//�����������нϴ��һ��
int max(int a, int b)
{
	return a>b ? a : b;
}

//ָ�������Ϊ��������
void swap(int *p1, int *p2)
{
	int temp;//��ʱ����
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

}

int pointerMax2(int *a, int *b)
{
	return *a >*b ? *a : *b;
}

int main82() {
	char str1[30] = "abcefg";
	char str2[30] = "xyz1";

	char *str;

	//ָ�뺯��
	str = strlong(str1, str2);
	/*
		char *str
		str="abcdefg"	
	*/

	printf("Longer string: %s\n", str);


	int a = 100, b = 200;
	int x = 10, y = 30;

	//swap ָ�������Ϊ��������
	printf("a:%d, b:%d\n", a, b);
	swap(&a,&b);

	printf("a:%d, b:%d\n", a, b);

	int zz = pointerMax2(&x, &y);
	printf("x:%d, y:%d, zz:%d\n", x, y, zz);

	//����ָ��  ������ʽ  returnType (*pointerName)(param list);
	/*
		returnType Ϊ��������ֵ���ͣ�
		pointerNmae Ϊָ�����ƣ�
		param list Ϊ���������б�
		�����б��п���ͬʱ�������������ͺ����ƣ�Ҳ����ֻ�������������ͣ�ʡ�Բ��������ƣ���һ��ͺ���ԭ�ͷǳ����ơ�
	*/
	

	int (*pointerMax)(int a, int b) = max;
	int z = (*pointerMax)(x, y);
	printf("x:%d, y:%d, z:%d\n", x,y,z);



	system("pause");
	return 0;
}


/*---------------------------------------------cosnt and pointer-------------------------------------------------------------*/
//const
int getNum() {
	return 100;
}

void constBae()
{

	int n = 90;
	const int MaxNum1 = getNum();  //����ʱ��ʼ��
	const int MaxNum2 = n;  //����ʱ��ʼ��
	const int MaxNum3 = 80;  //����ʱ��ʼ��

	//MaxNum2 = 200;���� ������Ͳ������޸���
	printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);
}

void constAndPointer()
{
	int a = 10, b = 20;

	const int *p1;
	int const *p2;
	int * const p3 = &a; //c++�б���Ҫ��ʼ��

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

	/*
	���䷽��
	const ����������������� ���� ָ�����
	�� ������ Զ �������� ���� ָ��ָ�������
	��� ���ĺ�Զ�� ���У���ô�� ͬʱ ���� ָ����� �Լ��� ָ�������
	*/

}

void constAndPointerParameter()
{
	/*
	��C�����У��������� const ����û�����Ե����ƣ���ȫ����ʹ��#define������档
	const ͨ�����ں����β��У�����β���һ��ָ�룬Ϊ�˷�ֹ�ں����ڲ��޸�ָ��ָ������ݣ��Ϳ����� const �����ơ�

	��C���Ա�׼���У��кܶຯ�����βζ��� const �����ˣ������ǲ��ֺ�����ԭ�ͣ�
	size_t strlen(const char * str);
	int strcmp(const char * str1, const char * str2);
	char * strcat(char * destination, const char * source);
	char * strcpy(char * destination, const char * source);
	int system(const char* command);
	int puts(const char * str);
	int printf(const char * format, ...);

	*/
	
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

//const �ͷ� const ����ת��
/*
Ҳ����˵��const char *��char *�ǲ�ͬ�����ͣ����ܽ�const char *���͵����ݸ�ֵ��char *���͵ı�����
���������ǿ��Եģ�����������char *���͵����ݸ�ֵ��const char *���͵ı�����

�������ƺ�������⣬char *ָ��������ж�ȡ��д��Ȩ�ޣ�
��const char *ָ�������ֻ�ж�ȡȨ�ޣ��������ݵ�Ȩ�޲�������κ����⣬���������ݵ�Ȩ�޾��п��ܷ���Σ�ա�
*/

void func(char *str) { }
int main()
{
	constBae();

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


	system("pause");
	return 0;
}