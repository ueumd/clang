
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <TlHelp32.h> //�г����н���

/*
����˵����
1. �г����н���
2. ָ�����̲��޸ĸý���Ŀ���ڴ�
		1. �򿪽��̣���ȡ�ں˶�����
		2. ��������Ŀ��
		3. �г����ҽ��
		4. �������1ʱ�����Ҷ���Ŀ��
		5. �޸Ķ���Ŀ���������ڴ��ֵ
3. ɱ������
4. �˳�
*/

const DWORD KONEK = 1024;
const DWORD KPAGE = 4 * KONEK;
const DWORD KONEG = KONEK * KONEK * KONEK;

// ����
void ShowMenu();
void ShowProcessList();
void EditProcessData();
void KillProcesss();

void FirstRound(HANDLE hProcess, DWORD dwValue, DWORD *pAddrList, DWORD *pAddrListCounter, const DWORD addrListMax);
BOOL CompareOnePage(HANDLE hProcess, DWORD dwBaseAddr, DWORD dwValue, DWORD *pAddrList, DWORD *pAddrListCounter, const DWORD addrListMax);
void ShowAddrList(DWORD *pDwAddrList, DWORD dwAddrCount);
void SecondRound(HANDLE hProcess, DWORD dwValue, DWORD *pAddrList, DWORD dwAddrListCounter, DWORD *pTargetList, DWORD *pTargetCounter);

int main(void) {
	int select = 0;
	while (true) {
		//��ʾ�˵�
		ShowMenu();
		while (!scanf_s("%d", &select)) { //����Ҫ���
			//fflush(stdin); // ���Ƽ���
			rewind(stdin); //������Ҫ��ʱ�������룬�������̻��������
			printf("please input your choice...");
		}
		switch (select)
		{
			// �г����н���
		case 1:
			ShowProcessList();
			break;
			// ָ�����̲��޸ĸý���Ŀ���ڴ�
		case 2:
			EditProcessData();
			break;
			// ɱ������
		case 3:
			KillProcesss();
			break;
		case 4:
			printf("Thank you using...");
			system("pause");
			return 0;
		default:
			printf("Please select again 1-4 ...\n");
		}
	}
	return 0;
}

void ShowMenu() {
	printf("--------------------------------------------------\n");
	printf("Menu:\n");
	printf("\t1.Show system process list.\n");
	printf("\t2.Input process id which you want to edit.\n");
	printf("\t3.Input process id which you want to kill.\n");
	printf("\t4.Exit\n");
	printf("--------------------------------------------------\n");
}

void ShowProcessList() {
	PROCESSENTRY32 pc;
	// �ṹ�Ĵ�С
	pc.dwSize = sizeof(pc);

	//���̿���
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 

	if (INVALID_HANDLE_VALUE == hProcessSnap) {
		printf("get snapshop failed\n");
	}

	// �����еĵ�һ������
	BOOL bMore = Process32First(hProcessSnap, &pc);

	// ����û��������
	while (bMore) {
		printf("\n-----------------------------------------------\n");
		printf("id: %d \t", pc.th32ProcessID);	//����id
		wprintf(L"name: %s", pc.szExeFile);    //Ӧ�ó����� xxx.exe
		// �����е���һ������
		bMore = Process32Next(hProcessSnap, &pc);
	}
	CloseHandle(hProcessSnap);
}

void EditProcessData() {
	DWORD dwId = 0;
	DWORD dwSearchValue = 0;
	DWORD dwAddrList[4 * KONEK] = { 0 };
	DWORD dwAddrCount = 0;
	BOOL bRet = FALSE;

	printf("\nPlease input process id which you want to eidt: ");
	while (!scanf_s("%u", &dwId)) {
		rewind(stdin);
		printf("Please input again:");
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwId); // ȫ��Ȩ�ޣ� �Ƿ�̳�, ID
	if (NULL == hProcess) {
		printf("Open process failed...\n");
		return;
	}
	else {
		printf("Open process success...\n");
		system("pause");

		//���ֲ���
		printf("Please input the value which you want search firts round: ");
		scanf_s("%u", &dwSearchValue);

		FirstRound(hProcess, dwSearchValue, dwAddrList, &dwAddrCount, 4 * KONEK);

		ShowAddrList(dwAddrList, dwAddrCount);

		// �ҵ���ֵ�ĸ�������0
		if (dwAddrCount == 0) {
			return;
		}
		// �ҵ��˵���1
		else if (dwAddrCount == 1) {
			DWORD value;
			printf("input the value which you want to set: ");
			scanf_s("%u", &value);

			bRet = WriteProcessMemory(hProcess, (LPVOID)dwAddrList[0], (LPCVOID)&value, sizeof(DWORD), NULL);
			if (bRet)
			{
				printf("Edit Success!!!\n");
			}
			else
			{
				printf("Edit failed!!!\n");
			}
		}
		//�ҵ���ֵ�ĸ�������1��
		else {
			DWORD dwSecondRoundSearchValue = 0;
			DWORD dwTargetList[KONEK] = { 0 };
			DWORD dwTargetCounter = 0;
			printf("input the value which you need second round find:");
			scanf_s("%u", &dwSecondRoundSearchValue);
			//�ҵ���ֵ�ĸ�������1��
			SecondRound(hProcess, dwSecondRoundSearchValue, dwAddrList, dwAddrCount, dwTargetList, &dwTargetCounter);
			ShowAddrList(dwTargetList, dwTargetCounter);
			DWORD value;
			printf("input the value which you want to set: ");
			scanf_s("%u", &value);

			for (DWORD i = 0; i < dwTargetCounter; i++)
			{
				bRet = WriteProcessMemory(hProcess, (LPVOID)dwTargetList[i], &value, sizeof(value), NULL);
				if (bRet)
				{
					printf("Edit Success!!!\n");
				}
				else
				{
					printf("Edit failed!!!\n");
				}
			}

		}
	}
	CloseHandle(hProcess);
}

