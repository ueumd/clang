#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main同步() {
	while (-1) {//-2，3，非0死循环，0 不循环
	
		//同步:
		//system("calc");

		/**
		异步：
		第一个参数是代表系统弹出
		第二个参数是代表执行
		第三个参数执行命令行
		第四个，第五个默认0，
		第六个参数，0代表窗口隐藏，1代表正常,3最大化,6最小化
		*/
		ShellExecuteA(0, "open", "notepad", 0, 0, 6);
	
		// Sleep()以毫秒为单位，1秒 = 1000毫秒;
		Sleep(2000);
	}
	return 0;
}