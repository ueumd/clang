#include<stdio.h>
#include<locale.h>

int main() {

	test2();
	system("pause");
	return 0;

}

int test2() {
	setlocale(LC_ALL, "zh-CN"); //��ʾ���� ����������ȷ��ʾ
	wchar_t wstr[10] = L"1234��������"; // ���ַ���wprintf
	wprintf(L"%ls", wstr); // ��дL��Сдl���ǿ��ַ�����
	
	return 0;
}