void KillProcesss() {
	BOOL bRet = FALSE;
	//typedef unsigned long       DWORD;
	DWORD dwId = 0; //�û�����Ľ���ID
	printf("\nPlease input process id which you want to kill: ");

	while (!scanf_s("%u", &dwId)) {
		rewind(stdin);
		printf("Please input process id which you want to kill: ");
	}
	
	//������ȷID��
	//�õ����̾��
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwId);
	if (hProcess != NULL) {
		bRet = TerminateProcess(hProcess, 0);
	}

	CloseHandle(hProcess);

	if (bRet) {
		printf("kill process success\n");
	}
	else {
		printf("kill process failed\n");
	}
}

void FirstRound(HANDLE hProcess, DWORD dwValue, DWORD *pAddrList, DWORD *pAddrListCounter, const DWORD addrListMax)
{
	DWORD dwBaseAddr = 64 * KONEK;

	DWORD dwPageCount = (2 * KONEG - 64 * KONEK * 2) / KPAGE;
	printf("%u pages\n", dwPageCount);

	printf("Start searching ...\n");
	DWORD dwBeginAddr = dwBaseAddr;
	for (; dwBaseAddr < 2 * KONEG - 64 * KONEK; dwBaseAddr += KPAGE)
	{
		if (!CompareOnePage(hProcess, dwBaseAddr, dwValue, pAddrList, pAddrListCounter, addrListMax))
		{
			return;
		}

		//������Ȱٷֱ�
		DWORD page = (dwBaseAddr - dwBeginAddr) / KPAGE + 1;
		printf("current is %u page, \t", page);
		double temp = ((double)page / dwPageCount) * 100;
		printf("-----%%%f------\n", temp);

	}
	printf("\nSearch finished...\n");
	system("pause");
}

BOOL CompareOnePage(HANDLE hProcess, DWORD dwBaseAddr, DWORD dwValue, DWORD *pAddrList, DWORD *pAddrListCounter, const DWORD addrListMax)
{
	BYTE byPage[KPAGE] = { 0 };
	/*
	��������ȡ�ɹ�ʱ����1�� ʧ���򷵻�0
	hProcess�����̾��
	lpBaseAddress���������ݵĵ�ַ
	lpBuffer����Ŷ�ȡ���ݵĵ�ַ
	nSize�����������ݴ�С
	lpNumberOfBytesRead�����ݵ�ʵ�ʴ�С
	*/
	if (!ReadProcessMemory(hProcess, (LPCVOID)dwBaseAddr, (LPVOID)byPage, KPAGE, NULL))
	{
		printf("Read Memory error!!!\n");
		return TRUE;
	}

	DWORD *pdwPointer = NULL;
	pdwPointer = (DWORD *)byPage;

	for (DWORD i = 0; i < KONEK; i++)
	{
		if (*pAddrListCounter >= addrListMax)
		{
			printf("Too many data, can not save...\n");
			return FALSE;
		}

		if (pdwPointer[i] == dwValue)
		{
			pAddrList[*pAddrListCounter] = dwBaseAddr + i * sizeof(DWORD);
			(*pAddrListCounter)++;
		}
	}
	return TRUE;
}

void ShowAddrList(DWORD *pDwAddrList, DWORD dwAddrCount)
{
	printf("\n----------Address list begin----------\n");
	for (DWORD i = 0; i < dwAddrCount; i++)
	{
		printf("%X\n", pDwAddrList[i]);
	}
	printf("\n----------Address list end------------\n");
}

void SecondRound(HANDLE hProcess, DWORD dwValue, DWORD *pAddrList, DWORD dwAddrListCounter, DWORD *pTargetList, DWORD *pTargetCounter)
{
	DWORD dwTemp = 0;
	for (DWORD i = 0; i < dwAddrListCounter; i++)
	{
		if (ReadProcessMemory(hProcess, (LPCVOID)pAddrList[i], &dwTemp, sizeof(dwTemp), NULL))
		{
			if (dwTemp == dwValue)
			{
				pTargetList[*pTargetCounter] = pAddrList[i];
				(*pTargetCounter)++;
			}
		}
	}
}