#pragma once
#include "Array.h"
#include <cmath>

template<typename T>
class HeapSortT
{
public:
	static void HeapSort(Array<T>& arr, int l, int r);
private:
	static void Heapify(Array<T>& arr, int l, int r);
	static void ShiftDown(Array<T>& arr, int l, int start, int end);
	static int IdxParent(int child) { int tmp = floor((child - 1) / 2); return tmp; }
	static int IdxChildL(int root) { int tmp = 2*root + 1; return tmp; }
	static int IdxChildR(int root) { int tmp = 2*root  +2; return tmp; }
};

template<typename T>
void HeapSortT<T>::HeapSort(Array<T>& arr, int l, int r)
{
	HeapSortT<T>::Heapify(arr, l ,r);

	int end = r;

	while (end > l)
	{
		arr.Swap(end, l);	//element zerowy jest najwiekszy, zamieñ go z ostatnim, aby znalaz³ siê na swoim miejscu
		--end;	//Przesun koniec o 1
		HeapSortT<T>::ShiftDown(arr, l, l, end);	//Napraw kopiec (przywróæ w³aœciwoœci)

	}
}


template<typename T>
void HeapSortT<T>::Heapify(Array<T>& arr, int l, int r)
{
	int last = r-l;
	int start = l + HeapSortT<T>::IdxParent(last);	//Zacznij od rodzica ostatiego elementu ostatniego elementu

 	while (start >= l)
	{
		HeapSortT<T>::ShiftDown(arr, l , start, l + last); //Przesuñ wêze³ start w dól, tak aby spe³nia³ w³aœciwoœci kopca
		--start; //Przeskosz na nastêpny element i powtórz
	}
}

template<typename T>
void HeapSortT<T>::ShiftDown(Array<T>& arr, int l, int start, int end)
{
	int root = start;

	while ((HeapSortT<T>::IdxChildL(root) - l) <= end) //Je¿eli istnieje potomek
	{
		int child = HeapSortT<T>::IdxChildL(root) - l;
		int swap = root;	//Zak³adamy, ¿e root wymaga zmiany z samym sob¹

		if (arr[swap] < arr[child]) //Je¿eli swap jest mniejszy od potomka, to zapamiêtaj indeks potomka do zmiany
			swap = child;	//W tym momencie po zmianie swap bedzie nowym rootem, wiêc nale¿y sprawdziæ:

		if (child + 1 <= end) //Je¿eli istnieje prawy potomek sprawdŸ, czy jego wartoœæ nie jest wiêksza od swap, jeœli jest, to zapamiêtaj
			if (arr[swap] < arr[child + 1])
				swap = child + 1;
		if (swap == root)  //Je¿eli root od zawsze byl najwiêkszym elementem
			return;
		else {
			arr.Swap(root, swap); //Wstaw element na w³aœciwe miejsce
			root = swap;	//Kontynuj sprawdzanie w do³
		}
	}	
}