#include <iostream>
#include <chrono>
#include "Array.h"
#include "MergSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "IntroSort.h"
#include "Experiment.h"
#include "UI.h"

using namespace std;

int main(int argc, char** argv)
{
	/*
	//int a[] = { 3, 1, 5, 10, 4, 5, 1, 6, 7, 1};
	Array<int> tmp(1000000);
	tmp.Generate();
	Array<int> tmp2 = tmp;
	Array<int> tmp3 = tmp;
	Array<int> tmp4 = tmp;

	cin.get();

	//####### QuickSort #########
	cout << "Sortuje quckiem" << endl;

	auto start = std::chrono::high_resolution_clock::now();

	QuickSortT<int>::QuickSort(tmp, 0, tmp2.GetSize() - 1);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;

	cout << "Czas sortowania w sekundach: " << duration.count() << "s" << endl;
	
	//######## IntroSort

	cout << "Sortuje intro" << endl;

	auto start2 = std::chrono::high_resolution_clock::now();

	IntroSortT<int>::IntroSort(tmp2);
	
	auto end2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration2 = end2 - start2;

	cout << "Czas sortowania w sekundach: " << duration2.count() << "s" << endl;

	//######### MergeSort ##########

	cout << "Sortuje Mergem" << endl;

	auto start3 = std::chrono::high_resolution_clock::now();

	MergeSortT<int>::MergeSort(tmp3);

	auto end3 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration3 = end3 - start3;

	cout << "Czas sortowania w sekundach: " << duration3.count() << "s" << endl;

	//######## HeapSort

	cout << "Sortuje Heapem" << endl;

	auto start4 = std::chrono::high_resolution_clock::now();

	HeapSortT<int>::HeapSort(tmp4, 0, tmp4.GetSize());

	auto end4 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration4 = end4 - start4;

	cout << "Czas sortowania w sekundach: " << duration4.count() << "s" << endl;

	//Check Sort

	if (!tmp.CheckSorting())
		cout << "Nie posortowane" << endl;
	else
		cout << "Posotrowane" << endl;

	if (!tmp2.CheckSorting())
		cout << "Nie posortowane" << endl;
	else
		cout << "Posotrowane" << endl;

	if (!tmp3.CheckSorting())
		cout << "Nie posortowane" << endl;
	else
		cout << "Posotrowane" << endl;

	if (!tmp4.CheckSorting())
		cout << "Nie posortowane" << endl;
	else
		cout << "Posotrowane" << endl;

	*/
	char tmp = 'p';

	cin.get();

	while(tmp != 'e')
		tmp = UI::Menu();

	//Experiment<int>::Run(Experiment<int>::intro, 100, 1000, 0, false);

	cin.get();

	return 0;
}