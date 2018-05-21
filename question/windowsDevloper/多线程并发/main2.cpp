/*
CreateThread
_beginthreadex

SetThreadPriority
ExitThread
TerminateThread

ExitProcess
_endthreadex

1.�����̣߳��޲�  CreateThread  _beginthreadex
2.�����̣߳��в�
3.���̺߳�������
4.�������ȼ�
5.���������ͬ���ȼ��߳�
6.���߳�����Ӷ��󣬿��߳��˳�ʱ�Ƿ�ִ������������
7.ExitThread��_endthreadex�̣߳����߳��˳�ʱ�Ƿ�ִ������������
8.TerminateThread�̣߳����߳��˳�ʱ�Ƿ�ִ������������
9.ExitProcess���̣����߳��˳�ʱ�Ƿ�ִ������������

*/

/*
HANDLE  WINAPI  CreateThread(
	LPSECURITY_ATTRIBUTES  lpThreadAttributes,   // �߳��ں˶���İ�ȫ���ԣ�һ�㴫��NULL��ʾʹ��Ĭ������
	SIZE_T  dwStackSize,												 // �߳�ջ�ռ��С������0��ʾʹ��Ĭ�ϴ�С��1MB��
	LPTHREAD_START_ROUTINE  lpStartAddress,      // ���߳���ִ�е��̺߳�����ַ������߳̿���ʹ��ͬһ��������ַ
	LPVOID  lpParameter,                         // �����̺߳����Ĳ���
	DWORD  dwCreationFlags,                      // ָ������ı�־�������̵߳Ĵ�����Ϊ0��ʾ�̴߳���֮�������Ϳ��Խ��е��ȣ����ΪCREATE_SUSPENDED���ʾ�̴߳�������ͣ���У���     �������޷����ȣ�ֱ������ResumeThread()
	LPDWORD  lpThreadId                          // �����̵߳�ID�ţ�����NULL��ʾ����Ҫ���ظ��߳�ID��
);
��������ֵ���ɹ��������̵߳ľ����ʧ�ܷ���NULL

����ʹ��_beginthreadex()������ʹ��CreateThread()

uintptr_t _beginthread(
	void			(*start_address )( void * ),
	unsigned	stack_size,
	void			*arglist
);

uintptr_t _beginthreadex(
	void			*security,
	unsigned	stack_size,
	unsigned	( *start_address )( void * ),
	void			*arglist,
	unsigned	initflag,
	unsigned	*thrdaddr
);
*/

#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>

DWORD WINAPI ThreadPro(LPVOID lpParam);
DWORD WINAPI ThreadProex(LPVOID lpParam);

int main(int argc, char *argv[]) {
	
	DWORD dwThreadId = 0;
	HANDLE hThread;
	hThread = CreateThread(NULL, NULL, ThreadPro, NULL, 0, &dwThreadId);
	CloseHandle(hThread);

	HANDLE hThreadex;
	unsigned int iThreadIdex;
	hThreadex = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadProex, NULL, 0, &iThreadIdex);
	Sleep(10);
	CloseHandle(hThreadex);


	for (int i = 0; i < 2; i++)
	{
		printf("world\n");
	}

	system("pause");
	return 0;
}

DWORD WINAPI ThreadPro(LPVOID lpParam) {
	for (int i = 0; i < 5; i++) {
		printf("hello\n");
	}
	return 0;
}

DWORD WINAPI ThreadProex(LPVOID lpParam) {
	for (int i = 0; i < 5; i++) {
		printf("_beginthreadex\n");
	}
	return 0;
}