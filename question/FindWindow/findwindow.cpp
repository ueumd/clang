#include <Windows.h>
#include<stdio.h>
/*
Win32����̨����
*/
int main() {
	HWND hWnd = FindWindow(NULL, L"123 - ���±�"); //����Ҫһ��

	if (hWnd) {
		SendMessage(hWnd, WM_CLOSE, 0, 0);
		printf("OK");
		getchar();
		return 0;
	}

	printf("failed");
	getchar();
	return 0;
}