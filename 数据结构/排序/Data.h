template<typename Type> class Element{
public:
	Type GetKey(){
		return key;
	}

	void SetKey(Type item){
		key = item;
	}

public:
	Element<Type>& operator =(Element<Type> copy){
		key = copy.key;
		return *this;
	}

	bool operator ==(Element<Type> item){
		return this->key == item.key;
	}

	bool operator !=(Element<Type> item){
		return this->key != item.key;
	}

	bool operator <(Element<Type> item){
		return this->key < item.key;
	}

	bool operator >(Element<Type> item){
		return this->key > item.key;
	}

	bool operator >=(Element<Type> item){
		return this->key >= item.key;
	}

	bool operator <=(Element<Type> item){
		return this->key <= item.key;
	}


private:
	Type key;
};

template<typename Type> class Sort;
template<typename Type> class DataList{
public:
	friend class Sort < Type > ;
	DataList(int size = m_nDefaultSize) : m_nMaxSize(size), m_ncurrentsize(0){
		m_pvector = new Element<Type>[size];
	}

	DataList(Type *data, int size);

	bool Insert(Type item);
	~DataList(){
		delete[] m_pvector;
	}

	int Size(){
		return this->m_ncurrentsize;
	}
	void Swap(Element<Type> &left, Element<Type> &right){
		Element<Type> temp = left;
		left = right;
		right = temp;
	}

	void Print();
private:
	static const int m_nDefaultSize = 10;
	Element<Type> *m_pvector;
	const int m_nMaxSize;
	int m_ncurrentsize;
};

template<typename Type> DataList<Type>::DataList(Type *data, int size)
	: m_nMaxSize(size > m_nDefaultSize ? size : m_nDefaultSize), m_ncurrentsize(0){
	this->m_pvector = new Element<Type>[size];
	for (int i = 0; i < size; i++){
		this->m_pvector[i].SetKey(data[i]);
	}
	this->m_ncurrentsize += size;

}

template<typename Type> bool DataList<Type>::Insert(Type item){
	if (this->m_ncurrentsize == this->m_nMaxSize){
		cerr << "The list is full!" << endl;
		return 0;
	}
	this->m_pvector[this->m_ncurrentsize++].SetKey(item);
}

template<typename Type> void DataList<Type>::Print(){
	cout << "The list is:";
	for (int i = 0; i < this->m_ncurrentsize; i++){
		cout << " " << this->m_pvector[i].GetKey();
	}
}
