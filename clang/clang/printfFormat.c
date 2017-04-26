#include<stdlib.h>
#include<stdio.h>
#define PAGES 931
#define STR "Jvascript-Nodejs"
int mainprintfformat()
{
	/*
	http://www.cppblog.com/totti1006/archive/2010/03/10/109341.html
	https://my.oschina.net/idreamo/blog/675006
	http://www.cnblogs.com/iceocean/articles/1594206.html
	*/
	printf("%s\n", "1234567890123456");

	/*
	m:%md
	用十进制整数来表示输出的最少位数 
	若实际位数多于定义的宽度，则按实际位数输出
	若实际位数少于定义的宽度则补以空格或0。
	*/
	printf("%10d\n", PAGES);	//0000000931 前面补7个空格
	printf("%6d\n", PAGES);		//   931 前面补3个空格
	printf("%06d\n",PAGES);     //000931 前面补3个000
	printf("%6d\n", 931931931); //931931931 前面无
	
	/* +输出正负符号*/
	printf("%d\n", PAGES);	//931
	printf("%+d\n", PAGES); //+931 +输出正负符号
	printf("负数：%+d\n", -931); //-931

	/*- 左对齐*/
	printf("*%-10d*\n\n", PAGES);  // -左对齐 931<m(10) 在931后补7空格
	
	printf("65=%c,66=%c\n\n", 65,66);	//A B

	printf("%十六进制：\n\n");	
	printf("%x\n", 11);		//b
	printf("%X\n", 11);		//B
	printf("%0X\n", 11);    //B 多这个啥意思？

	/*#x 输出带有0x的十六进制数*/
	printf("%#x\n\n", 11);  //0xb

	//8
	printf("%o\n",11); //13
	printf("%#o\n", 11); //013


	// Printf格式化浮点值
	/*
	 浮点数值通常都有一个小数点和一个可选的后缀e(大写或小写，表示科学计数法)。
     在e和指数之间可以用正（+）或负（-）表示指数的正负（正数的话可以省略符号）。
	 6.023e23
	*/

	double some = 6.023e23; //

	printf("%f\n",some);    //602299999999999975882752.000000  f小数点后6位，四舍五入
	printf("%10.3f\n",some);//602299999999999975882752.000  小数点后位，四舍五入
	printf("%e\n",some);	//6.023000e+23 double型的参数以指数形式打印，有一个数字会在小数点前，六位数字在小数点后，而在指数部分会以小写的e来表示。
	printf("%.4e\n", some); //6.0230e+23
	printf("%g\n\n", some);   //6.023e+23 %g double 型的参数会自动选择以%f 或%e 的格式来打印，其标准是根据欲打印的数值及所设置的有效位数来决定。


	const double c = 12345678.12385678;

	printf("%f\n",c); //12345678.123857 //后6位四舍五入
	printf("%.3f\n",c);//12345678.124

	/*
	科学记数法
	http://baike.baidu.com/item/科学记数法
	*/
	printf("%e\n",c);//1.234568e+07
	printf("%e\n\n",c);//1.234568e+07

	//Printf 格式化字符串
	printf("%s\n",STR);		//Jvascript-Nodejs
	printf("%020s\n", STR);	//0000Jvascript-Nodejs 补4个0
	printf("%.5s\n", STR);	//Jvasc
	

	printf("\n\n\n");

	// %u 输出无符号的十进制的整数
	printf("%d\n", 7); //7
	printf("%x\n", -7);//fffffff9(-7的补码)
	/*
	：f    f    f    f    f    f    f    9
	补码：1111 1111 1111 1111 1111 1111 1111 1001
	反码：1111 1111 1111 1111 1111 1111 1111 1000
	原码：1000 0000 0000 0000 0000 0000 0000 0111
	*/


	printf("%u\n", -7);// 4294967289    十六进制：fffffff9 ->十进制：4294967289
	/*
	当用无符号数最二进制的最高位代表的不是符号了
	简单理解：
	7  原码：0000 0111
	-7 原码：1000 0111

	如果认为：1000 0111 最高位1不是符号数，那么十六进制：87，十进制： 135
	*/
	system("pause");
	return 0;

}