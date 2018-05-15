#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
链表存在的价值
内存零碎数据的有效组织。比如，当我们用malloc来进行内存申请时候，当内存足够，而
由于碎片太多，没有 连续内存 时，只能以申请失败而告终，而用 链表 这种数据结构
来组织数据，就可以解决上类问题


int array[10]; //连续（物理，逻辑）大小相同

链表  // 节点大小相同，而物理不连续（逻辑上连续）
*/

typedef struct node {
	int data;						//数据域
	struct  node *next; //指针域 指向自类型
}Node;

// 创建空链表节点
Node *createEmptyNode() {
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

// 头插
void insertHeadNode(Node *head, int inserData) {
	Node *cur = (Node *)malloc(sizeof(Node));
	cur->data = inserData;

	cur->next = head->next;
	head->next = cur;
}

// 打印
void traverselist(Node * head) {
	head = head->next;
	while (head)
	{
		printf("%d\n ", head->data);
		head = head->next;
	}
}

// 求长度
int lenList(Node *head) {
	int len = 0;
	head = head->next;

	while (head) {
		len++;
		head = head->next;
	}
	return len;
}

// 查找节点
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

//删除节点
void *delNode(Node *head, Node *pfind) {
	while (head->next != pfind)	head = head->next;

	// 上一节点指向pfind的下一节点
	head->next = pfind->next;
	free(pfind);
}

// 值交换排序
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