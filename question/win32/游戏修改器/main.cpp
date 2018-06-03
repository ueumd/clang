
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <TlHelp32.h> //列出所有进程

/*
功能说明：
1. 列出所有进程
2. 指定进程并修改该进程目标内存
		1. 打开进程，获取内核对象句柄
		2. 查找首轮目标
		3. 列出查找结果
		4. 结果大于1时，查找二轮目标
		5. 修改二轮目标中所有内存的值
3. 杀死进程
4. 退出
*/

const DWORD KONEK = 1024;
const DWORD KPAGE = 4 * KONEK;
const DWORD KONEG = KONEK * KONEK * KONEK;

// 声明
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
		//显示菜单
		ShowMenu();
		while (!scanf_s("%d", &select)) { //符合要求的
			//fflush(stdin); // 不推荐了
			rewind(stdin); //不符合要求时重新输入，并将键盘缓冲区清空
			printf("please input your choice...");
		}
		switch (select)
		{
			// 列出所有进程
		case 1:
			ShowProcessList();
			break;
			// 指定进程并修改该进程目标内存
		case 2:
			EditProcessData();
			break;
			// 杀死进程
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
	// 结构的大小
	pc.dwSize = sizeof(pc);

	//进程快照
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 

	if (INVALID_HANDLE_VALUE == hProcessSnap) {
		printf("get snapshop failed\n");
	}

	// 快照中的第一个进程
	BOOL bMore = Process32First(hProcessSnap, &pc);

	// 还有没其他进程
	while (bMore) {
		printf("\n-----------------------------------------------\n");
		printf("id: %d \t", pc.th32ProcessID);	//进程id
		wprintf(L"name: %s", pc.szExeFile);    //应用程名称 xxx.exe
		// 快照中的下一个进程
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
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwId); // 全部权限， 是否继承, ID
	if (NULL == hProcess) {
		printf("Open process failed...\n");
		return;
	}
	else {
		printf("Open process success...\n");
		system("pause");

		//首轮查找
		printf("Please input the value which you want search firts round: ");
		scanf_s("%u", &dwSearchValue);

		FirstRound(hProcess, dwSearchValue, dwAddrList, &dwAddrCount, 4 * KONEK);

		ShowAddrList(dwAddrList, dwAddrCount);

		// 找到的值的个数等于0
		if (dwAddrCount == 0) {
			return;
		}
		// 找到了等于1
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
		//找到了值的个数超过1个
		else {
			DWORD dwSecondRoundSearchValue = 0;
			DWORD dwTargetList[KONEK] = { 0 };
			DWORD dwTargetCounter = 0;
			printf("input the value which you need second round find:");
			scanf_s("%u", &dwSecondRoundSearchValue);
			//找到的值的个数超过1个
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
	DWORD dwId = 0; //用户输入的进程ID
	printf("\nPlease input process id which you want to kill: ");

	while (!scanf_s("%u", &dwId)) {
		rewind(stdin);
		printf("Please input process id which you want to kill: ");
	}
	
	//输入正确ID后
	//得到进程句柄
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

		//计算进度百分比
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
	当函数读取成功时返回1， 失败则返回0
	hProcess：进程句柄
	lpBaseAddress：读出数据的地址
	lpBuffer：存放读取数据的地址
	nSize：读出的数据大小
	lpNumberOfBytesRead：数据的实际大小
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