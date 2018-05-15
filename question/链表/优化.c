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

// ����������ڵ�
Node *createEmptyNode() {
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

// ͷ��
void insertHeadNode(Node *head, int inserData) {
	Node *cur = (Node *)malloc(sizeof(Node));
	cur->data = inserData;

	cur->next = head->next;
	head->next = cur;
}

// ��ӡ
void traverselist(Node * head) {
	head = head->next;
	while (head)
	{
		printf("%d\n ", head->data);
		head = head->next;
	}
}

// �󳤶�
int lenList(Node *head) {
	int len = 0;
	head = head->next;

	while (head) {
		len++;
		head = head->next;
	}
	return len;
}

// ���ҽڵ�
Node *findNode(Node *head, int findData) {
	head = head->next;
	while (head) {
		if (head->data == findData) {
			break;
		}
		head = head->next;
	}
	return head;
}

//ɾ���ڵ�
void *delNode(Node *head, Node *pfind) {
	while (head->next != pfind)	head = head->next;

	// ��һ�ڵ�ָ��pfind����һ�ڵ�
	head->next = pfind->next;
	free(pfind);
}

// ֵ��������
void sortPopList(Node *head, int len) {
	Node *cur = NULL;
	int tmp;

	for (int i = 0; i < len - 1; i++) {
		cur = head->next;
		for (int j = 0; j < len - 1 - i; j++) {
			if (cur->data > cur->next->data) {
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}

			cur = cur->next;
		}
	}
}

void main() {

	//nodelist();

	Node *head = createEmptyNode();

	for (int i = 0; i < 10; i++) {
		insertHeadNode(head, rand()%100);
	}
	insertHeadNode(head,100);
	traverselist(head);
	int len = lenList(head);
	printf("len of list = %d\n", len);

	Node *pfind = findNode(head, 100);
	if (pfind == NULL) {
		printf("find none\n");
	}
	else {
		printf("your find in list %p\n", pfind);

		printf("del node: \n");
		delNode(head, pfind);
		traverselist(head);

		printf("sort node: \n");
		len = lenList(head);
		sortPopList(head, len);
		traverselist(head);
	}

	system("pause");
}