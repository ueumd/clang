#include<iostream>
using namespace std;

class Teacher {
public:
	Teacher() {
		cout << "�޲ι��� ��ִ���� " << endl;
	}

	Teacher(int a, int b) {
		m_a = a;
		m_b = b;
		cout << "�вι��� ��ִ���� " << endl;
	}

	Teacher(int a) {
		m_a = a;
		m_b = 0;
		cout << "�вι��� ��ִ���� " << endl;
	}

	~Teacher() {
		cout << "�������� ��ִ���� " << endl;
	}

	int m_a;		
	int m_b;	  

	void say() {
		cout << "��������" << m_a << "���ɼ���" << m_b << endl;
	}
};

void testStudent() {
	int a = 99, b = 10;
	// CPP�������Զ����ù��캯��

	//1���ŷ�
	Teacher t1;				  //�޲�
	Teacher t2(a, b);		//�в�
	
	//2�Ⱥŷ�
	Teacher t3 = (3, 4);//�в� Teacher t3 = 4 (3, 4)���ű��ʽ


	//3�ֶ�����
	Teacher t = Teacher(1, 2); //��������

	//����ִ���� �������� ����

// �����ʼ�� �� ����ֵ ������ͬ����
}

void maincccc() {
	testStudent();

	cin.get();
}