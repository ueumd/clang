#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
������ڵļ�ֵ
�ڴ��������ݵ���Ч��֯�����磬��������malloc�������ڴ�����ʱ�򣬵��ڴ��㹻����
������Ƭ̫�࣬û�� �����ڴ� ʱ��ֻ��������ʧ�ܶ����գ����� ���� �������ݽṹ
����֯���ݣ��Ϳ��Խ����������


int array[10]; //�����������߼�����С��ͬ

����  // �ڵ��С��ͬ���������������߼���������
*/
typedef struct node {
	int data;						//������
	struct  node *next; //ָ���� ָ��������
}Node;

void nodelist() {
	Node a, b, c, d, e, f;
	a.data = 1;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	e.data = 5;
	f.data = 6;

	Node *head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = NULL;

	Node *ph = head;

	while (ph != NULL) {
		printf("%d ", ph->data);
		ph = ph->next;
	}

}

// ͷ�巨
Node *createHeadList() {
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	Node *cur = NULL;
	int data;
	scanf("%d", &data);

	while (data)
	{
		cur = (Node *)malloc(sizeof(Node));
		cur->data = data;


		cur->next = head->next;
		head->next = cur;
		scanf("%d", &data);
	}

	return head;
}

//β�巨
// 1 2 3 4 0 => 1 2 3 4  
Node *createLastList() {
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	Node *pt = head;
	Node *cur = NULL;

	int data;
	printf("������ڵ����ݣ�");
	scanf("%d", &data);

	while (data)
	{
		cur = (Node *)malloc(sizeof(Node));
		cur->data = data;

		pt->next = cur;
		cur->next = NULL;

		pt = cur;

		scanf("%d", &data);
	}
	
	return head;

}



void mainnodelist() {

	//nodelist();
	
	Node *head = createLastList();
	traverselist(head);

	system("pause");
}