template<typename Type> class Tree;

template<typename Type> class TreeNode{
public:
	friend class Tree < Type > ;

private:
	Type m_data;
	TreeNode<Type> *m_pfirst, *m_pnext;
	TreeNode() :m_pfirst(NULL), m_pnext(NULL){}
	TreeNode(Type item, TreeNode<Type> *first = NULL, TreeNode<Type> *next = NULL)
		:m_data(item), m_pfirst(first), m_pnext(next){}
};

