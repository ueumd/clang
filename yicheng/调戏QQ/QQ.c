#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void openQQ() {
	//64λ �������(x86)Ҫ�пո�ת���ַ�
	printf("��QQ\n");

	//"D:\Program Files (x86)\Tencent\QQ\Bin\QQScLauncher.exe"
	//C:\\Program Files (x86)\\AliWangWang\\AliIM.exe
	// ShellExecuteA(0, "open", "\"D:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe\"", 0, 0, 1);
	ShellExecuteA(0, "open", "\"D:\\Program Files\\BaiduNetdisk\\BaiduNetdisk.exe\"", 0, 0, 1);
}

void closeQQ() {
	system("taskkill /f /im QQ.exe"); //��������
}

//�ݹ��ضԽ���
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
	HWND win; //ָ�� ���ش��ڱ��
	//win = FindWindowA("TXGuiFoundation", "QQ"); //Ѱ��QQ

	win = FindWindowA("DuiHostWnd", "��ӭʹ�ðٶ�����"); //Ѱ��QQ
	if (win == NULL) {
		printf("��ʧ��\n");
	}
	else {
		printf("�ҵ�\n");
		//while (1) {
		//	ShowWindow(win, SW_SHOW); //����
		//	Sleep(5000);
		//	ShowWindow(win, SW_HIDE);
		//}

		for (int i = 0; i <= 1500; i += 10) {

			// 3 4 xy����
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

		//moveJ(win, 0); //�ݹ�
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