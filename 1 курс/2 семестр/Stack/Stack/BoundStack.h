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
	T *stack_; // �� �� ������ ��
	int size_;
	int top_;
public:
	BoundStack(int size = 100); // �������� ������ �����
	BoundStack(const BoundStack<T> &ob); // ����������� �����������
	~BoundStack(){};
	
	friend class stackOverflow; // ������������
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