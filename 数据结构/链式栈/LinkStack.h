#include "StackNode.h"

template<typename Type> class LinkStack{
public:
	LinkStack() :m_ptop(NULL){}
	~LinkStack(){
		MakeEmpty();
	}

public:
	void MakeEmpty();           //make the stack empty
	void Push(const Type item); //push the data
	Type Pop();                 //pop the data
	Type GetTop() const;        //get the data
	void Print();               //print the stack

	bool IsEmpty() const{
		return m_ptop == NULL;
	}

private:
	StackNode<Type> *m_ptop;
};

template<typename Type> void LinkStack<Type>::MakeEmpty(){
	StackNode<Type> *pmove;
	while (m_ptop != NULL){
		pmove = m_ptop;
		m_ptop = m_ptop->m_pnext;
		delete pmove;
	}
}

template<typename Type> void LinkStack<Type>::Push(const Type item){
	m_ptop = new StackNode<Type>(item, m_ptop);
}

template<typename Type> Type LinkStack<Type>::GetTop() const
{
	if (IsEmpty()){
		cout << "There is no elements!" << endl;
		exit(1);
	}
	return m_ptop->m_data;
}

template<typename Type> Type LinkStack<Type>::Pop()
{
	if (IsEmpty()){
		cout << "There is no elements!" << endl;
		exit(1);
	}
	StackNode<Type> *pdel = m_ptop;
	m_ptop = m_ptop->m_pnext;
	Type temp = pdel->m_data;
	delete pdel;
	return temp;
}

template<typename Type> void LinkStack<Type>::Print(){
	StackNode<Type> *pmove = m_ptop;
	cout << "buttom";
	while (pmove != NULL){
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout << "--->top" << endl << endl << endl;
}

