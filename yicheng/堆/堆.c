#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void heapTest() {
	//内存分配，malloc calloc,realloc
	int *p = (int *)malloc(sizeof(int) * 10); //分配内存 指针类型
	printf("p=%p\n", p);

	int num = 0;
	for (int *px = p; px < p + 10; px++) { // 这里是步长++ 每次步长4
		*px = num;
		printf("%p, %d\n", px, *px); //此处打断点 可以看到在内存分配了10个地址
		num++;
	}

	free(p);

	/*
	可以看到在内存分配了10个地址 int类型指针占4个字节  这里是步长++ 每次步长4
	0x0071DDA8    +0   +0   +0   +0  ....
	0x0071DDAC    +1   +0   +0   +0  ....
	0x0071DDB0    +2   +0   +0   +0  ....
	0x0071DDB4    +3   +0   +0   +0  ....
	0x0071DDB8    +4   +0   +0   +0  ....
	0x0071DDBC    +5   +0   +0   +0  ....
	0x0071DDC0    +6   +0   +0   +0  ....
	0x0071DDC4    +7   +0   +0   +0  ....
	0x0071DDC8    +8   +0   +0   +0  ....
	0x0071DDCC    +9   +0   +0   +0  ....

	p=0071DDA8
	0071DDA8, 0
	0071DDAC, 1
	0071DDB0, 2
	0071DDB4, 3
	0071DDB8, 4
	0071DDBC, 5
	0071DDC0, 6
	0071DDC4, 7
	0071DDC8, 8
	0071DDCC, 9
	*/
}

int mainA() {

	/*
	这里运行了两次heapTest() 第一次运行内存并没有释放 第二次运行又开辟了新的空间
	所以堆不会自动释放内存，占着茅坑不拉S
	只能手工释放 free(p) 这时在运行时两次的内存地址是一样的。因为第一次运行完后释放，第二次接着上次内存的地址从新赋值
	*/
	heapTest();

	//此处打断点

	heapTest();

	//此处打断点
	system("pause");
	return 0;
}

int mainB() {
	/*
	b  表示二进制中的一个比特位（bit）
	B  表示字节（byte），一个字节是由 8 个 bit 组成的，1B = 8b
	kB 表示千字节（kilobyte），1kB = 1024B

	int a = 1; //4个字节 4B 占用内存： 4/1024 = 0.00390625

	换算：http://www.elecfans.com/tools/zijiehuansuan.html

	在计算机储存单位中最小的是B（字节），一个英文字符需要占用1个字节的空间，一个汉字需要占用2个字节的空间，
	其单位之间的换算如下：
	1KB=1024B 
	1MB=1024KB 
	1GB=1024MB
	1TB=1024GB 

	以下单位很少用，很少被提及
	1PB=1024TB 
	1EB=1024PB 
	1ZB=1024EB 
	1YB=1024ZB
	*/
	int abc = 1;
	printf("abc = %d\n", sizeof(abc)); //abc = 4
	
	unsigned long long ULL = 1024 * 1024 * 1024;  //ll   2^64-1  鲸吞
	/*
	1GB=1024MB		1MB=1024KB		1KB=1024B		1B=8bit
	1G = 1024×1024×1024B= 1024×1024KB
	*/
	ULL *= 1; //1G内存 //
	void *p = malloc(ULL);
	if (NULL == p) {
		printf("内存分配失败\n");
	}
	else {
		printf("内存分配成功\n"); //在windows进程里可以看到占1G内存 1051372K
	}

	system("pause");
	return 0;
}

int mainC(){
	// 慢慢的吃内存
	while (1)
	{
		//内存一定要及时释放
		void *p = malloc(1024 * 1024 * 100);//p, 栈    *(p+3)地址指向的内容
		Sleep(3000);
		free(p);//释放内存
		Sleep(3000);

	}
	system("pause");
	return 0;
}