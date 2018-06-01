#include<stdio.h>
#include<Windows.h>

int main1() {

	printf("表示范围小");

	char ch = 'A'; // 表示范围小，节约内存
	wchar_t ch1 = L'A'; //宽节符2个字节，表示范围

	printf("%d, %d \n", sizeof(char), sizeof(wchar_t)); // 1 2
	printf("%d, %d \n", sizeof(ch), sizeof(ch1));		// 1 2
	
	printf("%d", sizeof("1我")); //4个字节
	printf("\n%d", sizeof(L"1我"));//6个字节 

	// MessageBox(0, "Hello World", "Title1", 0); 与设置有关 unicode为宽字符 ，多字节为窄字符  用TEXT可以自动调节

	MessageBox(0, L"Hello World", L"Title1", 0);



	// TEXT可以兼容自动调整
	MessageBox(0, TEXT("Hello World"), TEXT("Title2"), 0);

	// A 代表调用多字节 窄字符
	//MessageBoxA(0, "你好天朝","你好世界", 0);

	// W 代表调宽字符
	//MessageBoxW(0, L"你好天朝", L"你好世界", 0);

	return 0;
}