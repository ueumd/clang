#include <iostream>
using namespace std;

class VLA {
private:
	const int m_len;	// 数组长度
	int *m_arr;			  // 数组指针

	int *m_p;					// 指向数组第i个元素的指针

	int *at(int i);	  // 获取第i个元素的指针

public:
	VLA(int len);			// 构造函数
	~VLA();						// 析构函数

	void input();		  // 从控制台输入数组元素
	void show();      // 显示数组元素
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
	delete[] m_arr;  //释放内存
}

//终端输入
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
		return m_arr + i; //步长+1
	}
}

int main() {
	int n;
	cout << "Input array length: ";
	cin >> n;

	VLA *parr = new VLA(n);
	//输入数组元素
	cout << "Input " << n << " numbers: ";
	parr->input();

	//输出数组元素
	cout << "Elements: ";
	parr->show();

	// 执行析构函数，释放类成员空间
	delete parr;


	system("pause");
	return 0;
}