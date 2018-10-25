#pragma once
#include <exception> 
class QueueUnderFlow:public std::exception
{public:
	char*reason;
	QueueUnderFlow():reason("Queue Over FLow"){};
	const char*what() const {return reason;}
};
class QueueOverFlow:public std::exception
{char*reason;
public:
	QueueOverFlow():reason("Queue Over FLow"){};
	const char*what() const {return reason;}
};
template <class T>
class Queue {
public:
	virtual ~Queue(){}
	virtual void enQueue(const T&inf)=0;
	virtual void deQueue()=0;
	virtual bool isEmpty()const=0;
	virtual  T& head()=0;
};
