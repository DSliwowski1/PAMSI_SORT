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
		arr.Swap(end, l);	//element zerowy jest najwiekszy, zamie� go z ostatnim, aby znalaz� si� na swoim miejscu
		--end;	//Przesun koniec o 1
		HeapSortT<T>::ShiftDown(arr, l, l, end);	//Napraw kopiec (przywr�� w�a�ciwo�ci)

	}
}


template<typename T>
void HeapSortT<T>::Heapify(Array<T>& arr, int l, int r)
{
	int last = r-l;
	int start = l + HeapSortT<T>::IdxParent(last);	//Zacznij od rodzica ostatiego elementu ostatniego elementu

 	while (start >= l)
	{
		HeapSortT<T>::ShiftDown(arr, l , start, l + last); //Przesu� w�ze� start w d�l, tak aby spe�nia� w�a�ciwo�ci kopca
		--start; //Przeskosz na nast�pny element i powt�rz
	}
}

template<typename T>
void HeapSortT<T>::ShiftDown(Array<T>& arr, int l, int start, int end)
{
	int root = start;

	while ((HeapSortT<T>::IdxChildL(root) - l) <= end) //Je�eli istnieje potomek
	{
		int child = HeapSortT<T>::IdxChildL(root) - l;
		int swap = root;	//Zak�adamy, �e root wymaga zmiany z samym sob�

		if (arr[swap] < arr[child]) //Je�eli swap jest mniejszy od potomka, to zapami�taj indeks potomka do zmiany
			swap = child;	//W tym momencie po zmianie swap bedzie nowym rootem, wi�c nale�y sprawdzi�:

		if (child + 1 <= end) //Je�eli istnieje prawy potomek sprawd�, czy jego warto�� nie jest wi�ksza od swap, je�li jest, to zapami�taj
			if (arr[swap] < arr[child + 1])
				swap = child + 1;
		if (swap == root)  //Je�eli root od zawsze byl najwi�kszym elementem
			return;
		else {
			arr.Swap(root, swap); //Wstaw element na w�a�ciwe miejsce
			root = swap;	//Kontynuj sprawdzanie w do�
		}
	}	
}