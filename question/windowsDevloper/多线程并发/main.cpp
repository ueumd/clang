#include <Windows.h>
#include <process.h>
#include <stdio.h>


void run(void *p) {
	int *px = (int *)p;
	printf("�߳�%d����; ", *px);

	char str[100] = {0}; //�ַ�����

	MessageBox(0, L"ABC", L"Title1", 0);
}

int main() {
	for (int i = 0; i < 5; i++) {
		//run();
		_beginthread(run, 0, &i);
		Sleep(10);
	}
	system("pause");
	return 0;
}