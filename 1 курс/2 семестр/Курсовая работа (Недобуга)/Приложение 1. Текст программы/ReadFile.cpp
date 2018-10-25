#include <iostream>
#include <fstream>
#include "Base.h"
using namespace std;

void ReadFile(Base* B, int I)
{
	fstream ip ("../Kurs1/Files/input.txt", ios::in);
	if(!ip)
		throw "Error open. ";
	for(int i=0;i<I; i++)
	{
		ip>>B[i];
		if(!ip)
			throw "Error. Unexpected end of file. ";
	}
	ip.close();
}
