#include "iostream"

using namespace std;
class FrA
{
public :
	friend void modifyFrA(FrA *pA, int _a); //����modifyFrA����FrA�ĺ�����
	
	FrA(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	
	int getA()
	{
		return this->a;
	}
private:
	int a;
	int b;
};

void modifyFrA(FrA *pA, int _a)
{
	pA->a = _a; //��������Ԫ���� �����ſ��Է���˽������
}
void maind44()
{
	FrA a1(1, 2);
	cout << a1.getA() << endl;

	modifyFrA(&a1, 300);
	
	cout << a1.getA() << endl;

	cout << "hello..." << endl;

	system("pause");
	return;
}