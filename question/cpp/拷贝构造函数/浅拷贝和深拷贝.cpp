#include <iostream>
using namespace std;
class Animal {
public:
	Animal() {}
	Animal(const char *myname){
		pName = (char *)malloc(strlen(myname)+1);
		strcpy(pName, myname);
	}

	// �Լ���д�������캯�� ���
	Animal(const Animal& A) {
		pName = (char *)malloc(strlen(A.pName) + 1);
		strcpy(pName, A.pName);
	}

	// ���� = ���
	Animal& operator=(Animal &A) {
		//1 ���ͷžɵ��ڴ�
		if (this->pName != NULL) {
			delete[] pName;
		}

		//2 ����A�����ڴ��С
		this->pName = (char *)malloc(strlen(A.pName) + 1);

		//��ֵ
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
ǳ�������⣬ָ��ͬһ���ڴ�ռ䣬��һ���������ڴ�ռ���ʧ���ڶ�������ʱû�и��ڴ�ռ䣬����
���������������Լ���д�������캯��
*/
#if 0
Animal cat("è��");
Animal cat2 = cat;

//�Ⱥ�Ҳ��ǳ���� �����������=
Animal cat3;
cat3 = cat; 

#endif
void testAnimal() {
	Animal cat("è��");			//������һ��
	cat.display();	//è��
	Animal cat2 = cat;		  //������һ��

	Animal cat3("С��");
	cat3 = cat;
	cat3.display(); //è��
}

void main() {
	testAnimal();
	cin.get();
}