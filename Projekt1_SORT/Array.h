#pragma once
#include <iostream>
#include <random>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

// Szablon klasy implementuj¹cej stukture danych 'Array'
// T - typ
// _data - przechowuje dane
// _size - przechowuje rozmiar tablicy

template <typename T>
class Array
{
private:
	T* _data;
	int _size;

//Konstuktory, funkcjie dostêpu
public:
	Array(int size);
	Array(int size, int[]);
	Array();
	~Array();
	Array(const Array<T>& a);
	int GetSize() const { return this->_size; }
	void SetSize(int size) { this->_size = size; }

//Funkcje publiczne
public:
	void Generate();
	void GenerateReverse();
	bool CheckSorting();
	void Concat(Array<T> end);
	void Swap(int i, int j);

//Operatory
public:
	T& operator [](int idx) {
		return _data[idx];
	}

	T operator [](int idx) const {
		return _data[idx];
	}

	Array<T>& operator= (const Array<T> &a);

//Fukcjie prywatne
private:
	//void Merge(Array<T>& l, Array<T>& r);
};

//Konstruktory
template<typename T>
Array<T>::Array(int size)
{
	this->_size = size;
	this->_data = new T[this->_size];
}

template<typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_data = new T[this->_size];
}

template<typename T>
Array<T>::Array(int size, int a[])
{
	this->_size = size;
	this->_data = new T[this->_size];
	for (int i = 0; i < size; ++i)
		this->_data[i] = a[i];
}

//Dekonstruktor
template<typename T>
Array<T>::~Array()
{
	delete[] this->_data;
}

//Konstruktor kopjuj¹cy
template<typename T>
Array<T>::Array(const Array<T>& a)
{
	this->_size = a.GetSize();
	this->_data = new T[this->_size];
	for (int i = 0; i < a.GetSize(); ++i)
		this->_data[i] = a._data[i];
}

//Operator przesuniêcia bitowego w lewo
template<typename T>
std::ostream &operator<<(std::ostream &output, Array<T> &a) {
	for(int i = 0; i<a.GetSize(); ++i)
		output << a[i] << ", ";

	return output;
}

//Operator przypisania
template<typename T>
Array<T>& Array<T>::operator= (const Array<T> &a)
{
	if (this != &a) {
		delete[] this->_data;
		this->_size = a.GetSize();
		this->_data = new T[this->_size];
		for (int i = 0; i < a.GetSize(); ++i)
			this->_data[i] = a._data[i];
	}
	return *this;
}

//Funkcja wype³niaj¹ca tablice
//prc - procent tablicy, który ma byæ ju¿ posotrowany
template<typename T>
void Array<T>::Generate()
{
	std::random_device rd; //weŸ losow¹ liczbe
	std::mt19937 eng(rd()); //  generator Mersenne Twister 19937 z seedem rd
	std::uniform_real_distribution<double> distr(-20000, 20000); // Tworzenie rozk³adu normalnego z typem zmiennych T w przedziale [-1048576, 1048576]

	for (int i = 0; i < this->GetSize(); ++i) {
		this->_data[i] = distr(eng); //losowanie i wpisanie liczby do tablicy
	}
}

//Funkcja wype³niaj¹ca tablice w kolejnosci malej¹cej
template<typename T>
void Array<T>::GenerateReverse()
{
	for (int i = 0; i < this->GetSize(); ++i) {
		this->_data[i] = this->GetSize()-i-1;
	}
}

//Do³¹cza tablice end do koñca aktualnej tablicy
template<typename T>
void Array<T>::Concat(Array<T> end)
{
	int size = this->GetSize() + end.GetSize();

	Array<T> tmp(size);

	for (int i = 0; i < this->GetSize(); i++)
	{
		tmp[i] = (*this)[i];
	}
	for (int i = this->GetSize(); i < size; i++)
	{
		tmp[i] = end[i - this->GetSize()];
	}
	*this = tmp;
}


/*
template<typename T>
void Array<T>::MergeSort()
{
	int n1, n2;
	int size = this->GetSize();

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
		S1[i] = (*this)[i];
	for (int i = n1; i < size; i++)
		S2[i - n1] = (*this)[i];

	//cout << "S1, size: " << S1.GetSize() << endl << S1 << endl;
	//cout << "S2, size: " << S2.GetSize() << endl << S2 << endl;

	S1.MergeSort();
	S2.MergeSort();

	this->Merge(S1, S2);
}


template<typename T>
void Array<T>::Merge(Array<T>& l, Array<T>& r)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < l.GetSize() && j < r.GetSize())
	{
		if (l[i] <= r[j])
		{
			(*this)[k] = l[i];
			i++;
		}
		else 
		{
			(*this)[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < l.GetSize())
	{
		(*this)[k] = l[i];
		i++;
		k++;
	}
	while (j < r.GetSize())
	{
		(*this)[k] = r[j];
		j++;
		k++;
	}
}

*/

template<typename T>
bool Array<T>::CheckSorting()
{
	T last;
	last = (*this)[0];
	for (int i = 1; i < this->GetSize(); ++i)
	{
		if (last > (*this)[i])
			return false;
		else
			last = (*this)[i];
	}

	return true;
}

template<typename T>
void Array<T>::Swap(int i, int j)
{
	T tmp = (*this)[i];

	(*this)[i] = (*this)[j];
	(*this)[j] = tmp;

}