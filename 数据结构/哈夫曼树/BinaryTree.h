#include "BinTreeNode.h"

template<typename Type> void Huffman(Type *, int, BinaryTree<Type> &);

template<typename Type> class BinaryTree{
public:

	BinaryTree(BinaryTree<Type> &bt1, BinaryTree<Type> &bt2){
		m_proot = new BinTreeNode<Type>(bt1.m_proot->m_data
			+ bt2.m_proot->m_data, bt1.m_proot, bt2.m_proot);
	}
	BinaryTree(Type item){
		m_proot = new BinTreeNode<Type>(item);
	}
	BinaryTree(const BinaryTree<Type> &copy){
		this->m_proot = copy.m_proot;
	}
	BinaryTree(){
		m_proot = NULL;
	}
	void Destroy(){
		m_proot->Destroy();
	}
	~BinaryTree(){
		//        m_proot->Destroy();
	}

	BinaryTree<Type>& operator=(BinaryTree<Type> copy);	//evaluate node
	friend void Huffman<Type>(Type *, int, BinaryTree<Type> &);
	friend bool operator < <Type>(BinaryTree<Type> &l, BinaryTree<Type> & r);
	friend bool operator > <Type>(BinaryTree<Type> &l, BinaryTree<Type> & r);
	friend bool operator <= <Type>(BinaryTree<Type> &l, BinaryTree<Type> & r);
	friend ostream& operator<< <Type>(ostream&, BinaryTree<Type>&);	//output the data
private:
	BinTreeNode<Type> *m_proot;
	void Print(BinTreeNode<Type> *start, int n = 0);	//print the tree with the root of start
};

template<typename Type> bool operator <(BinaryTree<Type> &l, BinaryTree<Type> &r){
	return l.m_proot->GetData() < r.m_proot->GetData();
}

template<typename Type> bool operator >(BinaryTree<Type> &l, BinaryTree<Type> &r){
	return l.m_proot->GetData() > r.m_proot->GetData();
}

template<typename Type> bool operator <=(BinaryTree<Type> &l, BinaryTree<Type> &r){
	return l.m_proot->GetData() <= r.m_proot->GetData();
}


template<typename Type> void BinaryTree<Type>::Print(BinTreeNode<Type> *start, int n){
	if (start == NULL){
		for (int i = 0; i < n; i++){
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	Print(start->m_pright, n + 1);	//print the right subtree
	for (int i = 0; i < n; i++){	//print blanks with the height of the node
		cout << "     ";
	}
	if (n >= 0){
		cout << start->m_data << "--->" << endl;//print the node
	}
	Print(start->m_pleft, n + 1);	//print the left subtree
}

template<typename Type> ostream& operator<<(ostream& os, BinaryTree<Type>& out){
	out.Print(out.m_proot);
	return os;
}

template<typename Type> BinaryTree<Type>& BinaryTree<Type>::operator=(BinaryTree<Type> copy){
	m_proot = m_proot->Copy(copy.m_proot);
	return *this;
}

