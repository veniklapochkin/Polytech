#include "WrongStackSize.h"
template <class T>
class Stack{
public:
	virtual ~Stack(){};
	virtual void push(const T& ob) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};