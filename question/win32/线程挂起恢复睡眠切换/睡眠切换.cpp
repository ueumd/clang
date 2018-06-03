/*----------------------------------------*/
/*
�̱߳���ʵս

��Ҫ�õ��ĺ�����
SuspendThread
ResumeThread
Sleep
SwitchToThread
GetTickCount64
GetThreadTimes
GetProcessTimes
GetThreadContext
SetThreadContext
1.�����̣߳������̣߳��ָ��߳�   _beginthreadex
2.�����̣߳��߳�˯��  Sleep   SwitchToThread  SetThreadPriority
3.�������̣߳��߳�ת��
4.�����̣߳����̼߳�ʱ  GetTickCount64  GetThreadTimes
5.�������̣������̼�ʱ  GetProcessTimes
6.ȡ��������������     GetThreadContext  SetThreadContext



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