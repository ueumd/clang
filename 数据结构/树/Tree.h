#include "TreeNode.h"
#include "LinkQueue.h"

template<typename Type> class Tree{
public:
	Tree() :m_proot(NULL), m_pcurrent(NULL){}
public:
	TreeNode<Type> *GetCurrent(){	//Get the current node
		return m_pcurrent;
	}
	void SetCurrent(TreeNode<Type> *current){	//set the current node
		m_pcurrent = current;
	}
	bool Insert(Type item);		//insert an new node to current node
	void Remove(Type item);		//delete the node whose data is equal to item
	void Remove(TreeNode<Type> *current);	//delete the node
	bool Find(Type item);		//find the node whose data is equal to item
	void PrintChild(TreeNode<Type> *current);	//print the child tree
	TreeNode<Type> *Parent(TreeNode<Type> *current);	//get the parent

	void Print();				//print the tree
	void PreOrder(TreeNode<Type> *root);	//ordering the tree by visiting the root first
	void PostOrder(TreeNode<Type> *root);	//ordering the tree by visiting the root last
	void LevelOrder(TreeNode<Type> *root);	//ordering the tree by level
	void PreOrder();
	void PostOrder();
	void LevelOrder();

private:
	TreeNode<Type> *m_proot, *m_pcurrent;
	bool Find(TreeNode<Type> *root, Type item);
	void Remove(TreeNode<Type> *root, Type item);
	TreeNode<Type> *Parent(TreeNode<Type> *root, TreeNode<Type> *current);
	void Print(TreeNode<Type> *start, int n = 0);
};

template<typename Type> bool Tree<Type>::Insert(Type item){
	TreeNode<Type> *newnode = new TreeNode<Type>(item);
	if (NULL == newnode){
		cout << "Application Error!" << endl;
		exit(1);
	}
	if (NULL == m_proot){
		m_proot = newnode;
		m_pcurrent = m_proot;
		return 1;
	}
	if (NULL == m_pcurrent){
		cerr << "insert error!" << endl;
		return 0;
	}

	if (NULL == m_pcurrent->m_pfirst){
		m_pcurrent->m_pfirst = newnode;
		m_pcurrent = newnode;
		return 1;
	}
	TreeNode<Type> *pmove = m_pcurrent->m_pfirst;
	while (pmove->m_pnext){
		pmove = pmove->m_pnext;
	}
	pmove->m_pnext = newnode;
	m_pcurrent = newnode;
	return 1;

}

template<typename Type> void Tree<Type>::Remove(TreeNode<Type> *current){
	if (NULL == current){
		return;
	}
	TreeNode<Type> *temp = Parent(current);
	if (NULL == temp){
		TreeNode<Type> *pmove = current->m_pfirst;
		if (NULL != pmove->m_pfirst){
			pmove = pmove->m_pfirst;
			while (pmove->m_pnext){
				pmove = pmove->m_pnext;
			}
			pmove->m_pnext = current->m_pfirst->m_pnext;
			current->m_pfirst->m_pnext = NULL;
		}
		else{
			pmove->m_pfirst = pmove->m_pnext;
		}
		m_proot = current->m_pfirst;
	}
	else{
		if (temp->m_pfirst == current){
			TreeNode<Type> *pmove = current->m_pfirst;
			if (pmove){
				while (pmove->m_pnext){
					pmove = pmove->m_pnext;
				}
				pmove->m_pnext = current->m_pnext;
			}
			else{
				current->m_pfirst = current->m_pnext;
			}

		}
		else{
			TreeNode<Type> *pmove = temp->m_pfirst;
			while (pmove->m_pnext != current){
				pmove = pmove->m_pnext;
			}
			pmove->m_pnext = current->m_pnext;
			while (pmove->m_pnext){
				pmove = pmove->m_pnext;
			}
			pmove->m_pnext = current->m_pfirst;
		}
	}
	delete current;
}

