#include <Windows.h>
#include "resource.h"

INT_PTR CALLBACK Login(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Login);
	return 0;
}

INT_PTR CALLBACK Login(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		// 确定
		if (LOWORD(wParam) == IDOK)
		{
			WCHAR username[32];
			WCHAR password[32];
			GetDlgItemText(hDlg, USERNAME, username, 32);
			GetDlgItemText(hDlg, IDPASSWORD, password, 32);

			if (!wcscmp(username, L"admin") && !wcscmp(password, L"123"))
			{
				MessageBox(hDlg, L"success", L"message", MB_OK);
			}
			else
			{
				MessageBox(hDlg, L"failed", L"message", MB_OK);
			}
			//EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}

		//取消
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}

		break;
	}
	return (INT_PTR)FALSE;
}