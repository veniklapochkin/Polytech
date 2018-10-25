#include <exception>
#include <stdlib.h>

class QueueUnderFlow : public std::exception{
	char *reason;
public:
	QueueUnderFlow() :reason("Queue Under Flow"){};
	const char *what(){
		return reason;
	}
};
