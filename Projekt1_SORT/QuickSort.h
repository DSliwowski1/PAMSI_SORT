#pragma once
#include <iostream>
#include <chrono>

#include "Array.h"


template <typename T>
class QuickSortT
{
public:
	static void QuickSort(Array<T>& arr, int l, int r);
	
private:
	static T PickPivot(Array<T>& arr, int l, int r);
	static int Partition(Array<T>& arr, int l, int r);
};

template<typename T>
void QuickSortT<T>::QuickSort(Array<T>& arr, int l, int r)
{

	int split;
	if (l < r) 
	{
		split = QuickSortT<T>::Partition(arr, l, r);

		QuickSortT<T>::QuickSort(arr, l, split);
		QuickSortT<T>::QuickSort(arr, split+1, r);
	}
}

template<typename T>
inline T QuickSortT<T>::PickPivot(Array<T>& arr, int l, int r)
{

	int m = l + (r - l) / 2; //Takie obliczenie œrodkowego indeksu pozwala unikn¹æ prze³enienia int

	if (arr[m] < arr[l])
		arr.Swap(m, l);
	if(arr[r] < arr[l])
		arr.Swap(r, l);
	if (arr[m] < arr[r])
		arr.Swap(m, r);

	//cout << arr[r] << endl;

	return arr[r];
}

template<typename T>
int QuickSortT<T>::Partition(Array<T>& arr, int l, int r)
{
	T pivot = QuickSortT<T>::PickPivot(arr, l, r);

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