#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <fstream>


using namespace std;

void fsread()
{

	//��D��д��һ��2.txt�ļ�
	char * fname = "d:/2dddd44d.txt";
	//�������ʽ���ļ�
	ofstream fout(fname, ios::app);//��һ�������������ļ�����

	if (!fout)
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	//���ļ�д������
	fout << "hello...111" << endl;
	fout << "hello...222" << endl;
	fout << "hello...333" << endl;

	fout.close();
	//�����뷽ʽ���ļ�
	ifstream fin(fname, ios::in);//����һ����������������ļ�����

	char ch;
	while (fin.get(ch))
	{
		cout << ch; //���ļ���ȡ����
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

//������д��
void ejzread()
{
	char *fname = "d://11.dat";
	ofstream fout(fname, ios::binary);

	if (!fout)
	{
		cout << "���ļ�ʧ��" << endl;
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