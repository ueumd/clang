#include <iostream>
using namespace std;

class VLA {
private:
	const int m_len;	// ���鳤��
	int *m_arr;			  // ����ָ��

	int *m_p;					// ָ�������i��Ԫ�ص�ָ��

	int *at(int i);	  // ��ȡ��i��Ԫ�ص�ָ��

public:
	VLA(int len);			// ���캯��
	~VLA();						// ��������

	void input();		  // �ӿ���̨��������Ԫ��
	void show();      // ��ʾ����Ԫ��
};

VLA::VLA(int len) :m_len(len) {
	if (len > 0) {
		m_arr = new int[len];
	}
	else {
		m_arr = NULL;
	}
}

VLA::~VLA() {
	delete[] m_arr;  //�ͷ��ڴ�
}

//�ն�����
void VLA::input() {
	for (int i = 0; m_p = at(i); i++) {
		cin >> *at(i);
	}
}

void VLA::show() {
	for (int i = 0; m_p = at(i); i++) {
		if (i == m_len - 1) {
			cout << *at(i) << endl;
		}
		else {
			cout << *at(i) << ", ";
		}
	}
}

int * VLA::at(int i) {
	if (!m_arr || i < 0 || i >= m_len) {
		return NULL;
	}
	else {
		return m_arr + i; //����+1
	}
}

int main() {
	int n;
	cout << "Input array length: ";
	cin >> n;

	VLA *parr = new VLA(n);
	//��������Ԫ��
	cout << "Input " << n << " numbers: ";
	parr->input();

	//�������Ԫ��
	cout << "Elements: ";
	parr->show();

	// ִ�������������ͷ����Ա�ռ�
	delete parr;


	system("pause");
	return 0;
}