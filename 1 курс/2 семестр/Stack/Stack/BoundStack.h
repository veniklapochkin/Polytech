#include <exception>
#include <iostream>
#include <sstream>
#include <string.h>
#include "stack.h"
using namespace std;

template <class T>
class BoundStack : public Stack<T>
{
protected:
	T *stack_; // ук на массив эл
	int size_;
	int top_;
public:
	BoundStack(int size = 100); // задается размер стека
	BoundStack(const BoundStack<T> &ob); // конструктор копирования
	~BoundStack(){};
	
	friend class stackOverflow; // переполнение
	void push(const T &ob)
	{
		stack_[++top_] = ob;
		if (top_ > size_)
			throw stackOverflow();
	};
	T pop()
	{
		return stack_[top_--];
		if (top_ < 0)
			throw stackOverflow();
	};
	bool isEmpty() { return (top_ == 0); }
};
template <class T>
BoundStack<T>::BoundStack(int size)
{
	stack_ = new T[size_ = size + 1];
	top_ = 0;
}
class stackOverflow{};