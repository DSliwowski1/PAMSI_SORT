#pragma once
#include "Array.h"
#include <cmath>
#include <iostream>
#include "HeapSort.h"


using namespace std;


template<typename T>
class IntroSortT
{
public:
	static void IntroSort(Array<T>& arr);
private:
	static void IntroSort(Array<T>& arr, int l, int r, int maxDepth);

	static T PickPivot(Array<T>& arr, int l, int r);
	static int Partition(Array<T>& arr, int l, int r);
};

template<typename T>
void IntroSortT<T>::IntroSort(Array<T>& arr)
{
	int maxDepth = 2 * floor(log2(arr.GetSize()));
	IntroSortT<T>::IntroSort(arr, 0, arr.GetSize() - 1, maxDepth);
}

template<typename T>
void IntroSortT<T>::IntroSort(Array<T>& arr, int l, int r, int maxDepth)
{
	int split;
	if (l < r)
	{
		if (maxDepth <= 0)
		{
			HeapSortT<T>::HeapSort(arr, l, r);
			return;
		}

		split = IntroSortT<T>::Partition(arr, l, r);
		IntroSortT<T>::IntroSort(arr, l, split, maxDepth - 1);
		IntroSortT<T>::IntroSort(arr, split + 1, r, maxDepth -1);
	}
}


template<typename T>
T IntroSortT<T>::PickPivot(Array<T>& arr, int l, int r)
{
	int m = l + (r - l) / 2; //Takie obliczenie œrodkowego indeksu pozwala unikn¹æ prze³enienia int

	if (arr[m] < arr[l])
		arr.Swap(m, l);
	if (arr[r] < arr[l])
		arr.Swap(r, l);
	if (arr[m] < arr[r])
		arr.Swap(m, r);

	//cout << arr[r] << endl;

	return arr[r];
}

template<typename T>
int IntroSortT<T>::Partition(Array<T>& arr, int l, int r)
{
	T pivot = IntroSortT<T>::PickPivot(arr, l, r);

	int i = l - 1;
	int j = r + 1;


	while (true)
	{
		do
			i++;
		while (arr[i] < pivot);
		do
			j--;
		while (arr[j] > pivot);


		if (i >= j)
			return j;

		arr.Swap(i, j);
	}
}