#pragma once

#include <string>
#include <iostream>
#include "Experiment.h"

using namespace std;

namespace UI
{
	char Menu()
	{
		int ammount, size;
		double prc;
		bool reverse = false, Mo3Killer = false;
		int type, tmp;

		cout << "Program do testowania sortowan liczb ca³kowitych" << endl;
		cout << "Wykonal Daniel Sliwowksi" << endl;

		cin.get();
	
		cout << "Wybierz rodzaj sortowania: " << endl;
		cout << "0 - MergeSort \n1 - QuickSort \n2 - IntroSort " << endl;
		
		cin >> type;

		if (type != 0 && type != 1 && type != 2)
		{
			cout << "Niewlasciwy typ." << endl;
			return 'p';
		}

		cout << "Podaj ilosc tablic do posortowania:" << endl;
		cin >> ammount;

		if (ammount <= 0)
		{
			cout << "Niewlasciwa ilosc tablic" << endl;
			return 'p';
		}

		cout << "Podaj rozmiar tablic:" << endl;
		cin >> size;

		if (size <= 0)
		{
			cout << "Niewlasciwa rozmiar tablic" << endl;
			return 'p';
		}

		cout << "Czy tablice maja byc w odwroconej kolejnosci?" << endl;
		cout << "0 - tak \n1 - nie\n2 - Mo3Killer" << endl;
		cin >> tmp;

		if (tmp == 0)
		{
			reverse = true;
		}
		else if (tmp == 1)
		{
			reverse = false;
		}
		else if (tmp == 2)
		{
			Mo3Killer = true;
		}
		else
		{
			cout << "Niewlasciwy wybor!" << endl;
			return 'p';
		}

		cout << "Podaj procent posotrowania tablicy (liczba z przedzialu [0, 1]):" << endl;
		cin >> prc;

		if (prc > 1 || prc < 0)
		{
			cout << "Liczba poza zakresem" << endl;
			return 'p';
		}

		cout << "Trwa badanie!" << endl;

		Experiment<int>::Run(static_cast<Experiment<int>::Algoritms>(type), ammount, size, prc, reverse, Mo3Killer);

		cout << "Dane zostaly zapisane w folderze z programem." << endl;
		cout << "Czy chce wyjœæ?" << endl;
		cout << "0 - tak \n1 - nie" << endl;
		cin >> tmp;

		if (tmp == 0)
		{
			return 'e';
		}
		else if (tmp == 1)
		{
			return 'c';
		}
		else
		{
			cout << "Niewlasciwy wybor!" << endl;
			return 'p';
		}
	}
};