#include "iostream"

using namespace std;

class HeroFighter
{
public:
	virtual int power()
	{
		return 10;
	}
};

class EnemyFigther
{
public:
	int attack()
	{
		return 15;
	}
};

class AdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}
};



//��̬����
void playFighter(HeroFighter *hf, EnemyFigther *ef)
{
	//��̬������
	//��дvirtual�ؼ��� ���Ǿ�̬���� c++����������	HeroFighter����ȥִ�� ������͵�power����,�ڱ���������׶ξ��Ѿ������˺����ĵ���
	 
	//д�˾��Ƕ�̬���ࣺ �ٰ //�����е�ʱ�� ���ݾ�����󣨾�������ͣ���ִ�в�ͬ����ĺ������ã����ֳɶ�̬��
	if (hf->power() > ef->attack())
	{
		cout << "����win" << endl;
	}
	else
	{
		cout << "���ǹҵ�" << endl;
	}
	
}

//ԭʼ��ʽ����
void maind6142()
{

	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFigther ef;

	if (hf.power() > ef.attack())
	{
		cout << "����win" << endl;
	}
	else
	{
		cout << "���ǹҵ�" << endl;
	}
	if (Advhf.power() > ef.attack())
	{
		cout << "Advhf����win" << endl;
	}
	else
	{
		cout << "Advhf���ǹҵ�" << endl;
	}



	cout << "hello..." << endl;

	system("pause");
	return;
}

void maind614()
{

	/*
	ʵ�ֶ�̬������������
	1.  Ҫ�м̳�
	2�� Ҫ���麯����д
	3�� �ø���ָ�루�������ã� ָ���������
	*/
	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFigther ef;


	playFighter(&hf, &ef);

	//���������� ִ�е��������opwer()
	playFighter(&Advhf, &ef);

	cout << "hello..." << endl;

	system("pause");
	return;
}