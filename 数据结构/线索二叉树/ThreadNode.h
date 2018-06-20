
template<typename Type> class ThreadTree;
template<typename Type> class ThreadInorderIterator;

template<typename Type> class ThreadNode{
public:
	friend class ThreadTree < Type > ;
	friend class ThreadInorderIterator < Type > ;
	ThreadNode() :m_nleftthread(1), m_nrightthread(1){
		m_pleft = this;
		m_pright = this;
	}
	ThreadNode(const Type item) :m_data(item), m_pleft(NULL), m_pright(NULL)
		, m_nleftthread(0), m_nrightthread(0){}

private:
	int m_nleftthread, m_nrightthread;
	ThreadNode<Type> *m_pleft, *m_pright;
	Type m_data;
};
