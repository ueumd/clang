#include<iostream>

using namespace std;

#if 0
1) 能够重载的运算符包括：
+ -*/ %  ^  & | ~!= <  > += -= *= /= %= ^= &= |= << >> <<= >>= == != <= >= && || ++  --, ->*  ->  ()[]  new  new[]  delete  delete[]
[]是下标运算符，()是函数调用运算符。自增自减运算符的前置和后置形式都可以重载。

2) 不能被重载
长度运算符sizeof、条件运算符: ? 、成员选择符.和域解析运算符::不能被重载

3) 重载不会改变运算符的用法，原有有几个操作数、操作数在左边还是在右边，这些都不会改变。
例如~号右边只有一个操作数， + 号总是出现在两个操作数之间，重载后也必须如此。

4) 运算符重载函数不能有默认的参数，否则就改变了运算符操作数的个数，这显然是错误的。

5) 运算符重载函数既可以作为类的成员函数，也可以作为全局函数。

本质： 函数调用
#endif

class Complex
{
public:
	int m_a;
	int m_b;
public:
	Complex() {}
	Complex(int a, int b) :m_a(a), m_b(b) {}

	//重载前++
	void operator ++() {
		m_a++;
		m_b++;
	}

	//重载+号
	Complex & operator + (const Complex &A) const {
		Complex  B;
		B.m_a = this->m_a + A.m_a;
		B.m_b = this->m_b + A.m_b;

		return B;
	}

	friend bool operator == (const Complex &A, const Complex &B);
	friend Complex operator -(const Complex &A, const Complex &B);
	friend ostream & operator <<(ostream & out, const Complex &C);

	
	void display() const {
		cout << m_a << "\t" << m_b << endl;
	}
};

Complex operator - (const Complex &A, const Complex &B) {
	Complex C;
	C.m_a = A.m_a - B.m_a;
	C.m_b = A.m_b - B.m_b;
	return C;
}

// 重载输出运算符
ostream & operator << (ostream &out, const Complex &C) {
	out << C.m_a << "----重载输出运算符----" << C.m_b << endl;
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

	++com;
	com.display();// 11    21

	Complex a(400, 600);
	Complex b(100, 200);
	Complex c;

	c = a + b; // c = a.operator+(b);

	c.display(); // 500 800

	c = a - b;
	c.display(); // 300 400


	cout << c;  // 300----重载输出运算符----400

	if (a == b) {
		cout << c;
	}
	else {
		cout << "不相等" << endl; //不相等
	}
}

class Array {

public:
	Array(int length = 0) :m_length(length) {
		if (length == 0) {
			m_p = NULL;
		}
		else {
			m_p = new int[length];
		}
	}
	~Array() {
		delete[] m_p;
	}

public:
	int & operator[](int i);
	const int & operator[](int i) const;

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

/*
重载[]（下标运算符）
返回值类型 & operator[ ] (参数);
const 返回值类型 & operator[ ] (参数) const;
*/
void test2() {
	Array A(5);
	for (int i = 0, len = A.length(); i < len; i++) {
		A[i] = i * 5;
	}
	A.display(); // 0, 5, 10, 15, 20

	const Array B(5);
	cout << B[5 - 1] << endl;  //访问最后一个元素

	//B[4] 转换为 B.operator[](4)
}

void main() {

	test2();

	cin.get();
}