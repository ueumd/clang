#include "Data.h"
#include "LinkQueue.h"

template<typename Type> class Sort{
public:
	void InsertSort(DataList<Type> &list, int n = -1);
	void BinaryInsertSort(DataList<Type> &list, int n = -1);
	void ShellSort(DataList<Type> &list, const int gap = -1);
	void BubbleSort(DataList<Type> &list);
	void QuickSort(DataList<Type> &list, int left = 0, int right = -3);
	void SelectSort(DataList<Type> &list);
	void HeapSort(DataList<Type> &list);
	void MergeSort(DataList<Type> &list);
	void RadixSort(DataList<int> &list, int m, int d);      //just use for integer!


private:
	void BubbleSwap(DataList<Type> &list, const int n, int &flag);
	void SelectChange(DataList<Type> &list, const int n);
	void HeapAdjust(DataList<Type> &list, const int start, const int end);
	void Merge(DataList<Type> &list, DataList<Type> &mergedlist, const int len);
	void MergeDouble(DataList<Type> &list, DataList<Type> &mergedlist, const int start, const int part, const int end);
};

template<typename Type> void Sort<Type>::InsertSort(DataList<Type> &list, int n){
	if (-1 == n){
		for (int i = 1; i < list.m_ncurrentsize; i++){
			InsertSort(list, i);
		}
		return;
	}
	Element<Type> temp = list.m_pvector[n];
	int i;
	for (i = n; i>0; i--){
		if (temp > list.m_pvector[i - 1]){

			break;
		}
		else{
			list.m_pvector[i] = list.m_pvector[i - 1];
		}
	}
	list.m_pvector[i] = temp;
}

