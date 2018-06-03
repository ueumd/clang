/*
tab ѡ� SysTabControl32
listbox �б�� ListBox
progress ������ msctls_progress32
ScrollBar ������ ScrollBar
listview �б���ͼ SysListView32
treeview ��״ͼ SysTreeView32
updown ����ѡ�� msctls_updown32
*/

#include <windows.h>

LRESULT CALLBACK WndProcForm(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInst;

int WINAPI WinMain2(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR szCmdLine,
	int iCmdShow
) {
	static TCHAR szClassName[] = TEXT("Win32Demo");  //��������
	HWND     hwnd;  //���ھ��
	MSG      msg;  //��Ϣ
	WNDCLASS wndclass;  //������

	hInst = hInstance;

	/**********�ڢٲ���ע�ᴰ����**********/
	//Ϊ������ĸ����ֶθ�ֵ
	wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
	wndclass.lpfnWndProc = WndProcForm;  //���ڹ���
	wndclass.cbClsExtra = 0;  //��ʱ����Ҫ���
	wndclass.cbWndExtra = 0;  //��ʱ����Ҫ���
	wndclass.hInstance = hInstance;  //��ǰ���ھ��
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //����ͼ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  //�����ʽ
	wndclass.hbrBackground = (HBRUSH)GetSysColorBrush(COLOR_BTNFACE);  //���ڱ�����ˢ����ɫ��
	wndclass.lpszMenuName = NULL;  //���ڲ˵�
	wndclass.lpszClassName = szClassName;  //��������
																				 //ע�ᴰ��
	RegisterClass(&wndclass);

	/*****�ڢڲ�����������(���ô�����ʾ����)*****/
	hwnd = CreateWindow(
		szClassName,			//��������
		TEXT("Welcome"),  //���ڱ��⣨�����ڱ�������
		WS_OVERLAPPEDWINDOW,  //���ڷ��
		CW_USEDEFAULT,  //��ʼ��ʱx���λ��
		CW_USEDEFAULT,  //��ʼ��ʱy���λ��
		800,  //���ڿ��
		500,  //���ڸ߶�
		NULL,  //�����ھ��
		NULL,  //���ڲ˵����
		hInstance,  //��ǰ���ڵľ��
		NULL  //��ʹ�ø�ֵ
	);

	//��ʾ����
	ShowWindow(hwnd, iCmdShow);
	//���£����ƣ�����
	UpdateWindow(hwnd);

	/**********�ڢ۲�����Ϣѭ��**********/
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);  //������Ϣ
		DispatchMessage(&msg);  //������Ϣ
	}

	return msg.wParam;
}

