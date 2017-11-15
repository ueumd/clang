#include<stdio.h>
#include<locale.h>

int main() {

	test2();
	system("pause");
	return 0;

}

int test2() {
	setlocale(LC_ALL, "zh-CN"); //表示中文 这样才能正确显示
	wchar_t wstr[10] = L"1234我是射手"; // 宽字符用wprintf
	wprintf(L"%ls", wstr); // 大写L与小写l都是宽字符处理
	
	return 0;
}