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
2.创建线程，线程睡眠  Sleep   SwitchToThread  SetThreadPriority
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

DWORD WINAPI ThreadPro1(LPVOID lpParam);
DWORD WINAPI ThreadPro2(LPVOID lpParam);

int main(void)
{
	HANDLE hThread1;
	unsigned int iThreadIdex1;
	hThread1 = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadPro1, NULL, 0, &iThreadIdex1);
	SetThreadPriority(hThread1, THREAD_PRIORITY_ABOVE_NORMAL);
	CloseHandle(hThread1);

	HANDLE hThread2;
	unsigned int iThreadIdex2;
	hThread2 = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadPro2, NULL, 0, &iThreadIdex2);
	SetThreadPriority(hThread2, THREAD_PRIORITY_BELOW_NORMAL);
	CloseHandle(hThread2);
	system("pause");
	return 0;
}

DWORD WINAPI ThreadPro1(LPVOID lpParam)
{
	for (int i = 0; i < 100; i++)
	{
		Sleep(INFINITE);
		printf("hello\n");

		//SwitchToThread();
	}
	return 0;
}

DWORD WINAPI ThreadPro2(LPVOID lpParam)
{
	for (int i = 0; i < 100; i++)
	{
		printf("world\n");
		Sleep(1000);
		//SwitchToThread();
	}
	return 0;
}