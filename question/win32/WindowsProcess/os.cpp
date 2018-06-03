#include<Windows.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

/*
https://msdn.microsoft.com/library/windows/desktop/ms724834(v=vs.85).aspx

error C4996: ‘GetVersionExW': 被声明为已否决
方法一. Project Properties > Configuration Properties > C/C++ > General > SDL checks关掉
*/


#ifndef SM_SERVERR2
# define SM_SERVERR2 89
#endif
#ifndef VER_SUITE_STORAGE_SERVER
# define VER_SUITE_STORAGE_SERVER 0x00002000
#endif

#ifndef VER_SUITE_COMPUTE_SERVER
# define VER_SUITE_COMPUTE_SERVER 0x00004000
#endif

string GetSystemName() {
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	OSVERSIONINFOEX os;				//包含操作系统版本信息。这些信息包括主要和次要版本号，内部版本号
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if (GetVersionEx((OSVERSIONINFO *)&os))
	{
		string vname;
		// 操作系统的主要版本号
		switch (os.dwMajorVersion) {
		case 4:
			// 操作系统的次版本号
			switch (os.dwMinorVersion) {
			case 0:
				if (os.dwPlatformId == VER_PLATFORM_WIN32_NT)vname = "Windows NT 4.0";
				else if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)vname = "Windows 95";
				break;
			case 10:
				vname = "Windows 98";
				break;
			case 90:
				vname = "Windows Me";
				break;
			}
			break;
		case 5:
			switch (os.dwMinorVersion) {
			case 0:
				vname = "Windows 2000";
				break;
			case 1:
				vname = "Windows XP";
				break;
			case 2:
				if (os.wProductType == VER_NT_WORKSTATION && \
					info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
					vname = "Windows XP Professional x64 Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0)
					vname = "Windows Server 2003";
				else if (GetSystemMetrics(SM_SERVERR2) != 0)
					vname = "Windows Server 2003 R2";
				break;
			}
			break;
		case 6:
			switch (os.dwMinorVersion) {
			case 0:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows Vista";
				else
					vname = "Windows Server 2008";
				break;
			case 1:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 7";
				else
					vname = "Windows Server 2008 R2";
				break;
			case 2:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 8";
				else
					vname = "Windows Server 2012";
				break;
			case 3:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 8.1";
				else
					vname = "Windows Server 2012 R2";
				break;
			}
			break;
		case 10:
		default:
			vname = "unknow os";
		}
		return vname;
	}
	else
		return "GetVersionEx failed";
}

int mainos(void) {
	cout << GetSystemName() << endl;
	system("pause");
	return 0;
}