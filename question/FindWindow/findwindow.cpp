#include <Windows.h>
#include<stdio.h>
/*
Win32控制台程序
*/
int main() {
	HWND hWnd = FindWindow(NULL, L"123 - 记事本"); //标题要一样

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