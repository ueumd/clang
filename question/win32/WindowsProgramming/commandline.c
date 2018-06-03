#include<Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	LPWSTR *szArgList;
	int argCount;

	szArgList = CommandLineToArgvW(GetCommandLineW(), &argCount);
	if (szArgList == NULL)
	{
		MessageBox(NULL, L"Unable to parse command line", L"Error", MB_OK);
		return 10;
	}

	for (int i = 0; i < argCount; i++)
	{
		MessageBox(NULL, szArgList[i], L"Arglist contents", MB_OK);
	}

	LocalFree(szArgList);
	return 0;
}