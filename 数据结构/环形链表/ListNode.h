template<typename Type> class CircularList;

template<typename Type> class ListNode{
private:
	friend class CircularList < Type > ;
	ListNode() :m_pnext(NULL){}
	ListNode(const Type item, ListNode<Type> *next = NULL) :m_data(item), m_pnext(next)
	{
	
	
	}
	~ListNode()
	{
		m_pnext = NULL;
	}

private:
	Type m_data;
	ListNode *m_pnext;
};