//���ڹ���
LRESULT CALLBACK WndProcForm(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	//���û�����
	static TCHAR szBufSex[10];			// �����Ա�
	static TCHAR szBufMarriage[10];	// �������״��
	static TCHAR szBufPet[20];			// ����
	static TCHAR szBufSubmit[100];	// �����ύʱ��ʾ���ļ�
	static TCHAR szBufTmp[10];			// ��ʱ������

	static HFONT hFont;  //�߼�����
											 //һ�鵥ѡ��ť
	static HWND labSex;  //��̬�ı���--�Ա�
	static HWND radioMale;  //��ѡ��ť--��
	static HWND radioFemale;  //��ѡ��ť--Ů
														//һ�鵥ѡ��ť
	static HWND labMarriage;  //��̬�ı���--����״��
	static HWND radioMarried;  //��ѡ��ť--�ѻ�
	static HWND radioSingle;  //��ѡ��ť--δ��
	static HWND radioSecrecy;  //��ѡ��ť--����

														 //һ�鸴ѡ��
	static HWND labPet;  //��̬�ı���--��ĳ���
	static HWND checkboxDog;  //��ѡ��--��
	static HWND checkboxCat;  //��ѡ��--è
	static HWND checkboxFish;  //��ѡ��--��
	static HWND checkboxOther;  //��ѡ��--����

	static HWND btnSubmit;  //��ť�ؼ�

	switch (message) {
	case  WM_CREATE:
		hFont = CreateFont(
			-14, -7, 0, 0, 400,
			FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
			FF_DONTCARE, TEXT("΢���ź�")
		);

		//ѡ���Ա�
		labSex = CreateWindow(
			TEXT("static"), TEXT("����Ա�"),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT/*���־���*/,
			10, 10, 80, 26,
			hWnd, (HMENU)1, hInst, NULL
		);

		radioMale = CreateWindow(
			TEXT("button"), TEXT("��"),
			WS_CHILD | WS_VISIBLE | BS_LEFT/*���־���*/ | BS_AUTORADIOBUTTON /*��ѡ��ť*/ | WS_GROUP,
			95, 10, 50, 26,
			hWnd, (HMENU)2, hInst, NULL
		);

		radioFemale = CreateWindow(
			TEXT("button"), TEXT("Ů"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTORADIOBUTTON,
			150, 10, 50, 26,
			hWnd, (HMENU)2, hInst, NULL
		);

		//ѡ�����״��
		labMarriage = CreateWindow(
			TEXT("static"), TEXT("����״����"),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			10, 40, 80, 26,
			hWnd, (HMENU)4, hInst, NULL
		);

		radioMarried = CreateWindow(
			TEXT("button"), TEXT("�ѻ�"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTORADIOBUTTON | WS_GROUP,
			95, 40, 65, 26,
			hWnd, (HMENU)5, hInst, NULL
		);

		radioSingle = CreateWindow(
			TEXT("button"), TEXT("δ��"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTORADIOBUTTON,
			165, 40, 65, 26,
			hWnd, (HMENU)6, hInst, NULL
		);

		radioSecrecy = CreateWindow(
			TEXT("button"), TEXT("����"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTORADIOBUTTON,
			235, 40, 100, 26,
			hWnd, (HMENU)7, hInst, NULL
		);

		//��ĳ���
		labPet = CreateWindow(
			TEXT("static"), TEXT("��ĳ��"),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			10, 70, 80, 26,
			hWnd, (HMENU)8, hInst, NULL
		);

		checkboxDog = CreateWindow(
			TEXT("button"), TEXT("��"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX/*��ѡ��*/,
			95, 70, 50, 26,
			hWnd, (HMENU)9, hInst, NULL
		);

		checkboxCat = CreateWindow(
			TEXT("button"), TEXT("è"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX,
			150, 70, 50, 26,
			hWnd, (HMENU)10, hInst, NULL
		);

		checkboxFish = CreateWindow(
			TEXT("button"), TEXT("��"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX,
			205, 70, 50, 26,
			hWnd, (HMENU)11, hInst, NULL
		);
		checkboxOther = CreateWindow(
			TEXT("button"), TEXT("����"),
			WS_CHILD | WS_VISIBLE | BS_LEFT | BS_AUTOCHECKBOX,
			260, 70, 65, 26,
			hWnd, (HMENU)12, hInst, NULL
		);

		//������ť�ؼ�
		btnSubmit = CreateWindow(TEXT("button"), TEXT("�� ��"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			95, 110, 200, 36,
			hWnd, (HMENU)13, hInst, NULL
		);

		SendMessage(labSex, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(radioMale, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(radioFemale, WM_SETFONT, (WPARAM)hFont, NULL);

		SendMessage(labMarriage, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(radioMarried, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(radioSingle, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(radioSecrecy, WM_SETFONT, (WPARAM)hFont, NULL);

		SendMessage(labPet, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(checkboxDog, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(checkboxCat, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(checkboxFish, WM_SETFONT, (WPARAM)hFont, NULL);
		SendMessage(checkboxOther, WM_SETFONT, (WPARAM)hFont, NULL);

		SendMessage(btnSubmit, WM_SETFONT, (WPARAM)hFont, NULL);

		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		if (wmEvent == BN_CLICKED) {
			switch (wmId) {
				//��ȡ�Ա�
			case 2:
			case 3:
				GetWindowText((HWND)lParam, szBufSex, 10);
				break;
				//��ȡ����״��
			case 5:
			case 6:
			case 7:
				GetWindowText((HWND)lParam, szBufMarriage, 10);
				break;
				//��ȡ����
			case 9:
			case 10:
			case 11:
			case 12:
				memset(szBufPet, 0, sizeof(szBufPet));
				//�Ƿ�ѡ�й�
				if (SendMessage(checkboxDog, BM_GETCHECK, 0, 0) == BST_CHECKED) {
					/*
					�����ú�����ָ�����ڵı������ı���������ڣ�������һ���������ڡ����ָ���Ĵ�����һ���ؼ����򿽱��ؼ����ı���
							���ǣ�GetWindowText���ܽ������� Ӧ�ó����пؼ����ı��� 
����						����ԭ�ͣ�Int GetWindowText��HWND hWnd��LPTSTR lpString��Int nMaxCount����
							hWnd�����ı��Ĵ��ڻ�ؼ��ľ����
							IpString��ָ������ı��� �������� ָ�롣
							nMaxCount��ָ��Ҫ�����ڻ������ڵ��ַ��������������а���NULL�ַ�������ı��������ޣ����ͱ��ضϡ�
					*/
					GetWindowText(checkboxDog, szBufTmp, 10);

					/*
				int wsprintf (LPTSTR lpOut��// ָ����Ҫ������ַ�����ָ��
��������������LPCTSTR lpFmt��					//ָ���ʽ�����ַ�����ָ��
������������������											// ������ѡ���� Ҫ��ʽ����ֵ
��������������)��
					��һ���������ַ���������
					�����Ǹ�ʽ�ַ�����wsprintf���ǽ���ʽ�����д����׼��������ǽ���д�뻺�����У��ú������ظ��ַ����ĳ��ȡ�
					*/

					wsprintf(szBufPet, TEXT("%s  %s"), szBufPet, szBufTmp);
				}
				//�Ƿ�ѡ��è
				LRESULT lRes = SendMessage(checkboxCat, BM_GETCHECK, 0, 0);
				if (lRes == BST_CHECKED) {
					//printf("ok");
				}
				if (SendMessage(checkboxCat, BM_GETCHECK, 0, 0) == BST_CHECKED) {
					GetWindowText(checkboxCat, szBufTmp, 10);
					wsprintf(szBufPet, TEXT("%s  %s"), szBufPet, szBufTmp);
				}
				//�Ƿ�ѡ����
				if (SendMessage(checkboxFish, BM_GETCHECK, 0, 0) == BST_CHECKED) {
					GetWindowText(checkboxFish, szBufTmp, 10);
					wsprintf(szBufPet, TEXT("%s  %s"), szBufPet, szBufTmp);
				}
				//�Ƿ�ѡ������
				if (SendMessage(checkboxOther, BM_GETCHECK, 0, 0) == BST_CHECKED) {
					GetWindowText(checkboxOther, szBufTmp, 10);
					wsprintf(szBufPet, TEXT("%s  %s"), szBufPet, szBufTmp);
				}
				break;

			case 13:
				wsprintf(szBufSubmit, TEXT("����Ա�%s\n����״����%s\r\n��ĳ��%s"), szBufSex, szBufMarriage, szBufPet);
				MessageBox(hWnd, szBufSubmit, TEXT("��Ϣ��ʾ"), MB_ICONINFORMATION);
				break;

			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		return DefWindowProc(hWnd, message, wParam, lParam);

	case WM_DESTROY:
		DeleteObject(hFont);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}