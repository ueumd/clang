#include<iostream>
using namespace std;
#if 0
1) �ܹ����ص������������
+ -*/ %  ^  & | ~!= <  > += -= *= /= %= ^= &= |= << >> <<= >>= == != <= >= && || ++  --, ->*  ->  ()[]  new  new[]  delete  delete[]
[]���±��������()�Ǻ�������������������Լ��������ǰ�úͺ�����ʽ���������ء�

2) ���ܱ�����
���������sizeof�����������: ? ����Աѡ���.������������::���ܱ�����

3) ���ز���ı���������÷���ԭ���м���������������������߻������ұߣ���Щ������ı䡣
����~���ұ�ֻ��һ���������� + �����ǳ���������������֮�䣬���غ�Ҳ������ˡ�

4) ��������غ���������Ĭ�ϵĲ���������͸ı���������������ĸ���������Ȼ�Ǵ���ġ�

5) ��������غ����ȿ�����Ϊ��ĳ�Ա������Ҳ������Ϊȫ�ֺ�����

���ʣ� ��������
#endif

class Complex
{
public:
	int m_a;
	int m_b;
public:
	Complex() {}
	Complex(int a, int b) :m_a(a), m_b(b) {}

	//����ǰ++
	void operator ++() {
		++m_a;
		++m_b;
	}

	//����++ ������ؼ�һ��int ռλ��
	Complex operator ++ (int) {
		cout << m_a << "---����++--" << m_b << endl;
		m_a++;
		m_b++;
		return *this;
	}

	//����+��
	Complex & operator + (const Complex &A) const {
		Complex  B;
		B.m_a = this->m_a + A.m_a;
		B.m_b = this->m_b + A.m_b;

		return B;
	}

	friend bool operator == (const Complex &A, const Complex &B);
	friend Complex & operator -(const Complex &A, const Complex &B);
	friend ostream & operator <<(ostream & out, const Complex &C);

	
	void display() const {
		cout << m_a << "\t" << m_b << endl;
	}
};

Complex & operator - (const Complex &A, const Complex &B) {
	Complex C;
	C.m_a = A.m_a - B.m_a;
	C.m_b = A.m_b - B.m_b;
	return C;
}

// ������������
ostream & operator << (ostream &out, const Complex &C) {
	out << C.m_a << "----������������----" << C.m_b << endl;
	return out;
}

bool operator == (const Complex &A, const Complex &B) {
	if (A.m_a == B.m_a && A.m_b == B.m_b) {
		return true;
	}
	else {
		return false;
	}
}

void test() {
	Complex com(10, 20);
	com.display(); // 10    20

	// ǰ��++
	++ com;
	com.display();// 11    21

	// ����++
	com++;
	com.display();

	Complex a(400, 600);
	Complex b(100, 200);
	Complex c;

	c = a + b; // c = a.operator+(b);

	c.display(); // 500 800

	c = a - b;
	c.display(); // 300 400

	// cout << c <<endl;
	cout << c;  // 300----������������----400

	if (a == b) {
		cout << c;
	}
	else {
		cout << "�����" << endl; //�����
	}
}

void main2() {
	test();
	cin.get();
}