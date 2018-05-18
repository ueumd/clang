#include<Windows.h>
#include "resource.h"
/*
其他的UI库 MFC（庞大） ATL
*/

/*
2.窗口风格设置  CreateWindow  CreateWindowEx
WS_BORDER：windows窄线边
WS_CAPTION：windows标题条，包含WS_BORDER
WS_CHILDWINDOW、WS_CHILD：窗口是一个子窗口，不能与WS_POPUP共用
WS_CLIPCHILDREN：作为父窗口，刷新时裁剪子窗口区域，提高刷新效率
WS_CLIPSIBLINGS：作为子窗口，刷新时裁剪其它子窗口的重叠区域，提高刷新效率
WS_DISABLED：关闭窗口响应，用户的任何操作均无效
WS_DLGFRAME：窗口有一个边框样式，通常与对话框一起使用。这种样式的窗口不能有标题栏。
WS_GROUP：窗口组件化时使用。
演示 WS_HSCROLL：窗口含有水平滚动条。
演示 WS_VSCROLL：窗口含有垂直滚动条。
演示 WS_MAXIMIZE：窗口初始状态最大化。
WS_MINIMIZE：窗口初始状态最小化。
WS_ICONIC：同WS_MINIMIZE
WS_MAXIMIZEBOX：窗口含有最大化按钮
WS_MINIMIZEBOX：窗口含有最小化按钮
WS_OVERLAPPED：重叠模式，含有标题框和边框
WS_TILED：同WS_OVERLAPPED
演示 WS_OVERLAPPEDWINDOW：(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
WS_TILEDWINDOW：同WS_OVERLAPPEDWINDOW
WS_POPUP：弹出窗口模式，不能与WS_CHILD共用
演示 WS_POPUPWINDOW：WS_POPUP | WS_BORDER | WS_SYSMENU
WS_SIZEBOX：窗口具有可伸缩边框。
WS_THICKFRAME：同WS_SIZEBOX
演示 WS_SYSMENU：标题栏带系统菜单，即关闭按钮。
WS_TABSTOP：作为窗口中的控件，设置了WS_TABSTOP标志的控件可以通过TAB键焦点轮转。
WS_VISIBLE：窗口是否可见。 由ShowWindow设置


3.窗口行为设置 ShowWindow()
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

4.窗口图标设置
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


int GetSystemMetrics(  //单位像素
int nIndex
);


示例：自建窗口
讲解：袁春旭

图标文件icon制作

在线制作ICON文件    https://www.ico.la/

离线制作ICON文件    软件介绍：anytoicon
*/

/*
消息处理
WM_CRATE:窗口创建消
WM_MOVE	窗口移动

WM_LBUTTONDOWN 鼠标按下
x = LOWORD(lParam) x位置
y = HIWORD(lParam) y位置

GetCursorPos(&pt) 相对屏幕

WM_KEYDONW 有按键按下
ALT按键 WM_SYSKEYDOWN
可打印按键消息 WM_CHAR
值 wParam
TranslateMessage(&msg)

判断组合键
1 字母：从0x01 - 0x1A   Ctrl + a Ctrl + z （推荐）
2 bIsCtrl = (::GetAsyncKeyState(VK_CONTROL) && 0x8000)
3 bIsCtrl = (::GetKeyState(VK_CONTROL) && 0x8000)
*/

