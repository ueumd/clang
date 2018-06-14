#include <iostream>
using namespace std;
class Animal {
public:
	Animal() {}
	Animal(const char *myname){
		pName = (char *)malloc(strlen(myname)+1);
		strcpy(pName, myname);
	}

	// 自己编写拷贝构造函数 深拷贝
	Animal(const Animal& A) {
		pName = (char *)malloc(strlen(A.pName) + 1);
		strcpy(pName, A.pName);
	}

	// 重载 = 深拷贝
	Animal& operator=(Animal &A) {
		//1 先释放旧的内存
		if (this->pName != NULL) {
			delete[] pName;
		}

		//2 根据A分配内存大小
		this->pName = (char *)malloc(strlen(A.pName) + 1);

		//赋值
		strcpy(pName, A.pName);

		return *this;
	}

	~Animal() {
		delete[] pName;
		cout << "xg" << endl;
	}

public:
	void display() {
		cout << pName << endl;
	}

public:
	char *pName;
};

/*
浅拷贝问题，指向同一块内存空间，第一次析构，内存空间消失。第二次析构时没有该内存空间，报错
解决方案：深拷贝，自己编写拷贝构造函数
*/
#if 0
Animal cat("猫咪");
Animal cat2 = cat;

//等号也是浅拷贝 解决方案重载=
Animal cat3;
cat3 = cat; 

#endif
void testAnimal() {
	Animal cat("猫咪");			//会析构一次
	cat.display();	//猫咪
	Animal cat2 = cat;		  //会析构一次

	Animal cat3("小花");
	cat3 = cat;
	cat3.display(); //猫咪
}

void main() {
	testAnimal();
	cin.get();
}