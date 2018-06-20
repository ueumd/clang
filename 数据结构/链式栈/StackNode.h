template<typename Type> class LinkStack;

template<typename Type> class StackNode{
private:
	friend class LinkStack < Type > ;
	StackNode(Type dt, StackNode<Type> *next = NULL) :m_data(dt), m_pnext(next){}

private:
	Type m_data;
	StackNode<Type> *m_pnext;
};
