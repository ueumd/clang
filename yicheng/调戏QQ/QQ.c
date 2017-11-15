#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void openQQ() {
	//64位 的情况下(x86)要有空格，转义字符
	printf("打开QQ\n");

	//"D:\Program Files (x86)\Tencent\QQ\Bin\QQScLauncher.exe"
	//C:\\Program Files (x86)\\AliWangWang\\AliIM.exe
	// ShellExecuteA(0, "open", "\"D:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe\"", 0, 0, 1);
	ShellExecuteA(0, "open", "\"D:\\Program Files\\BaiduNetdisk\\BaiduNetdisk.exe\"", 0, 0, 1);
}

void closeQQ() {
	system("taskkill /f /im QQ.exe"); //结束进程
}

//递归沿对角线
void moveJ(HWND win, int i) {

	if (i == 1500) {
		return;
	}
	else {
		SetWindowPos(win, NULL, i, i*9/16, 300, 400, 1);
		Sleep(30);
		moveJ(win, i + 10);
	}
}

void moveQQ() {
	HWND win; //指针 返回窗口编号
	//win = FindWindowA("TXGuiFoundation", "QQ"); //寻找QQ

	win = FindWindowA("DuiHostWnd", "欢迎使用百度网盘"); //寻找QQ
	if (win == NULL) {
		printf("玩失踪\n");
	}
	else {
		printf("找到\n");
		//while (1) {
		//	ShowWindow(win, SW_SHOW); //隐藏
		//	Sleep(5000);
		//	ShowWindow(win, SW_HIDE);
		//}

		for (int i = 0; i <= 1500; i += 10) {

			// 3 4 xy坐标
			SetWindowPos(win, NULL, i, 0, 300, 400, 1);
			Sleep(30);
		}

		{
			int i = 0;

			while (i <= 800) {
				SetWindowPos(win, NULL, 1500, i, 300, 400, 1);
				Sleep(30);
				i += 10;
			}
		}

		//moveJ(win, 0); //递归
	}
}

int main() {
	
	openQQ();
	Sleep(5000);
	moveQQ();
	// closeQQ();
	system("pause");
	return 0;
}