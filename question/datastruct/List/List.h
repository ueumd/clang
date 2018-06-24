#ifndef LIST_H
#define LIST_H

#include<iostream>
/*
线性表 -- 顺序表
3 5 7 2 9 1 8
前驱 后继
*/

class List {
public:
	List(int size);
	~List();

	void clear();
	bool isEmpty();
	int getLength();
	bool getElem(int i, int *e);										//获取指定位置的元素 
	int locateElem(int *e);													//查找指定元素的下标
	bool priorElem(int *currentElem, int *preElem);	//获取指定元素的前驱
	bool nextElem(int *currentElem, int *preElem);
	bool insert(int i, int *e);
	bool remove(int i, int *e);
	void traverse();

private:
	int m_iSize;									//容量
	int m_iLength;								//已有元素的个数
	int *m_pList;
};

List::List(int size) {
	m_iSize = size;
	m_iLength = 0;
	m_pList = new int[m_iSize];
}

List::~List() {
	delete[]m_pList;
	m_pList = NULL;

}

void List::clear() {
	m_iLength = 0;
}

bool List::isEmpty() {
	return m_iLength == 0 ? true : false;
}

int List::getLength() {
	return m_iLength;
}

bool List::getElem(int i, int *e) {
	if (i < 0 || i >= m_iSize) {
		return false;
	}

	*e = m_pList[i];
	return true;
}
int List::locateElem(int *e) {
	for (int i = 0; i < m_iLength; i++) {
		if (m_pList[i] == *e) {
			return i;
		}
	}
	return -1;
}

bool List::priorElem(int *currentElem, int *preElem) {
	int temp = locateElem(currentElem);
	if (temp == -1 || temp == 0) return false; //第一个元素是没有前驱的

	*preElem = m_pList[temp - 1];
	return true;
}


bool List::nextElem(int *currentElem, int *preElem) {
	int temp = locateElem(currentElem);
	if (temp == -1 || temp == m_iLength) return false; // 最后一个

	*preElem = m_pList[temp -1];
	return true;
}

void List::traverse() {
	for (int i = 0; i < m_iLength; i++) {
		std::cout << m_pList[i] << " ";
	}
	std::cout << std::endl;
}

/*
7 i = 3 *e=7

3 5 2 length: 3
0 1 2

3 5 7 2
*/
// 3 5 7 2 9 1 8
// 0 1 2 3 4 5 6   i=6 e=8
bool List::insert(int i, int *e) {
	
	if (i < 0 || i > m_iLength) return false;

	// 从最后一个元素开始 一个一个向后面移动
	for (int k = m_iLength-1; k >=i; k--) {
		m_pList[k + 1] = m_pList[k];
	}

	//insert elem
	m_pList[i] = *e;
	m_iLength++;

	return true;
}

/*
3 5 7 2  e=5
0 1 2 3
*/
bool List::remove(int i, int *e) {

	if (i < 0 || i >= m_iLength) return false;

	//先拷贝
	*e = m_pList[i];
	
	// 移次向后移动元素
	for (int k = i + 1; k < m_iLength; k++) {
		m_pList[k-1] = m_pList[k];
	}

	m_iLength--;

	return true;
}
#endif