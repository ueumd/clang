
template<typename Type> class BinaryTree;

template<typename Type> void Huffman(Type *, int, BinaryTree<Type> &);

template<typename Type> class BinTreeNode{
public:
	friend class BinaryTree < Type > ;
	friend void Huffman<Type>(Type *, int, BinaryTree<Type> &);
	BinTreeNode() :m_pleft(NULL), m_pright(NULL){}
	BinTreeNode(Type item, BinTreeNode<Type> *left = NULL, BinTreeNode<Type> *right = NULL)
		:m_data(item), m_pleft(left), m_pright(right){}
	void Destroy(){		//destroy the tree with the root of the node
		if (this != NULL){
			this->m_pleft->Destroy();
			this->m_pright->Destroy();
			delete this;
		}
	}
	Type GetData(){
		return m_data;
	}
	BinTreeNode<Type> *Copy(const BinTreeNode<Type> *copy);	//copy the node

private:
	BinTreeNode<Type> *m_pleft, *m_pright;
	Type m_data;
};

template<typename Type> BinTreeNode<Type>* BinTreeNode<Type>::Copy(const BinTreeNode<Type> *copy){
	if (copy == NULL){
		return NULL;
	}

	BinTreeNode<Type> *temp = new BinTreeNode<Type>(copy->m_data);
	temp->m_pleft = Copy(copy->m_pleft);
	temp->m_pright = Copy(copy->m_pright);
	return temp;
}

