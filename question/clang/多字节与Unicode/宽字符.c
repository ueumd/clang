#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //���ػ�
#include<Windows.h>

void charAndChinese() {
	/*
	1 һ������ռ�����ֽ�
	2 �ַ���������ʾ���֣��ַ�������
	3 ����%c����һ�������ʾһ������
	*/
	char str[] = "�������Ϻ�";

	char c = '��'; //ASCCI�����û������ַ�,�ַ�ֻ����ASCCI�����

	printf("str = %s\n", str);				// str = �������Ϻ�
	printf("%c%c\n", str[0], str[1]); //��
	printf("c = %c\n", c);						//c = ? �κ�����¶������������
																		// printf("c = %s\n", c); error
}

//���ַ�
void testWchar_t() {
	wchar_t ch = L'��';					  // L ���ַ� || ���ַ���
	printf("%d\n", sizeof(ch));		// 2

	setlocale(LC_ALL, "chs");			// ��������

	wprintf(L"%wc\n", ch);			  // ����� ����Ҫ�������԰汾����Ϊ������������
	//printf(L"%wc\n", ch);       // printf���ܴ�ӡ���ַ�

	wchar_t str[100] = L"����һ������ABC";	
	wprintf(L"str = %s\n", str);		// str = ����һ������ABC
	printf("%d\n", wcslen(str));		// 9
}

// ���� ������������ֵ�ʱ�� һ�����־���һ���ַ�
void testWchar_t2() {
	setlocale(LC_ALL, "chs");
	wchar_t ch1 = L'��';
	wchar_t ch2 = L'��';
	wchar_t ch3 = L'A';

	wprintf(L"%wc%wc%wc\n" , ch1, ch2, ch3); // ����A
}

void main()
{

	// charAndChinese();

	testWchar_t();
	testWchar_t2();

	//printf("�������Ϻ�\n");

	// 1 ʹ�ö��ֽ��ַ���������ʾ ʹ��Unicodeʱ������ʾ
	MessageBox(0, "�������Ϻ�", "����", 0); 
	  
	// 1 ʹ��Unicode�ַ���ʱ������ʾ ���ֽ��ַ���������ʾ
	MessageBox(0, L"�������Ϻ�", L"����", 0);

	MessageBoxW(0, L"�������Ϻ�", L"����", 0); //������

	system("pause");

}