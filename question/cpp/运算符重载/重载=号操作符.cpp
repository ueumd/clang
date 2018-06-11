#include<iostream>

using namespace std;

class Name {
public:
	Name(const char *p)  {
		m_len = strlen(p);
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, p);
	}

	/*
	Name obj2 = obj1;
	����������ֹ���д�������캯�� ʹ�����
	*/
	Name(const Name& obj) {//���ƹ��캯��
		m_len = obj.m_len;
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, obj.m_p);
	}		

	/*
	obj3 = obj1; //c++�������ṩ��=�Ų��� Ҳ�� ǳ����
	obj3.operator=(obj1)
	*/
	//void operator=(Name &obj1) {
	Name& operator=(Name &obj1) {
		//1 ���ͷžɵ��ڴ�
		if (this->m_p != NULL) {
			delete[] m_p;
			m_len = 0;
		}

		//2 ����obj�����ڴ��С
		this->m_len = obj1.m_len;
		this->m_p = new char[m_len + 1];

		//��obj1��ֵ
		strcpy(m_p, obj1.m_p);
		return *this;
	}

	//Name& operator=(const Name&); //���ظ�ֵ�����
	~Name() {
		if (m_p != NULL) {
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}

public:
	char *m_p;
	int m_len;
};

void mainequal() {
	Name obj1("ZhangShan");

	Name obj2 = obj1;				//c++�������ṩ�ģ� Ĭ��copy���캯�� ǳ����

	Name obj3("NoName");	
	//obj3 = obj1;	//c++�������ṩ��=�Ų��� Ҳ�� ǳ����


	obj3 = obj1; 
	//obj3.operator=(obj1);

	obj1 = obj2 = obj3;
	// obj2.opeartor=(obj3)
	// obj1 = void; ����	C2679	�����ơ� = ��: û���ҵ����ܡ�void�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)
	// ��������� 	Name& operator=(Name &obj1) {return *this}

	cout << obj1.m_p << endl;
	cout << obj3.m_p << endl;

	obj3.m_p = "aaaa";
	cout << obj1.m_p << endl;
	cout << obj3.m_p << endl;


	cin.get();
}