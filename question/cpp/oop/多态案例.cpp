#include "iostream"
using namespace std;

// Ӣ������
class HeroFighter
{
public:
	virtual int power() {
		return 10;
	}
};

// �߼�Ӣ������
class AdvHeroFighter : public HeroFighter
{
public:
	virtual int power() {
		return 20;
	}
};

// �л�
class EnemyFigther
{
public:
	int attack(){
		return 15;
	}
};


// ԭʼ��ʽ����
void dt1()
{
	HeroFighter    hf;
	AdvHeroFighter Advhf;
	EnemyFigther   ef;

	// 10  15 ���ǹҵ�
	if (hf.power() > ef.attack()) {
		cout << "����win" << endl;
	}
	else
	{
		cout << "���ǹҵ�" << endl;
	}

	// 20  15  Advhf����win
	if (Advhf.power() > ef.attack()){
		cout << "Advhf����win" << endl;
	}
	else{
		cout << "Advhf���ǹҵ�" << endl;
	}

}


/*
��̬������
��дvirtual�ؼ��� ���Ǿ�̬���� c++����������	HeroFighter����ȥִ�� ������͵�power����,�ڱ���������׶ξ��Ѿ������˺����ĵ���
д�˾��Ƕ�̬���ࣺ �ٰ //�����е�ʱ�� ���ݾ�����󣨾�������ͣ���ִ�в�ͬ����ĺ������ã����ֳɶ�̬��
*/
void playFighter(HeroFighter *hf, EnemyFigther *ef)
{
	if (hf->power() > ef->attack())
	{
		cout << "����win" << endl;
	}
	else
	{
		cout << "���ǹҵ�" << endl;
	}

}

//��̬����
void dt2()
{

	/*
	ʵ�ֶ�̬������������
	1.  Ҫ�м̳�
	2�� Ҫ���麯����д
	3�� �ø���ָ�루�������ã� ָ���������
	*/
	HeroFighter    hf;
	AdvHeroFighter Advhf;
	EnemyFigther   ef;

	playFighter(&hf, &ef);

	//���������� ִ�е��������opwer()  //�βθ������ÿ���ֱ�������������
	playFighter(&Advhf, &ef);

}

void main11() {
	//1 ԭʼ����
	dt1();

	//2 ��̬����
	dt2();

	cin.get();
}