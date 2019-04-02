#pragma once
#include <iostream>
#include <chrono>

#include "Array.h"

template<typename T>
class MergeSortT
{
public:
	static void MergeSort(Array<T>& arr);


	static void Experiment(int times, int ammount, float prc, bool reverse);

private:
	static void Merge(Array<T>& arr, Array<T>& l, Array<T>& r);
};

template<typename T>
void MergeSortT<T>::MergeSort(Array<T>& arr)
{
	{
		int n1, n2;
		int size = arr.GetSize();

		if (size <= 1)
			return;

		if (size % 2 != 0)
		{
			n1 = size / 2;
			n2 = n1 + 1;
		}
		else {
			n1 = n2 = size / 2;
		}

		Array<T> S1(n1), S2(n2);

		for (int i = 0; i < n1; i++)
			S1[i] = arr[i];
		for (int i = n1; i < size; i++)
			S2[i - n1] = arr[i];

		MergeSortT<T>::MergeSort(S1);
		MergeSortT<T>::MergeSort(S2);

		MergeSortT<T>::Merge(arr, S1, S2);
	}
}

template<typename T>
void MergeSortT<T>::Merge(Array<T>& arr, Array<T>& l, Array<T>& r)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < l.GetSize() && j < r.GetSize())
	{
		if (l[i] <= r[j])
		{
			arr[k] = l[i];
			i++;
		}
		else
		{
			arr[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < l.GetSize())
	{
		arr[k] = l[i];
		i++;
		k++;
	}
	while (j < r.GetSize())
	{
		arr[k] = r[j];
		j++;
		k++;
	}
}

template<typename T>
void MergeSortT<T>::Experiment(int times, int ammount, float prc, bool reverse)
{
	Array<T> tmp(ammount);

	for (int i = 0; i < times; ++i)
	{
		if (reverse)
			tmp.GenerateReverse();
		else
		{
			int tmp = ammount * prc;
			
		}



		cout << tmp << endl;

		auto start = std::chrono::high_resolution_clock::now();
		MergeSortT<int>::MergeSort(tmp);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		cout << tmp << endl;

		if (!tmp.CheckSorting())
			cout << "Nie posortowane";
		else
			cout << "Posotrowane" << endl;

		cout << "Czas sortowania w sekundach: " << duration.count() << "s" << endl;
	}
}