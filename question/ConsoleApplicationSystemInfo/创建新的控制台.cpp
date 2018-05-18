#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
/*
https://msdn.microsoft.com/zh-cn/library/windows/desktop/ms682425(v=vs.85).aspx
CreateProcess函数
创建一个新进程及其主线程。新进程在调用进程的安全上下文中运行。
如果调用进程正在模拟另一个用户，则新进程将该标记用于调用进程，而不是模拟标记。要在由模拟令牌表示的用户的安全上下文中运行新进程，请使用 CreateProcessAsUser或 CreateProcessWithLogonW函数。

BOOL   CreateProcess(
	LPCTSTR   lpApplicationName,										//   执行程序文件名 //相当于路径 c:/windows/notepad.exe 
	LPTSTR   lpCommandLine,													//   参数行

	LPSECURITY_ATTRIBUTES   lpProcessAttributes,    //   进程安全参数
	LPSECURITY_ATTRIBUTES   lpThreadAttributes,     //   线程安全参数
	BOOL   bInheritHandles,													//   继承标记
	DWORD   dwCreationFlags,												//   创建标记
	LPVOID   lpEnvironment,													//   环境变量
	LPCTSTR   lpCurrentDirectory,										//   运行该子进程的初始目录

	LPSTARTUPINFO   lpStartupInfo,									//   创建该子进程的相关参数  指向STARTUPINFO或STARTUPINFOEX结构的指针 。
	LPPROCESS_INFORMATION   lpProcessInformation    //   创建后用于被创建子进程的信息   指向PROCESS_INFORMATION结构的指针， 用于接收有关新进程的标识信息。
);
*/

int main创建新的控制台(void) {
	int ret = 0;
	//http://blog.sina.com.cn/s/blog_733880070102v3fr.html
	STARTUPINFO si;

	PROCESS_INFORMATION pi;  //接收进程相关信息
	
	/*
	https://blog.csdn.net/tjunxin/article/details/8540259
	ZeroMemory是美国微软公司的软件开发包SDK中的一个宏。 其作用是用0来填充一块内存区域
	*/

	ZeroMemory(&si, sizeof(si));					 //将内存大小先置为0
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;								//启动起来的窗口可以显示

	ZeroMemory(&pi, sizeof(pi));					//将内存大小先置为0

	//WCHAR commandline[] = L"cmd";
	//ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	// WCHAR commandline[] = L"notepad";
	WCHAR commandline[] = L"notepad 1.txt"; // 指定要显示的文本
	ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);

	/*
	typedef   struct   _PROCESS_INFORMATION   {   //   pi   
        HANDLE   hProcess;		  //进程句柄 
        HANDLE   hThread;				//进程的主线程句柄 

        DWORD   dwProcessId;   //进程ID 
        DWORD   dwThreadId;    //进程的主线程ID 
}   PROCESS_INFORMATION;  
	*/

	if (ret) {
		//CloseHandle 关闭一个打开的对象句柄。
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		printf("thread id = %d \n", pi.dwThreadId);
		printf("process id = %d \n", pi.dwProcessId);
	}
	else {
		printf("启动失败");
	}
		
	system("pause");
	return 0;
}