#include<Windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE prevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	int argCount = 0;
	LPWSTR *szArgList = CommandLineToArgvW(GetCommandLineW(), &argCount);

	if (NULL == szArgList) {
		MessageBox(NULL, L"Unable to parse command line", L"Error", MB_OK);
		return 10;
	}

	for (int i = 0; i < argCount; i++) {
		MessageBox(NULL, szArgList[i], L"arg", MB_OK);
	}

	LocalFree(szArgList);
	return 0;
}