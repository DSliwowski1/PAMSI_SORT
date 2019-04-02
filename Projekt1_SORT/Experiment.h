#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

#include "MergSort.h"
#include "QuickSort.h"
#include "IntroSort.h"
#include "Array.h"

template<typename T>
class Experiment
{
public:
	enum Algoritms {merge, quick, intro};

	static void Run(Algoritms alg, int ammount, int size, double prc, bool reverse, bool Mo3);

};

template<typename T>
void Experiment<T>::Run(Algoritms alg, int ammount, int size, double prc, bool reverse, bool Mo3)
{
	Array<T> arr(size);
	std::ofstream file;
	std::string filename;
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;
	std::chrono::duration<double> duration;

	filename = "Experiment_" + std::to_string(alg) + "_" + std::to_string(size) + "_" + std::to_string(prc) + ".csv";
	file.open(filename, std::ios::out);

	while (ammount > 0)
	{
		if (reverse)
			arr.GenerateReverse();
		else if (Mo3)
			arr.Mo3Killer();
		else
		{
			if (prc > 1 || prc < 0)
				std::cout << "prc poza przedzialem" << std::endl;
			else {
				int tmp = ammount * prc;
				if (tmp != 0)
					QuickSortT<T>::QuickSort(arr, 0, tmp);
			}
		}

		switch (alg)
		{
		case merge:
			start = std::chrono::high_resolution_clock::now();
			MergeSortT<int>::MergeSort(arr);
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
			file << size << ";" << duration.count() << endl;
		break;
		//*********************************************************
		case quick:
			start = std::chrono::high_resolution_clock::now();
			QuickSortT<int>::QuickSort(arr, 0, arr.GetSize() - 1);
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
			file << size << ";" << duration.count() << endl;
		break;
		//*********************************************************
		case intro:
			start = std::chrono::high_resolution_clock::now();
			IntroSortT<int>::IntroSort(arr);
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
			file << size << ";" << duration.count() << endl;
		break;
		//*********************************************************
		default:
		break;
		}
		ammount--;
		if (!arr.CheckSorting())
			cout << "Nie posortowane" << endl;
		else
			cout << "Posotrowane" << endl;
	}

}