#include <stdlib.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>

/*

WaitForSingleObject
WaitForMultipleObjects
1 ���̺߳����߳�ִ��˳��
2 ���̼߳�ִ��˳��
*/

DWORD WINAPI SetNum(LPVOID lpParam);
DWORD WINAPI GetResult(LPVOID lpParam);
int a = 10;
int b = 20;
int c = 0;

HANDLE hThreadex1;
HANDLE hThreadex2;

HANDLE hThreadex[2]; //����

// ��ں������߳�
int main(int argc, char *argv[]) {

	
	unsigned int iThreadIdex;

	// ���߳�
	hThreadex[0] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)GetResult, NULL, 0, &iThreadIdex);
	hThreadex[1] = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)SetNum, NULL, 0, &iThreadIdex);

	//WaitForSingleObject(hThreadex1, INFINITE);
	//WaitForSingleObject(hThreadex2, INFINITE);

	DWORD errNO = WaitForMultipleObjects(2, hThreadex, true, INFINITE);// 2�� �ȴ������� �Ƿ�ȫ���ȴ� ʱ��

	//CloseHandle(hThreadex1);
	//CloseHandle(hThreadex2);

	CloseHandle(hThreadex[0]);
	CloseHandle(hThreadex[1]);
	
	printf("%d + %d = %d\n", a, b, c);

	system("pause");
	return 0;
}

DWORD WINAPI SetNum(LPVOID lpParam) {
	a = 100;
	b = 200;
	return 0;
}

DWORD WINAPI GetResult(LPVOID lpParam) {
	WaitForSingleObject(hThreadex[1], INFINITE); //�ȴ��£��������߳�ÿ�ζ���300����������ʱ����30
	c = a + b;
	return 0;
}