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
2.�����̣߳��߳�˯��
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

DWORD WINAPI ThreadPro(LPVOID lpParam);

int main����ָ�(void)
{
	HANDLE hThread;
	unsigned int iThreadIdex;
	hThread = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadPro, NULL, 0, &iThreadIdex);
	int count = 0;
	int count2 = 0;

	//������
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