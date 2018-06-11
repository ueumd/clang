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
	解决方案：手工编写拷贝构造函数 使用深拷贝
	*/
	Name(const Name& obj) {//复制构造函数
		m_len = obj.m_len;
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, obj.m_p);
	}		

	/*
	obj3 = obj1; //c++编译器提供的=号操作 也属 浅拷贝
	obj3.operator=(obj1)
	*/
	//void operator=(Name &obj1) {
	Name& operator=(Name &obj1) {
		//1 先释放旧的内存
		if (this->m_p != NULL) {
			delete[] m_p;
			m_len = 0;
		}

		//2 根据obj分配内存大小
		this->m_len = obj1.m_len;
		this->m_p = new char[m_len + 1];

		//把obj1赋值
		strcpy(m_p, obj1.m_p);
		return *this;
	}

	//Name& operator=(const Name&); //重载赋值运算符
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

	Name obj2 = obj1;				//c++编译器提供的， 默认copy构造函数 浅拷贝

	Name obj3("NoName");	
	//obj3 = obj1;	//c++编译器提供的=号操作 也属 浅拷贝


	obj3 = obj1; 
	//obj3.operator=(obj1);

	obj1 = obj2 = obj3;
	// obj2.opeartor=(obj3)
	// obj1 = void; 错误	C2679	二进制“ = ”: 没有找到接受“void”类型的右操作数的运算符(或没有可接受的转换)
	// 解决方案： 	Name& operator=(Name &obj1) {return *this}

	cout << obj1.m_p << endl;
	cout << obj3.m_p << endl;

	obj3.m_p = "aaaa";
	cout << obj1.m_p << endl;
	cout << obj3.m_p << endl;


	cin.get();
}