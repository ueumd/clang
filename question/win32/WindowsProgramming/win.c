#include <windows.h>

/*
int WINAPI MessageBox( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType );
参数说明：
hWnd：		该消息框的父窗口句柄，如果此参数为NULL，则该消息框没有拥有父窗口。
lpText：消息框的内容。LPCTSTR 是自定义数据类型，等价于 const char *。
lpCaption：消息框的标题。
uType：对话框的按钮样式和图标。
*/

//int WINAPI WinMain11(
//	HINSTANCE hInstance,			// 当前窗口句柄
//	HINSTANCE hPrevInstance,  // 前一个窗口句柄，Win32下为NULL（Win16留下的废物，目前已弃用）
//	LPSTR lpCmdLine,					// 命令行参数
//	int nCmdShow						  // 窗口显示方式
//) {
//	int nSelect = MessageBox(NULL, TEXT("Hello!"), TEXT("标题"), MB_OKCANCEL);
//
//	if (nSelect == IDOK) {
//		MessageBox(NULL, TEXT("你点击了“确定”按钮"), TEXT("提示"), MB_OK);
//	}
//	else {
//		MessageBox(NULL, TEXT("你点击了“取消”按钮"), TEXT("提示"), MB_OK);
//	}
//
//	return 0;
//}