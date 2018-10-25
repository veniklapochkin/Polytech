#include "Subscriber.h"
// ‘ункци€, определ€юща€ максимальный объект (10)
Subscriber maxobject(Subscriber *subscriber, int size)  
{
	Subscriber maxobject;
	for (int i = 0; i < size; i++)
	if (subscriber[i] > maxobject)
		maxobject = subscriber[i];

	return maxobject;
};
