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

// 头插法
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

//尾插法
// 1 2 3 4 0 => 1 2 3 4  
Node *createLastList() {
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	Node *pt = head;
	Node *cur = NULL;

	int data;
	printf("请输入节点数据：");
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