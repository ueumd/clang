
template<typename Type> class MinHeap{
public:
	MinHeap(Type heap[], int n);		//initialize heap by a array
	~MinHeap(){
		delete[] m_pheap;
	}

public:
	bool Insert(const Type item);
	bool DeleteMin(Type &first);

private:
	void Adjust(const int start, const int end);	//adjust the elements from start to end


private:
	const int m_nMaxSize;
	Type *m_pheap;
	int m_ncurrentsize;
};

template<typename Type> void MinHeap<Type>::Adjust(const int start, const int end){
	int i = start, j = i * 2 + 1;
	Type temp = m_pheap[i];
	while (j <= end){
		if (j<end && m_pheap[j]>m_pheap[j + 1]){
			j++;
		}
		if (temp <= m_pheap[j]){
			break;
		}
		else{
			m_pheap[i] = m_pheap[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	m_pheap[i] = temp;
}

template<typename Type> MinHeap<Type>::MinHeap(Type heap[], int n) :m_nMaxSize(n){
	m_pheap = new Type[m_nMaxSize];
	for (int i = 0; i < n; i++){
		m_pheap[i] = heap[i];
	}
	m_ncurrentsize = n;
	int pos = (n - 2) / 2;	//Find the last tree which has more than one element;
	while (pos >= 0){
		Adjust(pos, n - 1);
		pos--;
	}
}

template<typename Type> bool MinHeap<Type>::DeleteMin(Type &first){
	first = m_pheap[0];
	m_pheap[0] = m_pheap[m_ncurrentsize - 1];
	m_ncurrentsize--;
	Adjust(0, m_ncurrentsize - 1);
	return 1;
}

template<typename Type> bool MinHeap<Type>::Insert(const Type item){
	if (m_ncurrentsize == m_nMaxSize){
		cerr << "Heap Full!" << endl;
		return 0;
	}
	m_pheap[m_ncurrentsize] = item;
	int j = m_ncurrentsize, i = (j - 1) / 2;
	Type temp = m_pheap[j];
	while (j > 0){
		if (m_pheap[i] <= temp){
			break;
		}
		else{
			m_pheap[j] = m_pheap[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	m_pheap[j] = temp;
	m_ncurrentsize++;
	return 1;
}

