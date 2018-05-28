#include<stdio.h>
#include<stdlib.h>
//导出函数，可以加载的时候调用
_declspec(dllexport) void go()
{
	//函数指针类型必须一致，否则无法调用成功
	//int ** 变量名挖掉就是类型
	//间接调用的方式调用函数，根据地址来调用
	void(*p1)(int a) = (void(*)(int a)) 0x011E1040;  //注意地址是16进制0x-011E1040
	p1(10);
	void(*p2)() = (void(*)()) 0x011E1050;
	p2();
}