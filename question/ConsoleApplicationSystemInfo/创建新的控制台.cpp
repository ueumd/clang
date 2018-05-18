#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
/*
https://msdn.microsoft.com/zh-cn/library/windows/desktop/ms682425(v=vs.85).aspx
CreateProcess����
����һ���½��̼������̡߳��½����ڵ��ý��̵İ�ȫ�����������С�
������ý�������ģ����һ���û������½��̽��ñ�����ڵ��ý��̣�������ģ���ǡ�Ҫ����ģ�����Ʊ�ʾ���û��İ�ȫ�������������½��̣���ʹ�� CreateProcessAsUser�� CreateProcessWithLogonW������

BOOL   CreateProcess(
	LPCTSTR   lpApplicationName,										//   ִ�г����ļ��� //�൱��·�� c:/windows/notepad.exe 
	LPTSTR   lpCommandLine,													//   ������

	LPSECURITY_ATTRIBUTES   lpProcessAttributes,    //   ���̰�ȫ����
	LPSECURITY_ATTRIBUTES   lpThreadAttributes,     //   �̰߳�ȫ����
	BOOL   bInheritHandles,													//   �̳б��
	DWORD   dwCreationFlags,												//   �������
	LPVOID   lpEnvironment,													//   ��������
	LPCTSTR   lpCurrentDirectory,										//   ���и��ӽ��̵ĳ�ʼĿ¼

	LPSTARTUPINFO   lpStartupInfo,									//   �������ӽ��̵���ز���  ָ��STARTUPINFO��STARTUPINFOEX�ṹ��ָ�� ��
	LPPROCESS_INFORMATION   lpProcessInformation    //   ���������ڱ������ӽ��̵���Ϣ   ָ��PROCESS_INFORMATION�ṹ��ָ�룬 ���ڽ����й��½��̵ı�ʶ��Ϣ��
);
*/

int main�����µĿ���̨(void) {
	int ret = 0;
	//http://blog.sina.com.cn/s/blog_733880070102v3fr.html
	STARTUPINFO si;

	PROCESS_INFORMATION pi;  //���ս��������Ϣ
	
	/*
	https://blog.csdn.net/tjunxin/article/details/8540259
	ZeroMemory������΢��˾�����������SDK�е�һ���ꡣ ����������0�����һ���ڴ�����
	*/

	ZeroMemory(&si, sizeof(si));					 //���ڴ��С����Ϊ0
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;								//���������Ĵ��ڿ�����ʾ

	ZeroMemory(&pi, sizeof(pi));					//���ڴ��С����Ϊ0

	//WCHAR commandline[] = L"cmd";
	//ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	// WCHAR commandline[] = L"notepad";
	WCHAR commandline[] = L"notepad 1.txt"; // ָ��Ҫ��ʾ���ı�
	ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);

	/*
	typedef   struct   _PROCESS_INFORMATION   {   //   pi   
        HANDLE   hProcess;		  //���̾�� 
        HANDLE   hThread;				//���̵����߳̾�� 

        DWORD   dwProcessId;   //����ID 
        DWORD   dwThreadId;    //���̵����߳�ID 
}   PROCESS_INFORMATION;  
	*/

	if (ret) {
		//CloseHandle �ر�һ���򿪵Ķ�������
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		printf("thread id = %d \n", pi.dwThreadId);
		printf("process id = %d \n", pi.dwProcessId);
	}
	else {
		printf("����ʧ��");
	}
		
	system("pause");
	return 0;
}