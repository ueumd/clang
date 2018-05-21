/*
CreateThread
_beginthreadex

SetThreadPriority
ExitThread
TerminateThread

ExitProcess
_endthreadex

1.创建线程， 无参  CreateThread  _beginthreadex
2.创建线程， 有参   整型 字符串 结构体 对象(内置对象，自定义对象) 
3.给线程函数传参
4.设置优先级  SetThreadPriority ResumeThread
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
#include <string>
#include <iostream>
using namespace std;

DWORD WINAPI ThreadPro(LPVOID lpParam);
DWORD WINAPI ThreadProex(LPVOID lpParam);

class Coor {
public:
	Coor(int iX, int iY) {
		m_ix = iX;
		m_iy = iY;
		cout << m_ix << "-------------" << m_iy << endl;
	}
	~Coor() {
		cout << m_ix << "~~~~~~~~~~~~~" << m_iy << endl;
	}
	void printCoor() {
		cout << m_ix << "," << m_iy << endl;
	}
private:
	int m_ix;
	int m_iy;
};

int main(int argc, char *argv[]) {

	DWORD dwThreadId = 0;
	HANDLE hThread;

	int x = 20;
	int y = 40;

	Coor coo1(4, 5);
	Coor coo2(20, 80);

	string str1 = "hello";
	string str2 = "123456";

	string *pStr3 = new string("hello AAA");
	string *pStr4 = new string("123456 BBB");

	// 传参 &str1
	hThread = CreateThread(NULL, NULL, ThreadPro, &coo1, 0, &dwThreadId);
	CloseHandle(hThread);

	HANDLE hThreadex;
	unsigned int iThreadIdex;

	// 传参 &coo2
	hThreadex = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadProex, &coo2, 0, &iThreadIdex);
	Sleep(10);
	CloseHandle(hThreadex);

	system("pause");
	return 0;
}

DWORD WINAPI ThreadPro(LPVOID lpParam) {
	Coor *p = (Coor *)lpParam;
	p->printCoor();
	ExitThread(1);
	//类型转换
	//string *p = (string *)lpParam;
	//cout << *p << endl;

	return 0;
}

DWORD WINAPI ThreadProex(LPVOID lpParam) {
	Coor *p = (Coor *)lpParam;
	p->printCoor();
	_endthreadex(1);
	return 0;
}