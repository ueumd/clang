#ifndef TREE_H
#define TREE_H
#include<iostream>
using namespace std;

/*
数组与树之间算法转换 int tree[n] = [3,5,8,2,6,9,7]
父结点左下标：index*2+1
父结点右下标：index*2+2

					 3(0)

		5(1)					 8(2)

2(3)		6(4)		9(5)	 7(6)

*/

class Tree {
public:
	Tree(int size, int *pRoot);
	~Tree();
	int *SearchNode(int index);
	bool AddNode(int index, int direction, int *pNode);
	bool DeleteNode(int index, int *pNode);
	void TreeTraversal();

private:
	int *m_pTree;
	int m_iSize;
};

Tree::Tree(int size, int *pRoot):m_iSize(size) {
	m_pTree = new int[m_iSize];
	if (NULL != m_pTree) {
		for (int i = 0; i < m_iSize; i++) {
			m_pTree[i] = 0;
		}

		//根节点
		m_pTree[0] = *pRoot; 
	}
}

Tree::~Tree() {
	delete[]m_pTree;
	m_pTree = NULL;
}

int *Tree::SearchNode(int index) {
	if (index < 0 || index >= m_iSize) {
		return NULL;
	}
	if (m_pTree[index] == 0) {
		return NULL;
	}
	return &m_pTree[index];
}

bool Tree::AddNode(int index, int direction, int *pNode) {
	if (index < 0 || index >= m_iSize || m_pTree[index] == 0) {
		return false;
	}

	int i = 0;

	//left
	if (direction == 0) {
		i = index * 2 + 1;
		if (i >= m_iSize || m_pTree[i] != 0) {
			return false;
		}

		//等于0空
		m_pTree[i] = *pNode;
	}

	//right
	if (direction == 1) {
		i = index * 2 + 2;
			if (i >= m_iSize || m_pTree[i] != 0) {
				return false;
			}

		//等于0空
		m_pTree[i] = *pNode;
	}

}

bool Tree::DeleteNode(int index, int *pNode) {
	if (index < 0 || index >= m_iSize || m_pTree[index] == 0) {
		return false;
	}
	*pNode = m_pTree[index];
	m_pTree[index] = 0;
	return true;
}

void Tree::TreeTraversal() {
	for (int i = 0; i < m_iSize; i++) {
		cout << m_pTree[i] << "  ";
	}
	cout << endl;
}
#endif