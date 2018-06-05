
#include<iostream>

using namespace std;

#if 0
stac  Student  stu;
heap  Student *pStu = new Student
#endif

class Student {
public:
	Student() {
		cout << "无参构造 被执行了 " << endl;
	}

	Student(char *name, int age, float score) {
		this->age = age;
		this->score = score;
		this->name = (char *)malloc(100);
		strcpy(this->name, name);

		cout << "有参构造 被执行了 " << endl;
	}

	~Student() {
		cout << "析构函数 被执行了 " << endl;
	}

	//成员变量
	char *name;		//4个字
	int age;			//4个字
	float score;	//4个字

	//成员函数
	void say() {
		cout << name << "的年龄是" << age << "，成绩是" << score << endl;
	}
};

//测试方法
void testStudent() {
	//创建对象 stu在栈上
	Student stu;
	stu.name = "小明";
	stu.age = 15;
	stu.score = 92.5f;
	stu.say();

	Student stu;


	Student *pStu = &stu;
	pStu->age = 16;
	stu.say();			// 16
	pStu->say();  // 16
	/*
	无参构造 被执行了
	小明的年龄是15，成绩是92.5
	小明的年龄是16，成绩是92.5
	小明的年龄是16，成绩是92.5
	*/

	cout << "------------------------------------------" << endl;

	//堆上创建  *pStuHeap 使用->来访问成员变量和函数
	Student *pStuHeap1 = new Student;
	pStuHeap1->name = "小红";
	pStuHeap1->age = 12;
	pStuHeap1->score = 99;
	pStuHeap1->say();

	cout << "------------------------------------------" << endl;

	Student *pStuHeap2 = new Student("小二", 10, 99.9);
	pStuHeap2->say();
	/*
	无参构造 被执行了
	小红的年龄是12，成绩是99
	------------------------------------------
	有参构造 被执行了
	小二的年龄是10，成绩是99.9
	*/

	/*
	栈内存程序自动管理
	堆内存由程序员管理，对象使用完毕后，可以通过delete删除
	实际开发中，new 和 delete 往往成对出现，以保证及时删除不再使用的对象，防止无用内存堆积。
	*/
	delete pStuHeap1;
	delete pStuHeap2;
}

//对象内存模型
#if 0
分别为每个对象的成员变量分配内存，但是所有对象都共享同一段函数代码。
-------------------------------------
	  对象1    对象2    对象2
	成员变量  成员变量   成员变量
-------------------------------------
			 公用成员函数代码
-------------------------------------
在计算 类 这种类型的 大小时，只计算了成员变量的大小，并没有把成员函数也包含在内
#endif

void testStudentSize() {
	Student stu;
	Student *pStu = new Student;

	cout << "  stack size: " << sizeof(stu) << endl;		  // 12
	cout << "   heap size: " << sizeof(*pStu) << endl;		// 12
	cout << "Student size: " << sizeof(Student) << endl;	// 12

	delete pStu; // 会执行析构函数
}

int main() {
	//testStudent();
	testStudentSize();

	system("pause");
	return 0;
}