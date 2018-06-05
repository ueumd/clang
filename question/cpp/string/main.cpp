#include <iostream>
#include <string>
using namespace std;
#if 0
与C风格的字符串不同，string 的结尾没有结束标志'\0'。
#endif

void test1() {
	string s1;											//空值 ''
	string s2 = "c plus plus";	
	string s3 = s2;		
	string s4(5, 's');						 //sssss

	cout << "s1: " << s1 << "s2: " << s2 << "s3: " << s3 << "s4: " << s4 << endl;

	// s1: s2: c plus pluss3: c plus pluss4: sssss
}

//转换成C风格字符串
void toCStyleString() {
	string path = "D:\\demo.txt";

	char cPath[100];
	strcpy(cPath, path.c_str());

	FILE *fp = fopen(cPath, "rt");

	cout << cPath << "\t" << path.length()  << endl;//D:\demo.txt     11
	cout << cPath << "\t" << sizeof(cPath) << endl; //D:\demo.txt     100
	cout << cPath << "\t" << strlen(cPath) << endl; //D:\demo.txt     11
}

void viewString() {
	string s = "ABCD123EFG";
	for (int i = 0, len = s.length(); i < len; i++) {
		cout << s[i] << ", "; 	//A, B, C, D, 1, 2, 3, E, F, G,
	}
	cout<<endl;

	s[1] = '9'; //改变下标1位置的元素B->9

	cout << s << endl;				// A9CD123EFG
}

int main() {
	test1();
	toCStyleString();
	viewString();


	system("pause");
	return 0;
}