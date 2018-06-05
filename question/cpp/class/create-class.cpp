
#include<iostream>

using namespace std;

#if 0
stac  Student  stu;
heap  Student *pStu = new Student
#endif

class Student {
public:
	Student() {
		cout << "�޲ι��� ��ִ���� " << endl;
	}

	Student(char *name, int age, float score) {
		this->age = age;
		this->score = score;
		this->name = (char *)malloc(100);
		strcpy(this->name, name);

		cout << "�вι��� ��ִ���� " << endl;
	}

	~Student() {
		cout << "�������� ��ִ���� " << endl;
	}

	//��Ա����
	char *name;		//4����
	int age;			//4����
	float score;	//4����

	//��Ա����
	void say() {
		cout << name << "��������" << age << "���ɼ���" << score << endl;
	}
};

//���Է���
void testStudent() {
	//�������� stu��ջ��
	Student stu;
	stu.name = "С��";
	stu.age = 15;
	stu.score = 92.5f;
	stu.say();

	Student stu;


	Student *pStu = &stu;
	pStu->age = 16;
	stu.say();			// 16
	pStu->say();  // 16
	/*
	�޲ι��� ��ִ����
	С����������15���ɼ���92.5
	С����������16���ɼ���92.5
	С����������16���ɼ���92.5
	*/

	cout << "------------------------------------------" << endl;

	//���ϴ���  *pStuHeap ʹ��->�����ʳ�Ա�����ͺ���
	Student *pStuHeap1 = new Student;
	pStuHeap1->name = "С��";
	pStuHeap1->age = 12;
	pStuHeap1->score = 99;
	pStuHeap1->say();

	cout << "------------------------------------------" << endl;

	Student *pStuHeap2 = new Student("С��", 10, 99.9);
	pStuHeap2->say();
	/*
	�޲ι��� ��ִ����
	С���������12���ɼ���99
	------------------------------------------
	�вι��� ��ִ����
	С����������10���ɼ���99.9
	*/

	/*
	ջ�ڴ�����Զ�����
	���ڴ��ɳ���Ա��������ʹ����Ϻ󣬿���ͨ��deleteɾ��
	ʵ�ʿ����У�new �� delete �����ɶԳ��֣��Ա�֤��ʱɾ������ʹ�õĶ��󣬷�ֹ�����ڴ�ѻ���
	*/
	delete pStuHeap1;
	delete pStuHeap2;
}

//�����ڴ�ģ��
#if 0
�ֱ�Ϊÿ������ĳ�Ա���������ڴ棬�������ж��󶼹���ͬһ�κ������롣
-------------------------------------
	  ����1    ����2    ����2
	��Ա����  ��Ա����   ��Ա����
-------------------------------------
			 ���ó�Ա��������
-------------------------------------
�ڼ��� �� �������͵� ��Сʱ��ֻ�����˳�Ա�����Ĵ�С����û�аѳ�Ա����Ҳ��������
#endif

void testStudentSize() {
	Student stu;
	Student *pStu = new Student;

	cout << "  stack size: " << sizeof(stu) << endl;		  // 12
	cout << "   heap size: " << sizeof(*pStu) << endl;		// 12
	cout << "Student size: " << sizeof(Student) << endl;	// 12

	delete pStu; // ��ִ����������
}

int main() {
	//testStudent();
	testStudentSize();

	system("pause");
	return 0;
}