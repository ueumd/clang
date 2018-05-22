/*
�߳�ͬ������ʵս

��Ҫ�õ��ĺ�����
Interlockedϵ�к���

InterlockedIncrement
1.ԭ�Ӳ�������1�����̼߳����д��ͻ

InterlockedDecrement
2.ԭ�Ӳ�������1

InterlockedExchangeAdd
InterlockedExchangeAdd64
3.ԭ�Ӳ�������N

InterlockedExchange
InterlockedExchange64
4.ԭ�Ӳ�������ֵ

InterlockedExchangePointer
5.ԭ�Ӳ�����ָ�븳ֵ
*/

#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>

DWORD a = 40000;
DWORD b = 40000;
DWORD c = 0;
DWORD d = 8;
DWORD e = 0;
DWORD f = 25;
DWORD g = 33;
DWORD *p = NULL;

HANDLE hThread[2];

DWORD WINAPI NumberAdd1(LPVOID lpParam);
DWORD WINAPI Assignment(LPVOID lpParam);
DWORD WINAPI CompareAndAssignment(LPVOID lpParam);

int main(int argc, char *argv[]) {
	unsigned int iThreadIdex;

	hThread[0] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)NumberAdd1, NULL, 0, &iThreadIdex);
	hThread[1] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)NumberAdd1, NULL, 0, &iThreadIdex);
	hThread[2] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)Assignment, NULL, 0, &iThreadIdex);

	WaitForMultipleObjects(2, hThread, true, INFINITE);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	printf("\na = %d\n", a);
	printf("\n&a = %x\n", &a);
	printf("\nb = %d\n", b);
	printf("\nc = %d\n", c);
	printf("\nd = %d\n", d);
	printf("\ne = %d\n", e);
	printf("\ng = %d\n", g);
	printf("\n*p = %d\n", *p);
	printf("\np = %x\n", p);
	system("pause");
	return 0;
}

DWORD WINAPI  NumberAdd1(LPVOID lpParam)
{
	for (int i = 0; i < 10000; i++)
	{
		//a++;
		//b++;
		//InterlockedIncrement(&a);
		//InterlockedIncrement(&b);
		//InterlockedDecrement(&a);
		//InterlockedDecrement(&b);
	
		// ��������
		InterlockedExchangeAdd(&a, -1);
		InterlockedExchangeAdd(&b, -1);
	}

	return 0;
}

DWORD WINAPI Assignment(LPVOID lpParam)
{
	InterlockedExchange(&d, a);
	InterlockedExchangePointer((LPVOID *)&p, &a);
	return 0;
}

DWORD WINAPI CompareAndAssignment(LPVOID lpParam)
{
	p = &f;
	//e = InterlockedCompareExchange(&d, 1000, 8);
	InterlockedCompareExchangePointer((PVOID *)&p, &g, NULL);
	return 0;
}