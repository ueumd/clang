
template<typename Type> class SeqStack{
public:
	SeqStack(int sz) :m_ntop(-1), m_nMaxSize(sz){
		m_pelements = new Type[sz];
		if (m_pelements == NULL){
			cout << "Application Error!" << endl;
			exit(1);
		}
	}
	~SeqStack(){
		delete[] m_pelements;
	}

public:

	void Push(const Type item); //push data
	Type Pop();                 //pop data
	Type GetTop() const;        //get data
	void Print();               //print the stack
	void MakeEmpty(){           //make the stack empty
		m_ntop = -1;
	}
	bool IsEmpty() const{
		return m_ntop == -1;
	}
	bool IsFull() const{
		return m_ntop == m_nMaxSize - 1;
	}


private:
	int m_ntop;
	Type *m_pelements;
	int m_nMaxSize;

};

template<typename Type> void SeqStack<Type>::Push(const Type item){
	if (IsFull()){
		cout << "The stack is full!" << endl;
		return;
	}
	m_pelements[++m_ntop] = item;
}

template<typename Type> Type SeqStack<Type>::Pop(){
	if (IsEmpty()){
		cout << "There is no element!" << endl;
		//exit(1);
	}
	return m_pelements[m_ntop--];
}

template<typename Type> Type SeqStack<Type>::GetTop() const{
	if (IsEmpty()){
		cout << "There is no element!" << endl;
		//exit(1);
	}
	return m_pelements[m_ntop];
}

template<typename Type> void SeqStack<Type>::Print(){
	cout << "bottom";
	for (int i = 0; i <= m_ntop; i++){
		cout << "--->" << m_pelements[i];
	}
	cout << "--->top" << endl << endl << endl;
}
