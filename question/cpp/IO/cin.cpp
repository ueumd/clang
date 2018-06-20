#include "iostream"

using namespace std;
/*
标准输入流对象cin
cin.get() 一次只能读取一个字符
cin.get(一个数参)//读一个字符
cin.get(三个参数)//可以读取字符串

cin.getline()
cin.ignore()
cin.peek()
cin.puback()
*/

void cintest()
{
	char mybuf[1024];
	int myInt;
	long myLong;

	cin >> myInt;
	cin >> myLong;

	cin >> mybuf; //遇见空格会停止接受 数据

	cout << "myInt" << myInt << endl;
	cout << "myLong" << myLong << endl;
	cout << "mybuf" << mybuf << endl;
}

void cinget()
{
	//字符会放在缓冲区
	char ch;
	while ((ch = cin.get()) != EOF) //结束按ctrl+z
	{
		cout << ch << endl;
	}
}

int main()
{
	cintest();
	//cinget();

	cin.get();
	return 0;
}