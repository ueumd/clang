#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int myadd(int a, int b) { //子任务的实现者
	printf("func add ... \n");
	return a + b;
}

int myadd2(int a, int b) { //子任务的实现者
	printf("func add ... \n");
	return a + b;
}

int myadd3(int a, int b) { //子任务的实现者
	printf("func add ... \n");
	return a + b;
}

// 定义一个函数指针类型
typedef int(*MyTypeFuncAdd)(int a, int b);

//函数指针 做 函数参数
int MainOp(MyTypeFuncAdd myFuncAdd) {
	int c = myFuncAdd(5, 6);
	return c;
}

int MainOp2(int(*MyPointerFuncAdd)(int a, int b)) {
	int c = MyPointerFuncAdd(5, 6);
	return c;
}

/*
为什么这样设计？
任务调用 和任务编写分开
*/

//任务调用者
void test() {
	MyTypeFuncAdd myFuncAdd = NULL;
	myFuncAdd = myadd;

	myadd(1, 2);		// 直接调用	
	myFuncAdd(3, 4); //间接调用

	MainOp(myadd);
	MainOp2(myadd);

	//在MainOp框架 没有发生任何变化的情况下
	MainOp(myadd2);
	MainOp(myadd3);
}

void main() {
	test();

	system("pause");
}