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

DWORD WINAPI ThreadProx(LPVOID lpParam);

// ��ں������߳�
int main���̺߳����߳�ִ��˳��(int argc, char *argv[]) {

	HANDLE hThreadex;
	unsigned int iThreadIdex;

	// ���߳�
	hThreadex = (HANDLE)_beginthreadex(NULL, NULL, (_beginthreadex_proc_type)ThreadProx, NULL, 0, &iThreadIdex);

	//�ȴ����̴߳�ӡ����ٴ�ӡ���̣߳� ���Ӿ���hello world�����ӡ
	DWORD errNo = WaitForSingleObject(hThreadex, INFINITE);//�ȴ����߳̽���  0    //hThreadex, 1   258��ʱ��

	printf("%d\n", errNo); // 0

	CloseHandle(hThreadex);

	for (int i = 0; i < 20; i++)
	{
		printf("world\n");
	}

	system("pause");
	return 0;
}

DWORD WINAPI ThreadProx(LPVOID lpParam) {
	for (int i = 0; i < 20; i++) {
		printf("hello\n");
	}
	return 0;
}