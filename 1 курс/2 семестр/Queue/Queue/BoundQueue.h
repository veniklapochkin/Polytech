#ifndef BOUND_QUEUE_H
#define BOUND_QUEUE_H
#include <stdlib.h>
#include <exception> 
#include "queue.h"
#include <iostream>
using namespace std;

class ErrSizeQueue:public exception
{
	char* reason;
public:
	
	ErrSizeQueue():reason ("Error Size Queue"){};
	const char*what() const {return reason;}
};
template<class T>
class BoundQueue: public Queue<T>{
	T*Queue_;
	int head_;
	int maxsize_;
	int tail_;
public:
	BoundQueue(int maxsize=10){maxsize_=maxsize;Queue_=new T[maxsize+1];head_=tail_=1;}
	~BoundQueue(){delete[] Queue_;}
	
	bool isEmpty()const {return head_==tail_;}
	bool isFull()const {return((tail_+1)%maxsize_==head_);}
	T& head()
	{
		if(isEmpty())throw QueueUnderFlow();
		return Queue_[head_];
	}
	void enQueue(const T&inf)
	{
		if(isFull())throw QueueOverFlow();
		Queue_[tail_]=inf;
		tail_=(tail_+1)%maxsize_;
	}
	void deQueue()
	{
		if(isEmpty())throw QueueUnderFlow();
		head_=(head_+1)%maxsize_;
	}
	void show()
	{
		for(int i=head_;i!=tail_;i=(i+1)%maxsize_)
			cout<<Queue_[i];

	}
};
#endif