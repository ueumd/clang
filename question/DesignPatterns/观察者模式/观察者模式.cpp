/*
����Ӧ��
- �����¼�������������е��ⲿ�¼�
- ����/����ĳ�������״̬�仯
- ������/������(publisher/subscriber)ģ���У���һ���ⲿ�¼����µĲ�Ʒ����Ϣ�ĳ��ֵȵȣ�������ʱ��֪ͨ�ʼ��б��еĶ�����
�����ڣ�
��������һ��һ�Զ��������ϵ��ʹ��ÿһ������ı�״̬�����������������ǵĶ��󶼻�õ�֪ͨ��

ʹ�ó�����������һ��һ�Զ�Ĺ�ϵ���ö���۲���󣨹�˾Ա����ͬʱ����һ������������飩���������״̬�����仯ʱ����֪ͨ���еĹ۲��ߣ�ʹ�����ܹ������Լ���
*/

#include <iostream>
#include "vector"
#include "string"
using namespace std;

class Secretary;

//����Ϸ��ͬ���ࣨ�۲��ߣ�
class PlayserObserver{
public:
	PlayserObserver(string name, Secretary *secretary){
		m_name = name;
		m_secretary = secretary;
	}
	void update(string action){
		cout << "�۲����յ�action:" << action << endl;
	}
private:
	string		m_name;
	Secretary	*m_secretary;
};

//�����ࣨ�������֪ͨ�ߣ�
class Secretary {
public:
	void addObserver(PlayserObserver *o){
		v.push_back(o);
	}
	void Notify(string action){
		for (vector<PlayserObserver *>::iterator it = v.begin(); it != v.end(); it++){
			(*it)->update(action);
		}
	}
	void setAction(string action){
		m_action = action;
		Notify(m_action);
	}
private:
	string m_action;
	vector<PlayserObserver *> v;
};

void main1()
{
	//subject ���۲���
	Secretary *s1 = new Secretary;

	//����Ĺ۲��߱�֪ͨ����
	PlayserObserver *po1 = new PlayserObserver("С��", s1);

	//PlayserObserver *po2 = new PlayserObserver("С��", s1);

	s1->addObserver(po1);
	//s1->addObserver(po2);

	s1->setAction("�ϰ�����");
	s1->setAction("�ϰ�����");
	cout << "hello..." << endl;
	system("pause");
	return;
}
