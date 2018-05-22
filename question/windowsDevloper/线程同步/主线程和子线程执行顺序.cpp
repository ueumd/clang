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

DWORD WINAPI ThreadProx(LPVOID lpParam);

// 入口函数主线程
int main主线程和子线程执行顺序(int argc, char *argv[]) {

	HANDLE hThreadex;
	unsigned int iThreadIdex;

	// 子线程
	hThreadex = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadProx, NULL, 0, &iThreadIdex);

	//等待子线程打印完毕再打印主线程， 不加就是hello world交叉打印
	DWORD errNo = WaitForSingleObject(hThreadex, INFINITE);//等待子线程结束  0    //hThreadex, 1   258超时？

	printf("%d\n", errNo); // 0

	CloseHandle(hThreadex);

	for (int i = 0; i < 20; i++)
	{
		printf("world\n");
	}

	system("pause");
	return 0;
}

DWORD WINAPI ThreadProx(LPVOID lpParam) {
	for (int i = 0; i < 20; i++) {
		printf("hello\n");
	}
	return 0;
}