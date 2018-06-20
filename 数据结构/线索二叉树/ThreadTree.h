#include "ThreadNode.h"

template<typename Type> class ThreadInorderIterator;

template<typename Type> class ThreadTree{
public:
	friend class ThreadInorderIterator < Type > ;
	ThreadTree() :m_proot(new ThreadNode<Type>()){}

private:
	ThreadNode<Type> *m_proot;
};
