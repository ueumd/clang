#include<Windows.h>
#include "resource.h"
/*
������UI�� MFC���Ӵ� ATL
*/

/*
2.���ڷ������  CreateWindow  CreateWindowEx
WS_BORDER��windowsխ�߱�
WS_CAPTION��windows������������WS_BORDER
WS_CHILDWINDOW��WS_CHILD��������һ���Ӵ��ڣ�������WS_POPUP����
WS_CLIPCHILDREN����Ϊ�����ڣ�ˢ��ʱ�ü��Ӵ����������ˢ��Ч��
WS_CLIPSIBLINGS����Ϊ�Ӵ��ڣ�ˢ��ʱ�ü������Ӵ��ڵ��ص��������ˢ��Ч��
WS_DISABLED���رմ�����Ӧ���û����κβ�������Ч
WS_DLGFRAME��������һ���߿���ʽ��ͨ����Ի���һ��ʹ�á�������ʽ�Ĵ��ڲ����б�������
WS_GROUP�����������ʱʹ�á�
��ʾ WS_HSCROLL�����ں���ˮƽ��������
��ʾ WS_VSCROLL�����ں��д�ֱ��������
��ʾ WS_MAXIMIZE�����ڳ�ʼ״̬��󻯡�
WS_MINIMIZE�����ڳ�ʼ״̬��С����
WS_ICONIC��ͬWS_MINIMIZE
WS_MAXIMIZEBOX�����ں�����󻯰�ť
WS_MINIMIZEBOX�����ں�����С����ť
WS_OVERLAPPED���ص�ģʽ�����б����ͱ߿�
WS_TILED��ͬWS_OVERLAPPED
��ʾ WS_OVERLAPPEDWINDOW��(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
WS_TILEDWINDOW��ͬWS_OVERLAPPEDWINDOW
WS_POPUP����������ģʽ��������WS_CHILD����
��ʾ WS_POPUPWINDOW��WS_POPUP | WS_BORDER | WS_SYSMENU
WS_SIZEBOX�����ھ��п������߿�
WS_THICKFRAME��ͬWS_SIZEBOX
��ʾ WS_SYSMENU����������ϵͳ�˵������رհ�ť��
WS_TABSTOP����Ϊ�����еĿؼ���������WS_TABSTOP��־�Ŀؼ�����ͨ��TAB��������ת��
WS_VISIBLE�������Ƿ�ɼ��� ��ShowWindow����


3.������Ϊ���� ShowWindow()
SW_HIDE
SW_SHOW
SW_MAXIMIZE
SW_MINIMIZE
SW_FORCEMINIMIZE
SW_SHOWDEFAULT
SW_SHOWMAXIMIZED
SW_SHOWMINIMIZED
SW_SHOWMINNOACTIVE
SW_SHOWNA
SW_SHOWNOACTIVATE
SW_SHOWNORMAL
SW_RESTORE

4.����ͼ������
HICON LoadIcon(
HINSTANCE hInstance,
LPCTSTR   lpIconName ==> MAKEINTRESOURCE
);

HANDLE LoadImage(
HINSTANCE hinst,
LPCTSTR   lpszName,  ==> MAKEINTRESOURCE
UINT      uType,
int       cxDesired, ==> GetSystemMetrics
int       cyDesired, ==> GetSystemMetrics
UINT      fuLoad
);


int GetSystemMetrics(  //��λ����
int nIndex
);


ʾ�����Խ�����
���⣺Ԭ����

ͼ���ļ�icon����

��������ICON�ļ�    https://www.ico.la/

��������ICON�ļ�    ������ܣ�anytoicon
*/

/*
��Ϣ����
WM_CRATE:���ڴ�����
WM_MOVE	�����ƶ�

WM_LBUTTONDOWN ��갴��
x = LOWORD(lParam) xλ��
y = HIWORD(lParam) yλ��

GetCursorPos(&pt) �����Ļ

WM_KEYDONW �а�������
ALT���� WM_SYSKEYDOWN
�ɴ�ӡ������Ϣ WM_CHAR
ֵ wParam
TranslateMessage(&msg)

�ж���ϼ�
1 ��ĸ����0x01 - 0x1A   Ctrl + a Ctrl + z ���Ƽ���
2 bIsCtrl = (::GetAsyncKeyState(VK_CONTROL) && 0x8000)
3 bIsCtrl = (::GetKeyState(VK_CONTROL) && 0x8000)
*/

/*
��Ϣ�˵� VM_COMMAND
ȡ���LOWORD(wParam)
*/

