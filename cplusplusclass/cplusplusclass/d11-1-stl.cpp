#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


void vectorTest()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(-1);
	v1.push_back(2);

	//������ �൱��һ��ָ��
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " "; //1 2 3
	}

	//�㷨 �㷨�͵������޷�����
	int num1 = count(v1.begin(), v1.end(), 2); //����2 ���м���

	cout << "num1: " << num1 << endl;

}

int main11111()
{
	vectorTest();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}