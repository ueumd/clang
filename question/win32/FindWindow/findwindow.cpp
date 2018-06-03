#include <Windows.h>
#include<stdio.h>
/*
Win32控制台程序
*/
int main() {
	HWND hWnd = FindWindow(NULL, L"学习中心v3.3.5::需求列表 - 禅道"); //标题要一样

	if (hWnd) {
		Sleep(10);
		SendMessage(hWnd, WM_CLOSE, 0, 0);
		printf("OK");
		getchar();
		return 0;
	}

	printf("failed");
	getchar();
	return 0;
}