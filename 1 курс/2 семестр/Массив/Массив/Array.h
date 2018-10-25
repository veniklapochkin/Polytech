#pragma once
#include <iostream>
using namespace std;

template <class T> class Array
{
private:
	int size_;
	T *array_;
public:
	Array()
	{

		array_ = 0;
		size_ = 0;
		cout << "Вызван конструктор массива по умолчанию, массив пуст" << endl;
	}

	Array(int size)
	{

		array_ = new T[size];
		size_ = size;
		cout << "Вызван конструктор с параметрами" << endl;
	}


	Array(const Array &ob)
	{
		this->array_ = new T[ob.size_];
		this->size_ = ob.size_;
		this->array_ = ob.array_;
		for (int i = 0; i<size_; i++)
			array_[i] = ob.array_[i];

		cout << "Вызван конструктор копирования массива" << endl;
	}

	T & operator [] (int i)
	{
		if (i >= 0 && i < size_)
		{
			return array_[i];
		}
		cout << "Перегрузка оператора индексирования" << endl;

	}

	//int min();

	~Array()
	{
		cout << "Вызван деструктор массива" << endl;
		delete[]array_;
	}
};

