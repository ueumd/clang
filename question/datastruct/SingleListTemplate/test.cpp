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
	cout << "���ܲ˵�" << endl;
	cout << "1.�½���ϵ��" << endl;
	cout << "2.ɾ����ϵ��" << endl;
	cout << "3.���ͨѶ¼" << endl;
	cout << "4.�˳�ͨѶ¼" << endl;
	cout << "****************************" << endl;

	cout << "�����룺";
	int order = 0;
	cin >> order;
	return order;
}

void test() {
	//	testNode();
	//	testPerson();
}

/*������ϵ��*/
void createPerson(List<Person> *pList) {
	Node<Person> node; //ջ�з�����ڴ棬�뿪��ǰ������������
	Person person;
	bool insertFlag = false;

	cout << "������������";
	cin >> person.name;
	cout << "������绰��";
	cin >> person.phone;

	node.data = person; //���ع�

	insertFlag = pList->insertTail(&node);

	if (insertFlag)
	{
		cout << "#�½��ɹ�" << endl;
	}
	else
	{
		cout << "#�½�ʧ��" << endl;
	}
}


/*ɾ����ϵ��*/
void deletePerson(List<Person> *plist){
	if (plist->isEmpty()){
		cout << "#ͨѶ¼Ϊ�գ�" << endl;
	}
	else {
		Node<Person> node;
		int i;
		bool deleteFlag = false;
		cout << "������Ҫɾ����ϵ�˵����[0-" << (plist->getLength() - 1) << "]��";
		cin >> i;

		deleteFlag = plist->remove(i, &node);//ɾ��

		if (deleteFlag){
			cout << "#��ɾ�� " << node.data.name << " " << node.data.phone << endl;
		}
		else{
			cout << "#ɾ��ʧ�ܣ���������ȷ����ţ�" << endl;
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
			cout << "�û�ָ��-->>�½���ϵ�ˣ�" << endl;
			createPerson(pList);
			break;
		case 2:
			cout << "�û�ָ��-->>ɾ����ϵ�ˣ�" << endl;
			deletePerson(pList);
			break;
		case 3:
			cout << "�û�ָ��-->>���ͨѶ¼��" << endl;
			pList->traverse();
			break;
		case 4:
			cout << "�û�ָ��-->>�˳�ͨѶ¼��" << endl;
			break;
		default:
			break;
		}
	}

	cin.get();
}