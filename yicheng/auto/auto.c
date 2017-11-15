#include <stdio.h>
/**
只要在函数内部 int num 等价于 auto int num
*/
void go() {
	auto int num = 10; //自动分配 自动释放
	printf("%p", &num);
}

int main() {
	go();
	printf("AAAAAAAAA\n");
	go();
	printf("AAAAAAAAA\n");
	return 0;
}