#include <Windows.h>
#include<stdio.h>
/*
Win32����̨����
*/
int main() {
	HWND hWnd = FindWindow(NULL, L"ѧϰ����v3.3.5::�����б� - ����"); //����Ҫһ��

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