/*
消息菜单 VM_COMMAND
取命令：LOWORD(wParam)
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
			// 默认的消息处理函数
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
		//窗口销毁消息
	
		//鼠标
	case WM_LBUTTONDOWN:
			//x = LOWORD(lParam); //x位置
			//y = HIWORD(lParam); // y位置
			//GetCursorPos(&pt);
			//
			//wsprintf(pos1, L"%d, %d", x, y); // 将pos写入内存当中
			//MessageBox(hWnd, pos1, L"Message", MB_OK);
			//相对屏幕
			//wsprintf(pos2, L"%d, %d", pt.x, pt.y);
			//MessageBox(hWnd, pos2, L"Message", MB_OK);
		break;
	
		// 根单击会冲突的
	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, L"WM_LBUTTONDBLCLK", L"Message", MB_OK);
		break;


		// 按键
	case WM_SYSKEYDOWN:
		//MessageBox(hWnd, L"WM_SYSKEYDOWN", L"Message", MB_OK);//阻塞程序 WM_KEYDOWN不会响应
		break;

	case WM_SYSKEYUP:
	  MessageBox(hWnd, L"WM_SYSKEYUP", L"Message", MB_OK);
		break;

	// 这个才能获取正确的ASCII码值字母 数字
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

		// 获取非ASCII ctrl shift 
	case WM_KEYDOWN:
		//wsprintf(str, L"%d", wParam);
		//MessageBox(hWnd, str, L"Message", MB_OK);
		break;

	case WM_DESTROY:
			PostQuitMessage(0);
			break;
	default:
			// 默认的消息处理函数
			return	DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

int WINAPI WinMain(
	HINSTANCE hInstance,			// 当前窗口句柄
	HINSTANCE hPrevInstance,  // 前一个窗口句柄，Win32下为NULL（Win16留下的废物，目前已弃用）
	LPSTR lpCmdLine,				  // 命令行参数
	int nCmdShow						  // 窗口显示方式
) 
{
	WNDCLASS wndclass;  //窗口类
	HWND hWnd;					//窗口句柄
	MSG msg;						//消息

	// 窗口背影
	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0)); //红色背景
	HBRUSH hHatchBrush = CreateHatchBrush(HS_CROSS, RGB(0x66, 0, 0x66));

	// 窗口ICON
	int width = GetSystemMetrics(SM_CXSMICON);
	int height = GetSystemMetrics(SM_CYSMICON);

	//HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	//生成的exe就会有图标
	// HICON hIcon = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, width, height, LR_DEFAULTCOLOR); 

	// 从外部加载图标 好用 TEXT("test.ico") 会根据当前系统判断用ASCII还是Unicode L"test.ico"
	HICON hIcon = (HICON)LoadImage(hInstance, TEXT("test.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	

	// wndclass.cbSize = sizeof(WNDCLASSEXW);
	// wndclass.style = 0;
	wndclass.style = CS_DBLCLKS; //能够接收鼠标双击事件
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = hIcon;
	wndclass.hCursor = NULL;
	wndclass.hbrBackground = hHatchBrush; // (HBRUSH)COLOR_WINDOW;

	//wndclass.lpszMenuName = NULL;
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); //MAKEINTRESOURCE 资源名转换的宏


	wndclass.lpszClassName = L"MainWindowClass";
	wndclass.lpfnWndProc = WinProc;

	//注册窗口
	ATOM win = RegisterClass(&wndclass);

	//创建窗口
	hWnd = CreateWindow(
		L"MainWindowClass",
		L"DaysunWindow",
		WS_OVERLAPPEDWINDOW, //窗口风格
		0,
		0,
		800,
		600,
		NULL,				  //父窗口句柄
		NULL,					//窗口菜单句柄
		hInstance,    //当前窗口的句柄
		NULL				  //不使用该值
	);

	if (!hWnd) {
		MessageBox(NULL, L"创建窗口失败", L"提示", MB_OK);
		return 0;
	}

	// 显示窗口
	ShowWindow(hWnd, nCmdShow); //窗口行为设置
	// ShowWindow(hWnd, SW_MAXIMIZE); //窗口最大化
	UpdateWindow(hWnd);

	//消息获取，分发
	/*
		typedef struct tagMSG {
			HWND hwnd;   hwnd表示消息所属的窗口。用户一般是在程序的窗口下进行操作，所以一个消息一般都是与某个窗口相关联的。例如在某个活动窗口中按下鼠标左键，产生的按键消息就是发给该窗口的。
			UINT message;   message表示消息类型，是一个数值。在Windows中，消息是由一个数值来表示的，不同类型的消息对应不同的数值。，鼠标左键按下消息是WM_LBUTTONDOWN，键盘按下消息是WM_KEYDOWN，字符消息是WM_CHAR，等等
			WPARAM wParam;
			LPARAM lParam;
			DWORD time;
			POINT pt;
		} MSG;

		第三、第四个成员变量wParam和lParam，用于指定消息的附加信息
		最后两个变量分别表示消息投递到消息队列中的时间和鼠标的当前位置。
	*/
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg); //按键
		DispatchMessage(&msg); //消息分发出去 WinProc 接收处理
	}

	return 0;
}