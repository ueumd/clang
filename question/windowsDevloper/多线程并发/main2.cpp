/*
CreateThread
_beginthreadex

SetThreadPriority
ExitThread
TerminateThread

ExitProcess
_endthreadex

1.创建线程，无参  CreateThread  _beginthreadex
2.创建线程，有参
3.给线程函数传参
4.设置优先级
5.创建多个不同优先级线程
6.在线程中添加对象，看线程退出时是否执行了析构函数
7.ExitThread，_endthreadex线程，看线程退出时是否执行了析构函数
8.TerminateThread线程，看线程退出时是否执行了析构函数
9.ExitProcess进程，看线程退出时是否执行了析构函数

*/

/*
HANDLE  WINAPI  CreateThread(
	LPSECURITY_ATTRIBUTES  lpThreadAttributes,   // 线程内核对象的安全属性，一般传入NULL表示使用默认设置
	SIZE_T  dwStackSize,												 // 线程栈空间大小。传入0表示使用默认大小（1MB）
	LPTHREAD_START_ROUTINE  lpStartAddress,      // 新线程所执行的线程函数地址，多个线程可以使用同一个函数地址
	LPVOID  lpParameter,                         // 传给线程函数的参数
	DWORD  dwCreationFlags,                      // 指定额外的标志来控制线程的创建，为0表示线程创建之后立即就可以进行调度，如果为CREATE_SUSPENDED则表示线程创建后暂停运行，这     样它就无法调度，直到调用ResumeThread()
	LPDWORD  lpThreadId                          // 返回线程的ID号，传入NULL表示不需要返回该线程ID号
);
函数返回值：成功返回新线程的句柄，失败返回NULL

尽量使用_beginthreadex()来代替使用CreateThread()

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