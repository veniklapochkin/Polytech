//Вывод структуры
#include <fstream>
using namespace std;
#include "header.h"
void outputf(Abonent *a, const int n)
{
    ofstream out("output.txt");
	for (int i=0; i<n; i++) 
	{	
		out<<a[i].numPhone<<" "; 
		out<<a[i].tarif<<" "; 
		out<<a[i].name; 
		out<<"\n";
	}
}