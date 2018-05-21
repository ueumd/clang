/*
CreateThread
_beginthreadex

SetThreadPriority
ExitThread
TerminateThread

ExitProcess
_endthreadex

1.�����̣߳� �޲�  CreateThread  _beginthreadex
2.�����̣߳� �в�   ���� �ַ��� �ṹ�� ����(���ö����Զ������) 
3.���̺߳�������
4.�������ȼ�  SetThreadPriority ResumeThread
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

	// ���� &str1
	hThread = CreateThread(NULL, NULL, ThreadPro, &coo1, 0, &dwThreadId);
	CloseHandle(hThread);

	HANDLE hThreadex;
	unsigned int iThreadIdex;

	// ���� &coo2
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
	//����ת��
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