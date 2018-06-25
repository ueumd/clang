#include<iostream>
#include "List.h"
#include "Node.h"
#include "Person.h"

using namespace std;

void testNode() {
	Node<int> node1;
	node1.data = 1;

	Node<int> node2;
	node2.data = 2;

	Node<int> node3;
	node3.data = 3;

	Node<int> node4;
	node4.data = 4;


	Node<int> node5;
	node5.data = 5;

	List<int> *p = new List<int>();

	p->insertTail(&node1);
	p->insertTail(&node2);
	p->insertTail(&node3);
	p->insertTail(&node4);

	p->insertHead(&node5);

	p->traverse(); // 4 3 2 1

	delete p;
	p = NULL;
}

void testPerson() {
	Node<Person> node1;
	node1.data.name = "tester1";
	node1.data.phone = "123456";

	Node<Person> node2;
	node2.data.name = "tester2";
	node2.data.phone = "139654321";

	List<Person> ps;
	ps.insertHead(&node1);
	ps.insertHead(&node2);
	ps.traverse();

}

int menu() {
	cout << "****************************" << endl;
	cout << "功能菜单" << endl;
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;
	cout << "****************************" << endl;

	cout << "请输入：";
	int order = 0;
	cin >> order;
	return order;
}

void test() {
	//	testNode();
	//	testPerson();
}

/*创建联系人*/
void createPerson(List<Person> *pList) {
	Node<Person> node; //栈中分配的内存，离开当前函数即被回收
	Person person;
	bool insertFlag = false;

	cout << "请输入姓名：";
	cin >> person.name;
	cout << "请输入电话：";
	cin >> person.phone;

	node.data = person; //重载过

	insertFlag = pList->insertTail(&node);

	if (insertFlag)
	{
		cout << "#新建成功" << endl;
	}
	else
	{
		cout << "#新建失败" << endl;
	}
}


/*删除联系人*/
void deletePerson(List<Person> *plist){
	if (plist->isEmpty()){
		cout << "#通讯录为空！" << endl;
	}
	else {
		Node<Person> node;
		int i;
		bool deleteFlag = false;
		cout << "请输入要删除联系人的序号[0-" << (plist->getLength() - 1) << "]：";
		cin >> i;

		deleteFlag = plist->remove(i, &node);//删除

		if (deleteFlag){
			cout << "#已删除 " << node.data.name << " " << node.data.phone << endl;
		}
		else{
			cout << "#删除失败，请输入正确的序号！" << endl;
		}
	}
}


void main() {
	List<Person> *pList = new List<Person>;
	int userOrder = 0;
	while (userOrder!=4)
	{
		userOrder = menu();
		switch (userOrder)
		{
		case 1:
			cout << "用户指令-->>新建联系人：" << endl;
			createPerson(pList);
			break;
		case 2:
			cout << "用户指令-->>删除联系人：" << endl;
			deletePerson(pList);
			break;
		case 3:
			cout << "用户指令-->>浏览通讯录：" << endl;
			pList->traverse();
			break;
		case 4:
			cout << "用户指令-->>退出通讯录：" << endl;
			break;
		default:
			break;
		}
	}

	cin.get();
}