template<typename Type> void Tree<Type>::Remove(TreeNode<Type> *root, Type item){
	if (NULL == root){
		return;
	}
	if (root->m_pfirst){
		TreeNode<Type> *pmove = root->m_pfirst;
		while (pmove){
			Remove(pmove, item);
			pmove = pmove->m_pnext;
		}
	}
	if (root->m_data == item){
		Remove(root);
	}

}
template<typename Type> void Tree<Type>::Remove(Type item){
	return Remove(m_proot, item);
}

template<typename Type> TreeNode<Type>* Tree<Type>::Parent(
	TreeNode<Type> *root, TreeNode<Type> *current){
	if (NULL == root){
		return NULL;
	}
	TreeNode<Type> *pmove = root->m_pfirst, *temp;
	if (NULL != pmove){
		while (pmove){
			if (pmove == current){
				return root;
			}
			pmove = pmove->m_pnext;
		}
	}
	pmove = root->m_pfirst;
	while (pmove){
		temp = Parent(pmove, current);
		if (temp){
			return temp;
		}
		pmove = pmove->m_pnext;
	}
	return NULL;
}

template<typename Type> TreeNode<Type>* Tree<Type>::Parent(TreeNode<Type> *current){
	return Parent(m_proot, current);
}

template<typename Type> void Tree<Type>::PrintChild(TreeNode<Type> *current){
	TreeNode<Type> *pmove = current->m_pfirst;
	cout << "first";
	if (NULL != pmove){
		cout << "--->" << pmove->m_data;
	}
	while (pmove->m_pnext){
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
}

template<typename Type> bool Tree<Type>::Find(TreeNode<Type> *root, Type item){
	if (root->m_data == item){
		return 1;
	}
	if (NULL == root){
		return 0;
	}
	TreeNode<Type> *pmove = root->m_pfirst;
	if (NULL == pmove){
		return 0;
	}
	while (pmove){
		if (Find(pmove, item)){
			return 1;
		}
		pmove = pmove->m_pnext;
	}
	return 0;
}

template<typename Type> bool Tree<Type>::Find(Type item){
	return Find(m_proot, item);
}

template<typename Type> void Tree<Type>::Print(TreeNode<Type> *start, int n = 0){
	if (NULL == start){
		for (int i = 0; i < n; i++){
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	TreeNode<Type> *pmove = start->m_pfirst;
	Print(pmove, n + 1);

	for (int i = 0; i < n; i++){
		cout << "     ";
	}
	cout << start->m_data << "--->" << endl;

	if (NULL == pmove){
		return;
	}
	pmove = pmove->m_pnext;
	while (pmove){
		Print(pmove, n + 1);
		pmove = pmove->m_pnext;
	}
}

template<typename Type> void Tree<Type>::Print(){
	Print(m_proot);
}

template<typename Type> void Tree<Type>::PreOrder(TreeNode<Type> *root)
{
	if (NULL == root){
		return;
	}
	cout << root->m_data;
	TreeNode<Type> *pmove = root->m_pfirst;
	while (pmove){
		PreOrder(pmove);
		pmove = pmove->m_pnext;
	}
}

template<typename Type> void Tree<Type>::PostOrder(TreeNode<Type> *root)
{
	if (NULL == root){
		return;
	}
	TreeNode<Type> *pmove = root->m_pfirst;
	while (pmove){
		PostOrder(pmove);
		pmove = pmove->m_pnext;
	}
	cout << root->m_data;
}

template<typename Type> void Tree<Type>::PreOrder(){
	PreOrder(m_proot);
}

template<typename Type> void Tree<Type>::PostOrder(){
	PostOrder(m_proot);
}

template<typename Type> void Tree<Type>::LevelOrder(TreeNode<Type> *root)
{	//using queue
	LinkQueue<TreeNode<Type> *> queue;
	TreeNode<Type> *pmove, *ptemp;
	if (root != NULL){
		queue.Append(root);
		while (!queue.IsEmpty()){
			ptemp = queue.Delete();
			cout << ptemp->m_data;
			pmove = ptemp->m_pfirst;
			while (pmove){
				queue.Append(pmove);
				pmove = pmove->m_pnext;
			}
		}
	}
}

template<typename Type> void Tree<Type>::LevelOrder()
{
	LevelOrder(m_proot);
}

