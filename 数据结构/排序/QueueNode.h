template<typename Type> class LinkQueue;

template<typename Type>
class QueueNode
{
private:
	friend class LinkQueue < Type > ;
	QueueNode(const Type item, QueueNode<Type> *next = NULL)
		:m_data(item), m_pnext(next){}
private:
	Type m_data;
	QueueNode<Type> *m_pnext;
};
