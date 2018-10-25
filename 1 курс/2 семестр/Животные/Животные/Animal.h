#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
class Animal
{
protected:
	string name_;
public:
	Animal(string name) : name_(name){};
	virtual void say() = 0;
};