template<typename Type> void Sort<Type>::BinaryInsertSort(DataList<Type> &list, int n){
	if (-1 == n){
		for (int i = 1; i < list.m_ncurrentsize; i++){
			BinaryInsertSort(list, i);
		}
		return;
	}
	Element<Type> temp = list.m_pvector[n];
	int left = 0, right = n - 1;
	while (left <= right){
		int middle = (left + right) / 2;
		if (temp < list.m_pvector[middle]){
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	for (int i = n - 1; i >= left; i--){
		list.m_pvector[i + 1] = list.m_pvector[i];
	}
	list.m_pvector[left] = temp;
}

template<typename Type> void Sort<Type>::ShellSort(DataList<Type> &list, const int gap){
	if (-1 == gap){
		int gap = list.m_ncurrentsize / 2;
		while (gap){
			ShellSort(list, gap);
			gap = (int)(gap / 2);
		}
		return;
	}
	for (int i = gap; i < list.m_ncurrentsize; i++){
		InsertSort(list, i);
	}
}

template<typename Type> void Sort<Type>::BubbleSwap(DataList<Type> &list, const int n, int &flag){
	flag = 0;
	for (int i = list.m_ncurrentsize - 1; i >= n; i--){
		if (list.m_pvector[i - 1] > list.m_pvector[i]){
			list.Swap(list.m_pvector[i - 1], list.m_pvector[i]);
			flag = 1;
		}
	}
}

template<typename Type> void Sort<Type>::BubbleSort(DataList<Type> &list){
	int flag = 1, n = 0;
	while (++n < list.m_ncurrentsize && flag){
		BubbleSwap(list, n, flag);
	}
}

template<typename Type> void Sort<Type>::QuickSort(DataList<Type> &list, int left = 0, int right = -1){
	if (-3 == right){
		right = list.m_ncurrentsize - 1;
	}
	if (left < right){
		int pivotpos = left;
		Element<Type> pivot = list.m_pvector[left];
		for (int i = left + 1; i <= right; i++){
			if (list.m_pvector[i] < pivot && ++pivotpos != i){
				list.Swap(list.m_pvector[pivotpos], list.m_pvector[i]);
			}
			list.Swap(list.m_pvector[left], list.m_pvector[pivotpos]);
		}
		QuickSort(list, left, pivotpos - 1);
		QuickSort(list, pivotpos + 1, right);
	}

}

template<typename Type> void Sort<Type>::SelectChange(DataList<Type> &list, const int n){
	int j = n;
	for (int i = n + 1; i < list.m_ncurrentsize; i++){
		if (list.m_pvector[i] < list.m_pvector[j]){
			j = i;
		}
	}
	if (j != n){
		list.Swap(list.m_pvector[n], list.m_pvector[j]);
	}
}

template<typename Type> void Sort<Type>::SelectSort(DataList<Type> &list){
	for (int i = 0; i < list.m_ncurrentsize - 1; i++){
		SelectChange(list, i);
	}
}

template<typename Type> void Sort<Type>::HeapAdjust(DataList<Type> &list, const int start, const int end){
	int current = start, child = 2 * current + 1;
	Element<Type> temp = list.m_pvector[start];
	while (child <= end){
		if (child < end && list.m_pvector[child] < list.m_pvector[child + 1]){
			child++;
		}
		if (temp >= list.m_pvector[child]){
			break;
		}
		else {
			list.m_pvector[current] = list.m_pvector[child];
			current = child;
			child = 2 * current + 1;
		}
	}
	list.m_pvector[current] = temp;
}

template<typename Type> void Sort<Type>::HeapSort(DataList<Type> &list){
	for (int i = (list.m_ncurrentsize - 2) / 2; i >= 0; i--){
		HeapAdjust(list, i, list.m_ncurrentsize - 1);
	}

	for (int i = list.m_ncurrentsize - 1; i >= 1; i--){
		list.Swap(list.m_pvector[0], list.m_pvector[i]);
		HeapAdjust(list, 0, i - 1);
	}
}

template<typename Type> void Sort<Type>::MergeDouble(DataList<Type> &list, DataList<Type> &mergedlist, const int start, const int part, const int end){
	int i = start, j = part + 1, k = start;
	while (i <= part && j <= end){
		if (list.m_pvector[i] <= list.m_pvector[j]){
			mergedlist.m_pvector[k++] = list.m_pvector[i++];
		}
		else {
			mergedlist.m_pvector[k++] = list.m_pvector[j++];
		}
	}
	if (i <= part){
		for (int m = i; m <= part && k <= end;){
			mergedlist.m_pvector[k++] = list.m_pvector[m++];
		}
	}
	else {
		for (int m = j; m <= end && k <= end; m++){
			mergedlist.m_pvector[k++] = list.m_pvector[m];
		}
	}
}
template<typename Type> void Sort<Type>::Merge(DataList<Type> &list, DataList<Type> &mergedlist, const int len){
	int n = 0;
	while (n + 2 * len < list.m_ncurrentsize){
		MergeDouble(list, mergedlist, n, n + len - 1, n + 2 * len - 1);
		n += 2 * len;
	}
	if (n + len < list.m_ncurrentsize){
		MergeDouble(list, mergedlist, n, n + len - 1, list.m_ncurrentsize - 1);
	}
	else {
		for (int i = n; i < list.m_ncurrentsize; i++){
			mergedlist.m_pvector[i] = list.m_pvector[i];
		}
	}
}

template<typename Type> void Sort<Type>::MergeSort(DataList<Type> &list){
	DataList<Type> temp(list.m_nMaxSize);
	temp.m_ncurrentsize = list.m_ncurrentsize;
	int len = 1;
	while (len < list.m_ncurrentsize){
		Merge(list, temp, len);
		len *= 2;
		Merge(temp, list, len);
		len *= 2;
	}
}

template<typename Type> void Sort<Type>::RadixSort(DataList<int> &list, int m, int d){
	LinkQueue<int> *queue = new LinkQueue<int>[d];
	int power = 1;
	for (int i = 0; i < m; i++){
		if (i){
			power = power * d;
		}
		for (int j = 0; j < list.m_ncurrentsize; j++){
			int k = (list.m_pvector[j].GetKey() / power) % d;
			queue[k].Append(list.m_pvector[j].GetKey());
		}

		for (int j = 0, k = 0; j < d; j++){
			while (!queue[j].IsEmpty()){
				list.m_pvector[k++].SetKey(queue[j].Delete());
			}
		}
	}
}
