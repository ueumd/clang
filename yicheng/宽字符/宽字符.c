#include<stdio.h>
#include<Windows.h>

int main1() {

	printf("��ʾ��ΧС");

	char ch = 'A'; // ��ʾ��ΧС����Լ�ڴ�
	wchar_t ch1 = L'A'; //��ڷ�2���ֽڣ���ʾ��Χ

	printf("%d, %d \n", sizeof(char), sizeof(wchar_t)); // 1 2
	printf("%d, %d \n", sizeof(ch), sizeof(ch1));		// 1 2
	
	printf("%d", sizeof("1��")); //4���ֽ�
	printf("\n%d", sizeof(L"1��"));//6���ֽ� 

	// MessageBox(0, "Hello World", "Title1", 0); �������й� unicodeΪ���ַ� �����ֽ�Ϊխ�ַ�  ��TEXT�����Զ�����

	MessageBox(0, L"Hello World", L"Title1", 0);



	// TEXT���Լ����Զ�����
	MessageBox(0, TEXT("Hello World"), TEXT("Title2"), 0);

	// A ������ö��ֽ� խ�ַ�
	//MessageBoxA(0, "����쳯","�������", 0);

	// W ��������ַ�
	//MessageBoxW(0, L"����쳯", L"�������", 0);

	return 0;
}