#include "ThreadTree.h"

template<typename Type> class ThreadInorderIterator{
public:
	ThreadInorderIterator(ThreadTree<Type> &tree) :m_ptree(tree), m_pcurrent(tree.m_proot){
		//InThread(m_ptree.m_proot->m_pleft,m_ptree.m_proot);
	}

	ThreadNode<Type> *First();
	ThreadNode<Type> *Prior();
	ThreadNode<Type> *Next();

	void Print();
	void Print(ThreadNode<Type> *start, int n = 0);
	void InOrder();
	void InsertLeft(ThreadNode<Type> *left);
	void InsertRight(ThreadNode<Type> *right);
	ThreadNode<Type> *GetParent(ThreadNode<Type> *current);


private:
	ThreadTree<Type> &m_ptree;
	ThreadNode<Type> *m_pcurrent;
	void InThread(ThreadNode<Type> *current, ThreadNode<Type> *pre);
};

template<typename Type> void ThreadInorderIterator<Type>::InThread(
	ThreadNode<Type> *current, ThreadNode<Type> *pre){
	if (current != m_ptree.m_proot){
		InThread(current->m_pleft, pre);
		if (current->m_pleft == NULL){
			current->m_pleft = pre;
			current->m_nleftthread = 1;
		}
		if (pre->m_pright == NULL){
			pre->m_pright = current;
			pre->m_nrightthread = 1;
		}

		pre = current;
		InThread(current->m_pright, pre);
	}
}

template<typename Type> ThreadNode<Type>* ThreadInorderIterator<Type>::First(){
	while (m_pcurrent->m_nleftthread == 0){
		m_pcurrent = m_pcurrent->m_pleft;
	}
	return m_pcurrent;
}

template<typename Type> ThreadNode<Type>* ThreadInorderIterator<Type>::Prior(){
	ThreadNode<Type> *pmove = m_pcurrent->m_pleft;
	if (0 == m_pcurrent->m_nleftthread){
		while (0 == pmove->m_nrightthread){
			pmove = pmove->m_pright;
		}
	}
	m_pcurrent = pmove;
	if (m_pcurrent == m_ptree.m_proot){
		return NULL;
	}
	return m_pcurrent;
}

template<typename Type> ThreadNode<Type>* ThreadInorderIterator<Type>::Next(){
	ThreadNode<Type> *pmove = m_pcurrent->m_pright;
	if (0 == m_pcurrent->m_nrightthread){
		while (0 == pmove->m_nleftthread){
			pmove = pmove->m_pleft;
		}
	}
	m_pcurrent = pmove;
	if (m_pcurrent == m_ptree.m_proot){
		return NULL;
	}
	return m_pcurrent;
}

template<typename Type> void ThreadInorderIterator<Type>::InOrder(){
	ThreadNode<Type> *pmove = m_ptree.m_proot;
	while (pmove->m_pleft != m_ptree.m_proot){
		pmove = pmove->m_pleft;
	}
	m_pcurrent = pmove;
	cout << "root";
	while (pmove != m_ptree.m_proot&&pmove){
		cout << "--->" << pmove->m_data;
		pmove = this->Next();
	}
	cout << "--->end";
}

template<typename Type> void ThreadInorderIterator<Type>::InsertLeft(ThreadNode<Type> *left){
	left->m_pleft = m_pcurrent->m_pleft;
	left->m_nleftthread = m_pcurrent->m_nleftthread;
	left->m_pright = m_pcurrent;
	left->m_nrightthread = 1;
	m_pcurrent->m_pleft = left;
	m_pcurrent->m_nleftthread = 0;
	if (0 == left->m_nleftthread){
		m_pcurrent = left->m_pleft;
		ThreadNode<Type> *temp = First();
		temp->m_pright = left;
	}
	m_pcurrent = left;
}

template<typename Type> void ThreadInorderIterator<Type>::InsertRight(ThreadNode<Type> *right){
	right->m_pright = m_pcurrent->m_pright;
	right->m_nrightthread = m_pcurrent->m_nrightthread;
	right->m_pleft = m_pcurrent;
	right->m_nleftthread = 1;
	m_pcurrent->m_pright = right;
	m_pcurrent->m_nrightthread = 0;
	if (0 == right->m_nrightthread){
		m_pcurrent = right->m_pright;
		ThreadNode<Type> *temp = First();
		temp->m_pleft = right;
	}
	m_pcurrent = right;
}

template<typename Type> ThreadNode<Type>* ThreadInorderIterator<Type>::GetParent(
	ThreadNode<Type> *current){
	ThreadNode<Type> *pmove = current;
	while (0 == pmove->m_nleftthread){
		pmove = pmove->m_pleft;
	}
	pmove = pmove->m_pleft;
	if (pmove == m_ptree.m_proot){
		if (pmove->m_pleft == current){
			return NULL;
		}
	}
	if (pmove->m_pright == current){
		return pmove;
	}
	pmove = pmove->m_pright;
	while (pmove->m_pleft != current){
		pmove = pmove->m_pleft;
	}
	return pmove;
}

template<typename Type> void ThreadInorderIterator<Type>::Print(ThreadNode<Type> *start, int n){
	if (start->m_nleftthread&&start->m_nrightthread){
		for (int i = 0; i < n; i++){
			cout << "     ";
		}
		if (n >= 0){
			cout << start->m_data << "--->" << endl;
		}

		return;
	}
	if (start->m_nrightthread == 0){
		Print(start->m_pright, n + 1);
	}
	for (int i = 0; i < n; i++){
		cout << "     ";
	}
	if (n >= 0){
		cout << start->m_data << "--->" << endl;
	}
	if (start->m_nleftthread == 0){
		Print(start->m_pleft, n + 1);
	}
}

template<typename Type> void ThreadInorderIterator<Type>::Print(){
	Print(m_ptree.m_proot->m_pleft);
}

