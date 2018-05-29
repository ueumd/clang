#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <fstream>


using namespace std;

void fsread()
{

	//向D盘写入一个2.txt文件
	char * fname = "d:/2dddd44d.txt";
	//以输出方式打开文件
	ofstream fout(fname, ios::app);//建一个输出流对象和文件关联

	if (!fout)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//向文件写入数据
	fout << "hello...111" << endl;
	fout << "hello...222" << endl;
	fout << "hello...333" << endl;

	fout.close();
	//以输入方式打开文件
	ifstream fin(fname, ios::in);//建立一个对输入流对象和文件关联

	char ch;
	while (fin.get(ch))
	{
		cout << ch; //从文件读取数据
	}

	fin.close();
}
class TeacherTest
{
public:
	TeacherTest()
	{
		age = 18;
		strcpy(name, "");
	}
	TeacherTest(int _age, char *_name)
	{
		age = _age;
		strcpy(name, _name);
	}
	void printT()
	{
		cout << "age: " << age << "  name:" << name << endl;
	}
private:
	int age;
	char name[32];
};

//二进制写入
void ejzread()
{
	char *fname = "d://11.dat";
	ofstream fout(fname, ios::binary);

	if (!fout)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	TeacherTest t1(18, "t1");
	TeacherTest t2(20, "t2");

	fout.write((char *)&t1, sizeof(t1));

	fout.write((char *)&t2, sizeof(t2));

	fout.close();

	ifstream fin(fname);
	TeacherTest tmp;
	fin.read((char *)&tmp, sizeof(TeacherTest));
	tmp.printT();
	
	fin.read((char *)&tmp, sizeof(TeacherTest));
	tmp.printT();

	fin.close();
}

int main1022()
{
	//fsread();
	ejzread();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}