#include <exception>
#include <stdlib.h>
class QueueOverFlow : public std::exception{
	char *reason;
public:
	QueueOverFlow() :reason("Queue Over Flow"){};
	const char *what(){
		return reason;
	}
};
