#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>

/*

WaitForSingleObject
WaitForMultipleObjects
1 主线程和子线程执行顺序
2 子线程间执行顺序
*/

DWORD WINAPI SetNum(LPVOID lpParam);
DWORD WINAPI GetResult(LPVOID lpParam);
int a = 10;
int b = 20;
int c = 0;

HANDLE hThreadex1;
HANDLE hThreadex2;

HANDLE hThreadex[2]; //数组

// 入口函数主线程
int main(int argc, char *argv[]) {

	
	unsigned int iThreadIdex;

	// 子线程
	hThreadex[0] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)GetResult, NULL, 0, &iThreadIdex);
	hThreadex[1] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)SetNum, NULL, 0, &iThreadIdex);

	//WaitForSingleObject(hThreadex1, INFINITE);
	//WaitForSingleObject(hThreadex2, INFINITE);

	DWORD errNO = WaitForMultipleObjects(2, hThreadex, true, INFINITE);// 2个 等待的数组 是否全部等待 时间

	//CloseHandle(hThreadex1);
	//CloseHandle(hThreadex2);

	CloseHandle(hThreadex[0]);
	CloseHandle(hThreadex[1]);
	
	printf("%d + %d = %d\n", a, b, c);

	system("pause");
	return 0;
}

DWORD WINAPI SetNum(LPVOID lpParam) {
	a = 100;
	b = 200;
	return 0;
}

DWORD WINAPI GetResult(LPVOID lpParam) {
	WaitForSingleObject(hThreadex[1], INFINITE); //等待下，这样主线程每次都是300，而不是有时候是30
	c = a + b;
	return 0;
}