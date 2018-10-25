#include <exception>
class WrongStackSize :public std::exception{
	char *reason;
public:
	WrongStackSize() :reason("Wrong Stack Size"){};
	const char *what(){
		return reason;
	}
};