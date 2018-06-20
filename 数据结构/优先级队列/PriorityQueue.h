#include "QueueNode.h"
#include "Compare.h"

template<typename Type, typename Cmp> class PriorityQueue{	//Cmp is Designed for compare
public:
	PriorityQueue() :m_prear(NULL), m_pfront(NULL){}
	~PriorityQueue(){
		MakeEmpty();
	}

	void MakeEmpty();               //make the queue empty
	void Append(const Type item);   //insert data
	Type Delete();                  //delete data
	Type GetFront();                //get data
	void Print();                   //print the queue

	bool IsEmpty() const{
		return m_pfront == NULL;
	}


private:
	QueueNode<Type, Cmp> *m_prear, *m_pfront;
};

template<typename Type, typename Cmp> void PriorityQueue<Type, Cmp>::MakeEmpty(){
	QueueNode<Type, Cmp> *pdel;
	while (m_pfront){
		pdel = m_pfront;
		m_pfront = m_pfront->m_pnext;
		delete pdel;
	}
}

template<typename Type, typename Cmp> void PriorityQueue<Type, Cmp>::Append(const Type item){
	if (m_pfront == NULL){
		m_pfront = m_prear = new QueueNode<Type, Cmp>(item);
	}
	else{
		m_prear = m_prear->m_pnext = new QueueNode<Type, Cmp>(item);
	}
}

template<typename Type, typename Cmp> Type PriorityQueue<Type, Cmp>::Delete(){
	if (IsEmpty()){
		cout << "There is no elements!" << endl;
		exit(1);
	}
	QueueNode<Type, Cmp> *pdel = m_pfront, *pmove = m_pfront;
	while (pmove->m_pnext){  //get the minimize priority's data

		//cmp:: lt is used for compare the two data, if the front one 
		//      is less than the back, then return 1
		if (Cmp::lt(pmove->m_pnext->m_data, pdel->m_pnext->m_data)){
			pdel = pmove;
		}
		pmove = pmove->m_pnext;
	}

	pmove = pdel;
	pdel = pdel->m_pnext;
	pmove->m_pnext = pdel->m_pnext;
	Type temp = pdel->m_data;
	delete pdel;
	return temp;
}

template<typename Type, typename Cmp> Type PriorityQueue<Type, Cmp>::GetFront(){
	if (IsEmpty()){
		cout << "There is no elements!" << endl;
		exit(1);
	}
	QueueNode<Type, Cmp> *pdel = m_pfront, *pmove = m_pfront->m_pnext;
	while (pmove){   //get the minimize priority's data
		if (Cmp::lt(pmove->m_data, pdel->m_data)){
			pdel = pmove;
		}
		pmove = pmove->m_pnext;
	}
	return pdel->m_data;
}

template<typename Type, typename Cmp> void PriorityQueue<Type, Cmp>::Print(){
	QueueNode<Type, Cmp> *pmove = m_pfront;
	cout << "front";

	while (pmove){
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}

	cout << "--->rear" << endl << endl << endl;
}