/*
ϵͳ������ϢID��ֵ��0X0000��0X03FF��Χ����ЩֵΪϵͳ���������壬�û��Զ�����ϢID���ܹ��������ͻ���û��Զ�����ϢID��ΧΪ��WM_USER��0X0400����0X7FFF����0XC000��0XFFFF��Windows��ϢID�������£�

WM_NULL---0X0000����ʾ�޲���������Ϣӳ���У����Ӧ�ó�����ͼʹ����������Ͷ�ݵ���Ϣʵ�к��Դ�������WM_NULL������Ϣ������������Ϣ������WindowProc���յ�WM_NULL������Ϣ������Ե���

0X0001----0X0087��������Ϣ������WM_SIZE��WM_PAINT��WM_ERASEBKGND�ȡ�

0X00A0----0X00A9���ǿͻ�����Ϣ������WM_NCMOUSEMOVE��WM_NCLBUTTONDBLCLK��WM_NCRBUTTONUP�ȡ�

0X0100----0X0108��������Ϣ������WM_KEYDOWN��WM_KEYFIRST��WM_CHAR��WM_SYSCHAR�ȡ�

0X0111----0X0112���˵��������WM_COMMAND��WM_SYSCOMMAND��0X0132----0x0132----0x0138����ɫ������Ϣ������WM_CTLCOLORMSGBOX��WM_CTLCOLORLISTBOX��WM_CTLCOLORDLG�ȡ�

0X0200----0X020A�������Ϣ������WM_LBUTTONUP��WM_RBUTTONUP�ȡ�

0X0211----0X0213���˵�ѭ����Ϣ������WM_ENTERMENULOOP��WM_EXITMENULOOP�ȡ�

0X0220----0X0230�����ĵ���Ϣ������WM_MDICREATE��WM_MDIDESTROY�ȡ�

0X03E0----0X03E8��DDE��Ϣ������WM_PASTE��WM_CLEAR��WM_UNDO�ȡ�

0X0400���û��Զ�����Ϣ����㣬WM_USER����WM_USER + N��ʽ���֡�
0X8000���û��Զ�����Ϣ����㣬WM_APP����WM_APP + N��ʽ���֡�

0X0400----0X7FFF���û��Զ�����Ϣ��Χ��

0X8001----0XBFFF��0xC000----0xFFFE���û��Զ�����Ϣ��Χ��
*/

LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	
	int x = 0;
	int y = 0;

	POINT pt;
	wchar_t pos1[20];
	wchar_t pos2[20];

	wchar_t str[100];

	switch (uMsg) {
	case WM_COMMAND:
	{
		// MENU
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case ID_DAYSUN_16563:
			MessageBox(hWnd, L"ID_DAYSUN_16563", L"Message", MB_OK);
			break;
		case ID_DAYSUN_EXIT:
			MessageBox(hWnd, L"ID_DAYSUN_EXIT", L"Message", MB_OK);
			quick_exit(-1);
			break;
		default:
			// Ĭ�ϵ���Ϣ������
			return	DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}
	break;

	case WM_CREATE:
		//MessageBox(hWnd, L"WM_CREATE", L"Message", MB_OK);
		break;
	case WM_MOVE:
	//	MessageBox(hWnd, L"WM_MOVE", L"Message", MB_OK);
		break;
		//����������Ϣ
	
		//���
	case WM_LBUTTONDOWN:
			//x = LOWORD(lParam); //xλ��
			//y = HIWORD(lParam); // yλ��
			//GetCursorPos(&pt);
			//
			//wsprintf(pos1, L"%d, %d", x, y); // ��posд���ڴ浱��
			//MessageBox(hWnd, pos1, L"Message", MB_OK);
			//�����Ļ
			//wsprintf(pos2, L"%d, %d", pt.x, pt.y);
			//MessageBox(hWnd, pos2, L"Message", MB_OK);
		break;
	
		// ���������ͻ��
	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, L"WM_LBUTTONDBLCLK", L"Message", MB_OK);
		break;


		// ����
	case WM_SYSKEYDOWN:
		//MessageBox(hWnd, L"WM_SYSKEYDOWN", L"Message", MB_OK);//�������� WM_KEYDOWN������Ӧ
		break;

	case WM_SYSKEYUP:
	  MessageBox(hWnd, L"WM_SYSKEYUP", L"Message", MB_OK);
		break;

	// ������ܻ�ȡ��ȷ��ASCII��ֵ��ĸ ����
	case WM_CHAR:
		if (wParam == 97) {
			wsprintf(str, L"%d", wParam);
			MessageBox(hWnd, str, L"Message", MB_OK);
		}

		switch (wParam)
		{
		case 0x01 : //ctrl+a
			MessageBox(hWnd, L"ctrl + a", L"Message", MB_OK);
			break;
		case 'f':
			MessageBox(hWnd, L"f", L"Message", MB_OK);
			break;
		case '@':
			MessageBox(hWnd, L"@", L"Message", MB_OK);
			break;
		}
		break;

		// ��ȡ��ASCII ctrl shift 
	case WM_KEYDOWN:
		//wsprintf(str, L"%d", wParam);
		//MessageBox(hWnd, str, L"Message", MB_OK);
		break;

	case WM_DESTROY:
			PostQuitMessage(0);
			break;
	default:
			// Ĭ�ϵ���Ϣ������
			return	DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

