#include "iostream"

using namespace std;
// 字符数组 int数组排序

template<typename T, typename T2>

int mySort(T *array, T2 size)
{
	T tmp;
	int i = 0, j = 0;
	if (array == NULL)
	{
		return -1;
	}
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}
template<typename T, typename T2>
void myPrint(T *array, T2 size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	printf("\n");
}

void main92()
{
	{
		int myarray[] = { 11,34,44,33,22,2,3,6,9 };
		int size = sizeof(myarray) / sizeof(*myarray);
		mySort<int, int>(myarray, size);
		myPrint<int, int>(myarray, size);
	}
	
	{
		char buf[] = "caezmf";
		int len = strlen(buf);
		mySort<char, int>(buf, len);
		myPrint<char, int>(buf, len);
	}

	cout << "hello..." << endl;

	system("pause");
	return;
}