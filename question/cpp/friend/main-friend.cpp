#include <iostream>
using namespace std;

#if 0
�ؼ��֣�friend
��Ԫ���� ���Է��ʵ�ǰ���е����г�Ա������ public��protected��private ���Եġ�
��Ԫ��
#endif

#if 0
ע��ĵط���
- ��ǰ����Address��
- �ȶ����࣬�ٶ������Ա����
#endif

class Address;  //��ǰ����Address��

class Student {
public:
	Student(char *name, int age, float score);

public:
	//��Ԫ����
	friend  void show(Student *pStu);

public:
	void setName(char *name);
	char* getName() const;
	void showAddr(Address *addr);

private:
	char *m_name;
	int m_age;
	float m_score;
};

class Address {
public:
	Address(char *province, char *city, char *district);
public:
	friend class Student; //��Ԫ�� Student��Address����Ԫ��
private:
	char *m_province;   //ʡ��
	char *m_city;				//����
	char *m_district;   //����������
};

Address::Address(char *province, char *city, char *district) {
	m_province = province;
	m_city = city;
	m_district = district;
}

Student::Student(char *name, int age, float score) : m_name(name), m_age(age), m_score(score) { }

//���Ա����
void Student::setName(char *name) {
	m_name = name;
}

//����Ա����
char * Student::getName() const {
	return m_name;
}

//��Ԫ������ͬ����ĳ�Ա����������Ԫ�����в���ֱ�ӷ�����ĳ�Ա������Ҫ��������
//showͬʱҲ��һ��ȫ�ֺ������������κ���

void show(Student *pStu) {
	cout << pStu->m_name << "�������� " << pStu->m_age << "���ɼ��� " << pStu->m_score << endl;
}

void Student::showAddr(Address *addr) {
	cout << m_name << "�������� " << m_age << "���ɼ��� " << m_score << endl;
	cout << "��ͥסַ��" << addr->m_province << "ʡ" << addr->m_city << "��" << addr->m_district << "��" << endl;
}

// ��ͨ��ȫ�ַ�������ֻ�ܷ���Student��public��Ա���� �� ��Ա����
void showTest(Student *pStu) {
	cout << pStu->getName() << endl;
}

int main() {
	Student stu("С��", 15, 90.6);
	show(&stu);

	Student *pstu = new Student("����", 16, 80.5);
	show(pstu);  //������Ԫ����


	Address *paddr = new Address("�ӱ�", "��ˮ", "�ҳ�");
	pstu->showAddr(paddr);

	showTest(&stu); //С��

	/*
	С���������� 15���ɼ��� 90.6
	���ڵ������� 16���ɼ��� 80.5
	���ڵ������� 16���ɼ��� 80.5
	��ͥסַ���ӱ�ʡ��ˮ���ҳ���
	С��
	*/

	system("pause");
	return 0;
}