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
		cout << "������ ����������� ������� �� ���������, ������ ����" << endl;
	}

	Array(int size)
	{

		array_ = new T[size];
		size_ = size;
		cout << "������ ����������� � �����������" << endl;
	}


	Array(const Array &ob)
	{
		this->array_ = new T[ob.size_];
		this->size_ = ob.size_;
		this->array_ = ob.array_;
		for (int i = 0; i<size_; i++)
			array_[i] = ob.array_[i];

		cout << "������ ����������� ����������� �������" << endl;
	}

	T & operator [] (int i)
	{
		if (i >= 0 && i < size_)
		{
			return array_[i];
		}
		cout << "���������� ��������� ��������������" << endl;

	}

	//int min();

	~Array()
	{
		cout << "������ ���������� �������" << endl;
		delete[]array_;
	}
};

