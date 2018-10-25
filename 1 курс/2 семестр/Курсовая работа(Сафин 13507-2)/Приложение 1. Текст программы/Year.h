#ifndef YEAR_H
#define YEAR_H
#include <iostream>
using namespace std;
typedef unsigned char p_char;
typedef unsigned short int u_int;
class Year{
private:
	p_char year_;
	void packAndSaveYear(u_int&); 
	u_int unpackAndGetYear() const;	
public:
	Year();
	/*Year(u_int);*/
	const bool operator<(const Year&);
	const bool operator>(const Year&);
	const bool operator==(const Year&);
	const Year& operator++();
	friend const Year operator++(Year&, int);
	
	friend istream& operator>>(istream&, Year&);
	friend ostream& operator<<(ostream&, const Year&);
};
#endif