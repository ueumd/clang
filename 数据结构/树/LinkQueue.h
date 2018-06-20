#include "QueueNode.h"

template<typename Type> class LinkQueue{
public:
	LinkQueue() :m_prear(NULL), m_pfront(NULL){}
	~LinkQueue(){
		MakeEmpty();
	}
	void Append(const Type item);
	Type Delete();
	Type GetFront();
	void MakeEmpty();
	bool IsEmpty() const{
		return m_pfront == NULL;
	}
	void Print();

private:
	QueueNode<Type> *m_prear, *m_pfront;
};

template<typename Type> void LinkQueue<Type>::MakeEmpty(){
	QueueNode<Type> *pdel;
	while (m_pfront){
		pdel = m_pfront;
		m_pfront = m_pfront->m_pnext;
		delete pdel;
	}
}

template<typename Type> void LinkQueue<Type>::Append(const Type item){
	if (m_pfront == NULL){
		m_pfront = m_prear = new QueueNode<Type>(item);
	}
	else{
		m_prear = m_prear->m_pnext = new QueueNode<Type>(item);
	}
}

template<typename Type> Type LinkQueue<Type>::Delete(){
	if (IsEmpty()){
		cout << "There is no element!" << endl;
		exit(1);
	}
	QueueNode<Type> *pdel = m_pfront;
	Type temp = m_pfront->m_data;
	m_pfront = m_pfront->m_pnext;
	delete pdel;
	return temp;
}

template<typename Type> Type LinkQueue<Type>::GetFront(){
	if (IsEmpty()){
		cout << "There is no element!" << endl;
		exit(1);
	}
	return m_pfront->m_data;
}

template<typename Type> void LinkQueue<Type>::Print(){
	QueueNode<Type> *pmove = m_pfront;
	cout << "front";
	while (pmove){
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout << "--->rear" << endl << endl << endl;
}

