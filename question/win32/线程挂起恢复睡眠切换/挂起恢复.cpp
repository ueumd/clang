/*----------------------------------------*/
/*
线程编码实战

需要用到的函数：
SuspendThread
ResumeThread
Sleep
SwitchToThread
GetTickCount64
GetThreadTimes
GetProcessTimes
GetThreadContext
SetThreadContext
1.创建线程，挂起线程，恢复线程   _beginthreadex
2.创建线程，线程睡眠
3.创建多线程，线程转换
4.创建线程，给线程记时  GetTickCount64  GetThreadTimes
5.创建进程，给进程记时  GetProcessTimes
6.取出和设置上下文     GetThreadContext  SetThreadContext

*/
/*----------------------------------------*/

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

DWORD WINAPI ThreadPro(LPVOID lpParam);

int main挂起恢复(void)
{
	HANDLE hThread;
	unsigned int iThreadIdex;
	hThread = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadPro, NULL, 0, &iThreadIdex);
	int count = 0;
	int count2 = 0;

	//挂起多次
	count = SuspendThread(hThread);
	printf("count = %d\n", count);
	count = SuspendThread(hThread);
	printf("count = %d\n", count);
	count = SuspendThread(hThread);
	printf("count = %d\n", count);
	count = SuspendThread(hThread);
	printf("count = %d\n", count);


	count2 = ResumeThread(hThread);
	printf("count2 = %d\n", count2);
	count2 = ResumeThread(hThread);
	printf("count2 = %d\n", count2);
	count2 = ResumeThread(hThread);
	printf("count2 = %d\n", count2);
	count2 = ResumeThread(hThread);
	printf("count2 = %d\n", count2);
	CloseHandle(hThread);
	system("pause");
	return 0;
}

DWORD WINAPI ThreadPro(LPVOID lpParam)
{
	for (int i = 0; i < 2; i++)
	{
		printf("hello\n");
	}
	return 0;
}