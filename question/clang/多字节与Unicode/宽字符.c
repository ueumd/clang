#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //本地化
#include<Windows.h>

void charAndChinese() {
	/*
	1 一个汉字占两个字节
	2 字符串可以显示汉字，字符不可以
	3 两个%c连在一起可以显示一个汉字
	*/
	char str[] = "这里是上海";

	char c = '中'; //ASCCI码表里没有这个字符,字符只能是ASCCI码里的

	printf("str = %s\n", str);				// str = 这里是上海
	printf("%c%c\n", str[0], str[1]); //这
	printf("c = %c\n", c);						//c = ? 任何情况下都不能正常输出
																		// printf("c = %s\n", c); error
}

//宽字符
void testWchar_t() {
	wchar_t ch = L'中';					  // L 宽字符 || 宽字符串
	printf("%d\n", sizeof(ch));		// 2

	setlocale(LC_ALL, "chs");			// 简体中文

	wprintf(L"%wc\n", ch);			  // 输出中 必须要设置语言版本，因为有其他国语言
	//printf(L"%wc\n", ch);       // printf不能打印宽字符

	wchar_t str[100] = L"我是一个好鸟ABC";	
	wprintf(L"str = %s\n", str);		// str = 我是一个好鸟ABC
	printf("%d\n", wcslen(str));		// 9
}

// 意义 当处理检索汉字的时候 一个汉字就是一个字符
void testWchar_t2() {
	setlocale(LC_ALL, "chs");
	wchar_t ch1 = L'我';
	wchar_t ch2 = L'是';
	wchar_t ch3 = L'A';

	wprintf(L"%wc%wc%wc\n" , ch1, ch2, ch3); // 我是A
}

void main()
{

	// charAndChinese();

	testWchar_t();
	testWchar_t2();

	//printf("这里是上海\n");

	// 1 使用多字节字符集正常显示 使用Unicode时不能显示
	MessageBox(0, "这里是上海", "城市", 0); 
	  
	// 1 使用Unicode字符集时正常显示 多字节字符集不能显示
	MessageBox(0, L"这里是上海", L"城市", 0);

	MessageBoxW(0, L"这里是上海", L"城市", 0); //都可以

	system("pause");

}