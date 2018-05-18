#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include <TlHelp32.h>

/*
生成 项目->属性->C++ -> 代码生成 -> 运行库 -> 多线程调试(/MTd) 打包动态库
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

	//遍历进程
	/*
	https://baike.baidu.com/item/PROCESSENTRY32/2828747
	用来存放快照进程信息的一个结构体。
	（存放进程信息和调用成员输出进程信息）用来 Process32First指向第一个进程信息，并将进程信息抽取到PROCESSENTRY32中。
	用Process32Next指向下一条进程信息。
	*/
	PROCESSENTRY32 pc;

	// 结构的大小
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
		printf("id: %d \t", pc.th32ProcessID);	//进程id
		wprintf(L"name: %s", pc.szExeFile);    //应用程名称 xxx.exe

		bMore = Process32Next(hProcessSnap, &pc);
	}
	// 关闭 
	CloseHandle(hProcessSnap);

	printf("\n-----------------------------------------------\n");
	int pid = 0;
	printf("请输入要进程ID 并回车： ");
	scanf("%d", &pid);
	CloseProcess(pid);

	system("pause");
	return 0;
}