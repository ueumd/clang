#include<iostream>
using namespace std;

class Array {
public:
	Array(int length) {
		if (length < 0) {
			length = 0;
		}
		m_length = length;
		m_p = new int[m_length];
	}

	//Array a2 = a1;
	Array(const Array& obj) {
		this->m_length = obj.m_length;
		this->m_p = new int[this->m_length];

		for (int i = 0; i < m_length; i++) {
			this->m_p[i] = obj.m_p[i];
		}
	}
	~Array() {
		if (m_p != NULL) {
			delete[] m_p;
			m_length = -1;
		}
	}

public:
	//��������ֵ����Ҫ����һ������
	//Ӧ�÷���һ�����ã�Ԫ�ر�����������һ��ֵ
	int& operator[](int i); 
	const int & operator[](int i) const;
	Array& Array::operator=(Array &a1);

public:
	int length() const {
		return m_length;
	}

	void display() const {
		for (int i = 0; i < m_length; i++) {
			if (i == m_length - 1) {
				cout << m_p[i] << endl;
			}
			else {
				cout << m_p[i] << ", ";
			}
		}
	}

private:
	int m_length;
	int *m_p;
};

int & Array::operator[](int i) {
	return m_p[i];
}


const int & Array::operator[](int i) const {
	return m_p[i];
}

// a3=a1;
Array& Array::operator=(Array &a1) {
	// 1�ͷ�ԭ�����ڴ�
	if (this->m_p != NULL) {
		delete[] m_p;
		m_length = 0;
	}

	// 2����a1��С�����ڴ�
	m_length = a1.m_length;
	m_p = new int[m_length];


	// 3 copy data
	
	for (int i = 0; i < m_length; i++) {
		m_p[i] = a1.m_p[i];
	//	m_p[i] = a1[i]; //�Ѿ�������[]�����Կ�����д
	}

	return *this; //����a3
}

/*
����[]���±��������
����ֵ���� & operator[ ] (����);
const ����ֵ���� & operator[ ] (����) const;
*/
void test2() {
	Array A(5);
	for (int i = 0, len = A.length(); i < len; i++) {
		// �������±������
		A[i] = i * 5;
	}
	A.display(); // 0, 5, 10, 15, 20

	const Array B(5);
	cout << B[5 - 1] << endl;  //�������һ��Ԫ��

														 //B[4] ת��Ϊ B.operator[](4)
}


void main() {
	test2();

	{
		Array a1(10);

		for (int i = 0, len = a1.length(); i < len; i++) {
			// �������±������
			a1[i] = i * 5;
		}
		a1.display();

		Array a2 = a1;

		a2.display();

		Array a3(5);

		for (int i = 0, len = a3.length(); i < len; i++) {
			// �������±������
			a3[i] = i * 5;
		}

		a3 = a2 = a1;  //�Ƚ������ ����=

		a3.display();
	}


	cin.get();
}