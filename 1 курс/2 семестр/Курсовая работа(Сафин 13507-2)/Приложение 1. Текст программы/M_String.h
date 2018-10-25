#ifndef MSTRING_H
#define MSTRING_H
#include <iostream>
using namespace std;
typedef unsigned short int u_int;
class M_String{
private:
	char* string_;
	u_int lenght_;
public:
	M_String();
	M_String(const u_int&);
	M_String(const M_String&);
	u_int getLenght();
	M_String operator=(M_String&);
	M_String operator+(M_String& const);
	friend istream& operator>>(istream&, M_String&);
	friend ostream& operator<<(ostream&, M_String&);
	const bool operator==(const M_String&);
	//=.
};
#endif