/*
结节要素： 索引 数据 左子节点指针 右子节点指针

满二叉树：

						(0)

		5(1)					 8(2)

2(3)		6(4)		9(5)	 7(6)


完全二叉树：

						(0)

		5(1)					 8(2)

2(3)		6(4)

完全叉树的性质：

	   A
	B    C
D  E  F  G

前序遍历: A BDE CFG
中序遍历: DBE A FCG
后序遍历: DEB FGC A

*/

#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree {

public:
	Tree();
	~Tree();

	Node *SearchNode(int index);

	bool AddNode(int index, int direction, Node *pNode);
	bool DeleteNode(int index, Node *pNode);

	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();

private:
	Node *m_pRoot;
};

Tree::Tree() {
	m_pRoot = new Node();
}

Tree::~Tree() {
	// DeleteNode(0,NULL);
	m_pRoot->DeleteNode();
}

Node *Tree::SearchNode(int index) {
	return m_pRoot->SearchNode(index);
}

bool Tree::AddNode(int index, int direction, Node *pNode) {
	//是否有该结点
	Node *temp = SearchNode(index);

	if (NULL == temp) {
		return false;
	}

	Node *node = new Node();
	if (NULL == node) {
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;

	if (direction == 0) {
		temp->pLChild = node;
	}

	if (direction == 1) {
		temp->pRChild = node;
	}

	return true;

}

bool Tree::DeleteNode(int index, Node *pNode) {
	Node *temp = SearchNode(index);
	if (NULL == temp) {
		return false;
	}
	if (pNode != NULL) {
		pNode->data = temp->data;
	}

	temp->DeleteNode();
	return true;
}

void Tree::PreorderTraversal() {
	m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal() {
	m_pRoot->InorderTraversal();
}
void Tree::PostorderTraversal() {
	m_pRoot->PostorderTraversal();
}
#endif