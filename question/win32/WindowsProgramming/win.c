#include <windows.h>

/*
int WINAPI MessageBox( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType );
����˵����
hWnd��		����Ϣ��ĸ����ھ��������˲���ΪNULL�������Ϣ��û��ӵ�и����ڡ�
lpText����Ϣ������ݡ�LPCTSTR ���Զ����������ͣ��ȼ��� const char *��
lpCaption����Ϣ��ı��⡣
uType���Ի���İ�ť��ʽ��ͼ�ꡣ
*/

//int WINAPI WinMain11(
//	HINSTANCE hInstance,			// ��ǰ���ھ��
//	HINSTANCE hPrevInstance,  // ǰһ�����ھ����Win32��ΪNULL��Win16���µķ��Ŀǰ�����ã�
//	LPSTR lpCmdLine,					// �����в���
//	int nCmdShow						  // ������ʾ��ʽ
//) {
//	int nSelect = MessageBox(NULL, TEXT("Hello!"), TEXT("����"), MB_OKCANCEL);
//
//	if (nSelect == IDOK) {
//		MessageBox(NULL, TEXT("�����ˡ�ȷ������ť"), TEXT("��ʾ"), MB_OK);
//	}
//	else {
//		MessageBox(NULL, TEXT("�����ˡ�ȡ������ť"), TEXT("��ʾ"), MB_OK);
//	}
//
//	return 0;
//}