int WINAPI WinMain(
	HINSTANCE hInstance,			// ��ǰ���ھ��
	HINSTANCE hPrevInstance,  // ǰһ�����ھ����Win32��ΪNULL��Win16���µķ��Ŀǰ�����ã�
	LPSTR lpCmdLine,				  // �����в���
	int nCmdShow						  // ������ʾ��ʽ
) 
{
	WNDCLASS wndclass;  //������
	HWND hWnd;					//���ھ��
	MSG msg;						//��Ϣ

	// ���ڱ�Ӱ
	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0)); //��ɫ����
	HBRUSH hHatchBrush = CreateHatchBrush(HS_CROSS, RGB(0x66, 0, 0x66));

	// ����ICON
	int width = GetSystemMetrics(SM_CXSMICON);
	int height = GetSystemMetrics(SM_CYSMICON);

	//HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	//���ɵ�exe�ͻ���ͼ��
	// HICON hIcon = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, width, height, LR_DEFAULTCOLOR); 

	// ���ⲿ����ͼ�� ���� TEXT("test.ico") ����ݵ�ǰϵͳ�ж���ASCII����Unicode L"test.ico"
	HICON hIcon = (HICON)LoadImage(hInstance, TEXT("test.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	

	// wndclass.cbSize = sizeof(WNDCLASSEXW);
	// wndclass.style = 0;
	wndclass.style = CS_DBLCLKS; //�ܹ��������˫���¼�
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = hIcon;
	wndclass.hCursor = NULL;
	wndclass.hbrBackground = hHatchBrush; // (HBRUSH)COLOR_WINDOW;

	//wndclass.lpszMenuName = NULL;
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); //MAKEINTRESOURCE ��Դ��ת���ĺ�


	wndclass.lpszClassName = L"MainWindowClass";
	wndclass.lpfnWndProc = WinProc;

	//ע�ᴰ��
	ATOM win = RegisterClass(&wndclass);

	//��������
	hWnd = CreateWindow(
		L"MainWindowClass",
		L"DaysunWindow",
		WS_OVERLAPPEDWINDOW, //���ڷ��
		0,
		0,
		800,
		600,
		NULL,				  //�����ھ��
		NULL,					//���ڲ˵����
		hInstance,    //��ǰ���ڵľ��
		NULL				  //��ʹ�ø�ֵ
	);

	if (!hWnd) {
		MessageBox(NULL, L"��������ʧ��", L"��ʾ", MB_OK);
		return 0;
	}

	// ��ʾ����
	ShowWindow(hWnd, nCmdShow); //������Ϊ����
	// ShowWindow(hWnd, SW_MAXIMIZE); //�������
	UpdateWindow(hWnd);

	//��Ϣ��ȡ���ַ�
	/*
		typedef struct tagMSG {
			HWND hwnd;   hwnd��ʾ��Ϣ�����Ĵ��ڡ��û�һ�����ڳ���Ĵ����½��в���������һ����Ϣһ�㶼����ĳ������������ġ�������ĳ��������а����������������İ�����Ϣ���Ƿ����ô��ڵġ�
			UINT message;   message��ʾ��Ϣ���ͣ���һ����ֵ����Windows�У���Ϣ����һ����ֵ����ʾ�ģ���ͬ���͵���Ϣ��Ӧ��ͬ����ֵ����������������Ϣ��WM_LBUTTONDOWN�����̰�����Ϣ��WM_KEYDOWN���ַ���Ϣ��WM_CHAR���ȵ�
			WPARAM wParam;
			LPARAM lParam;
			DWORD time;
			POINT pt;
		} MSG;

		���������ĸ���Ա����wParam��lParam������ָ����Ϣ�ĸ�����Ϣ
		������������ֱ��ʾ��ϢͶ�ݵ���Ϣ�����е�ʱ������ĵ�ǰλ�á�
	*/
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg); //����
		DispatchMessage(&msg); //��Ϣ�ַ���ȥ WinProc ���մ���
	}

	return 0;
}