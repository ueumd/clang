#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include <TlHelp32.h>

/*
���� ��Ŀ->����->C++ -> �������� -> ���п� -> ���̵߳���(/MTd) �����̬��
*/

BOOL CloseProcess(DWORD dwId) {
	BOOL bRet;
	HANDLE hHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwId);
	if (hHandle != NULL) {
		bRet = TerminateProcess(hHandle, 0);
	}
	CloseHandle(hHandle);

	return bRet;
}

int main(void) {

	//��������
	/*
	https://baike.baidu.com/item/PROCESSENTRY32/2828747
	������ſ��ս�����Ϣ��һ���ṹ�塣
	����Ž�����Ϣ�͵��ó�Ա���������Ϣ������ Process32Firstָ���һ��������Ϣ������������Ϣ��ȡ��PROCESSENTRY32�С�
	��Process32Nextָ����һ��������Ϣ��
	*/
	PROCESSENTRY32 pc;

	// �ṹ�Ĵ�С
	pc.dwSize = sizeof(pc);

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (INVALID_HANDLE_VALUE == hProcessSnap) {
		printf("get snapshop failed\n");
		system("pause");
		return 0;
	}

	BOOL bMore = Process32First(hProcessSnap, &pc);
	while (bMore) {
		printf("\n-----------------------------------------------\n");
		printf("id: %d \t", pc.th32ProcessID);	//����id
		wprintf(L"name: %s", pc.szExeFile);    //Ӧ�ó����� xxx.exe

		bMore = Process32Next(hProcessSnap, &pc);
	}
	// �ر� 
	CloseHandle(hProcessSnap);

	printf("\n-----------------------------------------------\n");
	int pid = 0;
	printf("������Ҫ����ID ���س��� ");
	scanf("%d", &pid);
	CloseProcess(pid);

	system("pause");
	return 0;
}