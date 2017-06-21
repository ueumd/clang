#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


void vectort1()
{
	vector<int> v1;

	cout << "length:" << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "length:" << v1.size() << endl;

	cout << v1.front() << endl;

	//�޸�ͷ��Ԫ�� ��������ֵ����ֵ Ӧ�÷���һ������
	v1.front() = 20;

	while (v1.size() > 0)
	{
		cout << v1.back();//��ȡβ��Ԫ��
		v1.pop_back();//ɾ��β��Ԫ��
	}
	cout << endl;
	cout << "length:" << v1.size() << endl; //0

}

void vectorInit()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2=v1;//�����ʼ�� vector�ṩ�˿������캯��
	vector<int> v3(v1.begin(), v1.begin() + 2);
}

void printVecotr(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

//���鷽ʽ���� ��ֵ ��ӡ
void vectorfz()
{
	vector<int> v1(10); //��forѭ����ֵʱ ����Ҫ�ڴ�ռ�׼���� (10)

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		//cout << v1[i] << " ";
	}

	//��������ʽ��ӡ
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//��������ʽ��ӡ �������
	for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	printVecotr(v1);

	cout << endl;

	vector<int> v2(10);
	v2.push_back(100);
	v2.push_back(200);
	//ǰ���ʼ��10��0 �����ٲ���100 200
	printVecotr(v2);//0 0 0 0 0 0 0 0 0 0 100 200
}

void vectorRemoveAndInser()
{
	vector<int> v1(10); //��forѭ����ֵʱ ����Ҫ�ڴ�ռ�׼���� (10)

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	//����ɾ��
	v1.erase(v1.begin(), v1.begin() + 3);
	printVecotr(v1);//4 5 6 7 8 9 10

	cout << endl;
	//ָ��λ��ɾ��
	v1.erase(v1.begin());
	printVecotr(v1);//5 6 7 8 9 10
	cout << endl;

	//����Ԫ�ص�ֵɾ��
	v1[1] = 2;
	v1[3] = 2;
	printVecotr(v1);
	cout << endl;
	for (vector<int>::iterator it = v1.begin(); it != v1.end();)
	{
		if (*it == 2) //����2��ȫ��ɾ��
		{
			it = v1.erase(it);//�� ɾ����������ָ���Ԫ�ص�ʱ��  eraseɾ����������it�Զ����ƶ�
		}
		else 
		{
			it ++;
		}
	}
	printVecotr(v1);
}

void vectorInsert()
{

	vector<int> v1(10); //��forѭ����ֵʱ ����Ҫ�ڴ�ռ�׼���� (10)

	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	printVecotr(v1);

	cout << endl;
}

int main1131()
{
	//vectort1();
	//vectorfz();

	//vectorRemoveAndInser();

	vectorInsert();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}