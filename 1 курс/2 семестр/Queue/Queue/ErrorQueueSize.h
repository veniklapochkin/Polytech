#include <exception>
#include <stdlib.h>
class ErrorQueueSize : public std::exception{
	char *reason;
public:
	ErrorQueueSize() :reason("Error Queue Size"){};
	const char *what(){
		return reason;
	}
};
